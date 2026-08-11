"""MkDocs-Hook: zeitgesteuerte Veroeffentlichung von Seiten.

Erlaubt, Arbeitsauftraege bereits vorab ins Repository zu pushen, aber
erst ab einem bestimmten Datum auf der gebauten Kurswebseite erscheinen
zu lassen. Dazu wird im YAML-Frontmatter der Markdown-Datei ein Feld
"publish_date" (Format YYYY-MM-DD) gesetzt. Liegt dieses Datum in der
Zukunft, wird die Seite beim Bauen komplett aus dem Build entfernt
(nicht nur aus der Navigation) - sie landet also gar nicht im
Ausgabeverzeichnis. Dateien ohne "publish_date" werden wie bisher immer
eingebaut.

Eine noch nicht veroeffentlichte Seite darf in "mkdocs.yml" trotzdem
schon in der "nav"-Konfiguration stehen - das ist ja gerade der Sinn.
Damit MkDocs daraus keinen kaputten Link erzeugt, muss der betroffene
nav-Eintrag ebenfalls verschwinden.

WICHTIG - warum das in "on_config" passiert und nicht erst in "on_nav":
MkDocs baut die Navigation in "get_navigation()" auf und protokolliert
dort SOFORT eine Warnung fuer jeden nav-Eintrag, zu dem es keine Datei
findet ("A reference to '...' is included in the 'nav' configuration,
which is not found in the documentation files."). Das geschieht, BEVOR
der "on_nav"-Hook ueberhaupt aufgerufen wird - ein nachtraegliches
Aufraeumen in "on_nav" kommt also zu spaet, um die Warnung zu
verhindern. Da der Deploy-Workflow mit "mkdocs build --strict" laeuft,
wuerde diese Warnung den gesamten Build abbrechen lassen, sobald auch
nur eine Seite ein zukuenftiges publish_date hat. Deshalb wird die
nav-Konfiguration bereits in "on_config" bereinigt, also bevor MkDocs
die Navigation baut. (Am gebauten Ergebnis getestet.)

Ein taeglicher, zeitgesteuerter Rebuild (siehe
.github/workflows/deploy-docs.yml) sorgt dafuer, dass eine Seite am
Stichtag automatisch erscheint, ohne dass dafuer erneut gepusht werden
muss.

Testmodus: Ist die Umgebungsvariable MKDOCS_TESTMODE auf "1" gesetzt,
wird die gesamte publish_date-Filterlogik uebersprungen - alle Seiten
werden unabhaengig von ihrem publish_date eingebunden, so als laege das
Datum immer in der Vergangenheit. Ausschliesslich fuer den lokalen
Aufruf von "mkdocs serve" gedacht (siehe CLAUDE.md); im automatischen
Deploy-Workflow (.github/workflows/deploy-docs.yml) darf diese
Variable nicht gesetzt werden.
"""

from __future__ import annotations

import datetime
import logging
import os
from pathlib import Path

from mkdocs.structure.files import Files
from mkdocs.structure.nav import Link, Navigation, Section
from mkdocs.utils import meta

log = logging.getLogger("mkdocs.hooks.publish_scheduler")

# Wird in on_config befuellt und in on_files/on_nav gelesen (pro
# Build-Lauf neu gesetzt - wichtig fuer "mkdocs serve", das mehrfach neu
# baut).
_excluded_src_uris: set[str] = set()


def _testmode_active() -> bool:
    return os.environ.get("MKDOCS_TESTMODE") == "1"


def _parse_publish_date(value: object) -> datetime.date | None:
    """Wandelt den Rohwert des "publish_date"-Feldes in ein date-Objekt um."""
    if value is None:
        return None
    if isinstance(value, datetime.datetime):
        return value.date()
    if isinstance(value, datetime.date):
        return value
    if isinstance(value, str):
        try:
            return datetime.date.fromisoformat(value.strip())
        except ValueError:
            log.warning(
                "publish_date '%s' hat nicht das Format YYYY-MM-DD - wird ignoriert.",
                value,
            )
            return None
    return None


