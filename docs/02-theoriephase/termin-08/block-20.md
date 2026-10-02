---
typ: theoriephase-block
termin: 8
block_id: "20"
datum: "2026-12-09"
kurztitel: "Binärdateien und Fehlerbehandlung"
thema: "Dateibearbeitung — Binärdateien, Datensätze, Fehlerbehandlung"
lernziele:
  - "Ihr könnt Datensätze fester Länge mit fwrite und fread in einer Binärdatei speichern und mit fseek gezielt einzelne Datensätze überschreiben."
  - "Ihr könnt den Inhalt einer Binärdatei in einem Hex-Editor einem Dateiformat aus Dateikopf und Datensätzen zuordnen."
  - "Ihr könnt Fehler in Dateifunktionen über Fehlercodes melden, statt sie zu verstecken."
musterloesungen_sichtbar: true
ki_einsatz: stufe_3_pflicht_reflexion
clean_code:
  - "Fehler melden statt verstecken"
bearbeitungsstatus: in-arbeit
publish_date: "2026-12-09"
---

# Binärdateien und Fehlerbehandlung (09.12.2026)

## Übung { .modus-uebung }

### Worum geht es?

In Block 19 habt ihr Daten als Text in einer CSV-Datei gespeichert. Das
ist gut lesbar, hat aber Grenzen: Jede Zahl muss in Text umgewandelt
werden, und eine einzelne Zeile lässt sich nicht ändern, ohne die ganze
Datei neu zu schreiben. Jetzt lernt ihr mit der **Binärdatei** die
Alternative kennen und seht an einem neuen, kleinen Beispiel, wie ihr mit
Fehlern beim Dateizugriff sauber umgeht.

!!! abstract "Lernziele"
    - Ihr könnt Datensätze fester Länge mit `fwrite` und `fread` in einer
      Binärdatei speichern und mit `fseek` gezielt einzelne Datensätze
      überschreiben.
    - Ihr könnt den Inhalt einer Binärdatei in einem Hex-Editor einem
      Dateiformat aus Dateikopf und Datensätzen zuordnen.
    - Ihr könnt Fehler in Dateifunktionen über Fehlercodes melden, statt
      sie zu verstecken.

### Das Beispiel: Ein Messreihen-Logger <span class="zeitangabe">ca. 2 Min.</span> { data-toc-label="Das Beispiel: Ein Messreihen-Logger" }

Ein Temperatursensor an einem Ofen liefert regelmäßig Messwerte. Jeder
Messwert besteht aus einer laufenden Nummer und der Temperatur. Die
Messreihe soll in einer Datei gespeichert und später wieder eingelesen
werden. Das ganze Programm steht in einer einzigen `main.c`.

Dafür legen wir ein eigenes, einfaches **Dateiformat** fest:

- Jeder Messwert ist ein Datensatz aus **8 Byte**: 4 Byte für die Nummer
  (`int`) und 4 Byte für die Temperatur (`float`).
- Die Datensätze stehen direkt hintereinander, ohne Trennzeichen und ohne
  Zeilenumbrüche. Die Bytes werden so in die Datei geschrieben, wie sie
  im Speicher liegen.
- Einen Dateikopf mit Angaben über die Datei selbst ergänzen wir erst später (in
  Schritt 3).

Das ist kompakter als Text und braucht keine Umwandlung der Zahlen. Weil
jeder Datensatz gleich lang ist, lässt sich seine Position in der Datei
berechnen (dazu mehr in Schritt 2). Dafür kann man die Datei nicht mehr
mit einem Texteditor lesen, ihr braucht einen **Hex-Editor**.

---

### Schritt 1: Messwerte binär speichern und lesen <span class="zeitangabe">ca. 10 Min.</span> { data-toc-label="Schritt 1: Messwerte binär speichern und lesen" }

