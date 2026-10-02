---
typ: theoriephase-block
termin: 8
block_id: "19"
datum: "2026-12-09"
kurztitel: "Dateien lesen und schreiben"
thema: "Dateibearbeitung"
lernziele:
  - "Ihr könnt mit FILE-Pointern und den Funktionen fopen, fclose, fgets und fprintf Daten dauerhaft in einer Textdatei speichern und wieder einlesen."
  - "Ihr könnt mit fseek und fgetpos innerhalb einer Datei navigieren, zum Beispiel um ihre Größe zu ermitteln."
  - "Ihr könnt eine bestehende Datenstruktur so erweitern, dass sie ihren Zustand über einen Programmneustart hinweg behält, und dabei begründete Entwurfsentscheidungen treffen."
musterloesungen_sichtbar: true
ki_einsatz: stufe_3_pflicht_reflexion
clean_code: []
bearbeitungsstatus: in-arbeit
publish_date: "2026-12-09"
---

# Dateien lesen und schreiben (09.12.2026)

## Übung { .modus-uebung }

### Worum geht es?

Euer Zwischenprojekt-Mockup aus Termin 7 hatte einen klaren Schönheitsfehler:
Sobald ihr es beendet habt, war die ganze Teileliste wieder weg. Heute
schließt ihr genau diese Lücke. Aus den Vorbereitungsvideos kennt ihr
bereits die wichtigsten Funktionen für die Dateibearbeitung in C — heute
wendet ihr sie an, zuerst an einem Minimalbeispiel, dann direkt an eurem
Projekt.

!!! abstract "Lernziele"
    - Ihr könnt mit FILE-Pointern und den Funktionen `fopen`, `fclose`,
      `fgets` und `fprintf` Daten dauerhaft in einer Textdatei speichern
      und wieder einlesen.
    - Ihr könnt mit `fseek` und `fgetpos` innerhalb einer Datei
      navigieren, zum Beispiel um ihre Größe zu ermitteln.
    - Ihr könnt eine bestehende Datenstruktur so erweitern, dass sie
      ihren Zustand über einen Programmneustart hinweg behält, und dabei
      begründete Entwurfsentscheidungen treffen.

### Kurzer Rückblick <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Kurzer Rückblick" }

1\. Was war am Zwischenprojekt-Mockup aus Termin 7 unbefriedigend, sobald
ihr das Programm beendet habt?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Alle eingetragenen Teile waren weg. Das Mockup hat nichts dauerhaft
    gespeichert, weil das im Auftrag bewusst noch ausgeklammert war.
<!-- MUSTERLOESUNG-ENDE -->

2\. Was macht `fopen`, und was gibt die Funktion zurück, wenn das Öffnen
fehlschlägt (z. B. weil die Datei noch nicht existiert)?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    `fopen` öffnet eine Datei und liefert einen Dateizeiger (`FILE *`)
    darauf zurück, über den alle weiteren Datei-Funktionen (`fprintf`,
    `fgets`, `fclose`, ...) arbeiten. Schlägt das Öffnen fehl, gibt
    `fopen` `NULL` zurück — das sollte vor der weiteren Nutzung immer
    geprüft werden.
<!-- MUSTERLOESUNG-ENDE -->

3\. Wofür braucht man `fclose`, und was kann passieren, wenn man es
vergisst?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    `fclose` schließt die Datei und sorgt dafür, dass alle noch
    zwischengespeicherten Daten tatsächlich geschrieben werden. Vergisst
    man es, können Änderungen verloren gehen, und die Datei bleibt unter
    Umständen für andere Programme gesperrt.
<!-- MUSTERLOESUNG-ENDE -->

---

### Schritt 1: Kurzer Reminder — Datei schreiben und lesen <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Schritt 1: Kurzer Reminder — Datei schreiben und lesen" }

