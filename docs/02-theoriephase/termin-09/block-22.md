---
typ: theoriephase-block
termin: 9
block_id: "22"
datum: "2026-12-16"
kurztitel: "Dynamische Speicherallokierung"
thema: "Dynamische Speicherallokierung"
lernziele:
  - "Ihr könnt mit malloc, calloc, realloc und free Speicher zur Laufzeit anfordern, vergrößern und wieder freigeben."
  - "Ihr könnt ein Array passender Größe erst zur Laufzeit anlegen, nachdem die Anzahl der Elemente aus einer Datei bekannt ist."
  - "Ihr könnt begründen, wer für das free zuständig ist, wenn eine Funktion allokierten Speicher zurückgibt."
musterloesungen_sichtbar: true
ki_einsatz: stufe_3_pflicht_reflexion
clean_code:
  - "Wer allokiert, gibt frei"
bearbeitungsstatus: in-arbeit
publish_date: "2026-12-16"
---

# Dynamische Speicherallokierung (16.12.2026)

## Übung { .modus-uebung }

### Worum geht es?

In Block 19 hatte euer Lager die feste Größe `MAX_TEILE`: Das Array musste
so groß sein, dass auf jeden Fall alles hineinpasste, auch wenn in der
Datei nur drei Teile standen. Heute lernt ihr, Speicher erst **zur
Laufzeit** anzufordern, wenn das Programm weiß, wie viel es braucht.

!!! abstract "Lernziele"
    - Ihr könnt mit `malloc`, `calloc`, `realloc` und `free` Speicher zur
      Laufzeit anfordern, vergrößern und wieder freigeben.
    - Ihr könnt ein Array passender Größe erst zur Laufzeit anlegen,
      nachdem die Anzahl der Elemente aus einer Datei bekannt ist.
    - Ihr könnt begründen, wer für das `free` zuständig ist, wenn eine
      Funktion allokierten Speicher zurückgibt.

### Kurzer Rückblick <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Kurzer Rückblick" }

1\. Was gibt `fopen` zurück, wenn die Datei nicht geöffnet werden kann, und
was folgt daraus für euren Code?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    `fopen` gibt dann `NULL` zurück. Der Rückgabewert muss geprüft
    werden, bevor man mit dem Dateizeiger arbeitet, sonst stürzt das
    Programm beim ersten Zugriff ab. Genau dasselbe gilt heute für
    `malloc`: Auch wenn nicht genug Speicher da ist, liefert es `NULL`.
<!-- MUSTERLOESUNG-ENDE -->

2\. Eine Funktion bekommt ein Array als Parameter. Warum muss man ihr
zusätzlich die Anzahl der Elemente übergeben?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Beim Aufruf bekommt die Funktion nur einen Pointer auf das erste
    Element. Wie viele Elemente es gibt, weiß sie nicht, `sizeof` liefert
    in der Funktion nur die Größe des Pointers. Bei dynamisch angelegtem
    Speicher gibt es ohnehin nur den Pointer: Die Anzahl der Elemente
    müssen wir selbst festhalten.
<!-- MUSTERLOESUNG-ENDE -->

---

### Schritt 1: Reminder — malloc, calloc, realloc und free <span class="zeitangabe">ca. 11 Min.</span> { data-toc-label="Schritt 1: Reminder — malloc, calloc, realloc und free" }

Die vier Funktionen kennt ihr aus dem Vorbereitungsvideo. Alle stehen in
`stdlib.h`:

- `malloc(Bytes)` fordert Speicher an. Der Inhalt ist **unbestimmt**.
- `calloc(Anzahl, Größe)` fordert Speicher für `Anzahl` Elemente an und
  füllt ihn mit **Nullen**.
- `realloc(Zeiger, neueGröße)` ändert die Größe eines bereits angeforderten
  Speicherbereichs. Der bisherige Inhalt bleibt erhalten, der Bereich kann
  dabei an eine andere Stelle im Speicher verschoben werden.
- `free(Zeiger)` gibt den Speicher wieder zurück.