Mit `fwrite` schreibt ihr ein ganzes Array in einem Aufruf in die Datei,
mit `fread` lest ihr es wieder ein. Beide bekommen vier Angaben: die
Adresse der Daten, die Größe eines Elements, die Anzahl der Elemente und
den Dateizeiger.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-08/code/live-20-1-binaer-schreiben-lesen.c"
    ```

    1. Ein Messwert besteht aus einem `int` und einem `float`, zusammen
       8 Byte. Genau diese 8 Byte stehen später pro Datensatz in der
       Datei.
    2. Das `b` im Modus steht für **binär**: `"wb"` schreibt, `"rb"`
       liest. Ohne `b` würde Windows beim Schreiben jedes Byte mit dem
       Wert 10 (Zeilenvorschub) in zwei Bytes umwandeln.
    3. `fwrite` schreibt alle `ANZAHL` Messwerte auf einmal. Die Größe
       eines Elements ermittelt `sizeof(Messwert)`.
    4. `fread` liefert zurück, wie viele Elemente tatsächlich gelesen
       wurden.

**Hinweis:** Dieser Code prüft nirgends, ob `fopen`, `fwrite` oder `fread`
erfolgreich waren. Das ist hier bewusst weggelassen, damit der Blick auf
den neuen Funktionen bleibt. In Schritt 4 holen wir das nach.
{: .hinweis-klein }

Jetzt schauen wir uns an, was tatsächlich in der Datei steht. Öffnet
`messwerte.dat` in einem Hex-Editor, zum Beispiel mit dem
Programm HxD. Ein Hex-Editor
zeigt links die Position (Offset), in der Mitte die Bytes als
Hexadezimalzahlen und rechts die Zeichen dazu:

```text
00000000  01 00 00 00 00 00 AC 41 02 00 00 00 00 00 B0 41  .......A.......A
00000010  03 00 00 00 00 00 BA 41 04 00 00 00 00 00 B6 41  .......A.......A
```

- Pro Datensatz stehen 8 Bytes. Die ersten vier (`01 00 00 00`) sind die
  Nummer 1, die nächsten vier (`00 00 AC 41`) die Temperatur 21,5.
- Die Nummer steht mit dem **niedrigstwertigen Byte zuerst** (Little
  Endian): `01 00 00 00` ist die Zahl 1, nicht 16 777 216.
- Wie genau die Bits einer `float`-Zahl kodiert sind, müssen wir hier
  nicht auflösen. Wichtig ist: Die Datei enthält das Speicherabbild der
  Zahl, keinen Text.
- Die Zeichenspalte rechts ist kaum lesbar, weil nur wenige Bytes
  druckbare Zeichen sind. Das `A` kommt vom Byte `41`.

---

### Schritt 2: Einen Datensatz direkt ändern <span class="zeitangabe">ca. 6 Min.</span> { data-toc-label="Schritt 2: Einen Datensatz direkt ändern" }

In Aufgabe 48 musstet ihr die ganze Textdatei neu schreiben, um einen
Wert zu ändern. Hier geht es einfacher: Jeder Datensatz ist 8 Byte lang,
der Datensatz mit dem Index `i` beginnt also bei Byte `i * 8`. Mit
`fseek` springen wir direkt dorthin und überschreiben nur diesen einen
Messwert.

Wichtig: Wer mit `fseek` an eine Stelle springt und dort schreibt,
**überschreibt** den bestehenden Inhalt an genau dieser Stelle. Das
verhält sich anders als in einem Texteditor, wo eingefügter Text den
restlichen Inhalt nach hinten schiebt. In der Datei wird nichts
verschoben, und die Länge der Datei ändert sich nicht (solange wir nicht
über das Dateiende hinaus schreiben). Deshalb muss der neue Datensatz
genau so lang sein wie der alte.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1" hl_lines="29-33"
    --8<-- "02-theoriephase/termin-08/code/live-20-2-datensatz-direkt-aendern.c"
    ```

    1. `"r+b"` öffnet eine bestehende Datei zum Lesen **und** Schreiben,
       ohne ihren Inhalt zu löschen (anders als `"wb"`).
    2. Der dritte Datensatz hat den Index 2 und beginnt bei Byte
       `2 * sizeof(Messwert)`. `SEEK_SET` bedeutet: gezählt ab dem
       Dateianfang.
    3. Geschrieben wird nur dieser eine Datensatz, und zwar **über** den
       alten. Alle anderen Bytes der Datei bleiben unverändert.

Das funktioniert nur, weil alle Datensätze gleich lang sind. Bei einer
Textdatei mit unterschiedlich langen Zeilen lässt sich die Position einer
Zeile nicht berechnen. Schaut im Hex-Editor nach: Nur vier Bytes haben
sich geändert.

