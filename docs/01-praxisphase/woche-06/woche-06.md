---
typ: praxisphase-woche
woche: 6
thema: "Entwicklungsumgebung installieren und bedienen"
workload_minuten: 120
lernziele:
  - "Du kannst Visual Studio 2026 Community mit der C/C++-Workload installieren."
  - "Du kannst in Visual Studio ein neues, leeres Projekt anlegen und ihm eine C-Datei hinzufügen."
  - "Du kannst erklären, was eine Datei, ein Projekt und eine Projektmappe (Solution) in Visual Studio jeweils sind und wie sie zusammenhängen."
  - "Du kannst ein einfaches C-Programm bauen (kompilieren) und ausführen."
  - "Du kannst eine Fehlermeldung beim Bauen lesen und einer Zeile in deinem Quelltext zuordnen."
quellen:
  - "Youtube-Playlist, Video Nr. 5 – C-Programmierung #01: Projekt in VS2019 erstellen und Hello World! (7:54): https://youtu.be/pIvhgGFTEcU"
  - "Visual Studio Download: https://visualstudio.microsoft.com/de/downloads/"
ki_einsatz: stufe_1_nachschlagewerk
bearbeitungsstatus: fertig
publish_date: 2026-10-05
---

<!-- ZIELGRUPPE: Erstsemester im 1. Fachsemester, KEINE Vorkenntnisse in
     Programmierung oder Informatik. Die Studierenden sind im Betrieb und
     haben in dieser Phase KEINEN Kontakt zum Lehrenden — dieses Dokument
     muss vollständig aus sich heraus verständlich sein.

     BEWUSSTE SCOPE-ENTSCHEIDUNG: curriculum-map.yaml nennt für Woche 6 auch
     "Haltepunkt setzen" (Debugging). Das ist hier bewusst NICHT enthalten —
     der Workload-Rahmen (1-2h) ist durch Installation + Projekt anlegen +
     Hello World bereits ausgeschöpft, und ein Debugger ist ohne eigenen
     Code mit mehreren Zeilen kaum sinnvoll zu erproben. "Fehlermeldungen
     finden" wird stattdessen leichtgewichtig über eine bewusst provozierte
     Fehlermeldung in "Zum Ausprobieren" abgedeckt. Siehe hinweis-Feld bei
     Woche 6 in curriculum-map.yaml. -->

# Woche 6: Entwicklungsumgebung installieren und bedienen

> Zeitbedarf: ca. 2 Stunden (Download und Installation laufen dabei
> größtenteils im Hintergrund).

## Worum geht es?

Bisher hast du Algorithmen nur auf Papier entworfen — als PAP und als
Pseudocode. Ab nächster Woche schreibst du deine ersten echten C-Programme.
Damit das klappt, brauchst du zuerst ein Werkzeug, mit dem du C-Quelltext
schreiben, in ein lauffähiges Programm übersetzen und starten kannst: eine
**IDE** (*Integrated Development Environment*, integrierte
Entwicklungsumgebung).

In diesem Kurs verwendest du dafür **Visual Studio 2026 Community**. Diese
Woche installierst du es, legst dein erstes Projekt an und bringst ein
winziges Programm zum Laufen: das klassische "Hello World!". Um C selbst
geht es dabei noch kaum — das kommt ab nächster Woche. Diese Woche ist reine
**Werkzeugkunde**: Wie kommst du von der Installation zu einem Fenster, das
tatsächlich etwas ausgibt?

!!! abstract "Diese Woche mit KI, aber gezielt"
    Installation und IDE-Bedienung sind reines Nachschlagewissen — das
    lohnt sich kaum, auswendig zu lernen. Wenn bei der Installation oder
    beim Bauen deines Programms eine Fehlermeldung auftaucht, die du nicht
    verstehst, darfst du sie dir von einem KI-Werkzeug erklären lassen.
    Nutze KI hier ausschließlich zum **Erklären**, nicht dazu, dir Code
    schreiben zu lassen — dein Hello-World-Programm tippst du selbst.
    Mehr dazu unter [KI im Kurs](../../ki-nutzung.md).

## Das solltest du danach können

- Du kannst Visual Studio 2026 Community mit der C/C++-Workload
  installieren.
- Du kannst in Visual Studio ein neues, leeres Projekt anlegen und ihm eine
  C-Datei hinzufügen.