Alle drei Anforderungen liefern `NULL`, wenn nicht genug Speicher da ist.
Der so angeforderte Speicher liegt im **Heap**, einem eigenen
Speicherbereich: Anders als lokale Variablen verschwindet er nicht am Ende
einer Funktion, sondern bleibt bis zum `free` bestehen. Wächst die
Datenmenge, muss auch ein Array mitwachsen können, dafür gibt es
`realloc`.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-09/code/live-22-1-malloc-calloc-realloc.c"
    ```

    1. Die Größe wird in Byte angegeben: Anzahl der Elemente mal
       `sizeof` eines Elements.
    2. Wie bei `fopen` muss geprüft werden, ob die Anforderung geklappt
       hat.
    3. Der Inhalt ist unbestimmt: Hier steht, was früher an dieser
       Stelle im Speicher lag. Darauf darf man sich nie verlassen, das
       Auslesen dient hier nur zur Anschauung. Im Debug-Build von Visual
       Studio steht überall derselbe auffällige Wert (z. B. -842150451),
       im Release-Build anderer Zufall.
    4. `free` gibt den Speicher zurück. Danach darf über diesen Pointer
       nicht mehr zugegriffen werden.
    5. `calloc` bekommt Anzahl und Elementgröße getrennt und füllt den
       Speicher mit Nullen.
    6. `realloc` liefert die (möglicherweise neue) Adresse des
       vergrößerten Bereichs. Das Ergebnis geht zunächst in einen
       **eigenen** Pointer.
    7. Ist `realloc` gescheitert, ist der alte Bereich weiterhin gültig
       und über `werte` erreichbar, wir können ihn also noch freigeben.
    8. Erst nach der Prüfung wird der neue Pointer übernommen. Die
       ersten `anzahl` Werte sind dabei erhalten geblieben, der neue
       Bereich dahinter ist unbestimmt.

Startet das Programm und gebt zum Beispiel `3` ein. Ihr seht dann bei
`malloc` drei beliebige Zahlen, bei `calloc` dreimal `0` und bei
`realloc` die Werte `0 1 4 9 16 25`.

!!! warning "realloc immer über einen temporären Pointer"
    Schreibt das Ergebnis von `realloc` niemals direkt in den Pointer, der
    auf den bisherigen Speicher zeigt, also nicht
    `werte = realloc(werte, ...)`. Schlägt `realloc` fehl, liefert es
    `NULL`, und dieses `NULL` überschreibt dann den einzigen Pointer auf
    den alten Speicher. Der alte Bereich ist weiterhin belegt, aber
    niemand kann ihn mehr freigeben: ein **Speicherleck**. Deshalb: erst
    in einen temporären Pointer schreiben, auf `NULL` prüfen und
    **danach** übernehmen.

---

### Das Beispiel: Ersatzteile aus einer Datei laden <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Das Beispiel: Ersatzteile aus einer Datei laden" }

In Block 19 stand die Teileliste in einer CSV-Datei, im Programm aber in
einem Array fester Größe. Da wir nicht wussten, wie viele Teile in der
Datei stehen, musste es für 200 Teile reichen, auch wenn nur drei
darin standen. Besser: erst die Anzahl aus der Datei lesen und dann ein
Array genau dieser Größe anlegen, **zur Laufzeit**.

Dafür bekommt die Datei in der ersten Zeile die Anzahl der Teile
([ersatzteile.csv](code/ersatzteile.csv){: download="ersatzteile.csv" }
herunterladen und im Projektordner ablegen):

```text
4
1042;Zahnradsatz;12
2310;Dichtungsring;48
1187;Lagerbuchse;25
3056;Antriebsriemen;7
```

Alles andere bleibt bewusst minimal: kein Menü, keine Suche, kein
Schreiben, nur Laden und Ausgeben.

---

### Schritt 2: Genau so viel Speicher wie nötig <span class="zeitangabe">ca. 12 Min.</span> { data-toc-label="Schritt 2: Genau so viel Speicher wie nötig" }

Das Programm liest die Anzahl aus der ersten Zeile, legt mit `malloc` ein
Array genau dieser Größe an, liest die Teile ein, gibt sie aus und
schließt mit `free` ab.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-09/code/live-22-2-teile-dynamisch.c"
    ```

    1. Die erste Zeile enthält die Anzahl der Teile. `atoi` wandelt den
       Text dieser Zeile in eine Zahl um (bekannt aus Termin 4).
    2. Jetzt, zur Laufzeit, ist die Anzahl bekannt: Der Speicher wird für
       genau `anzahl` Teile angefordert.
    3. `teile` ist ein Pointer, lässt sich aber wie ein Array mit
       `teile[i]` ansprechen. Der restliche Code zum Einlesen ist
       derselbe wie in Block 19: `%29[^;]` liest Text bis zum nächsten
       Semikolon, höchstens 29 Zeichen.
    4. Der Vergleich zeigt, wie viel Speicher ein Array fester Größe
       verschwendet hätte.
    5. Der Speicher wird nicht mehr gebraucht und deshalb zurückgegeben.