---

### Schritt 3: Dateikopf und Prüfung beim Laden <span class="zeitangabe">ca. 12 Min.</span> { data-toc-label="Schritt 3: Dateikopf und Prüfung beim Laden" }

Woher weiß ein Programm, dass eine Datei wirklich in unserem Format
vorliegt und nicht beschädigt ist? Viele Dateiformate lösen das mit einem
**Dateikopf** am Anfang der Datei. Aus dem Anfang einer Datei lässt sich
so das Format erkennen. In unserem Beispiel ist der Kopf 12 Byte lang:

| Offset | Länge | Inhalt |
|---|---|---|
| 0 | 4 Byte | Kennung `MWL` (mit Endmarke `\0`) |
| 4 | 4 Byte | Versionsnummer des Formats (`int`) |
| 8 | 4 Byte | Anzahl der Datensätze (`int`) |
| 12 | n × 8 Byte | die Messwerte |

Je nach Format kann ein Kopf noch weitere Angaben enthalten (Metadaten
wie Datum, Größe oder Einstellungen) und entsprechend länger sein. Die
feste Bytefolge ganz am Anfang, hier die Kennung `MWL`, heißt
**magische Zahl** (englisch *magic number*). Programme prüfen sie zuerst,
um das Dateiformat zu erkennen. Verwechselt das nicht mit den „magischen
Zahlen" aus dem Clean Code (Block 7): Dort sind Zahlen gemeint, die ohne
Namen im Code stehen. Es ist derselbe Begriff für zwei völlig
verschiedene Dinge.

Das Programm schreibt jetzt zuerst den Kopf und dann die Messwerte. Beim
Laden prüft es: Stimmen Kennung und Version? Ist die Anzahl plausibel? Und
sind wirklich so viele Messwerte in der Datei, wie der Kopf angibt? Das
Beispiel baut auf Schritt 1 auf, die Korrektur eines Messwerts aus
Schritt 2 lassen wir weg.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-08/code/live-20-3-dateikopf-pruefung.c"
    ```

    1. Vier Byte für die Kennung: drei Buchstaben und die Endmarke `\0`.
    2. Das Programm hält zwischen Schreiben und Lesen an. In dieser Pause
       könnt ihr die Datei im Hex-Editor verändern und speichern.
    3. Der Kopf wird mit den Werten initialisiert. `"MWL"` füllt das
       `char`-Array samt Endmarke. Er wird vor den Messwerten geschrieben.
    4. Was aus einer Datei kommt, kann beliebige Bytes enthalten. Die
       Endmarke wird deshalb erzwungen, damit `strcmp` nicht über das
       Array hinaus liest.
    5. Sind weniger Messwerte in der Datei als im Kopf angegeben, ist die
       Datei zu kurz und damit beschädigt.
    6. Die Funktion gibt 0 zurück, wenn die Datei fehlt, beschädigt ist
       **oder** wirklich leer. Der Aufrufer kann das nicht
       unterscheiden.

So sieht eine gültige Datei im Hex-Editor aus, vor den vier Messwerten
steht jetzt der Kopf:

```text
00000000  4D 57 4C 00 01 00 00 00 04 00 00 00 01 00 00 00  MWL.............
00000010  00 00 AC 41 02 00 00 00 00 00 B0 41 03 00 00 00  ...A.......A....
00000020  00 00 BA 41 04 00 00 00 00 00 B6 41              ...A.......A
```

Probiert es aus: Startet das Programm und verändert in der Pause die
Datei im Hex-Editor, zum Beispiel indem ihr die letzten Bytes löscht oder
das `M` am Anfang ändert. Danach meldet das Programm „0 Messwerte
geladen". Es erkennt den Fehler, aber wir erfahren nicht, **was** nicht
stimmt. Das beheben wir im nächsten Schritt.

---

### Schritt 4: Fehler melden statt verstecken <span class="zeitangabe">ca. 13 Min.</span> { data-toc-label="Schritt 4: Fehler melden statt verstecken" }

!!! tip "Clean Code: Fehler melden statt verstecken"
    Ein Fehler, der still verschluckt wird, taucht später als rätselhaftes
    Verhalten wieder auf. In Schritt 3 gibt `messwerteLaden` bei jedem
    Problem einfach 0 zurück, und `messwerteSpeichern` ignoriert Fehler
    ganz. Besser: Eine Funktion **meldet** den Fehler über ihren
    Rückgabewert, zum Beispiel als Fehlercode. Der Aufrufer entscheidet
    dann, wie er darauf reagiert. Und prüft den Rückgabewert von
    Funktionen, die scheitern können, wie `fopen`, `fread`, `fwrite` und
    `fclose`.

Wir erweitern dafür den Stand aus Schritt 3. Die Fehlerarten bekommen einen
`enum`, die Dateifunktionen geben einen Wert davon zurück. Das Ergebnis der Messwerte selbst kommt über einen
Pointer-Parameter zurück. Die Ausgabe der Fehlermeldung steht an einer
einzigen Stelle.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1" hl_lines="26-34 36-39 51-56 61-67 78 82 85-92 95 99 101 103-105 108-109 111-115 119 122-130 133-156"
    --8<-- "02-theoriephase/termin-08/code/live-20-4-fehlercodes.c"
    ```

    1. Jede Fehlerart hat einen eigenen Namen. Die Namen sprechen für sich
       und die Zahlenwerte brauchen wir nirgends.
    2. Der Aufrufer prüft den Fehlercode und entscheidet selbst, was
       passiert, hier: eine Meldung ausgeben.
    3. `fwrite` liefert die Anzahl der tatsächlich geschriebenen
       Elemente. Weicht sie vom erwarteten Wert ab, ist etwas
       schiefgegangen, etwa weil der Datenträger voll ist.
    4. Auch `fclose` kann scheitern: Erst beim Schließen werden die
       letzten Daten tatsächlich auf den Datenträger geschrieben.
    5. Die Funktion meldet, **was** schiefgegangen ist, und entscheidet
       nicht selbst über die Reaktion.
    6. Die Meldungen für alle Fehlercodes stehen an einer Stelle und
       lassen sich leicht ändern oder übersetzen.