- Du kannst erklären, was eine Datei, ein Projekt und eine Projektmappe
  (Solution) in Visual Studio jeweils sind und wie sie zusammenhängen.
- Du kannst ein einfaches C-Programm bauen (kompilieren) und ausführen.
- Du kannst eine Fehlermeldung beim Bauen lesen und einer Zeile in deinem
  Quelltext zuordnen.

## Erarbeitung { .abschnitt-erarbeitung }

**Schritt 1:** Lade **Visual Studio 2026 Community** herunter und
installiere es.

Die Download-Seite findest du hier:
<https://visualstudio.microsoft.com/de/downloads/>. Community ist die
kostenlose Version von Visual Studio — für dieses Modul genau richtig.

!!! warning "Plane Zeit ein"
    Der Installer lädt mehrere Gigabyte nach, das dauert je nach
    Internetverbindung eine Weile. Starte die Installation deshalb nicht
    erst kurz vor knapp, sondern zu einem Zeitpunkt, an dem der Download
    im Hintergrund laufen kann, während du etwas anderes tust. Wie viel
    freien Speicherplatz du am Ende brauchst, nennt dir der Installer
    selbst, bevor du bestätigst — prüfe kurz, ob dein Gerät das hergibt.

    Darfst du auf deinem Gerät keine Software installieren (zum Beispiel
    auf einem Firmenlaptop ohne Administratorrechte während deiner
    Praxisphase im Betrieb), installiere Visual Studio stattdessen auf
    einem privaten Rechner. Kläre das rechtzeitig, nicht erst kurz vor
    dem ersten Präsenztermin.

Im Installationsprogramm musst du eine **Workload** (ein Paket aus
zusammengehörigen Komponenten) auswählen. Die Workloads sind als Kacheln
dargestellt und thematisch gruppiert; **"Desktopentwicklung mit C++"**
findest du in der Gruppe **"Desktop & Mobile"**. Setze dort den Haken —
mit den Standardeinstellungen, die dabei vorausgewählt sind. Weitere
Workloads brauchst du für dieses Modul nicht.

**Warum steht da überall "C++", wenn wir C programmieren?** Das wirst du
bei der Installation und später ständig in Visual Studio lesen — und es
wirkt erstmal widersprüchlich, schließlich programmieren wir in diesem Kurs
ausschließlich in **C**, nicht in C++. Der Grund: Microsoft liefert
Compiler und Werkzeuge für C und C++ gemeinsam als ein Paket aus, weil
beide Sprachen eng verwandt sind und denselben Compiler benutzen. Eine
eigene Workload nur für C gibt es nicht. Ob dein Code am Ende als C oder
als C++ übersetzt wird, entscheidet allein die **Dateiendung** deiner
Quelldatei — dazu gleich mehr.
{: .hinweis-klein }

---

**Schritt 2:** Schau dir das Video **„C-Programmierung #01: Projekt in
VS2019 erstellen und Hello World!"** an (7:54 Min.).

<div class="video-wrapper">
  <iframe src="https://www.youtube-nocookie.com/embed/pIvhgGFTEcU" title="Video: Projekt in VS2019 erstellen und Hello World!" loading="lazy" allowfullscreen referrerpolicy="strict-origin-when-cross-origin"></iframe>
</div>

Das Video zeigt die Version Visual Studio 2019 statt 2026 — die Fenster
sehen deshalb an ein paar Stellen etwas anders aus. Die grundsätzlichen
Schritte sind aber bis heute praktisch identisch geblieben.

Achte beim Zuschauen besonders auf zwei Dinge, die im Video kurz erwähnt
werden, aber leicht überhört werden:

- Das **Projekt** wird als "Leeres Projekt" unter C++ angelegt — das ist
  kein Widerspruch (siehe Kasten oben), sondern die einzige verfügbare
  Vorlage.
- Die neu hinzugefügte Datei bekommt die Endung **`.c`**, nicht `.cpp`.
  Genau das sorgt dafür, dass Visual Studio deinen Code als **C**
  behandelt.

