---
typ: theoriephase-block
termin: 1
block_id: "01"
datum: "2026-10-21"
kurztitel: "Grundbegriffe und Zahlensysteme"
thema: >-
  Zahlensysteme in der Praxis (formatierte Ganzzahl-Ausgabe in
  Dezimal/Oktal/Hex, Zeichencodierung/ASCII) | Ein-/Ausgabe-Werkzeuge in C
  (Codepage/Umlaute, scanf_s mit char, system(cls), system(pause),
  ESC-Sequenzen als Ausblick)
lernziele:
  - "Du kannst eine ganze Zahl in C mit printf in Dezimal, Oktal und Hexadezimal ausgeben."
  - "Du kannst erklären, wozu eine Codepage dient, und ein Konsolenprogramm so anpassen, dass Umlaute korrekt erscheinen."
  - "Du kannst ein einzelnes Zeichen mit scanf_s einlesen und sowohl als Zeichen als auch als ASCII-Zahl ausgeben."
  - "Du kannst Zeilen- und Blockkommentare sinnvoll einsetzen, um Code nachvollziehbar zu machen."
  - "Du kannst mit system(\"cls\") und system(\"pause\") den Ablauf einer Konsolenanwendung steuern."
musterloesungen_sichtbar: true
ki_einsatz: stufe_0_ohne
clean_code: []
bearbeitungsstatus: in-arbeit
---

# Grundbegriffe und Zahlensysteme (21.10.2026)

## Grundbegriffe und Zahlensysteme { .modus-uebung }

### Worum geht es?

Willkommen zum ersten Präsenztermin! In der Praxisphase habt ihr Visual
Studio installiert, euer erstes C-Programm zum Laufen gebracht und gelernt,
mit `printf` und `scanf_s` Werte auszugeben und einzulesen. Heute bauen wir
darauf direkt auf: Ausgehend von einem einfachen Hello-World-Programm
erweitern wir den Code Schritt für Schritt um eine ganze Reihe nützlicher
Ein-/Ausgabe-Techniken, die ihr ab jetzt ständig brauchen werdet.

!!! abstract "Lernziele"
    - Ihr könnt eine ganze Zahl in C mit `printf` in Dezimal, Oktal und
      Hexadezimal ausgeben.
    - Ihr könnt erklären, wozu eine Codepage dient, und ein
      Konsolenprogramm so anpassen, dass Umlaute korrekt erscheinen.
    - Ihr könnt ein einzelnes Zeichen mit `scanf_s` einlesen und sowohl
      als Zeichen als auch als ASCII-Zahl ausgeben.
    - Ihr könnt Zeilen- und Blockkommentare sinnvoll einsetzen, um Code
      nachvollziehbar zu machen.
    - Ihr könnt mit `system("cls")` und `system("pause")` den Ablauf einer
      Konsolenanwendung steuern.

### Kurzer Rückblick <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Kurzer Rückblick" }

1\. Wozu dient die formatierte Ausgabe mit `printf` eigentlich, wenn der
Rechner intern sowieso nur mit Bitmustern arbeitet?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    `printf` übersetzt die intern als reines Bitmuster gespeicherten Werte
    in eine für Menschen lesbare Darstellung. Je nachdem, welches
    Formatierungszeichen ihr verwendet, wird genau dieselbe Bitfolge ganz
    unterschiedlich interpretiert und dargestellt — als Dezimalzahl, als
    Hexadezimalzahl oder sogar als Zeichen. Der Rechner selbst "weiß" davon
    nichts; die Bedeutung entsteht erst durch die Interpretation.
<!-- MUSTERLOESUNG-ENDE -->

2\. Welches Formatierungszeichen habt ihr in Woche 7 schon kennengelernt,
um eine ganze Zahl hexadezimal auszugeben?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    `%x`. Heute kommt mit `%o` (Oktal) noch ein weiteres dazu.
<!-- MUSTERLOESUNG-ENDE -->

---

