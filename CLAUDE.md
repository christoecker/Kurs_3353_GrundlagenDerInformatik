# Projektkontext: Kurs "Grundlagen der Informatik" (GdI) — Mechatronik/Automatisierung

Diese Datei ist der Einstiegskontext für Claude Code in diesem Repository.
Lies sie vollständig, bevor du Inhalte erstellst oder bearbeitest.

## Worum es geht

Wir bauen die Lehr- und Lernmaterialien für das Modul "Grundlagen der
Informatik" (Kennnummer 3353, 5 CP, 150 h Workload) im praxisintegrierten
Studiengang Mechatronik/Automatisierung (B.Eng.) auf. Zielgruppe:
**Erstsemester im 1. Fachsemester ohne jede Vorkenntnis** in Programmierung
oder Informatik. Turnus: jährlich im Wintersemester. Aktueller Durchlauf:
**WS 2026/2027**.

Prüfungsform: **Klausur** (voraussichtlich E-Klausur in ILIAS). Das Modulhandbuch
lässt "Klausur oder Projektarbeit" zu; gewählt ist die Klausur. Das prägt die
Aufgabengestaltung (siehe "Klausurbezug" unten).

Programmiersprache des gesamten Moduls ist **C**, ausschließlich prozedural.
**Keine objektorientierten Konzepte, kein C++** — das ist eine harte Vorgabe.
Entwicklungsumgebung: Visual Studio bzw. Visual Studio Code unter Windows.

Verbindliche Termin- und Themenübersicht:
`00-projektsteuerung/curriculum-map.yaml` — **das ist die Single Source of
Truth** für was wann behandelt wird. Bei jeder inhaltlichen Änderung diese
Datei mitpflegen. Die Pflichtinhalte laut Modulhandbuch stehen in
`00-projektsteuerung/modulbeschreibung.md`; Inhalte, die noch keinem Block
zugewiesen sind, führt `curriculum-map.yaml` am Ende unter
`offene_pflichtinhalte` — diese Liste muss vor Kursende leer sein.

Grundsatzentscheidungen zu Aufbau, Format und Werkzeugen werden in
`00-projektsteuerung/entscheidungen.md` protokolliert.

## Quellen und Urheberrecht

- **Hauptquelle für die Programmier-Themen** ist die Youtube-Playlist des
  Professors: <https://www.youtube.com/playlist?list=PL2LjUivoqcmUUY746pJUnpfwAkW5N60Ha>
  Das ist eigenes Material und darf ohne urheberrechtliche Einschränkung
  referenziert und paraphrasiert werden.
- Ergänzend ein noch zu bestimmendes **Fachbuch** (bevorzugt aus dem Hanser-
  oder SpringerLink-Programm, die Hochschulbibliothek hat Zugriff).
- Für **Rechnerarchitektur, Zahlensysteme und Algorithmen/PAP** sind die
  Quellen noch nicht festgelegt. Sie werden **erst beim Erstellen der
  jeweiligen Einheit** recherchiert, nicht vorab auf Vorrat.
- Rechercheergebnisse und Verwendungsnachweise werden in
  `03-quellen/<thema>.md` festgehalten.
- Aus fremden, urheberrechtlich geschützten Quellen werden **niemals
  Textpassagen wörtlich übernommen**. Inhalte werden eigenständig neu
  formuliert, Kapitel und Seiten nur als Referenz zitiert.

## Format des Kurses (wichtig für alle Materialien!)

Der Kurs hat zwei Lernphasen; die zweite zerfällt in zwei Modi. Jedes
Material muss eindeutig einem davon zugeordnet sein:

1. **Praxisphase – Selbststudium** (`docs/01-praxisphase/`): **7 Wochen**,
   BEVOR die Theoriephase beginnt. Studierende sind im Betrieb und lernen
   alleine. Workload strikt limitiert auf **1–2 Stunden pro Woche** — die
   Phase ist kurz, weil Erstsemester die Vorbereitungsinfos später bekommen
   als höhere Semester; der Wochen-Workload wird deshalb NICHT als Ausgleich
   erhöht. Kein Kontakt zum Lehrenden außer über die Materialien selbst.
   Aufgaben müssen absolut selbsterklärend sein und dürfen **keine
   Vorkenntnisse** voraussetzen. Jede Woche geht montags online (siehe
   "Zeitgesteuerte Veröffentlichung"), erste Woche 31.08.2026, letzte
   12.10.2026.

2. **Übung** (Abschnitt `## <Kurztitel> { .modus-uebung }` in
   `docs/02-theoriephase/termin-XX/block-NN.md`): Präsenz, 45 Minuten, der
   Lehrende hat den aktiven Part. In GdI heißt das ganz überwiegend
   **Live-Coding**: ein kleines Problem wird gemeinsam Schritt für Schritt
   in C umgesetzt.

3. **Betreutes Selbststudium** (Abschnitt
   `## <Kurztitel> { .modus-selbststudium }` in derselben Datei, direkt im
   Anschluss): Präsenz, 45 Minuten. Studierende arbeiten allein oder in
   Kleingruppen, der Lehrende betreut. Aufgaben sollen
   **abwechslungsreich** sein: Programmieraufgaben, Fehlersuche in
   vorgegebenem Code, Schreibtischtests, PAP-Aufgaben, kurze Recherchen,
   Code-Reviews untereinander — nicht immer nur "schreibe ein Programm,
   das ...".

Es gibt in diesem Modul **keine Vorlesung**. Eine separate Kategorie
**"Praktikum" gibt es ebenfalls nicht** — die dafür im Modulhandbuch
vorgesehenen 16 h Präsenz gehen bewusst vollständig in zusätzliche
Übungs-/bS-Blöcke auf. Das Kategorien-Schema sieht "Praktikum" deshalb gar
nicht erst als Einheitstyp vor.

Übung und betreutes Selbststudium eines Blocks liegen bewusst in EINER Datei
(`block-NN.md`, `NN` = `block_id` aus `curriculum-map.yaml`), nicht in
getrennten Dateien. Blöcke sind über die **gesamte** Theoriephase fortlaufend
nummeriert (nicht pro Termin neu bei 1) und nach Terminen sortiert.

Die Theoriephase umfasst **10 Termine** vom 21.10. bis 23.12.2026. Die
meisten Termine haben 2 Blöcke; drei Termine (4.11., 18.11., 2.12.) haben 3.
Zeitraster: 08:30–10:00, 10:15–11:45, 12:30–14:00.

Zusätzlich bekommt jeder Termin eine Übersichtsseite
(`termin-XX/index.md`) — kein Übungs-/Selbstkontrollteil, nur Überblick und
Vorbereitungsauftrag, max. 90 Minuten Workload.

Weder "Block" noch die interne `block_id` tauchen im sichtbaren Titel oder in
Überschriften auf (siehe "Theoriephase: Block-Struktur & Templates").

## Sonderfall Zwischenprojekt (Termin 6, 25.11.2026)

Dieser Termin folgt **nicht** dem 45'/45'-Rhythmus und benutzt **nicht** die
Klassen `.modus-uebung`/`.modus-selbststudium`. Stattdessen: längere
zusammenhängende Arbeitsphasen, in denen die Studierenden mit
KI-Unterstützung eine kleine eigene Anwendung entwickeln. Der Lehrende
schiebt kurze Unterbrechungen zur Zwischenstandsabfrage und Problemlösung
ein.