Testet es wie in Schritt 3, indem ihr in der Pause die Datei verändert:
eine gültige Datei, eine abgeschnittene Datei und eine Datei mit
geänderter Kennung. Löscht die Datei in der Pause außerdem einmal ganz.
Jetzt bekommt jeder Fall seine eigene, verständliche Meldung.

---

### Zusammenfassung <span class="zeitangabe">ca. 2 Min.</span> { data-toc-label="Zusammenfassung" }

- **Binärdatei:** Mit `fwrite` und `fread` werden Datensätze so in die
  Datei geschrieben, wie sie im Speicher liegen. Den Modus `"wb"`, `"rb"`
  oder `"r+b"` mit `b` verwenden.
- **Datensätze fester Länge:** Ihre Position lässt sich berechnen. Mit
  `fseek` springt man direkt zu einem Datensatz und überschreibt nur ihn.
- **Überschreiben statt Einfügen:** Schreiben nach `fseek` ersetzt die
  Bytes an dieser Stelle, nichts wird verschoben.
- **Dateikopf und magische Zahl:** Das Dateiformat lässt sich am Anfang
  der Datei erkennen. Kennung, Version und Anzahl erlauben dem Programm
  zu prüfen, ob die Datei zum erwarteten Format passt und vollständig
  ist.
- **Fehler melden statt verstecken:** Funktionen geben Fehlercodes
  zurück, der Aufrufer entscheidet über die Reaktion, und alle
  Rückgabewerte, die auf einen Fehler hinweisen können, werden geprüft.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

!!! abstract "Lernziele"
    - Ihr könnt den Inhalt einer Binärdatei von Hand in Kennung, Version,
      Anzahl und Datensätze zerlegen.
    - Ihr könnt ein Programm schreiben, das beliebige Dateien byteweise
      einliest und lesbar ausgibt.
    - Ihr könnt ein Programm so ändern, dass ein Abbruch beim Speichern
      die alte Datei nicht zerstört.

Ab heute ist KI-Unterstützung auch zur Code-Generierung regulär erlaubt,
siehe [KI im Kurs](../../ki-nutzung.md). Teil A bearbeitet ihr bewusst
ohne KI und ohne Rechner: Einen Hexdump von Hand zu zerlegen ist genau die
Fähigkeit, die ihr in den folgenden Teilen braucht, um die Ausgaben eures
Programms und der KI zu überprüfen.

