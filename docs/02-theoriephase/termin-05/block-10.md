---
typ: theoriephase-block
termin: 5
block_id: "10"
datum: "2026-11-18"
kurztitel: "Sortieralgorithmen"
thema: "Sortieralgorithmen — Quicksort (Divide-and-Conquer, Rekursion), experimenteller Komplexitätsvergleich mit Bubblesort"
lernziele:
  - "Du kannst an einem Beispiel erklären, was ein Pivot-Element ist und wie es die Elemente eines Arrays in zwei Teile trennt."
  - "Du kannst begründen, warum die Wahl des Pivot-Elements für die Korrektheit von Quicksort unerheblich ist, aber die Laufzeit beeinflusst."
  - "Du kannst erklären, wie aus dem Umsortieren um ein Pivot-Element und der anschließenden Rekursion das Prinzip Divide-and-Conquer entsteht."
  - "Du kannst die Standardfunktion qsort aus stdlib.h mit einer eigenen Vergleichsfunktion einsetzen, um ein Array nach einem gewählten Kriterium zu sortieren."
  - "Du kannst Quicksort anhand eines gegebenen Pseudocodes als rekursive Funktion in C umsetzen."
  - "Du kannst die Anzahl der Vergleiche zweier Sortieralgorithmen experimentell messen und mit ihrer theoretischen Zeitkomplexität in Beziehung setzen."
musterloesungen_sichtbar: false
ki_einsatz: stufe_0_ohne
clean_code: []
bearbeitungsstatus: in-arbeit
publish_date: "2026-11-18"
---

# Sortieralgorithmen (18.11.2026)

## Übung { .modus-uebung }

### Worum geht es?

Ihr kennt mit Bubblesort schon ein Sortierverfahren — und aus eurem
Vorbereitungsvideo den Namen **Quicksort**, der zweite große
Sortieralgorithmus dieses Kurses. Heute schaut ihr euch an, wie er
funktioniert, warum er in der Praxis so viel schneller ist als Bubblesort,
und lernt mit `qsort` eine fertige Sortierfunktion aus der
C-Standardbibliothek kennen.

!!! abstract "Lernziele"
    - Ihr könnt an einem Beispiel erklären, was ein Pivot-Element ist und
      wie es die Elemente eines Arrays in zwei Teile trennt.
    - Ihr könnt begründen, warum die Wahl des Pivot-Elements für die
      Korrektheit von Quicksort unerheblich ist, aber die Laufzeit
      beeinflusst.
    - Ihr könnt erklären, wie aus dem Umsortieren um ein Pivot-Element und
      der anschließenden Rekursion das Prinzip Divide-and-Conquer
      entsteht.
    - Ihr könnt die Standardfunktion `qsort` aus `stdlib.h` mit einer
      eigenen Vergleichsfunktion einsetzen, um ein Array nach einem
      gewählten Kriterium zu sortieren.

### Kurzer Rückblick <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Kurzer Rückblick" }

1\. Was passiert, wenn ihr ein Array an eine Funktion übergebt und diese
Funktion die Elemente verändert — und wie nennt man dieses Verhalten?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Die Funktion bekommt das Original, nicht eine Kopie — Änderungen an den
    Array-Elementen wirken sich deshalb auch außerhalb der Funktion aus.
    Man nennt das **Call by Reference**, im Gegensatz zu **Call by Value**
    bei einfachen Parametern wie `int`, wo die Funktion nur mit einer Kopie
    arbeitet.
<!-- MUSTERLOESUNG-ENDE -->

2\. Wie funktioniert Bubblesort grundsätzlich, und wie viele Durchläufe
braucht er im schlechtesten Fall für ein Array mit `n` Elementen?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Bubblesort vergleicht benachbarte Elemente von links nach rechts und
    vertauscht sie, wenn sie in der falschen Reihenfolge stehen. Nach
    jedem Durchlauf steht ein weiteres Element an seiner endgültigen
    Position. Im schlechtesten Fall sind dafür `n - 1` Durchläufe nötig.
<!-- MUSTERLOESUNG-ENDE -->

---

### Das Beispiel: Eine Zahlenreihe partitionieren <span class="zeitangabe">ca. 15 Min.</span> { data-toc-label="Das Beispiel: Eine Zahlenreihe partitionieren" }