**Lernziel des Tages ist nicht "ein Programm haben", sondern die
Softwareentwicklung mit KI zu STEUERN und das Ergebnis zu BEWERTEN** — eine
kleine Vorstufe dessen, was die Studierenden später beruflich können sollen.

Der Termin belegt beide Slots des Tages (180 min) als EINE Einheit; die Datei
heißt deshalb `block-13-14.md` mit `block_id: "13-14"` und `format: projekt`.
Die konkrete Struktur-Variante (`_templates/projekttag.template.md`) wird
**bei der Planung dieses Termins gemeinsam entworfen**, nicht vorab
festgelegt.

## Planung vor Umsetzung bei Theoriephase-Inhalten

Bei jedem Prompt zur Erstellung oder inhaltlichen Änderung eines
Termin-Blocks in der Theoriephase (alles unter `docs/02-theoriephase/`, das
kein Template und keine reine Infrastrukturänderung ist) gilt: **zuerst eine
Planung im Chat vorlegen** — **ohne dabei Dateien anzulegen oder zu ändern**.
Erst nach expliziter Freigabe durch den Professor erfolgt die tatsächliche
Erstellung.

Diese Regel gilt **nicht** für:

- Praxisphase-Einheiten (dort direkt umsetzen),
- reine Infrastruktur-/Werkzeugarbeit an der Theoriephase (Templates in
  `_templates/`, Hooks, das Schema von `aufgaben-register.yaml`,
  `mkdocs.yml`, leere Platzhalterdateien zum Testen der Nav-Struktur).

### Phase 1: Planung (auf Kommando "Plane Block &lt;NN&gt;")

Thema und Inhalte des angeforderten Blocks aus `curriculum-map.yaml`
ermitteln. Ausgabe **ausschließlich im Chat**, **ohne dabei Dateien anzulegen
oder zu ändern**:

1. **Für die Übung:** eine nummerierte Liste mit kleinschrittigem Vorgehen.
   Jeder Listenpunkt beschreibt einen Live-Coding-Schritt oder
   Erklärabschnitt, inklusive der Angabe, welche Code-Snippet-Datei dabei
   entsteht.
2. **Für das betreute Selbststudium:** eine nummerierte Liste der geplanten
   Aufgabe(n) inklusive Teilaufgaben, mit vorläufiger Nummer aus
   `00-projektsteuerung/aufgaben-register.yaml`.
3. Angabe der `ki_einsatz`-Stufe und ggf. neu einzuführender
   Clean-Code-Prinzipien.

Danach **stoppt die Bearbeitung** — keine Dateien werden angelegt oder
geändert, bis eine explizite Freigabe erfolgt. Anpassungswünsche werden nach
Rückmeldung eingearbeitet und erneut als aktualisierte Liste ausgegeben; erst
nach explizitem **"GO"** folgt Phase 2.

Für den Zwischenprojekt-Termin (Termin 6) gilt die Phase-1-Struktur **nicht**
in dieser Form — dort wird stattdessen zuerst die Ablaufstruktur des
Projekttags selbst zur Diskussion gestellt.

### Phase 2: Erstellung (nach "GO")

Die Block-Datei nach der verbindlichen Struktur aus
`docs/02-theoriephase/_templates/block.template.md` anlegen, alle
Konventionen dieser Datei einhalten, und anschließend:

- `curriculum-map.yaml` fortschreiben (`bearbeitungsstatus`, ggf.
  `clean_code_einfuehrung`),
- `aufgaben-register.yaml` um die neuen Aufgaben ergänzen,
- Glossar prüfen und ergänzen (Pflichtschritt, siehe unten),
- Nav-Eintrag in `mkdocs.yml` ergänzen — erst jetzt, wo die Datei existiert.

## Didaktische Leitplanken

- **Erstsemester ohne Vorkenntnisse.** Jeder Fachbegriff wird bei seiner
  ersten Verwendung erklärt und ins Glossar aufgenommen. Keine vorausgesetzten
  Programmiererfahrungen, keine impliziten Analogien zu anderen Sprachen.
- **Hoher Praxisanteil.** Wenig reine Theorie, viel Arbeit an lauffähigem
  Code. Jedes Live-Coding-Beispiel muss tatsächlich kompilieren und laufen.
- **Vom PAP zum Code.** Die Praxisphase baut algorithmisches Denken über
  Programmablaufpläne auf, bevor überhaupt Code geschrieben wird. Dieser rote
  Faden wird in der Theoriephase weitergeführt: neue Konstrukte werden, wo
  sinnvoll, zuerst als PAP gezeigt und dann in C übersetzt.
- **Steigende Selbstständigkeit.** Frühe bS-Aufgaben sind stark geführt
  (Rahmen vorgegeben, Lücken füllen), spätere offen formuliert.
- **Klausurbezug.** Da mit Klausur geprüft wird, enthält jede Einheit
  mindestens eine Aufgabe, die **ohne Rechner** lösbar ist — Code lesen,
  Ausgabe vorhersagen, Fehler finden, Schreibtischtest. Reines "am Rechner
  ausprobieren" bereitet nicht auf die Prüfungsform vor.
- **Kein durchgängiger Fallstudien-Case.** GdI-Aufgaben sind themenbezogen;
  es gibt bewusst keinen Fallstudien-Pool. Ein Bezug zur
  Mechatronik/Automatisierung (Sensorwerte, Motorsteuerung, Messreihen,
  Zustandsautomaten) ist willkommen, wo er sich natürlich ergibt — aber nicht
  erzwungen.

## Clean Code als wiederkehrendes Prinzip

Clean Code (DRY, KISS, YAGNI, Konvention vor Konfiguration, sprechende Namen,
Kommentare erklären das Warum) ist **kein eigener Themenblock** und **kein
Sonderformat**. Stattdessen:

- Prinzipien werden **nach und nach** eingeführt, jeweils dort, wo sie zum
  ersten Mal wirklich nötig werden (z. B. DRY bei den Funktionen, Magic
  Numbers bei den Variablen, YAGNI beim Zwischenprojekt).
- Der Einführungszeitpunkt steht je Block im Feld `clean_code_einfuehrung` in
  `curriculum-map.yaml` und im Frontmatter-Feld `clean_code` der Block-Datei.
- **Ab dem Einführungszeitpunkt** wird das jeweilige Prinzip in allen
  folgenden Aufgaben als Qualitätskriterium mit eingefordert — sichtbar in der
  Aufgabenstellung und in der Musterlösung begründet.
- Die Einführung selbst passiert im Fließtext bzw. in einem
  `!!! tip "Clean Code: <Prinzip>"`-Block, nicht als eigener
  Gliederungspunkt. Sie wird immer am gerade entstandenen Code gezeigt, nicht
  abstrakt behauptet.

## KI-Konzept

Referenzdokument für die Studierenden: `docs/ki-nutzung.md`.

### Zeitliche Staffelung — das ist der Kern

- **Frühe Termine (Blöcke 01–12: Grundlagen, Verzweigungen, Schleifen,
  Variablen, Funktionen, Rekursion, Arrays, Pointer): bewusst zurückhaltender
  bis gar kein KI-Einsatz beim eigentlichen Programmieren.** Ziel ist, dass
  die Studierenden zuerst selbst algorithmisch denken und Code schreiben
  lernen. In diesen Blöcken steht in den Aufgaben ausdrücklich, dass die
  Lösung eigenständig entstehen soll — und **warum**. Ein Verbot ohne
  Begründung wird ignoriert.