### Aufgabe 49: Hexdump-Tool

Ein Hex-Editor zeigt, was wirklich in einer Datei steht. Ihr zerlegt
zuerst selbst einen Hexdump und programmiert dann ein eigenes Tool, das
einen solchen Hexdump erzeugt.

#### Teil A — Einen Hexdump zerlegen (ohne Rechner und ohne KI)

Die folgende Datei im Format aus der Übung (Kopf mit Kennung, Version und
Anzahl, danach 8-Byte-Messwerte aus `int` und `float`) liegt als Hexdump
vor:

```text
00000000  4D 57 4C 00 01 00 00 00 03 00 00 00 2C 01 00 00  MWL.........,...
00000010  00 00 94 41 2D 01 00 00 00 00 9A 41 2E 01 00 00  ...A-......A....
00000020  00 00 A0 41                                      ...A
```

1. Wie lautet die Kennung, welche Version und welche Anzahl von
   Messwerten steht im Kopf?
2. Welche Nummer hat der zweite Messwert? Denkt an die Byte-Reihenfolge.
3. Welche Bytes gehören zur Temperatur des zweiten Messwerts?
4. Wie groß muss die Datei laut Kopf sein, und stimmt das mit dem Dump
   überein?

Hier zwei weitere Dateien, die beide beschädigt sind. Welche Prüfung aus
Schritt 3 und 4 der Übung schlägt jeweils an, und woran erkennt ihr es?

```text
Datei 1:
00000000  4D 57 4C 00 01 00 00 00 03 00 00 00 2C 01 00 00  MWL.........,...
00000010  00 00 94 41 2D 01 00 00 00 00 9A 41 2E 01 00 00  ...A-......A....

Datei 2:
00000000  4D 57 4B 00 01 00 00 00 03 00 00 00 2C 01 00 00  MWK.........,...
00000010  00 00 94 41 2D 01 00 00 00 00 9A 41 2E 01 00 00  ...A-......A....
00000020  00 00 A0 41                                      ...A
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    1. Die ersten vier Bytes `4D 57 4C 00` sind die Zeichen `M`, `W`,
       `L` und die Endmarke, die Kennung lautet also `MWL`. Version:
       `01 00 00 00` = 1. Anzahl: `03 00 00 00` = 3.
    2. Der zweite Datensatz beginnt bei Offset 20 (`14` hexadezimal). Die
       Nummer steht dort als `2D 01 00 00`. Das niedrigstwertige Byte
       steht zuerst, die Zahl ist also `0x012D` = 301.
    3. Die Temperatur des zweiten Messwerts sind die vier Bytes
       `00 00 9A 41`, direkt nach der Nummer (Offsets 24 bis 27).
    4. Laut Kopf: 12 Byte Kopf + 3 × 8 Byte = 36 Byte (hexadezimal
       `24`). Die letzte Zeile beginnt bei Offset `20` (hexadezimal)
       und enthält 4 Bytes, der Dump hat also 32 + 4 = 36 Byte. Das
       passt.

    **Datei 1** hat nur 32 Byte statt 36: Es fehlen die letzten 4 Byte,
    die Temperatur des dritten Messwerts. Der Kopf verspricht 3
    Messwerte, gelesen werden können aber nur 2 vollständige. Das Laden
    meldet `FEHLER_LESEN`. Die Datei wurde abgeschnitten, zum Beispiel
    durch einen Absturz beim Schreiben.

    **Datei 2** hat die richtige Größe, aber die Kennung lautet
    `4D 57 4B 00`, also `MWK` statt `MWL`. Die Prüfung der Kennung
    schlägt an (`FEHLER_KENNUNG`). Ein einzelnes Byte wurde verändert
    oder die Datei gehört gar nicht zu unserem Programm.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Ein Hexdump-Tool programmieren

Programmiert ein Programm, das beim Aufruf einen Dateinamen bekommt und
die Datei im selben Format wie oben ausgibt. Pro Zeile 16 Bytes:

- links der Offset als 8-stellige Hexadezimalzahl,
- in der Mitte die Bytes als zweistellige Hexadezimalzahlen,
- rechts die Zeichen dazu, nicht druckbare Zeichen (kleiner als 32 oder
  größer als 126) als Punkt.

Die letzte Zeile ist meist kürzer. Die Spalte rechts soll trotzdem
ausgerichtet bleiben. Testet das Tool mit der `messwerte.dat` aus der
Übung und vergleicht mit dem Hex-Editor. Ihr dürft die KI für die
Code-Erzeugung einsetzen, prüft aber jede Zeile gegen den Hex-Editor.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil B anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-08/code/aufg-49-hexdump.c"
    ```

    1. `fread` liefert die Anzahl der tatsächlich gelesenen Bytes. In
       der letzten Zeile ist sie kleiner als 16, und bei 0 ist die
       Datei zu Ende.
    2. `%08X` gibt den Offset hexadezimal aus, mit führenden Nullen auf 8
       Stellen.
    3. Fehlen Bytes in der letzten Zeile, füllen Leerzeichen die Lücke,
       damit die Zeichenspalte ausgerichtet bleibt.
    4. Der Operator `? :` entscheidet pro Byte: druckbares Zeichen oder
       Punkt.

    Ein Hexdump ist bei jeder Datei möglich, ihr müsst ihr Format dafür
    nicht kennen. Das Tool arbeitet byteweise und kennt weder Datensätze
    noch Dateikopf.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil C — Sicher speichern