Quicksort sortiert nicht wie Bubblesort durch viele kleine Vertauschungen,
sondern durch einen Trick: Es wählt ein **Pivot-Element** aus der Reihe und
bringt alle anderen Elemente so in eine neue Reihenfolge, dass links vom
Pivot-Element nur kleinere oder gleiche Werte stehen und rechts davon nur
größere. Diesen Schritt nennt man **Partitionieren**. Das Pivot-Element
selbst landet dabei genau an der Stelle, an der es im fertig sortierten
Array stehen wird — es muss danach nie wieder bewegt werden.

Wir partitionieren gemeinsam die Reihe `12  45  3  67  21  9` (Indizes 0
bis 5). Als Pivot-Element nehmen wir das **letzte** Element der Reihe: `9`.

**Warum die Wahl des Pivot-Elements egal ist — mit einer Einschränkung:**
Das Partitionieren funktioniert mit *jedem* Element als Pivot, die Wahl
beeinflusst also nicht, ob am Ende richtig sortiert wird — nur, *wie
gleichmäßig* die Reihe dabei geteilt wird. Ein Pivot-Element nahe der Mitte
der sortierten Reihenfolge teilt die Reihe in zwei etwa gleich große
Hälften; ein Pivot-Element, das das kleinste oder größte Element der Reihe
ist, erzeugt eine sehr ungleiche Teilung (eine Teilreihe bleibt fast leer,
die andere enthält fast alle Elemente). Das ist kein reiner Zufallsfall:
Bei diesem Pseudocode (Pivot = immer das rechte Element) tritt genau das
bei einer **bereits sortierten** oder **umgekehrt sortierten** Reihe bei
*jedem* Rekursionsschritt auf — mit spürbaren Folgen für die
Geschwindigkeit. Mehr dazu im betreuten Selbststudium.
{: .hinweis-klein }

Zwei Zeiger, `i` von links und `j` von rechts, laufen aufeinander zu:
`i` sucht (von links kommend) das erste Element, das *größer* als das
Pivot-Element ist — das gehört nicht mehr in die linke Hälfte. `j` sucht
(von rechts kommend) das erste Element, das *kleiner oder gleich* dem
Pivot-Element ist — das gehört nicht in die rechte Hälfte. Finden beide
etwas, werden diese zwei Elemente vertauscht. Das wiederholt sich, bis sich
`i` und `j` treffen:

```text
Start: 12  45  3  67  21  9   (Pivot = daten[5] = 9)
i = 0, j = 4

-- 1. Durchlauf der aeusseren WHILE-Schleife (i < j: 0 < 4) --
  i-Suche:  daten[0] = 12 > 9         -> i bleibt bei 0
  j-Suche:  daten[4] = 21 > 9         -> weiter
            daten[3] = 67 > 9         -> weiter
            daten[2] = 3 <= 9         -> j bleibt bei 2
  daten[0] = 12 > daten[2] = 3        -> vertauschen
  Array jetzt: 3  45  12  67  21  9

-- 2. Durchlauf der aeusseren WHILE-Schleife (i < j: 0 < 2) --
  i-Suche:  daten[0] = 3 <= 9         -> i wird 1
            daten[1] = 45 > 9         -> i bleibt bei 1
  j-Suche:  daten[2] = 12 > 9         -> j wird 1
  i = 1, j = 1: die aeussere Schleife endet (i < j gilt nicht mehr)

-- Pivot-Element platzieren --
  daten[1] = 45 > Pivot 9             -> Pivot-Element an Position 1 tauschen
  Ergebnis: 3  9  12  67  21  45
```

Das Pivot-Element `9` steht jetzt an Index 1 — links davon nur `3` (kleiner),
rechts davon nur `12, 67, 21, 45` (größer). Genau hier **entsteht Divide-and-
Conquer**: Übrig bleiben zwei kleinere, unabhängige Teilprobleme — die Reihe
links vom Pivot-Element (Index 0, hier trivial: ein einzelnes Element) und
die Reihe rechts davon (Index 2 bis 5). Beide werden **genauso** behandelt:
Pivot-Element wählen, partitionieren, wieder aufteilen — bis eine Teilreihe
nur noch aus `0` oder `1` Elementen besteht. Das ist das
**Abbruchkriterium**: Eine solche Teilreihe ist automatisch schon sortiert,
die Rekursion endet dort.