- **Wendepunkt ist das Zwischenprojekt (Termin 6, 25.11.2026).** Dort wird
  KI-Unterstützung gezielt und mit voller Reflexionspflicht eingeführt.
- **Ab Termin 7** (Strukturen, Dateibearbeitung, dynamischer Speicher) ist KI
  regulär zugelassen. Ein wiederkehrendes Aufgabenmuster ist dann: **ein
  fertiges, lauffähiges Programm wird bereitgestellt und muss gezielt
  angepasst oder erweitert werden**, gerne mit KI-Unterstützung, aber mit
  Pflicht zur Dokumentation, was übernommen, korrigiert oder verworfen wurde.
- **Die Wiederholungsblöcke (23, 24) sind wieder KI-frei** — die Prüfung ist
  es auch.

### Eskalationsstufen — INTERNES Planungsraster

Jede Einheit (Praxisphase-Woche, Block) trägt im Frontmatter das Feld
`ki_einsatz` mit einer dieser Stufen:

- `stufe_0_ohne` — KI ist für diese Aufgabe nicht vorgesehen. Nachschlagen in
  Dokumentation oder Lehrbuch bleibt erlaubt; gemeint ist der Verzicht darauf,
  sich die Lösung erzeugen zu lassen.
- `stufe_1_nachschlagewerk` — KI darf zum Nachschlagen und Erklären genutzt
  werden (Syntax, Fehlermeldungen, Begriffe), nicht zum Erzeugen der Lösung.
- `stufe_2_pair_programmer` — KI darf beim Erarbeiten der Lösung mitwirken;
  die Studierenden bleiben in der steuernden Rolle und müssen jede übernommene
  Zeile erklären können.
- `stufe_3_pflicht_reflexion` — KI-Einsatz ist ausdrücklich erwünscht,
  gekoppelt an eine verpflichtende schriftliche Reflexion: Was wurde
  übernommen, was korrigiert, was verworfen und warum. Diese Reflexion ist
  Teil der Abgabe, nicht optionaler Anhang.

**Diese vier Stufen sind ausschließlich ein internes Planungsraster.** Sie
dienen dazu, die Progression über den Kurs hinweg konsistent zu halten, und
leben in `curriculum-map.yaml` und im Frontmatter. Sie tauchen **nirgends im
studierenden-facing Text auf** — weder die Stufennamen noch die Nummern noch
das Wort „Stufe".

### Was die Studierenden stattdessen sehen

Für die Studierenden ist der KI-Einsatz **binär**: Eine Aufgabe wird **mit**
oder **ohne** KI bearbeitet. Das steht in einem kurzen Hinweisblock direkt bei
der Aufgabe. Dazu kommt:

- Bei **ohne KI**: eine kurze Begründung, warum genau diese Aufgabe davon lebt,
  selbst gelöst zu werden. Ein Verbot ohne Begründung wird ignoriert.
- Bei **mit KI**: die konkrete Angabe, **wofür** die KI eingesetzt werden soll
  — sich eine Fehlermeldung erklären lassen, gemeinsam einen Entwurf
  entwickeln, ein fertiges Programm erweitern und die Übernahmen
  dokumentieren. Diese Angabe ist Teil der Aufgabenstellung, nicht eine
  allgemeine Erlaubnis.

Die Übersetzung von der internen Stufe in diesen Text passiert beim Schreiben
der Einheit: `stufe_0_ohne` wird zu „ohne KI", die Stufen 1 bis 3 werden zu
„mit KI" plus der jeweils passenden konkreten Zweckangabe. Referenzdokument für
die Studierenden bleibt `docs/ki-nutzung.md`; auch dort steht nur die binäre
Unterscheidung.

Ziel durchgehend: Studierende bleiben **im Lead**, KI wird gezielt und
reflektiert eingesetzt, nicht als Ersatz fürs Verstehen.

## Code im Repository

C-Code liegt **im selben Repository** — sowohl Live-Coding-Beispiele als auch
Musterlösungen zu bS-Aufgaben. Kein separates Code-Repo.

**Die Studierenden beziehen alles über die Kurswebseite**, nie über das
Repository direkt. `mkdocs.yml` setzt deshalb bewusst kein `repo_url` (sonst
baut Material oben rechts einen GitHub-Link ein), und in
studierenden-facing Texten wird nicht auf das Repository verwiesen. Jede
Datei, die die Studierenden brauchen, muss über eine Seite erreichbar sein —
Code über `--8<--`-Snippets, sonstige Dateien über einen relativen Link auf
den `code/`-Ordner.

Für die Musterlösungen gilt trotzdem das Prinzip **Eigenverantwortung**:
Sobald sie freigeschaltet sind (siehe "Sichtbarkeits-Toggles"), stehen sie
offen auf der Seite. Wer vorab hineinsieht, nimmt sich selbst die Lernchance.

### Live-Coding wird schrittweise aufgebaut

Live-Coding-Inhalte werden als **einzelne, für sich stehende Beispiele**
eingebunden, nicht als ein monolithisches Gesamtprogramm. Jeder
Live-Coding-Schritt ist eine eigene, lauffähige Datei; die Block-Seite bindet
sie nacheinander per `pymdownx.snippets` ein. So kann der Lehrende einzelne
Schritte überspringen oder umstellen, ohne dass die Seite bricht.

Die Live-Coding-Stände stehen auf der Seite in einem **zugeklappten**
`??? quote livecoding "Code: ..."`-Block. Sie sind **immer** im gebauten HTML
enthalten (kein Hook, kein Frontmatter-Flag) — das Zuklappen verhindert
lediglich, dass man das Ergebnis beim Überfliegen versehentlich mitliest.

**Wichtige Nebenbedingung:** In einem zugeklappten `???`-Block darf **kein
Mermaid-Diagramm** stehen — ein im DOM vorhandenes, aber verstecktes Diagramm
lässt die Diagrammerkennung beim Laden fehlschlagen, und zwar für ALLE
Diagramme der Seite. Live-Coding-Blöcke enthalten deshalb ausschließlich
Code-Fences; PAPs stehen immer außerhalb.

### Dateibenennung und Einbindung

Ablage: **ein `code/`-Unterordner je Termin**,
`docs/02-theoriephase/termin-XX/code/` (analog
`docs/01-praxisphase/woche-XX/code/`). Kein zentraler Pool-Ordner.

| Zweck | Schema | Beispiel |
|---|---|---|
| Live-Coding-Schritt | `live-<block_id>-<schritt>-<slug>.c` | `live-04-2-schleife-summe.c` |
| bS-Musterlösung | `aufg-<NN>-<slug>.c` | `aufg-07-messwerte-mitteln.c` |
| Vorgegebener Ausgangscode | `vorgabe-<NN>-<slug>.c` | `vorgabe-12-sortierung.c` |

`<NN>` ist immer die Nummer aus `aufgaben-register.yaml`.
Live-Coding-Schritte bekommen keine Registernummer (siehe
"Aufgaben-Register").

Einbindung immer per Snippet, **nie** durch Abtippen des Codes in den
Markdown-Text:

    ```c
    --8<-- "02-theoriephase/termin-02/code/live-04-2-schleife-summe.c"
    ```