Nur zur Auffrischung, die Funktionen kennt ihr schon aus den Videos: Eine
Datei anlegen und beschreiben, dann wieder öffnen und zeilenweise
einlesen.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-08/code/live-19-1-reminder-schreiben-lesen.c"
    ```

    1. Unterdrückt die Visual-Studio-Warnung, dass `fopen` als "unsicher"
       gilt (wie schon bei `localtime` in Termin 6) — Standard-C kennt
       diese Warnung nicht.
    2. Öffnen zum Schreiben (`"w"`) legt die Datei an bzw. überschreibt
       sie, falls sie schon existiert.
    3. Erneutes Öffnen, diesmal zum Lesen (`"r"`).
    4. Existiert die Datei nicht oder lässt sie sich nicht öffnen, ist
       `datei` jetzt `NULL`.
    5. `fgets` liest Zeile für Zeile, bis die Datei zu Ende ist (dann
       liefert es `NULL`) — neu gegenüber der Konsoleneingabe mit
       `scanf_s`.

---

### Schritt 2: Dateigröße ermitteln <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Schritt 2: Dateigröße ermitteln" }

Mit `fseek` lässt sich innerhalb einer Datei an eine bestimmte Position
springen, mit `fgetpos` die aktuelle Position auslesen. Kombiniert damit
lässt sich auch die Größe einer Datei bestimmen: ans Ende springen, dann
die dortige Position abfragen.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-08/code/live-19-2-dateigroesse.c"
    ```

    1. `fseek` springt an die angegebene Position. `SEEK_END` steht für
       das Dateiende, der Offset `0` bedeutet "genau dort, keine Bytes
       davor".
    2. `fgetpos` schreibt die aktuelle Position in `groesse` — der Typ
       dafür ist `fpos_t`.
    3. Da `fpos_t` unter Windows schlicht eine ganze Zahl ist, lässt sie
       sich direkt mit `%lld` ausgeben. Das ist eine Windows-Besonderheit,
       keine Garantie des C-Standards.

**Randbemerkung:** `fseek` und `fgetpos` setzt ihr selten direkt für die
Dateigröße ein — in der Praxis reicht meist, die Datei einmal komplett zu
lesen (wie in Schritt 1). Die Funktionen sind aber nützlich, sobald ihr
innerhalb einer Datei gezielt an eine Position springen wollt, zum
Beispiel zum Anhängen.
{: .hinweis-klein }

---

### Aufgabe 47: CSV-Persistenz für die Ersatzteilverwaltung <span class="zeitangabe">ca. 36 Min.</span> { data-toc-label="Aufgabe 47: CSV-Persistenz für die Ersatzteilverwaltung" }

Jetzt übertragen wir das auf euer Projekt. Ausgangspunkt ist eine auf das
Nötigste reduzierte Fassung des Zwischenprojekt-Programms: nur Teil
eintragen, alle Teile anzeigen, Beenden — Suche, Bestand ändern und die
Kommandozeilenparameter sind für diese Übung bewusst entfernt.

=== "main.c"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-08/code/vorgabe-47-ersatzteilverwaltung/main.c"
    ```

=== "teileverwaltung.h"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-08/code/vorgabe-47-ersatzteilverwaltung/teileverwaltung.h"
    ```