Drei Begriffe aus dem Video tauchen ab jetzt ständig auf, deshalb kurz
zusammengefasst: Eine **Datei** ist dein einzelner Quelltext — genau eine
`.c`-Datei mit deinem Programm. Ein **Projekt** bündelt eine oder mehrere
Dateien zusammen mit den Einstellungen, aus denen daraus ein einzelnes
Programm gebaut wird. Eine **Projektmappe (Solution)** ist der Container,
der wiederum ein oder mehrere Projekte zusammenfasst — in diesem Kurs
reicht dir dafür immer genau ein Projekt pro Projektmappe.

---

**Schritt 3:** Lege selbst ein neues Projekt an und bringe dein eigenes
Hello-World-Programm zum Laufen.

Mach es wie im Video: Lege über **Datei → Neu → Projekt** ein neues, leeres
Projekt an (Visual Studio legt dabei automatisch auch eine passende
Projektmappe dafür an — je nach Version musst du das nicht mehr getrennt
tun) und füge dem Projekt anschließend eine neue Datei mit der Endung `.c`
hinzu. Tippe danach folgendes Programm ab — klicke auf die kleinen Kreise
im Code für eine kurze Erklärung der jeweiligen Zeile:

```c title="hello-world.c" linenums="1"
--8<-- "01-praxisphase/woche-06/code/hello-world.c"
```

1. `stdio.h` ist die Standardbibliothek für Ein- und Ausgabe. Ohne dieses
   `#include` kennt der Compiler die Funktion `printf` nicht.
2. `main` ist die Funktion, die beim Start deines Programms automatisch als
   Erstes ausgeführt wird. Was `void` hier genau bedeutet und warum viele
   C-Programme stattdessen `int` verwenden, lernst du in der nächsten
   Woche im Detail.
3. `printf(...)` gibt den Text zwischen den Anführungszeichen aus. Das
   `\n` am Ende sorgt für einen Zeilenumbruch danach.

**Bauen und starten:** Damit aus deinem Quelltext ein lauffähiges Programm
wird, muss Visual Studio ihn zuerst **bauen** — also vom Compiler übersetzen
und zu einer ausführbaren Datei zusammenfügen lassen. Nutze dazu im Menü
**Erstellen → Projektmappe erstellen** (oder die Tastenkombination
**Strg+Umschalt+B**). Erst danach kannst du das Programm starten.

**Starten ohne Debuggen:** Startest du dein Programm über **Debuggen →
Debuggen starten** (oder die Taste **F5**), öffnet sich kurz ein
Konsolenfenster mit deiner Ausgabe — und schließt sich sofort wieder, bevor
du sie lesen kannst. Das liegt daran, dass das Programm nach der letzten
Zeile einfach endet und das Fenster mitnimmt. Nutze stattdessen
**Debuggen → Starten ohne Debuggen** (oder **Strg+F5**): Dann bleibt das
Fenster offen, bis du eine beliebige Taste drückst.
{: .hinweis-klein }

Wenn du "Hello World!" in einem offenen Konsolenfenster siehst, hat alles
funktioniert.

## Zum Ausprobieren { .abschnitt-ausprobieren }

**1.** Ändere den Text zwischen den Anführungszeichen so, dass statt
"Hello World!" dein eigener Name erscheint. Baue das Projekt neu und starte
es erneut — deine Änderung sollte jetzt in der Konsole erscheinen.

**2.** Lösche versuchsweise das Semikolon `;` am Ende der `printf`-Zeile und
baue das Projekt erneut. Das Bauen schlägt jetzt fehl. Zwei Fensterbereiche
zeigen dir jetzt etwas an: die **Fehlerliste** listet die Fehlermeldung
kompakt auf (Datei, Zeile, Fehlertext in eigenen Spalten), das
**Ausgabe**-Fenster zeigt zusätzlich den vollständigen Text des Compilers.
Für den Anfang reicht ein Blick in die Fehlerliste.

**Fehlermeldungen lesen:** Fehlermeldungen beim Bauen wirken am Anfang oft
kryptisch und manchmal zeigen sie auch auf die falsche Zeile — der Compiler
bemerkt ein fehlendes Semikolon oft erst beim nächsten Sprachelement
danach. Wichtig sind vor allem zwei Angaben: die **Datei und Zeilennummer**
(damit weißt du, wo du suchen musst) und der **Fehlertext** selbst. Solche
Meldungen sind auch ein guter Kandidat dafür, sie dir von einem
KI-Werkzeug erklären zu lassen, wenn du nicht weiterkommst.
{: .hinweis-klein }