`pymdownx.snippets` ist mit `base_path: ["docs"]` und `check_paths: true`
konfiguriert — ein falscher Pfad bricht den Build hart ab, statt still eine
leere Stelle zu erzeugen.

## Sichtbarkeits-Toggles

Es gibt drei unabhängige Mechanismen; sie sind frei kombinierbar.

### 1. `publish_date` — zeitgesteuert, ganze Seite

Frontmatter-Feld `publish_date: YYYY-MM-DD`. Der Hook
`hooks/publish_scheduler.py` entfernt beim Bauen jede Datei mit einem
`publish_date` in der Zukunft **komplett** aus dem Build (nicht nur aus der
Navigation) und räumt die dadurch kaputten Nav-Einträge auf. Fehlt das Feld,
wird die Seite immer eingebaut. Ein täglicher GitHub-Actions-Lauf
(`.github/workflows/deploy-docs.yml`) baut die Seite neu, damit eine Einheit
am Stichtag auch ohne erneuten Push erscheint.

Wird für die Praxisphase genutzt: jede Woche geht montags online (31.08.,
07.09., 14.09., 21.09., 28.09., 05.10., 12.10.2026).

**Testmodus lokal** über die Umgebungsvariable `MKDOCS_TESTMODE` — gilt nur
lokal, nie im Deploy-Workflow:

```powershell
$env:MKDOCS_TESTMODE="1"
mkdocs serve
```

Zum Zurückschalten in den Normalmodus (mit Datumsfilter, wie es dann auch auf
der echten Seite erscheint):

```powershell
$env:MKDOCS_TESTMODE="0"
mkdocs serve
```

`$env:`-Variablen gelten nur für die aktuelle PowerShell-Sitzung — nach
Schließen des Terminals ist der Testmodus automatisch wieder aus.

**Falle, im Datenbanken-Kurs live aufgetreten:** Trägt
`termin-XX/index.md` selbst ein zukünftiges `publish_date`, verliert die
Nav-Sektion ihre Index-Seite. Material kann den Sektionstitel dann nicht mehr
zu einem Link verschmelzen — "Termin N" wird wieder zu einem reinen
Auf-/Zuklapp-Schalter, obwohl die Block-Seiten einzeln erreichbar bleiben.
**Regel:** Das `publish_date` von `index.md` darf nie später liegen als das
früheste `publish_date` ihrer Block-Unterseiten. Im Zweifel bekommt
`index.md` gar kein `publish_date`.

### 2. `musterloesungen_sichtbar` — manuell, Musterlösungen

Frontmatter-Feld `musterloesungen_sichtbar: true|false`. Alles zwischen
`<!-- MUSTERLOESUNG-START -->` und `<!-- MUSTERLOESUNG-ENDE -->` wird beim
Bauen **vollständig aus dem Markdown entfernt**, wenn das Feld auf `false`
steht — die Musterlösung landet gar nicht erst im gebauten HTML (kein
CSS-Trick, kein clientseitiges Verstecken). Bei `true` oder fehlendem Feld
bleibt der Text unverändert. Hook: `hooks/solution_toggle.py`.

Typischer Ablauf für einen Block: Datei wird mit
`musterloesungen_sichtbar: false` erstellt und kann so vor und während der
Einheit an die Studierenden weitergegeben werden. Nach der Einheit wird das
Feld manuell auf `true` gesetzt (Ein-Wort-Commit, pushen, Actions baut neu).

### 3. `nachtrag_sichtbar` — manuell, Nachträge

Zweites, unabhängiges Marker-Paar im selben Hook:
`<!-- NACHTRAG-START -->` / `<!-- NACHTRAG-ENDE -->`, gesteuert über
`nachtrag_sichtbar`. Für Abschnitte, die erst **während** der Veranstaltung
freigegeben werden sollen — z. B. eine Anforderungsänderung, die die
Studierenden nicht vorab lesen dürfen, weil sie sonst ihren
Überraschungseffekt verliert. Besonders relevant für das Zwischenprojekt.

Zwei bewusste Unterschiede zum Musterlösungs-Toggle:

- **Fehlt das Feld, gilt der Nachtrag als ausgeblendet** (beim
  Musterlösungs-Toggle ist es umgekehrt). Ein vergessenes Feld kann so keinen
  geplanten Überraschungseffekt zerstören.
- Musterlösungen **innerhalb** eines Nachtrag-Blocks werden mit ausgeblendet,
  unabhängig von `musterloesungen_sichtbar` — der Nachtrag wird zuerst
  entfernt.

**Warum nicht einfach auskommentieren:** Ein mehrzeiliger HTML-Kommentar um
einen Markdown-Abschnitt funktioniert NICHT — Python-Markdown bricht solche
Kommentare an Leerzeilen auf, der Inhalt landet dann trotzdem im gebauten
HTML. Außerdem lassen sich `<!-- MUSTERLOESUNG-START -->`-Marker nicht in
einen HTML-Kommentar schachteln. Reine Hinweise an die Lehrperson (ohne
Markdown-Blockelemente) dürfen dagegen weiterhin als HTML-Kommentar im
Dateikopf stehen — sie überstehen den Build unverändert, sind auf der Seite
unsichtbar, aber im Seitenquelltext lesbar.

**Kein Toggle für Live-Coding-Code.** Der ist bewusst immer im Build, siehe
"Live-Coding wird schrittweise aufgebaut" oben.

## Aufgaben-Register

`00-projektsteuerung/aufgaben-register.yaml` führt eine fortlaufende
Nummerierung ALLER Aufgaben der **Theoriephase** — sowohl der in der Übung
gestellten (`typ: uebung-aufgabe`) als auch der im betreuten Selbststudium
bearbeiteten (`typ: bs-aufgabe`). Nummern sind 2-stellig mit führender Null
und laufen fortlaufend über die gesamte Theoriephase (nicht pro Termin neu
bei 1). Schema je Eintrag: `nummer`, `termin`, `block_id`, `kurztitel`,
`dateiname`, `typ`. Das vollständige Schema steht als Kommentar im Kopf der
Datei selbst.

**Die Praxisphase vergibt keine Aufgabennummern.** Dort gibt es nur
Kontrollfragen, Quizze und ggf. kleine, nicht registrierte Übungen —
Erstsemester sollen sich einlesen und orientieren, nicht abliefern.

**Nicht jeder Übungsinhalt ist eine Aufgabe:** reine
Live-Coding-Demonstrationen ohne eigenständige Aufgabenstellung bekommen
**keine** Nummer und keinen Eintrag; ihr Code wird über das `live-…`-Schema
benannt.

Die Datei wird bei jeder neuen Aufgabe fortgeschrieben, nicht nachträglich
gesammelt gepflegt — analog zum Glossar-Pflichtschritt.

## Theoriephase: Block-Struktur & Templates

`docs/02-theoriephase/_templates/` enthält:

- `termin-index.template.md` — die **Termin-Übersichtsseite**
  (`termin-XX/index.md`). Frontmatter: `termin`, `datum`, `thema_termin`,
  `workload_minuten` (max. 90), `lernziele`. Seitentitel
  `# Termin <N> (<DD.MM.YYYY>) — <Gesamttitel>` — anders als bei den
  Block-Seiten steht hier "Termin &lt;N&gt;" im Titel, weil diese Seite der
  Landing-Point der ganzen Nav-Sektion ist. Kombiniert eine kurze Tagesagenda
  (Links auf die Block-Dateien) samt einzeiligem Blockquote zum Zeitbedarf
  (`> Zeitbedarf zur Vorbereitung: ca. <X> Minuten.`) mit dem
  Vorbereitungsauftrag als `## Vorbereitung`, gegliedert in
  `### Worum geht es?` und `### Zur Auffrischung` (dort je ein fett
  hervorgehobener Unterabsatz pro Block mit konkreten Verweisen). Die
  Lernziele aus dem Frontmatter werden hier NICHT zusätzlich als sichtbare
  Liste wiederholt. Für Termin 1 und 2 bewusst nur ein knappes Wrap-Up, da
  die Praxisphase Rechnerarchitektur, Zahlensysteme, Algorithmen/PAP und das
  erste C-Programm bereits abgedeckt hat.
- `block.template.md` — der Standardweg für einen kompletten
  90-Minuten-Block. Struktur siehe unten.
- `projekttag.template.md` — Struktur-Variante für Termin 6
  (Zwischenprojekt). **Existiert noch nicht**; wird bei der Planung dieses
  Termins entworfen.

### Aufbau von `block.template.md`

Seitentitel: `# <Kurztitel> (<DD.MM.YYYY>)` (Kurztitel aus `kurztitel`, Datum
aus `datum`), OHNE Trennlinie danach.

**Übungsteil** — `## <Kurztitel> { .modus-uebung }`:

- `### Worum geht es?` — kurzer Fließtext (Anschluss an die letzte Einheit),
  direkt gefolgt von den Lernzielen als ausformulierte Sätze in einem
  `!!! abstract "Lernziele"`-Block. **Keine eigene
  "### Lernziele"-Überschrift**, nie als nackte Liste.
- `### Kurzer Rückblick` — einzeln nummerierte Fragen zur letzten Einheit;
  die erste bewusst allgemeiner (wozu dient das übergeordnete Konzept
  grundsätzlich?), die weiteren spezifischer. Formuliert als
  `**N.** Frage`-Absätze, **NICHT** als echte nummerierte Markdown-Liste:
  Ein Admonition-Block zwischen zwei Listenpunkten wird von Python-Markdown
  nicht mehr zuverlässig erkannt (am gebauten Ergebnis getestet). Jede Frage
  bekommt eine eigene, einzeln umschaltbare Antwort:
  `<!-- MUSTERLOESUNG-START -->` + `??? note "Musterlösung anzeigen"` +
  `<!-- MUSTERLOESUNG-ENDE -->` — exakt derselbe Admonition-Typ und Titeltext
  wie bei den Praxisphase-Selbstkontrollfragen. Aufklappbare Blöcke zeigen
  projektweit IMMER eine Musterlösung, deshalb tragen sie überall denselben
  Typ und denselben Titel.