def _publish_date_of(path: Path) -> datetime.date | None:
    """Liest das publish_date aus dem Frontmatter einer Markdown-Datei."""
    try:
        source = path.read_text(encoding="utf-8")
    except OSError as exc:
        log.warning("'%s' konnte nicht gelesen werden: %s", path, exc)
        return None
    _, page_meta = meta.get_data(source)
    return _parse_publish_date(page_meta.get("publish_date"))


def _prune_nav_config(items: list) -> list:
    """Entfernt nav-Eintraege, die auf noch nicht veroeffentlichte Seiten zeigen.

    Arbeitet auf der ROHEN nav-Struktur aus mkdocs.yml, also auf
    verschachtelten Listen aus Strings ("pfad/zur/datei.md") und Dicts
    ({"Titel": "pfad.md"} bzw. {"Titel": [...]}). Sections, die dadurch
    leer werden, fallen ebenfalls weg.
    """
    kept: list = []
    for item in items:
        if isinstance(item, str):
            if item not in _excluded_src_uris:
                kept.append(item)
        elif isinstance(item, dict):
            pruned: dict = {}
            for title, value in item.items():
                if isinstance(value, str):
                    if value not in _excluded_src_uris:
                        pruned[title] = value
                elif isinstance(value, list):
                    children = _prune_nav_config(value)
                    if children:
                        pruned[title] = children
                else:
                    pruned[title] = value
            if pruned:
                kept.append(pruned)
        else:
            kept.append(item)
    return kept


def on_config(config):
    """Ermittelt die noch nicht faelligen Seiten und raeumt die nav auf."""
    _excluded_src_uris.clear()

    if _testmode_active():
        log.info(
            "MKDOCS_TESTMODE=1 - publish_date-Filterung wird uebersprungen, "
            "alle Seiten werden eingebunden."
        )
        return config

    docs_dir = Path(config["docs_dir"])
    today = datetime.date.today()
    # Per "exclude_docs" ausgeschlossene Dateien (z. B. die Templates) duerfen
    # hier gar nicht erst angefasst werden: Ihr Frontmatter enthaelt
    # absichtlich Platzhalter wie "publish_date: <YYYY-MM-DD>", die sonst
    # jedes Mal eine Warnung ausloesen - und unter "--strict" den Build
    # abbrechen lassen wuerden.
    exclude_spec = config.get("exclude_docs")

    for path in sorted(docs_dir.rglob("*.md")):
        src_uri = path.relative_to(docs_dir).as_posix()
        if exclude_spec is not None and exclude_spec.match_file(src_uri):
            continue
        if any(part.startswith(".") for part in path.relative_to(docs_dir).parts):
            continue

        publish_date = _publish_date_of(path)
        if publish_date is not None and publish_date > today:
            _excluded_src_uris.add(src_uri)
            log.info(
                "'%s' wird erst ab %s veroeffentlicht - aus dem Build ausgeschlossen.",
                src_uri,
                publish_date.isoformat(),
            )

    if _excluded_src_uris and config.get("nav"):
        config["nav"] = _prune_nav_config(config["nav"])

    return config


def on_files(files: Files, config):
    """Entfernt die in on_config ermittelten Seiten komplett aus dem Build."""
    if not _excluded_src_uris:
        return files
    return Files([file for file in files if file.src_uri not in _excluded_src_uris])


def _prune_nav_items(items: list) -> list:
    """Sicherheitsnetz: entfernt Nav-Eintraege auf ausgeschlossene Seiten.

    Sollte nach dem Bereinigen in on_config nichts mehr zu tun finden.
    Bleibt als Absicherung fuer den Fall, dass ein nav-Eintrag auf einem
    Weg entsteht, den _prune_nav_config nicht erfasst. MkDocs loest einen
    nav-Eintrag, dessen Datei nicht (mehr) existiert, zu einem "Link" mit
    dem rohen Konfigurationspfad als URL auf.
    """
    kept = []
    for item in items:
        if isinstance(item, Section):
            item.children = _prune_nav_items(item.children)
            if item.children:
                kept.append(item)
        elif isinstance(item, Link) and item.url in _excluded_src_uris:
            continue
        else:
            kept.append(item)
    return kept


def on_nav(nav: Navigation, config, files: Files):
    """Entfernt Navigationseintraege, die auf ausgeschlossene Seiten verweisen."""
    if not _excluded_src_uris:
        return nav
    nav.items = _prune_nav_items(nav.items)
    return nav