### Das Beispiel: Ein Werkzeugkasten für Ein- und Ausgabe <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Das Beispiel: Ein Werkzeugkasten für Ein- und Ausgabe" }

Wir bauen heute gemeinsam einen kleinen "Werkzeugkasten" für die Ein- und
Ausgabe in C: ein Programm, das nach und nach zeigt, wie ihr Zahlen in
unterschiedlichen Zahlensystemen ausgebt, wie ihr mit deutschen Umlauten in
der Konsole umgeht, wie ihr ein einzelnes Zeichen einlest und wie ihr den
Ablauf eurer Konsolenanwendung steuert. Am Ende habt ihr ein vollständiges
Programm, das all diese Bausteine kombiniert — und die ihr in euren eigenen
Programmen ab sofort wiederverwenden könnt.

---

### Schrittweise Umsetzung <span class="zeitangabe">ca. 30 Min.</span> { data-toc-label="Schrittweise Umsetzung" }

Wir starten wieder bei einem Hello-World-Programm und bauen es Schritt für
Schritt aus.

#### Schritt 1: Ausgangspunkt und Kommentare

Unser Startpunkt ist das bekannte Hello-World-Programm — diesmal ergänzt um
zwei Arten von Kommentaren, die ihr aus Woche 7 schon kurz gesehen habt.
Ein **Zeilenkommentar** beginnt mit `//` und gilt nur bis zum Zeilenende.
Ein **Blockkommentar** steht zwischen `/*` und `*/` und kann sich über
mehrere Zeilen erstrecken — praktisch für längere Erklärungen am Anfang
einer Datei oder eines schwierigen Codeabschnitts. Der Compiler ignoriert
beide Kommentararten vollständig; sie sind ausschließlich für Menschen
gedacht, die den Code lesen.

**Kommentare sinnvoll einsetzen:** Ein Kommentar ist erst dann hilfreich,
wenn er etwas erklärt, das aus dem Code selbst nicht ohnehin schon
hervorgeht. Was genau einen *guten* Kommentar ausmacht, schauen wir uns in
einer späteren Einheit als eigenes Clean-Code-Prinzip genauer an — heute
geht es erst einmal nur um die Schreibweise.
{: .hinweis-klein }

??? quote livecoding "Beispiel-Code"
    ```c
    --8<-- "02-theoriephase/termin-01/code/live-01-1-hello.c"
    ```

---

#### Schritt 2: Eine Zahl in drei Zahlensystemen ausgeben

Wir lesen jetzt eine ganze Zahl ein und geben sie in drei verschiedenen
Zahlensystemen aus: Dezimal (`%d`), Oktal (`%o`, neu) und Hexadezimal
(`%x`, kennt ihr schon aus Woche 7). Was ihr in Woche 2 von Hand
ausgerechnet habt, übernimmt hier `printf` für euch — wissen, was hinter
den Zahlensystemen steckt, müsst ihr trotzdem.