---

### Der Pseudocode <span class="zeitangabe">ca. 8 Min.</span> { data-toc-label="Der Pseudocode" }

Genau dieses Vorgehen steht als Pseudocode formuliert. `quicksort` steuert
die Rekursion, `teile` erledigt das Partitionieren von eben:

```text linenums="1"
funktion quicksort(links, rechts)
    IF links < rechts THEN
        teiler := teile(links, rechts)
        quicksort(links, teiler - 1)
        quicksort(teiler + 1, rechts)
    END IF
```

1. Das Abbruchkriterium: Eine Teilreihe mit `0` oder `1` Element
   (`links < rechts` ist dann falsch) wird nicht weiter bearbeitet — sie ist
   schon sortiert.
2. Die beiden rekursiven Aufrufe setzen das Divide-and-Conquer-Prinzip um:
   Ein Aufruf sortiert alles links vom Pivot-Element, der andere alles
   rechts davon. `teiler` ist dabei die Position, an der das Pivot-Element
   nach dem Partitionieren steht — sie gehört zu keiner der beiden
   Teilreihen mehr dazu.

```text linenums="1"
funktion teile(links, rechts)
    i := links
    j := rechts - 1
    pivot := daten[rechts]

    WHILE i < j DO
        WHILE i < j und daten[i] <= pivot DO
            i := i + 1
        END WHILE

        WHILE j > i und daten[j] > pivot DO
            j := j - 1
        END WHILE

        IF daten[i] > daten[j] THEN
            tausche daten[i] mit daten[j]
        END IF
    END WHILE

    IF daten[i] > pivot THEN
        tausche daten[i] mit daten[rechts]
    ELSE
        i := rechts
    END IF

    output i
```

1. Die Wahl des Pivot-Elements: Hier fällt die Entscheidung, welches
   Element als Referenzwert dient — in diesem Pseudocode immer das rechte
   Element der aktuell betrachteten Teilreihe.
2. Das Umsortieren relativ zum Pivot-Element: Die beiden inneren
   `WHILE`-Schleifen suchen je ein falsch stehendes Element von links und
   von rechts, die `IF`-Anweisung tauscht sie. Nach der äußeren
   `WHILE`-Schleife steht fest, wo die Grenze zwischen "kleiner/gleich" und
   "größer" verläuft — die letzte `IF`/`ELSE`-Anweisung bringt das
   Pivot-Element selbst genau an diese Grenze.

---

### Eine fertige Sortierfunktion: qsort <span class="zeitangabe">ca. 15 Min.</span> { data-toc-label="Eine fertige Sortierfunktion: qsort" }