---

### Schritt 3: Allokieren in einer Funktion <span class="zeitangabe">ca. 13 Min.</span> { data-toc-label="Schritt 3: Allokieren in einer Funktion" }

!!! tip "Clean Code: Wer allokiert, gibt frei"
    Wer Speicher allokiert, ist dafür verantwortlich, dass er genau
    einmal wieder freigegeben wird. Gibt eine Funktion allokierten
    Speicher zurück, geht diese Verantwortung auf den **Aufrufer** über.
    Das gehört als Kommentar an den Funktionskopf, denn dem Pointer sieht
    man nicht an, ob jemand `free` aufrufen muss. Praktisch heißt das:
    Zu jedem `malloc` oder `calloc` gehört genau ein `free` an einer
    klar erkennbaren Stelle. „Aufrufer“ ist dabei die Funktion, die eine
    andere Funktion aufruft, hier `main`.

Das Laden soll jetzt wiederverwendbar in eine Funktion. Sie gibt das
angelegte Array zurück, das ein lokales Array nicht könnte: Ein lokales
Array verschwindet am Ende der Funktion, dynamisch angeforderter Speicher
bleibt dagegen bis zum `free` bestehen.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-09/code/live-22-3-teile-laden-funktion.c"
    ```

    1. Der Kommentar dokumentiert die Verantwortung: Das zurückgegebene
       Array muss vom Aufrufer freigegeben werden. Die Anzahl der Teile
       kommt über den Pointer-Parameter `anzahl` zum Aufrufer zurück.
    2. `NULL` heißt hier: Laden fehlgeschlagen, weil die Datei fehlt oder
       der Speicher nicht reicht. Zur Vereinfachung genügt das,
       Fehlercodes wie in Block 20 wären der nächste Ausbau.
    3. Genau ein `free`, dort, wo das Array nicht mehr gebraucht wird.
    4. Das Array wird in der Funktion angelegt und lebt nach ihrer
       Rückkehr weiter.
    5. Mit der Rückgabe des Pointers geht die Verantwortung für das
       `free` an den Aufrufer über.

Beachtet, was hier **nicht** vorkommt: Wir gehen davon aus, dass die
Datei fehlerfrei ist. Was passiert, wenn mitten im Einlesen etwas
schiefgeht, ist Thema im betreuten Selbststudium.

---

### Zusammenfassung <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Zusammenfassung" }

- **Speicher zur Laufzeit:** `malloc` (Inhalt unbestimmt), `calloc`
  (mit Nullen gefüllt), `realloc` (Größe ändern) und `free` (zurückgeben).
  Jede Anforderung kann `NULL` liefern und wird geprüft.
- **realloc:** Das Ergebnis immer erst in einen temporären Pointer
  schreiben, prüfen und dann übernehmen.
- **Passende Größe:** Ist die Anzahl der Elemente erst zur Laufzeit
  bekannt, wird das Array dann angelegt, ohne ungenutzten Platz.
- **Wer allokiert, gibt frei:** Zu jedem `malloc` gehört genau ein
  `free`. Gibt eine Funktion allokierten Speicher zurück, ist der Aufrufer
  verantwortlich, und das steht im Kommentar am Funktionskopf.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

!!! abstract "Lernziele"
    - Ihr könnt Entwicklungsvorschläge für Code mit dynamischem Speicher
      bewerten und ein Speicherleck auf einem Fehlerpfad erkennen.
    - Ihr könnt eine Struktur mit einem Zeiger auf dynamisch angelegten
      Speicher erzeugen und vollständig wieder freigeben.

Ab heute ist KI-Unterstützung auch zur Code-Generierung regulär erlaubt,
siehe [KI im Kurs](../../ki-nutzung.md). Aufgabe 50 bearbeitet ihr
bewusst ohne Rechner und ohne KI: Genau das Lesen und Beurteilen von Code,
den ein anderer (oder eine KI) geschrieben hat, ist die Fähigkeit, die ihr
braucht, um Vorschläge einer KI zu überprüfen. Würde die KI sie beurteilen,
würdet ihr diese Fähigkeit nicht üben.

### Aufgabe 50: Den nächsten Entwicklungsschritt bewerten

Gegeben ist der Stand aus der Übung:

```c linenums="1"
--8<-- "02-theoriephase/termin-09/code/vorgabe-50-teile-laden.c"
```

Lest den Code in Ruhe durch, bevor ihr weiterlest.

**Der nächste geplante Schritt:** Die Funktion `teileLaden` soll die Datei
prüfen. Eine Zeile gilt als fehlerhaft, wenn `sscanf` nicht alle drei Felder
lesen konnte oder wenn die Datei weniger Zeilen hat, als die erste Zeile
verspricht. Bei einer fehlerhaften Zeile soll das Laden abbrechen, die
Funktion soll `NULL` zurückgeben und der Aufrufer meldet, dass das Laden
fehlgeschlagen ist.

Zwei Entwicklungsvorschläge liegen vor:

=== "Vorschlag A"
    Ich prüfe in der Einlese-Schleife bei jeder Zeile, ob `fgets` eine
    Zeile geliefert hat und ob `sscanf` genau drei Felder gelesen hat.
    Ist das nicht der Fall, gebe ich eine Warnung mit der Zeilennummer aus,
    gebe das bereits angelegte Array mit `free` frei, setze `teile` auf
    `NULL` und verlasse die Schleife mit `break`. So bleibt am Ende der
    Funktion genau eine Stelle, an der die Datei geschlossen und das
    Ergebnis zurückgegeben wird.

=== "Vorschlag B"
    Ich prüfe in der Einlese-Schleife bei jeder Zeile, ob `fgets` eine
    Zeile geliefert hat und ob `sscanf` genau drei Felder gelesen hat.
    Ist das nicht der Fall, gebe ich eine Warnung mit der Zeilennummer aus,
    schließe die Datei mit `fclose` und gebe sofort `NULL` zurück. Dadurch
    arbeitet der Aufrufer nie mit unvollständigen Daten, und die Funktion
    bleibt kurz, weil nur dieser eine frühe `return` ergänzt werden muss.

**Aufgabe:** Welcher Vorschlag ist besser, und warum? Fragt euch dabei,
was vor dem Abbruch schon angelegt wurde und wer es danach noch freigeben
kann. Ein Beispiel für eine fehlerhafte Datei: Sie beginnt mit der Zahl
`4`, die zweite Teilezeile ist aber unvollständig.

```text
4
1042;Zahnradsatz;12
2310;Dichtungsring
1187;Lagerbuchse;25
3056;Antriebsriemen;7
```

Die Zeilennummer in der Warnung ergibt sich aus der Schleifenvariable `i`:
Das Teil mit dem Index `i` steht in Zeile `i + 2` der Datei, denn Zeile 1
enthält die Anzahl. Notiert eure Begründung in drei bis vier Sätzen, am
besten mit einer kleinen Skizze, welche Variablen und welcher Speicher beim
Abbruch existieren. So könnt ihr sie mit der Musterlösung vergleichen.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Vorschlag A ist besser. Beide Vorschläge prüfen die Zeilen
    gleichermaßen und liefern im Fehlerfall `NULL`. Der Unterschied liegt
    darin, was **zusätzlich** nötig ist: Beim Abbruch ist das Array schon
    mit `malloc` angelegt, im Heap. Vorschlag B schließt zwar die Datei,
    vergisst aber `free(teile)`.

    Zum Zeitpunkt des `return NULL` existieren in `teileLaden` noch die
    lokalen Variablen `datei`, `zeile`, `teile` und die Laufvariable. Der
    Pointer `teile` zeigt auf das Array für 4 Teile, in dem erst das erste
    gefüllt ist. Mit dem `return` verschwinden die lokalen Variablen, also
    auch `teile`, der Speicher selbst bleibt aber belegt. Zurückgegeben wird
    `NULL`, der Aufrufer hat also keinen Pointer auf den Speicher und kann
    ihn nicht freigeben. Niemand im Programm kann ihn mehr erreichen: ein
    **Speicherleck**. Bei jedem fehlerhaften Laden geht ein weiteres Array
    verloren.

    Der Fehler fällt leicht durch, weil ein früher `return` bisher nur
    bedeutete, aufzuhören. Sobald Speicher im Spiel ist, muss **jeder**
    Ausgang einer Funktion, auch der Fehlerpfad, alles freigeben, was die
    Funktion bis dahin allokiert hat. Vorschlag A tut das und bündelt den
    Ausgang an einer Stelle.

    ```c linenums="1" hl_lines="53-55 57-63"
    --8<-- "02-theoriephase/termin-09/code/aufg-50-teile-laden-geprueft.c"
    ```

    1. Der Speicher ist schon angelegt, also wird er vor dem Abbruch
       freigegeben.
    2. `teile` wird auf `NULL` gesetzt: Das ist zugleich der Rückgabewert
       für den Aufrufer und verhindert, dass ein bereits freigegebener
       Pointer zurückgegeben wird.
    3. `break` verlässt die Schleife. Danach wird die Datei an der einen
       Stelle geschlossen und `teile` zurückgegeben.
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 51: Messreihe als Struktur mit dynamischem Speicher

Eine Messreihe besteht aus einer Nummer, der Anzahl ihrer Werte und den
Werten selbst. Wie viele Werte es gibt, steht erst zur Laufzeit fest.
Deshalb enthält die Struktur nur einen **Zeiger** auf die Werte, und die
Werte liegen in dynamisch angelegtem Speicher.

Die Struktur `Messreihe` hat drei Member: `int id`, `int anzahl` und
`double *werte`.

Ihr schreibt drei Funktionen:

- `Messreihe *messreiheErzeugen(int id, int anzahl)` legt die Struktur
  **und** das Array für die Werte an (mit Nullen gefüllt). Bei `anzahl <= 0`
  oder wenn Speicher fehlt, liefert sie `NULL`.
- `void messreiheLoeschen(Messreihe *reihe)` gibt alles wieder frei.
- `double messreiheMittelwert(const Messreihe *reihe)` liefert den
  Mittelwert der Werte.

#### Teil A — Speicherskizze (ohne Rechner und zuerst ohne KI)

Skizziert, was nach `messreiheErzeugen(1, 5)` im Speicher steht: Welche
Zeiger gibt es, worauf zeigen sie? In welcher Reihenfolge müssen die
beiden Speicherbereiche freigegeben werden, und was passiert bei der
umgekehrten Reihenfolge? Und wer ruft `messreiheLoeschen` auf, und warum
ist das nicht Aufgabe von `messreiheErzeugen`? Eine eigene Skizze ist
wichtig, weil ihr damit den Code prüft, den ihr später von der KI
bekommt.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    Es gibt zwei getrennte Speicherbereiche auf dem Heap: die Struktur
    `Messreihe` (`id`, `anzahl`, `werte`) und das Array mit 5 `double`.
    Der Pointer `reihe` zeigt auf die Struktur, deren Member `werte`
    zeigt auf das Array.

    Freigegeben wird **zuerst das Array** (`free(reihe->werte)`), **dann
    die Struktur** (`free(reihe)`). Würde man zuerst `free(reihe)`
    aufrufen, wäre der Zeiger auf das Array in der freigegebenen
    Struktur nicht mehr lesbar. Man könnte das Array nicht mehr
    freigeben, und es bliebe als Speicherleck zurück.

    `messreiheLoeschen` ruft der **Aufrufer** auf, hier `main`, sobald die
    Messreihe nicht mehr gebraucht wird. `messreiheErzeugen` kann das nicht
    übernehmen, denn sie gibt die Messreihe ja gerade zurück, damit sie
    weiterlebt. Mit dem Rückgabewert geht die Verantwortung für die
    Freigabe an den Aufrufer über.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Umsetzen

Schreibt die drei Funktionen. Ausgangspunkt ist dieser Rahmen mit einem
fertigen `main`. Wenn eure Funktionen stimmen, gibt das Programm
`Messreihe 1: Mittelwert 21.00` aus. Ihr dürft die KI für die
Code-Erzeugung einsetzen. Prüft aber jede Zeile gegen eure Skizze aus
Teil A.

```c linenums="1"
--8<-- "02-theoriephase/termin-09/code/vorgabe-51-messreihe-rahmen.c"
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil B anzeigen"
    ```c linenums="1" hl_lines="39-40 42-44 46-51 53-55 60-61 63-64 69 71-72 74"
    --8<-- "02-theoriephase/termin-09/code/aufg-51-messreihe.c"
    ```

    1. Der Zeiger auf das dynamisch angelegte Array der Werte, die Anzahl
       steht daneben in `anzahl`.
    2. Zugriff in zwei Schritten: `reihe->werte` ist der Zeiger auf das
       Array, `[i]` das einzelne Element.
    3. Erste Allokierung: die Struktur selbst.
    4. Zweite Allokierung: das Array der Werte, mit Nullen gefüllt.
    5. Scheitert die zweite Allokierung, muss die erste vor dem Abbruch
       freigegeben werden, sonst entsteht ein Speicherleck.
    6. Erst das Array, dann die Struktur. Danach darf nicht mehr auf
       `reihe` zugegriffen werden.

    Das ist eine von mehreren möglichen Lösungen, eure darf anders
    aussehen und trotzdem gut sein. Der Kommentar vor den Funktionen
    hält fest, wer freigibt (Clean Code: Wer allokiert, gibt frei).
    `messreiheLoeschen` prüft auf `NULL`, damit sich die Funktion
    auch nach einer fehlgeschlagenen Erzeugung gefahrlos aufrufen lässt.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil C — Wenn eine Allokierung scheitert (optional)