=== "teileverwaltung.c"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-08/code/vorgabe-47-ersatzteilverwaltung/teileverwaltung.c"
    ```

Die Teile sollen künftig in einer CSV-Datei gespeichert werden, damit sie
einen Neustart überleben.

---

#### Teil A — Entwurf klären

Bevor wir Code schreiben, klären wir gemeinsam ein paar Fragen, die die
Struktur der Lösung beeinflussen.

1\. Sollte die Datei die ganze Zeit offen gehalten werden, oder nur kurz
zum Lesen/Schreiben geöffnet und anschließend wieder geschlossen werden?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Kurz öffnen, den Vorgang erledigen, sofort wieder schließen ist
    robuster: Bei einem Programmabsturz gehen so keine noch
    ungeschriebenen Daten verloren, und die Datei blockiert nicht
    dauerhaft für andere Programme.
<!-- MUSTERLOESUNG-ENDE -->

2\. Sollte der Inhalt der Datei zusätzlich in einem Array im Programm
gespiegelt werden?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Ja. Nur über die Datei zu suchen oder anzuzeigen wäre langsam und
    umständlich — `bsearch` funktioniert nicht auf einer Datei. Die
    Datei dient nur als dauerhafte Ablage, das vertraute Array bleibt
    die schnelle Arbeitskopie im Speicher und wird beim Programmstart
    einmal komplett aus der Datei befüllt.
<!-- MUSTERLOESUNG-ENDE -->

3\. Müssen die Einträge in der Datei sortiert sein?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Nein. Sortierung wird nur für Anzeige und Suche im Array gebraucht
    (wie im Zwischenprojekt), nicht für die Datei selbst. Die Datei kann
    einfach in der Reihenfolge bleiben, in der die Teile eingetragen
    wurden.
<!-- MUSTERLOESUNG-ENDE -->

4\. Wie ergänzt man eine Zeile in der Datei, wenn ein neues Teil
eingetragen wird — insbesondere wenn es zwischen zwei bestehenden Zeilen
stehen müsste?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Gar nicht "zwischen" zwei Zeilen — genau das vermeidet die vorherige
    Antwort: Weil die Datei nicht sortiert sein muss, hängt man die neue
    Zeile einfach ans Ende an. Eine Zeile in der Mitte einer Textdatei
    einzufügen wäre ungleich aufwendiger, dafür müsste man im Grunde die
    ganze Datei neu schreiben.
<!-- MUSTERLOESUNG-ENDE -->

5\. Was passiert, wenn die Datei beim allerersten Programmstart noch gar
nicht existiert?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    `fopen` mit `"r"` gibt dann `NULL` zurück. Das ist kein Fehlerfall,
    sondern der Normalfall beim ersten Start — das Lager bleibt dann
    einfach leer, eine Datei muss dafür nicht künstlich angelegt werden.
<!-- MUSTERLOESUNG-ENDE -->

6\. Was, wenn eine Zeile in der Datei nicht dem erwarteten Format
entspricht — zum Beispiel weil sie abgebrochen ist oder die
CSV-Struktur nicht eingehalten wurde?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Das darf das Programm weder zum Absturz bringen noch dazu, falsche
    Daten unbemerkt zu übernehmen. Wie man das konkret erkennt und
    behandelt, klärt ihr im Detail in der folgenden bS-Aufgabe — hier
    reicht die Feststellung, dass man dem Dateiinhalt nicht blind
    vertrauen darf.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Umsetzen und testen

Mit den Antworten aus Teil A ergänzen wir zwei neue Funktionen:
`teileAusDateiLaden` (beim Programmstart) und `teilAnDateiAnhaengen`
(beim Eintragen eines neuen Teils). `teilEinfuegen` selbst bleibt
unverändert und schreibt **nicht** in die Datei — sonst würde sich der
Dateiinhalt bei jedem Neustart verdoppeln, weil `teileAusDateiLaden` die
bereits gespeicherten Zeilen sonst erneut anhängen würde.

??? quote livecoding "Beispiel-Code"
    === "main.c"
        ```c linenums="1" hl_lines="24 84"
        --8<-- "02-theoriephase/termin-08/code/live-19-3-csv-persistenz/main.c"
        ```

        1. Direkt nach dem Anlegen des leeren Lagers wird
           `teileAusDateiLaden` aufgerufen — lädt den gespeicherten
           Stand, falls vorhanden.
        2. Nach erfolgreichem Eintragen wird das neue Teil zusätzlich an
           die Datei angehängt.

    === "teileverwaltung.h"
        ```c linenums="1" hl_lines="15 16"
        --8<-- "02-theoriephase/termin-08/code/live-19-3-csv-persistenz/teileverwaltung.h"
        ```

    === "teileverwaltung.c"
        ```c linenums="1" hl_lines="1 7 18-20 22-24 26-32 34-35 37-41 43-45"
        --8<-- "02-theoriephase/termin-08/code/live-19-3-csv-persistenz/teileverwaltung.c"
        ```

        1. `sscanf` liest aus dem String `zeile`, genau wie `scanf_s`
           von der Konsole liest.
        2. `datei == NULL`: Beim allerersten Start gibt es die Datei
           noch nicht (siehe Teil A, Frage 5).
        3. `fgets` liefert `NULL`, sobald die Datei zu Ende ist.
        4. Die Rückgabe von `sscanf` (wie viele Felder erfolgreich
           gelesen wurden) prüfen wir hier noch bewusst nicht — das
           kommt in der folgenden bS-Aufgabe.
        5. Nur ins Array einfügen, **nicht** erneut in die Datei
           schreiben — die Zeile steht dort ja schon.
        6. `"a"` (append) hängt an die Datei an, statt sie zu
           überschreiben.

**Testen:** Startet euer Programm, tragt ein Teil ein, beendet das
Programm und startet es erneut — das Teil sollte sofort wieder in der
Liste stehen. Schaut euch nebenbei die Datei `ersatzteile.csv` im
Projektordner an (z. B. mit einem Texteditor).
{: .hinweis-klein }

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

!!! abstract "Lernziele"
    - Ihr könnt eine bestehende Dateischnittstelle um Fehlerbehandlung
      ergänzen, sodass sie unerwarteten Dateiinhalt nicht unkommentiert
      übernimmt.
    - Ihr könnt begründen, warum eine Bestandsänderung eines bereits
      gespeicherten Teils ein komplettes Neuschreiben der Datei
      braucht, statt nur einer einzelnen geänderten Zeile.

Ab heute ist KI-Unterstützung — auch zur Code-Generierung — regulär
erlaubt, siehe [KI im Kurs](../../ki-nutzung.md). Diese Aufgabe nutzt das
bewusst aus und ist dadurch etwas umfangreicher als die bisherigen
bS-Aufgaben.

### Aufgabe 48: Bestand persistieren und Datei prüfen

Euer Programm aus der Übung speichert neue Teile dauerhaft — aber eine
**Bestandsänderung** eines bereits vorhandenen Teils (Zu- oder Abgang)
landet bisher nur im Array, nicht in der Datei. Und falls die Datei
jemals beschädigt ist (z. B. durch einen Absturz mitten im Schreiben
oder eine Zeile, die nicht dem CSV-Format entspricht), würde euer
Programm aus der Übung entweder abstürzen oder stillschweigend falsche
Daten übernehmen.

#### Teil A — Bestandsänderungen dauerhaft speichern

Überlegt euch (gerne mit KI-Unterstützung), wie sich eine
Bestandsänderung eines **bereits vorhandenen** Teils dauerhaft in der
Datei speichern lässt. Anders als beim Anhängen eines neuen Teils lässt
sich eine einzelne Zeile in einer Textdatei nicht einfach "überschreiben",
ohne die Zeilenlänge exakt gleich zu halten.

Setzt eine Lösung um (ein Menüpunkt "Bestand ändern" sowie eine passende
Dateifunktion) und testet sie: Ändert den Bestand eines Teils, beendet
das Programm, startet es neu — die Änderung muss erhalten bleiben.

---

#### Teil B — Beschädigte Dateien erkennen

Baut in das Einlesen der Datei eine Prüfung ein, die eine beschädigte
oder unvollständige Zeile erkennt (z. B. eine abgebrochene letzte Zeile
oder eine Zeile mit falscher Spaltenanzahl), diese Zeile überspringt und
eine kurze Warnung ausgibt — statt sie als falsches Teil zu übernehmen
oder das Programm abstürzen zu lassen.

Testet das gezielt: Öffnet eure `ersatzteile.csv` in einem Texteditor,
baut absichtlich eine fehlerhafte Zeile ein (z. B. eine unvollständige
letzte Zeile) und startet das Programm neu.

---

#### Teil C — Kurze Reflexion

Haltet 2 bis 3 kurze Statements fest (z. B. als Kommentar am Anfang
eurer `main.c`): Was lief bei der KI-Unterstützung heute im Vergleich
zum Zwischenprojekt anders, besser — oder vielleicht auch schlechter —
und warum? Seid darauf vorbereitet, eure Statements in der Abschlussdiskussion zu der Lerneinheit kurz darzustellen.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Ausgangspunkt ist das Ergebnis aus Teil B der Übung
    (`teileAusDateiLaden`/`teilAnDateiAnhaengen`), ergänzt um
    `teilSuchen` und `bestandAendern` aus dem Zwischenprojekt sowie zwei
    neue Bausteine: eine Funktion, die das komplette Lager in die Datei
    zurückschreibt, und eine Prüfung beim Einlesen. Das ist eine von
    mehreren möglichen Lösungen — eure Umsetzung darf anders aussehen
    und trotzdem gut sein.

    === "main.c"
        ```c linenums="1" hl_lines="23 42 64-66 98-101 103-104 106-111 113-114 116-119"
        --8<-- "02-theoriephase/termin-08/code/aufg-48-bestand-und-pruefung/main.c"
        ```

    === "teileverwaltung.h"
        ```c linenums="1" hl_lines="17 20-22 24"
        --8<-- "02-theoriephase/termin-08/code/aufg-48-bestand-und-pruefung/teileverwaltung.h"
        ```

    === "teileverwaltung.c"
        ```c linenums="1" hl_lines="31 33-37 55-64 66-67 69-70 86-91 93-95 97-99"
        --8<-- "02-theoriephase/termin-08/code/aufg-48-bestand-und-pruefung/teileverwaltung.c"
        ```

        1. `sscanf` gibt zurück, wie viele Felder es erfolgreich lesen
           konnte. Sind es nicht alle drei, ist die Zeile beschädigt
           oder unvollständig — sie wird übersprungen statt als
           (falsches) Teil übernommen zu werden.
        2. Genau diese Prüfung war in der Übung noch bewusst offen
           gelassen.
        3. `"w"` überschreibt die komplette Datei mit dem aktuellen
           Stand des Arrays — einfacher, als eine einzelne Zeile gezielt
           zu ändern.

    Für Teil A reicht es, `teilSuchen` (per `bsearch`, wie im
    Zwischenprojekt) und `bestandAendern` wiederzuverwenden und nach der
    Änderung `lagerInDateiSpeichern` aufzurufen. Für Teil B genügt die
    Prüfung des `sscanf`-Rückgabewerts — zusätzliche Prüfungen (z. B. ob
    die Teilenummer plausibel ist) sind möglich, aber für diese Aufgabe
    nicht erforderlich.
<!-- MUSTERLOESUNG-ENDE -->