Die Bibliothek `stdlib.h` (die ihr schon von `atoi`, `rand` und `system`
kennt) bringt eine eigene, universelle Sortierfunktion mit: `qsort`. Sie
funktioniert nach demselben Prinzip wie euer Pseudocode eben, ist aber
fertig implementiert und sortiert nicht nur `int`-Arrays, sondern
Arrays *jedes* Datentyps. Referenz:
[devdocs.io/c/algorithm/qsort](https://devdocs.io/c/algorithm/qsort).

#### Schritt 1: Ein Array aufsteigend sortieren

`qsort` bekommt vier Angaben: das Array, die Anzahl seiner Elemente, die
Größe eines einzelnen Elements — und eine **Vergleichsfunktion**, die
`qsort` bei Bedarf selbst aufruft, um zwei Elemente miteinander zu
vergleichen.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-10-1-qsort-basis.c"
    ```

    1. Die Vergleichsfunktion bekommt zwei `const void *`-Parameter — das
       sind Pointer, die noch nicht erklärt wurden. Übernehmt das Muster
       für heute so, wie es dasteht; die Pointer-Grundlagen folgen in den
       nächsten Blöcken dieses Termins.
    2. `qsort` bekommt das Array, die Anzahl der Elemente, die Größe eines
       Elements (`sizeof(int)`) und die Vergleichsfunktion übergeben.
    3. Die Vergleichsfunktion liefert einen negativen Wert, wenn `a`
       kleiner als `b` ist, `0` bei Gleichheit, und einen positiven Wert,
       wenn `a` größer ist. Bei kleinen Zahlen wie hier reicht dafür die
       einfache Subtraktion; bei sehr großen oder sehr kleinen `int`-Werten
       kann sie allerdings selbst über- oder unterlaufen (Termin 3) — dann
       bräuchte es stattdessen zwei einzelne Vergleiche.

**Warum überhaupt eine Vergleichsfunktion?** `qsort` weiß nichts darüber,
wie zwei `int`-Werte, zwei Strings oder zwei selbst definierte Datensätze
sinnvoll zu vergleichen sind — das müsst ihr ihr sagen. Genau das macht
`qsort` so vielseitig einsetzbar.
{: .hinweis-klein }

---

#### Schritt 2: Das Sortierkriterium austauschen

`qsort` selbst bleibt dabei immer gleich — nur die Vergleichsfunktion
ändert sich. Mit einer zweiten Vergleichsfunktion sortiert dieselbe
Funktion plötzlich absteigend.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-10-2-qsort-absteigend.c"
    ```

    1. Derselbe Aufruf von `qsort` wie eben — nur die letzte Angabe hat
       sich geändert.
    2. `vergleicheAbsteigend` vertauscht einfach `a` und `b` gegenüber
       `vergleicheAufsteigend` — dieselbe Pointer-Syntax wie in Schritt 1,
       auch dazu später mehr.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

Jetzt setzt ihr den Pseudocode aus der Übung selbst in C um. Anschließend
vergleicht ihr experimentell, wie sich Bubblesort und Quicksort bei
wachsender Datenmenge tatsächlich schlagen — und stellt das Ergebnis der
theoretischen Zeitkomplexität gegenüber.

!!! abstract "Lernziele"
    - Ihr könnt Quicksort anhand eines gegebenen Pseudocodes als rekursive
      Funktion in C umsetzen.
    - Ihr könnt die Anzahl der Vergleiche zweier Sortieralgorithmen
      experimentell messen und mit ihrer theoretischen Zeitkomplexität in
      Beziehung setzen.

### Aufgabe 32: Eigene Quicksort-Implementierung

#### Teil A — Von Hand partitionieren (ohne Rechner)

Partitioniert **ohne Rechner** die Reihe `18  4  27  9  40  15` (Indizes 0
bis 5) nach demselben Verfahren wie in der Übung: Pivot-Element ist das
letzte Element der Reihe, zwei Zeiger `i` und `j` suchen von links bzw.
rechts nach falsch stehenden Elementen. Notiert, wie die Reihe nach jedem
Tausch aussieht, und an welcher Position das Pivot-Element am Ende steht.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    ```text
    Start: 18  4  27  9  40  15   (Pivot = daten[5] = 15)
    i = 0, j = 4

    -- 1. Durchlauf --
      i-Suche: daten[0] = 18 > 15         -> i bleibt bei 0
      j-Suche: daten[4] = 40 > 15         -> weiter
               daten[3] = 9 <= 15         -> j bleibt bei 3
      daten[0] = 18 > daten[3] = 9        -> vertauschen
      Array jetzt: 9  4  27  18  40  15

    -- 2. Durchlauf (i < j: 0 < 3) --
      i-Suche: daten[0] = 9 <= 15         -> i wird 1
               daten[1] = 4 <= 15         -> i wird 2
               daten[2] = 27 > 15         -> i bleibt bei 2
      j-Suche: daten[3] = 18 > 15         -> j wird 2
      i = 2, j = 2: die aeussere Schleife endet

    -- Pivot-Element platzieren --
      daten[2] = 27 > Pivot 15            -> Pivot-Element an Position 2 tauschen
      Ergebnis: 9  4  15  18  40  27
    ```

    Das Pivot-Element `15` steht am Ende an Index 2 — links davon nur `9`
    und `4` (kleiner), rechts davon `18`, `40` und `27` (größer).
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Als Funktion umsetzen

Übertragt den Pseudocode aus der Übung jetzt in echten C-Code: zwei
Funktionen `void quicksort(int daten[], int links, int rechts)` und
`int teile(int daten[], int links, int rechts)`. **Wichtig:** Der
Pseudocode benutzt `daten`, ohne es als Parameter aufzuführen — in C müsst
ihr es dagegen als zusätzlichen ersten Parameter an beide Funktionen
übergeben, genau wie ihr das schon von den Array-Funktionen aus Termin 4
kennt. Beschränkt euch auf `int`-Arrays, ein Sortierkriterium wie bei
`qsort` wird hier noch nicht gebraucht.

Testet eure Lösung mit dem vorgegebenen Array:

```c linenums="1"
--8<-- "02-theoriephase/termin-05/code/vorgabe-32-quicksort.c"
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil B anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/aufg-32-quicksort.c"
    ```

    Die Umsetzung folgt dem Pseudocode praktisch zeilenweise — jede
    Pseudocode-Zeile wird zu einer C-Zeile, ergänzt um `daten` als
    Parameter. Ein typischer Fehler ist, `j` mit `rechts` statt mit
    `rechts - 1` zu initialisieren: Damit würde `daten[j]` beim ersten
    Schleifendurchlauf auf das Pivot-Element selbst zeigen (`daten[rechts]`
    ist ja gerade der Pivot-Wert), und die Suchschleife für `j` bräche
    sofort ab, ohne ein einziges Element geprüft zu haben.
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 33: Bubblesort vs. Quicksort — experimenteller Komplexitätsvergleich

Ihr habt in der Vorbereitung gesehen, dass sich die Zeitkomplexität eines
Algorithmus mit der O-Notation beschreiben lässt. Jetzt prüft ihr, was das
für echte Zahlen bedeutet: Bubblesort hat *immer* die Komplexität `O(n²)`.
Quicksort hat im **Durchschnitt** `O(n log n)` — im **schlechtesten Fall**
aber ebenfalls `O(n²)`, nämlich genau dann, wenn das Pivot-Element (wie in
der Übung besprochen) die Reihe immer maximal ungleich teilt, zum Beispiel
bei einer bereits sortierten Reihe. Die Zufallsarrays in diesem Experiment
sorgen dafür, dass dieser schlechteste Fall so gut wie nie auftritt.

Als **Kennzahl** verwendet ihr die **Anzahl der Vergleiche** zwischen zwei
Elementen (bzw. einem Element und dem Pivot-Element) — nicht die Anzahl der
Vertauschungen. Der Grund: Genau die Anzahl der Vergleiche ist es, die in
der O-Notation für beide Algorithmen beschrieben wird.

Das folgende, bereits vollständige Programm sortiert Zufallsarrays
wachsender Größe (`n = 100` bis `n = 12800`, jeweils dasselbe Array für
beide Algorithmen) mit einer mitzählenden Bubblesort- und einer
mitzählenden Quicksort-Funktion und gibt das Ergebnis als CSV-Zeilen aus:

```c linenums="1"
--8<-- "02-theoriephase/termin-05/code/vorgabe-33-komplexitaetsvergleich.c"
```

1. `vergleicheZahlen` ist der Trick hinter der ganzen Messung: eine kleine
   Hilfsfunktion, die zwei Zahlen vergleicht *und dabei* eine globale
   Zählvariable erhöht. Überall dort, wo `teileMitZaehler` sonst direkt
   `a[i] <= pivot` schreiben würde, steht deshalb
   `vergleicheZahlen(a[i], pivot) <= 0` — das Ergebnis ist dasselbe, nur
   dass jetzt jeder einzelne Vergleich mitgezählt wird.
2. `srand(42)` legt einen **festen** Startwert für die Zufallszahlen fest.
   So erzeugt das Programm bei jedem Lauf exakt dieselben Zahlen — wichtig,
   damit Bubblesort und Quicksort wirklich auf denselben Daten verglichen
   werden, nicht auf zufällig unterschiedlichen.
3. Das ist derselbe rekursive Aufbau wie eure Lösung zu Aufgabe 32 — nur
   dass `teileMitZaehler` statt eines direkten Vergleichs die
   Zählfunktion aus Anmerkung 1 benutzt.
4. Bei Bubblesort genügt ein einfacher Zähler direkt an der Vergleichsstelle
   `a[i] > a[i + 1]`, weil es hier (anders als bei Quicksort) nur eine
   einzige Stelle im Code gibt, an der zwei Elemente verglichen werden.

**Zwei feste, unveränderliche Arrays statt Rechner-Speicherverwaltung:**
`original` und `arbeitskopie` sind mit `MAX_N = 12800` groß genug für den
größten Testfall angelegt. Das Programm arbeitet also für jede Array-Größe
`n` immer nur mit den ersten `n` Elementen dieser beiden Arrays. Eine
speichersparendere Lösung (Arrays passend zur jeweiligen Größe anlegen)
brauchte dynamische Speicherverwaltung, die kommt in einem späteren Termin.
{: .hinweis-klein }

**Schritt 1:** Führt das Programm aus. Es gibt für jede Array-Größe eine
Zeile mit drei durch Komma getrennten Werten aus: `n`, Anzahl Vergleiche
bei Bubblesort, Anzahl Vergleiche bei Quicksort.

**Schritt 2:** Öffnet die Auswertungsvorlage
[vorlage-33-komplexitaetsvergleich.xlsx](code/vorlage-33-komplexitaetsvergleich.xlsx).
Ihre Zeilen sind bereits nach denselben `n`-Werten sortiert wie die
Programmausgabe — übertragt für jede Zeile die beiden gemessenen Werte von
Hand in die gelb markierten Spalten B und C.

**Die CSV-Ausgabe nicht direkt in Excel einfügen:** Je nach
Spracheinstellung trennt Excel Spalten beim Einfügen mit Semikolon statt
mit Komma — die Werte landen dann alle in einer einzigen Zelle statt in
getrennten Spalten. Bei nur acht Zeilen ist das Übertragen von Hand
zuverlässiger.
{: .hinweis-klein }

Die Vorlage berechnet automatisch zwei theoretische Vergleichskurven
(`O(n²)` und `O(n log n)`) und zeichnet ein Diagramm mit allen vier Reihen.
Da die Konstante der O-Notation unbekannt ist, sind die theoretischen
Kurven so skaliert, dass sie beim größten gemessenen `n` exakt auf euren
Messwert treffen — verglichen wird also die **Form** der Kurve, nicht ihr
absoluter Wert.

**Schritt 3:** Beantwortet anhand des Diagramms:

- Passt die Form der gemessenen Bubblesort-Werte zur `O(n²)`-Kurve, und die
  der Quicksort-Werte zur `O(n log n)`-Kurve?
- Ab welcher Größenordnung wird der Unterschied zwischen beiden Algorithmen
  im Diagramm deutlich sichtbar?
- Was bedeutet dieser Unterschied für die Wahl eines Sortieralgorithmus bei
  großen Datenmengen?
- In der Übung stand: Eine ungünstige Pivot-Wahl verschlechtert die
  Laufzeit von Quicksort. Was vermutet ihr: Wie würden sich die
  Vergleichszahlen von Quicksort verändern, wenn statt zufälliger Arrays
  bereits **sortierte** Arrays verwendet würden?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Die gemessenen Bubblesort-Werte folgen der `O(n²)`-Kurve sehr genau —
    das liegt daran, dass Bubblesort ohne Sonderfall *immer* genau
    `n · (n - 1) / 2` Vergleiche durchführt, unabhängig von der Reihenfolge
    der Daten. Die Quicksort-Werte liegen nah an, aber nicht exakt auf der
    `O(n log n)`-Kurve: Quicksort braucht je nach Zufallsdaten und
    Pivot-Wahl etwas mehr oder weniger Vergleiche, die durchschnittliche
    Größenordnung passt aber.

    Bei kleinen `n` liegen beide Kurven noch dicht beieinander, bei
    steigendem `n` wächst die Bubblesort-Kurve dramatisch schneller — schon
    bei `n = 12800` sind es rund 82 Millionen Vergleiche bei Bubblesort
    gegenüber deutlich weniger als einer Million bei Quicksort. Für große
    Datenmengen ist Quicksort deshalb die klar bessere Wahl; bei sehr
    kleinen Arrays fällt der Unterschied dagegen kaum ins Gewicht.
<!-- MUSTERLOESUNG-ENDE -->