**Weitere Formatierungszeichen nachschlagen:** `%d`, `%o` und `%x` sind nur
drei von vielen Formatierungszeichen, die `printf` versteht. Eine
vollständige Übersicht findet ihr in der
[C-Referenz zu `printf`](https://devdocs.io/c/io/fprintf) — praktisch zum
Nachschlagen, wenn ihr mal ein anderes Format braucht.
{: .hinweis-klein }

??? quote livecoding "Beispiel-Code"
    ```c
    --8<-- "02-theoriephase/termin-01/code/live-01-2-zahlenformate.c"
    ```

---

#### Schritt 3: Umlaute und Codepage

Versucht ihr, in eurem Programm einen Text mit `ä`, `ö`, `ü` oder `ß`
auszugeben, erscheinen in der Konsole oft merkwürdige Ersatzzeichen statt
der erwarteten Umlaute. Der Grund: Die Windows-Konsole verwendet
standardmäßig eine andere Zeichencodierung (**Codepage**) als die, in der
Visual Studio eure Quelldatei speichert. Mit dem Befehl `chcp 1252` stellt
ihr die Konsole auf die Codepage 1252 um — das ist die in Deutschland
übliche Windows-Codepage, die unter anderem alle deutschen Umlaute enthält.
Da `chcp` ein Befehl der Windows-Kommandozeile ist, kein Bestandteil von C,
rufen wir ihn über die Funktion `system()` auf, die einen beliebigen
Befehlszeilenbefehl ausführt.

**Datei mit Umlauten richtig speichern:** `chcp 1252` allein reicht nicht
immer aus: Speichert Visual Studio eure Datei ohne einen bestimmten Marker
am Dateianfang (ein sogenanntes "BOM", *Byte Order Mark*), kann es
passieren, dass jeder Umlaut im Quelltext falsch in euer Programm
übernommen wird — unabhängig von der Codepage zur Laufzeit. Falls eure
Umlaute trotz `chcp 1252` falsch erscheinen: Datei in Visual Studio über
**Datei → Speichern unter... → den kleinen Pfeil neben "Speichern" →
"Speichern mit Codierung..."** und dort **"Unicode (UTF-8 mit Signatur) -
Codepage 65001"** auswählen.
{: .hinweis-klein }

??? quote livecoding "Beispiel-Code"
    ```c
    --8<-- "02-theoriephase/termin-01/code/live-01-3-codepage.c"
    ```

---

#### Schritt 4: Zurück zum ASCII-Code

Erinnert ihr euch an den ASCII-Code aus Woche 2
([Rückbezug: ASCII-Code](../../01-praxisphase/woche-02/ascii-code.md))? Jedes
Zeichen wird intern als Zahl gespeichert. Wir lesen jetzt ein einzelnes
Zeichen ein und geben es sowohl als Zeichen (`%c`) als auch als Zahl (`%d`)
aus — ihr seht direkt den zugehörigen ASCII-Code. Eine Besonderheit von
`scanf_s`: Bei `%c` verlangt es zusätzlich zur Adresse der Variable noch
einen dritten Parameter — die Zahl `1` steht hier dafür, dass höchstens ein
einziges Zeichen eingelesen werden darf. Das ist ein Sicherheitsmechanismus,
den das einfache `scanf` nicht kennt.

??? quote livecoding "Beispiel-Code"
    ```c
    --8<-- "02-theoriephase/termin-01/code/live-01-4-ascii.c"
    ```

---

#### Schritt 5: Konsole steuern — `cls` und `pause`

Zwei kleine, aber praktische Helfer für den Alltag: `system("cls")` löscht
den Inhalt der Konsole (Achtung: `cls` ist ein Windows-Befehl, unter
anderen Betriebssystemen funktioniert das nicht). `system("pause")` hält
das Programm an und wartet auf einen Tastendruck — nützlich, damit sich das
Konsolenfenster nach Programmende nicht sofort wieder schließt.

??? quote livecoding "Beispiel-Code"
    ```c
    --8<-- "02-theoriephase/termin-01/code/live-01-5-cls-pause.c"
    ```

---

#### Schritt 6: Ausblick — ESC-Sequenzen

Mit sogenannten **ESC-Sequenzen** — speziellen Zeichenfolgen, die mit dem
Escape-Zeichen `\x1b` beginnen — lässt sich die Konsole noch weiter
steuern, zum Beispiel Textfarbe, Hintergrundfarbe und sogar die genaue
Position des Cursors. Das geht über den eigentlichen C-Standard hinaus und
funktioniert auf den meisten aktuellen Windows-Rechnern zuverlässig,
besonders wenn eure Konsole in einem Windows-Terminal-Fenster läuft — bei
älteren oder anders eingestellten Konsolen kann es sein, dass ihr statt der
Wirkung nur die rohe Zeichenfolge seht (z. B. `←[31m`). Die Zahlen in der
Sequenz haben feste Bedeutungen: `31` färbt den folgenden Text rot, `44`
setzt einen blauen Hintergrund, `97` ein helles Weiß (beides zusammen mit
Semikolon getrennt), `0` setzt alles wieder auf Standard zurück, und
`<Zeile>;<Spalte>H` positioniert den Cursor an eine feste Stelle. Die volle
Anwendung davon — ein gezeichnetes Eingabefeld — probiert ihr gleich im
betreuten Selbststudium selbst aus.

??? quote livecoding "Beispiel-Code"
    ```c
    --8<-- "02-theoriephase/termin-01/code/live-01-6-esc-basics.c"
    ```

---

### Gesamtergebnis <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Gesamtergebnis" }

Zum Schluss noch einmal das vollständige Programm, das alle Bausteine
dieser Einheit kombiniert:

??? quote livecoding "Code: vollständiges Programm"
    ```c
    --8<-- "02-theoriephase/termin-01/code/live-01-final-werkzeugkasten.c"
    ```

Damit habt ihr heute folgende Konzepte kennengelernt:

- **Formatierte Ausgabe** einer Zahl in mehreren Zahlensystemen mit
  `printf` (`%d`, `%o`, `%x`).
- **Codepage und Zeichencodierung**: Warum Umlaute in der Konsole manchmal
  falsch erscheinen und wie `system("chcp 1252")` das behebt.
- **Zeichen einlesen** mit `scanf_s("%c", ...)`, inklusive des
  zusätzlichen Größenparameters.
- **Ablaufsteuerung der Konsole** mit `system("cls")` und
  `system("pause")`.
- **Zeilen- und Blockkommentare**, um Code nachvollziehbar zu machen.

---

## Grundbegriffe und Zahlensysteme { .modus-selbststudium }

### Worum geht es?

Jetzt seid ihr dran: Wendet die Werkzeuge aus der Übung selbst an, um
kleine, vollständige Programme zu schreiben.

!!! abstract "Lernziele"
    - Ihr könnt die in der Übung gezeigten Ein-/Ausgabe-Techniken
      eigenständig in einem vollständigen Programm kombinieren.
    - Ihr könnt vorhersagen, was ein gegebenes Programm mit `printf` in
      verschiedenen Formaten ausgibt.

### Aufgabe 01: Persönliche Begrüßung

Schreibt ein Programm, das nach dem Anfangsbuchstaben eures Vornamens (ein
einzelnes Zeichen) und eurem Alter fragt und anschließend eine
personalisierte Begrüßung mit korrekt dargestellten Umlauten ausgibt. Achtet
darauf, dass die Codepage passend eingestellt ist, bevor ihr Umlaute
ausgebt, kommentiert die wichtigsten Zeilen kurz, und beendet euer Programm
mit `system("pause")`, damit ihr die Ausgabe in Ruhe lesen könnt.

**Reihenfolge beachten:** Fragt zuerst nach dem Anfangsbuchstaben (mit
`%c`), erst danach nach dem Alter (mit `%d`) — nicht umgekehrt. Warum das
wichtig ist, steht in der Musterlösung unten.
{: .hinweis-klein }

Notiert euch außerdem in ein bis zwei Sätzen: Was würde passieren, wenn ihr
die Zeile mit `chcp 1252` weglasst — und warum?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c
    --8<-- "02-theoriephase/termin-01/code/aufg-01-persoenliche-begruessung.c"
    ```

    Die Reihenfolge der beiden Einlesevorgänge ist hier wichtig: Zuerst wird
    mit `%c` das einzelne Zeichen eingelesen, danach erst mit `%d` die
    Zahl. `%d` überspringt beim Einlesen automatisch führende Leerzeichen
    und Zeilenumbrüche — `%c` tut das nicht. Stünde die Zahl zuerst, würde
    `%c` anschließend versehentlich den Zeilenumbruch einlesen, der nach der
    Zahleneingabe übrig bleibt, statt auf euren Anfangsbuchstaben zu warten.
    Diesem Problem — dass ein übrig gebliebenes Zeichen die nächste Eingabe
    stört — begegnet ihr im nächsten Termin noch einmal genauer.

    Ohne `chcp 1252` würde die Konsole eure Umlaute mit der falschen
    Codepage interpretieren und stattdessen merkwürdige Ersatzzeichen
    anzeigen — der Text bliebe inhaltlich unverändert, nur die Darstellung
    der Umlaute wäre kaputt.

<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 02: Eine Zahl, drei Systeme

#### Teil A — Programmieren

Schreibt ein Programm, das eine ganze Zahl einliest und sie anschließend in
vier Formen ausgibt: Dezimal, Oktal, Hexadezimal und als ASCII-Zeichen.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    ```c
    --8<-- "02-theoriephase/termin-01/code/aufg-02-zahl-drei-systeme.c"
    ```

    Alle vier Ausgaben greifen auf dieselbe Variable `zahl` zu — nur das
    Formatierungszeichen entscheidet, wie der Wert interpretiert und
    dargestellt wird. Bei der Ausgabe als ASCII-Zeichen (`%c`) solltet ihr
    eine Zahl eingeben, die tatsächlich einem druckbaren Zeichen entspricht
    (z. B. 65 für `A`) — sonst erscheint ein unsichtbares Steuerzeichen.

<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Schreibtischtest

Schaut euch das folgende Programm an, **ohne es auszuführen**, und notiert
euch für jede der vier `printf`-Zeilen, was sie ausgibt:

```c
--8<-- "02-theoriephase/termin-01/code/aufg-02-schreibtischtest.c"
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```text
    65
    101
    41
    A
    ```

    `wert` enthält den ASCII-Code des Großbuchstabens `A`. Dezimal ist das
    einfach `65`. Oktal (Basis 8) ergibt `101`, hexadezimal (Basis 16)
    ergibt `41` — beides dieselbe Zahl, nur anders dargestellt. Mit `%c`
    wird dieselbe Zahl schließlich als das Zeichen interpretiert, dessen
    ASCII-Code sie ist: `A`.

<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 03: Eingabefeld mit ESC-Sequenzen

Das folgende Programm zeichnet mit ESC-Sequenzen ein Eingabefeld in die
Konsole und liest einen Messwert direkt in dieses Feld ein:

```c
--8<-- "02-theoriephase/termin-01/code/vorgabe-03-eingabefeld-esc.c"
```

**Nur Zeichenmüll statt Rahmen und Farbe?** Seht ihr statt eines
gezeichneten Rahmens nur rohe Zeichenfolgen wie `←[31m`, liegt das an eurem
Konsolenfenster, nicht an eurem Code: Startet das Programm stattdessen über
ein Windows-Terminal-Fenster (statt der klassischen Eingabeaufforderung),
sollte es funktionieren.
{: .hinweis-klein }

Anders als bei Aufgabe 01 und 02 dürft ihr euch hier von einer KI erklären
lassen, was die einzelnen ESC-Sequenzen bewirken (`\x1b[2J`,
`\x1b[<Zeile>;<Spalte>H`) — mehr dazu unter
[KI im Kurs](../../ki-nutzung.md). Die Erweiterung selbst — ein **zweites**
Eingabefeld für einen weiteren Messwert, zum Beispiel Drehzahl und
Temperatur eines Motorprüfstands wie schon in Woche 7 — schreibt ihr danach
eigenständig: Die KI hilft euch nur, die vorgegebenen Zeilen zu verstehen,
nicht dabei, die Erweiterung für euch zu erzeugen.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c
    --8<-- "02-theoriephase/termin-01/code/aufg-03-eingabefeld-esc-erweitert.c"
    ```

    Der Kern der Erweiterung ist einfach: Das zweite Feld wird mit
    denselben ESC-Sequenzen gezeichnet wie das erste, nur an einer anderen
    Zeilenposition. `\x1b[2J` löscht dabei einmal am Anfang den gesamten
    Bildschirm, `\x1b[<Zeile>;<Spalte>H` positioniert den Cursor danach
    jeweils exakt dort, wo als Nächstes etwas erscheinen soll — sowohl für
    die Rahmen als auch für die beiden Eingaben und die abschließende
    Ausgabe.

<!-- MUSTERLOESUNG-ENDE -->