Schlägt in `messreiheErzeugen` die zweite Allokierung fehl, ist die
Struktur schon angelegt. Geht jeden Pfad eurer Funktion durch, auf dem
`NULL` zurückgegeben wird: Ist dort alles freigegeben, was bis dahin
allokiert wurde? Das kennt ihr aus Aufgabe 50.

Zum Testen ersetzt ihr vorübergehend den Aufruf
`calloc(anzahl, sizeof(double))` durch `calloc(anzahl, (size_t)-1)`.
`(size_t)-1` ist die größte Zahl, die ein Speichermaß in C darstellen
kann. `anzahl` Elemente dieser Größe passen nirgends hinein, `calloc`
erkennt das und liefert `NULL`. (Habt ihr `malloc` verwendet, versucht es
entsprechend mit `malloc((size_t)-1)`.) Eure Funktion muss dann sauber
`NULL` zurückgeben, und im `main` erscheint die Fehlermeldung.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil C anzeigen"
    Zwei Pfade geben `NULL` zurück, bei denen schon etwas angelegt sein
    kann. Wenn die erste Allokierung scheitert, ist noch nichts angelegt, es
    gibt nichts freizugeben. Wenn die zweite scheitert, ist die Struktur
    schon da und wird mit `free(reihe)` freigegeben (Marker 5 in der
    Musterlösung oben). Mit dem Testtrick läuft genau dieser Pfad. Das
    Programm meldet, dass die Messreihe nicht erzeugt werden konnte, und
    hinterlässt keinen belegten Speicher. Danach den Testtrick wieder
    entfernen.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil D — Kurze Reflexion

Haltet 2 bis 3 kurze Statements fest (z. B. als Kommentar am Anfang
eurer `main.c`): Wo hat die KI euch beim Umgang mit dem Speicher
geholfen? Hat sie ein `free` vergessen, die falsche Reihenfolge gewählt
oder einen Fehlerpfad übersehen, und woran habt ihr das gemerkt? Eure
Statements werden am Ende des Termins gemeinsam besprochen.