- `### Das Beispiel: <Name>` — kurze, eigenformulierte Beschreibung des
  Problems, das gleich gemeinsam programmiert wird. Stammt es (auch nur
  sinngemäß) aus einer fremden Quelle, wird direkt darunter Kapitel und Seite
  angegeben (z. B. *"Beispiel eigenständig neu formuliert nach &lt;Quelle&gt;,
  Kap. 4.2, S. 61."*), zusätzlich zum ohnehin geltenden Verbot wörtlicher
  Übernahme.
- `### <Überleitung, z. B. "Schrittweise Umsetzung">` mit je einer
  `#### `-Überschrift pro Live-Coding-Schritt. Jeder Schritt: Beschreibung an
  die Studierenden gerichtet, ggf. PAP-Ausschnitt (außerhalb des
  Code-Blocks), dann der Code des Schritts in einem zugeklappten
  `??? quote livecoding "Code: Stand nach diesem Schritt"`-Block mit
  `--8<--`-Einbindung.
- `### Gesamtergebnis` — das vollständige Programm einmalig per Snippet in
  einem `??? quote livecoding`-Block, plus eine Zusammenfassung der
  behandelten Konzepte **außerhalb** des zugeklappten Blocks, damit sie beim
  Überfliegen sichtbar bleibt.
- Optional weitere `###`-Vertiefungen nach demselben Muster (z. B. "Typische
  Fehler", "Was passiert, wenn ...") sowie ein
  `!!! tip "Clean Code: <Prinzip>"`-Block, wenn hier ein Prinzip neu
  eingeführt wird.

**Betreutes Selbststudium** — `## <Kurztitel> { .modus-selbststudium }`:

- `### Worum geht es?` mit Lernzielen im gleichen
  `!!! abstract "Lernziele"`-Muster (auch hier keine eigene Überschrift).
- Weicht `ki_einsatz` von "normal" ab, wird das hier für die Studierenden
  sichtbar gemacht, mit Verweis auf `docs/ki-nutzung.md`.
- `### Aufgabe <NN>: <Kurztitel>` mit fortlaufender Nummer aus dem Register
  und einem aufklappbaren `??? info "Bezug zu Lehrinhalten"` (Verweis auf
  Praxisphase-Woche bzw. frühere Termine).
- Bei mehreren Teilaufgaben Gliederung in `#### Teil A — ...` /
  `#### Teil B — ...` mit `---` dazwischen.
- Musterlösungen in `???+ note "Musterlösung Teil A anzeigen"` innerhalb von
  `<!-- MUSTERLOESUNG-START/ENDE -->`. Bewusst `???+` (offen, aber
  zuklappbar): Ein per CSS verstecktes, aber im DOM vorhandenes
  Mermaid-Diagramm in einem geschlossenen `???`-Block lässt die
  Diagrammerkennung für ALLE Diagramme der Seite fehlschlagen (am gebauten
  Ergebnis getestet). `???+` bleibt zuklappbar, startet aber offen und
  vermeidet das Problem.
- Musterlösungen enthalten immer auch eine kurze Begründung/Erklärung, nicht
  nur den Code.

### Trennlinien

Horizontale Trennlinien (`---` auf eigener Zeile, Leerzeilen davor/danach):

- IMMER zwischen `{ .modus-uebung }` und `{ .modus-selbststudium }`.
- IMMER zwischen den `###`-Hauptphasen innerhalb der Übung (Kurzer Rückblick
  / Beispiel / Umsetzung / Gesamtergebnis / optionale Vertiefung).
- IMMER zwischen mehreren `####`-Teilaufgaben im bS (Teil A / Teil B / Teil C).
- NICHT zwischen den kumulativen `####`-Live-Coding-Schritten innerhalb einer
  Übungsphase — die gehören inhaltlich eng zusammen.
- NICHT direkt nach dem Seitentitel.

### Ansprache

Beide Abschnitte sind **konsequent studierenden-facing** geschrieben (die
Datei wird direkt an die Studierenden weitergegeben, vor/während ohne
Musterlösungen, danach mit): entweder neutral beschreibend ("Ablauf: ...")
oder direkte Ansprache ("Ihr lernt heute ...", "Wir schauen uns gemeinsam
an ..."), wie im Praxisphase-Material. **NIEMALS** als Meta-Anweisung an die
Lehrperson formuliert (also nicht "Erkläre den Studierenden, dass ..." oder
"Zeige den Studierenden, wie ..."). Das gilt auch für didaktische "Worauf
achten"-Hinweise: direkt an die Studierenden gerichtet, in den Fließtext
integriert oder als eigener kurzer Absatz, nie als Notiz an die Lehrperson.

**Titel/Überschriften bleiben frei von Steuerungs-Vokabular:** Die Wörter
"Block" und "Drehbuch" tauchen in keinem außenwirksamen Text auf (weder
Seitentitel noch Überschriften noch Nav-Label) — sie bleiben ausschließlich
als internes Feld `block_id` im Frontmatter erhalten (Dateinamen wie
`block-01.md` bleiben unverändert).

### Frontmatter eines Blocks

`typ`, `termin`, `block_id`, `datum`, `kurztitel` (kurz, für Titel/Nav-Label),
`thema` (vollständige Beschreibung wie in `curriculum-map.yaml`, für den
Abgleich zwischen den Dateien), `lernziele` (klar, beobachtbar formuliert),
`musterloesungen_sichtbar`, `ki_einsatz`, `clean_code`,
`bearbeitungsstatus`, optional `publish_date` und `nachtrag_sichtbar`.
**Kein `fallstudie`-Feld** — GdI hat keinen Fallstudien-Pool.

## Modus-Badges (Übung/Selbststudium)

Die beiden Hauptüberschriften eines Blocks tragen die attr_list-Klassen
`.modus-uebung` bzw. `.modus-selbststudium`. CSS-Regeln in
`docs/stylesheets/extra.css` zeigen dadurch automatisch ein farbiges Badge
direkt in der Überschriftenzeile — "👥 Übung" (blau) und "✏️ Betreutes
Selbststudium" (orange) — zusätzlich zu einer dezenten Hintergrundfarbe und
einem linken Rahmen an der ganzen Überschriftenzeile. Das macht den Wechsel
von "jetzt gemeinsam" zu "jetzt eigenständig" auf einen Blick sichtbar, ohne
dass die Überschrift selbst diese Wörter enthalten muss. Kein zusätzlicher
Markdown-Aufwand nötig, die beiden Klassen im Template genügen.

## Zeitangaben-Konvention

Grobe Zeitangaben (z. B. "ca. 5 Min.") sind nützlich zur Orientierung, sollen
den Lesefluss aber nicht dominieren — deshalb IMMER als
`<span class="zeitangabe">ca. X Min.</span>` (ohne Klammern), direkt in
derselben Zeile wie die zugehörige Überschrift. Damit die Zeitangabe nicht
auch im Inhaltsverzeichnis auftaucht, wird sie zusätzlich per
`data-toc-label`-Attribut (aus der `attr_list`-Extension) ausgeblendet — der
Wert ist dabei immer der reine Überschriftentext ohne Badge:

```markdown
### Kurzer Rückblick <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Kurzer Rückblick" }
```

Die CSS-Regel rendert das als dezentes Badge mit Stoppuhr-Icon (`::before`-
Inhalt "⏱"), rechtsbündig in der Überschriftenzeile, farblich über die
Material-Variablen `--md-default-fg-color--light`/`--lightest`, damit es in
Hell- und Dunkelmodus funktioniert. Der Überschriftentext bleibt linksbündig.

Der Seitentitel sowie die beiden Hauptüberschriften
(`## <Kurztitel> { .modus-uebung }` / `## <Kurztitel> { .modus-selbststudium }`)
bleiben grundsätzlich frei von Zeitangaben.

## Nav-Struktur Theoriephase

Jeder Präsenztermin bekommt in `mkdocs.yml` eine eigene Nav-Sektion (analog
zur Praxisphase, wo jede Woche einen Eintrag bekommt), aber **ohne separaten
"Vorbereitung"-Unterpunkt**: Dank des Theme-Features `navigation.indexes`
übernimmt die Termin-Übersichtsseite die Rolle der Sektions-Startseite und
macht den Sektionstitel selbst ("Termin 1") anklickbar.

**Wichtige technische Voraussetzung:** Material for MkDocs erkennt eine Seite
nur dann als Sektions-Index, wenn ihr Dateiname exakt `index` ist
(`page.is_index` prüft `file.name == "index"` — reine Nav-Position als erster
Eintrag reicht NICHT aus und erzeugt einen doppelten Nav-Eintrag). Die Datei
muss also zwingend `02-theoriephase/termin-XX/index.md` heißen.

Die beiden Block-Unterseiten bekommen als Nav-Label ihren `kurztitel` aus dem
Frontmatter, nicht "Block 01"/"Block 02" (das Wort "Block" ist außenwirksam
tabu):

```yaml
nav:
  - Theoriephase:
      - "Termin 1":
          - 02-theoriephase/termin-01/index.md
          - "Grundbegriffe und Zahlensysteme": 02-theoriephase/termin-01/block-01.md
          - "Algorithmen und Programmablaufpläne": 02-theoriephase/termin-01/block-02.md
```

Ein Nav-Eintrag darf erst ergänzt werden, wenn die zugehörige Datei
tatsächlich existiert — sonst erzeugt MkDocs eine kaputte Verlinkung
(Klartext-Pfad statt echtem Seitenlink). Aktuell stehen deshalb nur die drei
allgemeinen Seiten in der Nav; Wochen und Termine kommen dazu, sobald ihre
Dateien angelegt werden.

## Praxisphase: Aufbau einer Woche

Template: `docs/01-praxisphase/_template/woche.template.md`.

- Lese-/Arbeitsschritte IMMER als `**Schritt N:** ...`-Absätze, NICHT als
  nummerierte Liste. Grund: Sobald zwischen den Schritten ein
  Admonition-Block eingefügt werden muss, bricht eine nummerierte Liste die
  Zählung und beginnt danach fälschlich wieder bei 1. Unterpunkte innerhalb
  eines Schritts dürfen normale Listen sein, solange dort kein
  Admonition-Block dazwischensteht.
- Der Abschnitt "Zum Ausprobieren" ist optional und bekommt **keine**
  Aufgabennummer.
- Jede Woche endet mit `## Selbstkontrolle` (Format je Frage situativ wählen,
  siehe unten).
- Musterlösungen inline als `??? note "Musterlösung anzeigen"`, immer mit
  kurzer Begründung, nicht nur dem Ergebnis.

### Selbstkontrollfragen: Format situativ wählen

Zwei Formate stehen zur Verfügung und werden gemischt genutzt — die Wahl
erfolgt pro Frage situativ, nicht nach fester Quote oder festem Schema:

- **Quiz-Format** (`<quiz>`-Block mit Checkboxen für Single-/Multiple-Choice,
  oder `[[Begriff]]`-Syntax für Lückentext): geeignet für Faktenwissen,
  Terminologie, Abgrenzungen zwischen Begriffen, Klassifikationen,
  Zuordnungen, Reihenfolgen. Für GdI besonders passend bei
  Zahlensystem-Umrechnungen, Datentypen, Operatoren und "Was gibt dieses
  Programm aus?"-Fragen.
- **Offene Frage mit ausklappbarer Musterantwort** (`???`-Block): geeignet für
  Fragen, die eine Erklärung in eigenen Worten, eine Begründung, einen
  Transfer auf ein neues Beispiel oder eine Abwägung verlangen — hier würde
  eine Quiz-Antwort den eigentlichen Lerneffekt (selbst formulieren)
  verhindern.

Es gibt bewusst KEINE feste Vorgabe wie "3 von 5 Fragen als Quiz". Die
Mischung ergibt sich aus dem jeweiligen Thema der Woche, nicht aus einer
Formel.

**Wichtig bei Lückentext-Quizzes:** Der Fragetext mit den `[[Begriff]]`-Lücken
muss im Markdown-Quelltext eine einzige durchgehende Zeile sein, unabhängig
von der Zeilenlänge — kein Zeilenumbruch, auch kein "weicher". Das
`mkdocs_quiz`-Plugin übernimmt jeden Zeilenumbruch aus dem Quelltext sichtbar
in den gerenderten Lückentext. Diese Regel gilt für einen einzelnen, am Stück
formulierten Satz mit Lücken. Für die **Zuordnungsfrage** ist mehrzeilige
Struktur dagegen gewollt.

**Zuordnungsfrage** (Variante des Lückentext-Quiz): Vier nummerierte
Begriffe/Aussagen/Satzanfänge stehen oben in einer **Tabelle**, darunter folgen
vier Zeilen mit je einer `[[N]]`-Lücke gefolgt von einem Text, der zu genau
einem der oberen Punkte passt. Die vier Zuordnungszeilen stehen bewusst
**nicht** in der Reihenfolge 1-2-3-4, sonst ist die Zuordnung trivial. Aufbau:

```
<quiz>
Ordne ... zu:

| Nr. | Begriff |
|---|---|
| 1 | Erster Begriff/Aussage/Satzanfang |
| 2 | Zweiter Begriff/Aussage/Satzanfang |
| 3 | Dritter Begriff/Aussage/Satzanfang |
| 4 | Vierter Begriff/Aussage/Satzanfang |

- [[3]] Text, der zu Punkt 3 passt.
- [[1]] Text, der zu Punkt 1 passt.
- [[4]] Text, der zu Punkt 4 passt.
- [[2]] Text, der zu Punkt 2 passt.

---
Optionaler Tipp, der nach dem Absenden angezeigt wird.
</quiz>
```

Zwei Details, die beide am gebauten Ergebnis geprüft sind:

- **Die Begriffe oben stehen in einer Tabelle, NICHT in einer nummerierten
  Liste.** Python-Markdown erkennt eine direkt folgende `-`-Liste sonst nicht
  als neue Liste, sondern hängt sie als Elemente 5–8 an die `<ol>` an. Die
  Zuordnungszeilen bekämen dadurch sichtbar die Nummern 5, 6, 7 und 8 —
  ausgerechnet neben den Eingabefeldern, in die 1 bis 4 gehören. Eine Tabelle
  ist ein eigenständiger Blockmodus und beendet die Liste zuverlässig.
- **Die vier Zuordnungszeilen müssen eine Markdown-Liste sein**
  (`- [[N]] Text`), nicht durch Leerzeilen getrennte Absätze. Das
  `mkdocs_quiz`-Plugin ersetzt `[[N]]` intern zunächst durch einen
  HTML-Kommentar als Platzhalter; steht dieser ganz am Anfang eines Absatzes,
  erkennt Markdown ihn als eigenständigen HTML-Block und trennt ihn vom
  nachfolgenden Text — das Eingabefeld landet dann in einer eigenen Zeile, der
  Text darunter. Als Listenelement bleiben Feld und Text in derselben Zeile.

Der `---`-Trenner für den Tipp funktioniert trotz der `|---|---|`-Zeile der
Tabelle: Das Plugin sucht die erste Zeile, die für sich genommen eine
horizontale Linie ist.

### Antwortbezogenes Feedback bei Auswahlfragen

Bei `<quiz>`-Blöcken mit Checkboxen kann jede einzelne Antwortoption eine eigene
Rückmeldung bekommen — als Blockquote-Zeile **direkt** unter der Option, ohne
Leerzeile dazwischen:

```
- [x] Richtige Antwort.
> Warum das stimmt.
- [ ] Falsche Antwort.
> Warum das nicht stimmt — und was stattdessen gilt.
```

Das ist im Selbststudium besonders wertvoll: Die Studierenden erfahren nicht nur
*dass* sie danebenlagen, sondern *warum*. Nicht jede Option braucht eine
Rückmeldung; sinnvoll ist sie vor allem bei der attraktivsten Fehlannahme.

Eine Leerzeile zwischen Option und Blockquote lässt den Build hart
fehlschlagen ("Orphaned feedback line"). Text nach der letzten Option (ohne
`>`) wird zum Erklärungsabschnitt, der nach dem Absenden für die ganze Frage
erscheint.

### Antworten stehen im Seitenquelltext

Das Plugin schreibt zu jedem Quiz zusätzlich den **Markdown-Quelltext der Frage
in einen HTML-Kommentar** (`<!-- mkdocs-quiz-source ... -->`) ins gebaute HTML —
inklusive der `- [x]`-Markierungen. Auf der Seite ist davon nichts zu sehen, im
Seitenquelltext aber schon. Das ist Verhalten des Plugins und nicht
abschaltbar; es passt zum Prinzip Eigenverantwortung (Musterlösungen stehen
ohnehin offen auf der Seite), sollte aber bekannt sein: **Quizfragen sind kein
Prüfungsinstrument.**

## Programmablaufpläne (PAP)

**TODO — die Konvention wird beim ersten PAP-haltigen Termin festgelegt.**

Feststehend ist bisher nur: PAPs werden als Mermaid-`flowchart` erstellt
(nicht als Bild, nicht als ASCII-Grafik), mit **nativen Flowchart-Shapes**
statt der HTML-Label-Technik, die im Datenbanken-Kurs für ER-Diagramme nötig
war.

Beim ersten PAP-haltigen Termin gemeinsam festzulegen und danach hier als
verbindliche Referenz zu dokumentieren:

- Schriftgröße / `%%{init: ...}%%`-Zeile
- Shape-Zuordnung: Start/Ende, Verarbeitung, Verzweigung, Ein-/Ausgabe,
  Unterprogramm, Konnektor
- Beschriftung der Kanten bei Verzweigungen (`ja`/`nein` vs. `wahr`/`falsch`)
- Richtung (`TD` vs. `LR`) und Umgang mit Rücksprüngen bei Schleifen
- Einrückung innerhalb von Admonition-Blöcken

Bis dahin: **keine PAP-Konvention erfinden**, sondern nachfragen. Die
Entscheidung hängt mit der Wahl der PAP-Symbolik in der Praxisphase zusammen
(siehe `03-quellen/algorithmen-pap.md`) und wird gemeinsam getroffen.

**Grundregeln, die unabhängig davon schon gelten:**

- Wird ein Mermaid-Block innerhalb eines `???`/`!!!`-Admonitions verwendet,
  bekommt der komplette Fence (öffnende und schließende Backticks sowie jede
  Inhaltszeile dazwischen) durchgehend dieselbe Einrückung wie der restliche
  Text dieses Admonitions.
- Ein Mermaid-Diagramm steht **nie** in einem zugeklappten `???`-Block —
  siehe "Live-Coding wird schrittweise aufgebaut" oben.
- Jede Knoten-Definition ist eine einzige durchgehende Zeile im Quelltext,
  ohne eingebetteten Zeilenumbruch.
- Für Farben immer `rgb(...)`/`rgba(...)` verwenden, niemals `#rrggbb`: Ein
  `#` innerhalb eines Knoten-Labels wird von Mermaid als Beginn einer
  HTML-Entity interpretiert und zerstört dabei lautlos das gesamte
  `style`-Attribut.

## Glossar pflegen

`docs/glossar.md` ist das zentrale, veröffentlichte Glossar des Kurses und
wird laufend gepflegt, nicht nachträglich. **Nach dem Erstellen JEDER neuen
Einheit** (Praxisphase-Woche, Block) ist zu prüfen, ob dabei neue Fachbegriffe
eingeführt oder erklärt wurden, die im Glossar noch fehlen — und diese sind
dann dort zu ergänzen. Das ist ein **Pflichtschritt bei der Erstellung neuer
Einheiten**, kein optionales Aufräumen im Nachhinein.

Für Erstsemester ohne Vorkenntnisse ist das besonders kritisch: Begriffe wie
"Compiler", "Deklaration", "Bezeichner", "Gültigkeitsbereich" oder "Referenz"
sind für die Zielgruppe wirklich neu.

- Definitionen kurz und in eigenen Worten formulieren, niemals aus einer
  Quelle übernehmen (Urheberrecht).
- Eine Erklärung, die selbst wieder drei unerklärte Fachbegriffe enthält, ist
  keine Erklärung.
- Die Spalte "Verwendet ab" trägt die Einheit ein, in der der Begriff zuerst
  eingeführt wird (z. B. "Praxisphase Woche 2").
- Das Glossar bleibt durchgehend alphabetisch nach Begriff sortiert.

## Musterlösungen

Zu jeder Aufgabe gehört eine Musterlösung **inline in derselben Datei**, nicht
in einer separaten Datei. In der Praxisphase als aufklappbarer
`??? note "Musterlösung anzeigen"`-Block, in der Theoriephase zusätzlich
innerhalb eines `<!-- MUSTERLOESUNG-START/ENDE -->`-Abschnitts mit steuerbarer
Sichtbarkeit. Musterlösungen enthalten immer auch eine kurze
Begründung/Erklärung, nicht nur den Code: Was ist der Kern der Lösung? Welche
Alternativen gäbe es? Welcher typische Fehler wird hier vermieden?

Code-Musterlösungen werden **nie** direkt im Text ausformuliert, sondern immer
per `--8<--` eingebunden — siehe "Dateibenennung und Einbindung" oben.

## Einheitliches Layout / Templates

Jede Einheit entsteht aus einem Template in
`docs/01-praxisphase/_template/` bzw. `docs/02-theoriephase/_templates/`.
Templates NICHT bei jeder neuen Einheit neu erfinden — Wiedererkennungswert
ist ausdrücklich gewünscht. Wenn ein Template geändert werden muss, wird es
zentral angepasst und diese Änderung in
`00-projektsteuerung/entscheidungen.md` dokumentiert.

## Rollen / Perspektiven

Im Ordner `.claude/agents/` liegen fünf Perspektiven, die beim Erstellen von
Materialien einbezogen werden können:

| Rolle | Blick |
|---|---|
| `fachliche-korrektheit` | Informatik-Begriffe, Zahlensysteme, Rechnerarchitektur, Algorithmen |
| `didaktik` | Lernzielbezug, Schrittgröße, Aufgabenvielfalt, Klausurbezug |
| `studi-perspektive` | Erstsemester ohne Vorkenntnisse: Wo steige ich aus? |
| `ki-nutzung` | Passt die Eskalationsstufe zur Kursphase? |
| `technik-c` | Kompiliert das? Ist das wirklich C und nicht C++? |

Diese sind bewusst **als Perspektiven zum Gegenlesen gedacht, nicht als starre
Freigabe-Kette** — sie sollen die Qualität verbessern, aber keine Erstellung
blockieren.

## Qualitätssicherung bei Aufgabenstellungen

Die Rollen `didaktik` und `studi-perspektive` werden **verpflichtend bei der
Erstellung jeder neuen Aufgabe** einbezogen (Praxisphase-Einheit, Übung,
bS-Aufgabe) — nicht erst nachträglich bei Beanstandungen, sondern als fester
Bestandteil des Erstellungsprozesses selbst.

Konkrete Prüffragen für diesen Check:

- Setzt die Aufgabe irgendetwas voraus, was ein Erstsemester ohne
  Vorkenntnisse noch nicht haben kann?
- Passt die verwendete Darstellungsform (PAP-Notation, Code-Formatierung,
  Tabellen, Diagramme) zu dem, was in vorherigen Einheiten bereits eingeführt
  wurde? Neue, ungewohnte Darstellungsformen ohne Not verwirren und erzeugen
  Ablehnung.
- Ist die Aufgabenstellung so vollständig und in sich abgeschlossen, dass
  NICHT in einer alten Aufgabenbeschreibung nachgeschlagen werden muss?
  Benötigte Vorgaben aus früheren Einheiten (Code-Rahmen, Datenformate,
  Funktionssignaturen, Beispielausgaben) müssen direkt in der aktuellen
  Aufgabe vollständig angegeben werden.
- Querbezüge zu früheren Lerneinheiten sind erlaubt und sinnvoll, aber nicht
  exzessiv — sie sollen den roten Faden zeigen, nicht die eigenständige
  Bearbeitbarkeit gefährden.
- Bezieht sich jede Frage/Teilaufgabe tatsächlich auf das, was in DIESER
  Einheit erarbeitet werden soll?
- Ist mindestens eine Teilaufgabe ohne Rechner lösbar (Klausurbezug)?
- Verwendet jedes Codebeispiel nur Konstrukte, die zu diesem Zeitpunkt schon
  eingeführt wurden?

## Flexibilität / Erweiterbarkeit

Jede Einheit (Praxisphase-Woche, Theoriephase-Block) ist eine eigenständige,
in sich geschlossene Datei/Ordnereinheit. Umstrukturierung (Themen tauschen,
neue Einheiten ergänzen) darf immer nur `curriculum-map.yaml` plus die
betroffenen Einheiten berühren, nie das Gesamtkonzept.

## Was noch offen / in Arbeit ist

Siehe `00-projektsteuerung/curriculum-map.yaml`, Feld `bearbeitungsstatus` je
Einheit. Bislang ist nur das Grundgerüst angelegt — Inhalte werden Schritt für
Schritt gemeinsam mit dem Professor erarbeitet, nicht auf einmal
vorproduziert.

Die Infrastruktur (Templates, Hooks, Aufgaben-Register, Snippets-Einbindung,
CSS, Deploy-Workflow) steht. Offene Punkte auf Projektebene:

- **PAP-Diagramm-Konvention** — beim ersten PAP-haltigen Termin festzulegen.
- **Struktur des Zwischenprojekt-Tags** (`projekttag.template.md`) — bei der
  Planung von Termin 6 zu entwerfen.
- **Fachbuch** für die Programmier-Themen noch nicht bestimmt (siehe
  `03-quellen/fachbuch-programmierung.md`).
- **Quellen** für Rechnerarchitektur, Zahlensysteme und Algorithmen/PAP noch
  nicht recherchiert (siehe `03-quellen/`).
- **Video-Index** der Youtube-Playlist noch nicht erfasst (siehe
  `03-quellen/youtube-playlist.md`).
- `_referenz-datenbanken/` enthält Referenzmaterial aus dem
  Datenbanken-Kurs (Kurs 3019) und wird händisch gelöscht, sobald es nicht
  mehr gebraucht wird. **Nicht als Vorlage für neue Inhalte verwenden** —
  Inhalte, Themen und KI-Konzept von GdI sind eigenständig.