Euer Logger aus der Übung hat ein Problem: `messwerteSpeichern` öffnet die
Datei mit `"wb"`, und dabei wird der alte Inhalt **sofort** gelöscht. Bricht
das Programm danach ab (Absturz, Stromausfall), sind die alten Daten weg
und die neue Datei ist unvollständig.

Die Idee zum sicheren Speichern:

1. Den neuen Inhalt zuerst in eine **temporäre Datei** schreiben, zum
   Beispiel `messwerte.tmp`. Die alte Datei bleibt dabei unberührt.
2. Prüfen, ob alles geklappt hat (Rückgabewerte von `fwrite` und
   `fclose`). Wenn nicht, die temporäre Datei mit `remove` wieder
   löschen und den Fehler melden.
3. Erst wenn die neue Datei komplett und fehlerfrei geschrieben ist, die
   alte mit `remove` löschen und die temporäre mit `rename` auf den
   richtigen Namen umbenennen.

Bricht das Programm in Schritt 1 oder 2 ab, ist die alte Datei noch
vollständig da. Unter Windows überschreibt `rename` keine bestehende
Datei, deshalb muss die alte vorher mit `remove` gelöscht werden. Dabei
bleibt ein sehr kleines Zeitfenster zwischen `remove` und `rename`.
Professionelle Systeme schließen auch das, für unsere Zwecke reicht das
Verfahren.

Baut das in `messwerteSpeichern` aus Schritt 4 der Übung ein. Testet:
Fügt probehalber vor dem `remove` der alten Datei ein `exit(1);` ein.
Danach muss die alte `messwerte.dat` unverändert vorhanden sein.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil C anzeigen"
    ```c linenums="1" hl_lines="8 81 91-94 96-98"
    --8<-- "02-theoriephase/termin-08/code/aufg-49-sicher-speichern.c"
    ```

    1. Die neue Fassung entsteht in der temporären Datei, die alte
       `messwerte.dat` bleibt unberührt.
    2. Ist das Schreiben gescheitert, wird die unvollständige temporäre
       Datei entfernt, die alte Datei bleibt gültig.
    3. Der Rückgabewert von `remove` wird hier bewusst ignoriert: Beim
       allerersten Speichern gibt es noch keine alte Datei, das ist kein
       Fehler.
    4. `rename` macht aus der temporären Datei die neue
       `messwerte.dat`. Scheitert das, wird der Fehler gemeldet und nicht
       versteckt.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil D — Kurze Reflexion

Haltet 2 bis 3 kurze Statements fest (z. B. als Kommentar am Anfang
eurer `main.c`): Wie habt ihr die Angaben und den Code der KI heute
überprüft, zum Beispiel den Hexdump oder das sichere Speichern (mit
simuliertem Abbruch)? Was habt ihr ungeprüft
übernommen, wo hat sich die KI geirrt, und was bedeutet das für euer
Vertrauen in ihre Antworten? Bringt eure Statements in die
Abschlussdiskussion zur Lerneinheit mit.