Setze das Semikolon danach wieder ein und baue das Projekt erneut, damit dein
Programm wieder läuft.

## Selbstkontrolle { .abschnitt-selbstkontrolle }

### Frage 1

<quiz>
Ordne jeden Begriff seiner Erklärung zu:

| Nr. | Begriff |
|---|---|
| 1 | Datei |
| 2 | Projekt |
| 3 | Projektmappe (Solution) |
| 4 | Compiler |

- [[3]] Ein Container, der ein oder mehrere Projekte zusammenfasst.
- [[1]] Ein einzelner Quelltext, zum Beispiel mit der Endung `.c`.
- [[4]] Das Programm, das Quelltext in Maschinensprache übersetzt.
- [[2]] Die Sammlung aller Dateien und Einstellungen, aus denen ein einzelnes Programm gebaut wird.

</quiz>

### Frage 2

<quiz>
Welche Dateiendung sorgt in Visual Studio dafür, dass eine Quelldatei als C (nicht C++) übersetzt wird?
- [ ] `.cpp`
> Nein — diese Endung lässt Visual Studio die Datei als C++ behandeln, auch wenn der Inhalt wie reines C aussieht.
- [x] `.c`
> Richtig — die Endung entscheidet, welcher Compiler-Modus verwendet wird.
- [ ] `.h`
> Nein — das ist die Endung für Header-Dateien, dazu kommt später mehr.
- [ ] `.txt`
> Nein — das ist keine von Visual Studio erkannte Quelltext-Endung.

</quiz>

### Frage 3

Du startest dein Programm mit **F5** ("Debuggen starten"), und das
Konsolenfenster schließt sich sofort wieder, bevor du die Ausgabe lesen
kannst. Was ist die Ursache, und wie behebst du es?

??? note "Musterlösung anzeigen"
    Das Programm läuft komplett durch und beendet sich, sobald die
    schließende geschweifte Klammer `}` von `main` erreicht ist — und mit
    dem Programm schließt sich auch das Konsolenfenster, das es geöffnet
    hatte. Abhilfe schafft
    **Debuggen → Starten ohne Debuggen** (**Strg+F5**) statt **F5**: Damit
    hält Visual Studio das Fenster nach dem Programmende offen, bis eine
    Taste gedrückt wird.

### Frage 4

<quiz>
Bevor ein C-Programm ausgeführt werden kann, muss der Quelltext zunächst vom [[Compiler]] übersetzt werden; in Visual Studio wird dieser Schritt [[Bauen]] genannt und läuft unter anderem über den Menüpunkt Erstellen.

---
Nachzulesen im Abschnitt "Bauen und starten" oben.
</quiz>

### Frage 5

Warum reicht für dieses Modul eine Projektmappe mit genau einem Projekt,
obwohl Visual Studio grundsätzlich mehrere Projekte in einer Projektmappe
zusammenfassen kann?

??? note "Musterlösung anzeigen"
    Mehrere Projekte in einer Projektmappe lohnen sich vor allem, wenn
    mehrere zusammengehörige Programme (z. B. ein Programm und eine
    zugehörige Bibliothek) gemeinsam entwickelt werden. In diesem Kurs
    schreibst du dagegen jede Aufgabe als ein einzelnes, in sich
    abgeschlossenes Programm — dafür genügt jeweils ein Projekt in einer
    eigenen Projektmappe.

### Frage 6

Beim Bauen deines Programms erscheint diese Fehlermeldung in der
Fehlerliste:

```text
hello-world.c(5): error C2143: syntax error: missing ';' before '}'
```

Welche zwei Angaben in dieser Zeile helfen dir am meisten dabei, den
Fehler zu finden — und was verrät jede davon?

??? note "Musterlösung anzeigen"
    Die Angabe `hello-world.c(5)` nennt **Datei und Zeile**, in der der
    Compiler das Problem bemerkt hat — hier Zeile 5, die `printf`-Zeile.
    Das ist der erste Ort, an dem du nachschaust, auch wenn sich die
    Meldung formal auf das *nächste* Sprachelement bezieht (hier die
    schließende Klammer `}` in Zeile 6) — der Compiler bemerkt ein
    fehlendes Semikolon eben erst dort. Der Text
    `missing ';' before '}'` ist der **Fehlertext** und sagt dir konkret,
    was fehlt: ein Semikolon vor der schließenden Klammer.
