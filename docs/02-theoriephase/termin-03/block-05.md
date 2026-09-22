---
typ: theoriephase-block
termin: 3
block_id: "05"
datum: "2026-11-04"
kurztitel: "Funktionen"
thema: "Funktionen"
lernziele:
  - "Du kannst eine Funktion mit Parametern und Rückgabewert in C schreiben, per Funktionsprototyp deklarieren und aufrufen."
  - "Du kannst erklären, warum eine Funktion denselben Algorithmus mit unterschiedlichen Parametern wiederverwendbar macht."
  - "Du kannst eine Funktion, die mehrere Aufgaben übernimmt, in fokussierte Einzelfunktionen aufteilen."
  - "Du kannst einen fehlenden Funktionsprototyp als Fehlerursache erkennen und beheben."
musterloesungen_sichtbar: true
ki_einsatz: stufe_0_ohne
clean_code:
  - "DRY"
  - "Eine Funktion, eine Aufgabe"
bearbeitungsstatus: in-arbeit
publish_date: 2026-11-04
---

# Funktionen (04.11.2026)

## Übung { .modus-uebung }

### Worum geht es?

Bisher stand aller Code in `main`. Heute lernt ihr, Code in eigene,
benannte **Funktionen** auszulagern — den wichtigsten Baustein, um
Programme zu strukturieren und Wiederholungen zu vermeiden.

!!! abstract "Lernziele"
    - Ihr könnt eine Funktion mit Parametern und Rückgabewert in C
      schreiben, per Funktionsprototyp deklarieren und aufrufen.
    - Ihr könnt erklären, warum eine Funktion denselben Algorithmus mit
      unterschiedlichen Parametern wiederverwendbar macht.

### Kurzer Rückblick <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Kurzer Rückblick" }

**1.** Wozu dient eine Wiederholung (Schleife) grundsätzlich, und was
unterscheidet die drei Schleifenformen aus Termin 2 (`while`, `do-while`,
`for`) voneinander?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Eine Wiederholung führt dieselben Anweisungen mehrfach aus, ohne dass
    ihr sie mehrfach hinschreiben müsst. `while` prüft die Bedingung vor
    dem Rumpf und kann null Durchläufe haben, `do-while` läuft immer
    mindestens einmal und prüft erst am Ende, `for` ist die kopfgesteuerte
    Sonderform für eine von vornherein bekannte Anzahl Durchläufe mit
    Zählvariable.
<!-- MUSTERLOESUNG-ENDE -->

**2.** In der Übung von Termin 2 habt ihr mit `do-while` das
Horner-Schema (Dezimal → Dual) umgesetzt. Warum passt dafür ausgerechnet
eine fußgesteuerte Wiederholung besonders gut?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Der PAP aus Termin 1 berechnet Rest und Division, bevor überhaupt zum
    ersten Mal geprüft wird, ob die Zahl `0` erreicht ist — die
    Schleifenanweisungen laufen also immer mindestens einmal. Genau das
    leistet `do-while`, während `while` die Bedingung schon vor dem ersten
    Durchlauf prüfen würde.
<!-- MUSTERLOESUNG-ENDE -->

---

### Das Beispiel: Eine Begrüßungsfunktion <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Das Beispiel: Eine Begrüßungsfunktion" }

Stellt euch vor, ihr wollt an mehreren Stellen im Programm jemanden
begrüßen. Ohne Funktion müsstet ihr den Ausgabe-Code jedes Mal erneut
hinschreiben. Wir bauen deshalb eine **Funktion** `begruessung`, die genau
das für uns übernimmt — und die wir beliebig oft aufrufen können.

---

### Schrittweise Umsetzung <span class="zeitangabe">ca. 12 Min.</span> { data-toc-label="Schrittweise Umsetzung" }

Eine Funktion besteht aus einem **Funktionsprototyp** (kündigt dem
Compiler Name, Parameter und Rückgabetyp schon vor der eigentlichen
Verwendung an), dem **Aufruf** und der **Definition** (der eigentliche
Code). Wir schreiben `begruessung` bewusst *nach* `main` — üblicher Stil,
damit `main` als Einstiegspunkt oben steht — und brauchen dafür den
Prototyp direkt über `main`.

#### Schritt 1: Eine Funktion mit einem Parameter

Ganz ohne Parameter würde `begruessung` immer denselben Text ausgeben —
wenig nützlich. Über einen **Parameter** (hier: den Anfangsbuchstaben
eures Vornamens, wie schon in Aufgabe 01 aus Block 01) bekommt die
Funktion bei jedem Aufruf einen anderen Wert übergeben und kann sich
entsprechend unterschiedlich verhalten. Das Schlüsselwort `void` vor dem
Funktionsnamen bedeutet: Diese Funktion **gibt nichts zurück**.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-05-1-begruessung.c"
    ```

---

#### Schritt 2: Noch ein Parameter — wie oft?

Eine Funktion kann mehrere Parameter haben, durch Komma getrennt. Wir
ergänzen `anzahl`, das steuert, wie oft die Begrüßung ausgegeben wird —
dafür reicht eine `for`-Schleife im Funktionskörper, die ihr schon aus
Termin 2 kennt.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-05-2-begruessung-anzahl.c"
    ```

---

### Was steckt eigentlich hinter einer Funktion? <span class="zeitangabe">ca. 2 Min.</span> { data-toc-label="Was steckt eigentlich hinter einer Funktion?" }

Im Kern ist eine Funktion nichts anderes als ein Algorithmus, bei dem
einige Werte **variabel** bleiben — genau das leisten die Parameter. Statt
für jede Situation eigenen Code zu schreiben, schreibt ihr den Algorithmus
**einmal** und füttert ihn bei jedem Aufruf mit den passenden Werten. Was
das konkret bringt, seht ihr am besten an einem Vorher-Nachher-Vergleich.

---

### Wiederholten Code vermeiden <span class="zeitangabe">ca. 10 Min.</span> { data-toc-label="Wiederholten Code vermeiden" }

Zurück zu einem Beispiel aus Termin 1: Fläche und Umfang eines Rechtecks
berechnen — diesmal für **zwei** Rechtecke.

#### Schritt 1: Duplizierter Code

Ohne Funktion sieht die naheliegende Lösung so aus: derselbe
Berechnungs- und Ausgabe-Code, einmal für jedes Rechteck kopiert.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-05-3-dry-vorher.c"
    ```

**Was daran stört:** Ändert sich später, wie die Ausgabe formatiert wird,
oder kommt ein dritter Wert dazu, müsst ihr das an **jeder** Kopie einzeln
nachziehen — und leicht eine davon vergessen.
{: .hinweis-klein }

---

#### Schritt 2: Dieselbe Aufgabe als Funktion

Dieselbe Berechnung, jetzt einmal als Funktion `rechteckAuswerten`
geschrieben und zweimal mit unterschiedlichen Werten aufgerufen.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-05-4-dry-nachher.c"
    ```

!!! tip "Clean Code: DRY"
    *DRY* steht für **D**on't **R**epeat **Y**ourself — wiederholt euch
    nicht. Statt denselben Code mehrfach zu kopieren, schreibt ihr ihn
    einmal als Funktion und ruft ihn mit unterschiedlichen Parametern auf.
    Ein drittes Rechteck kostet jetzt nur noch eine einzige zusätzliche
    Zeile, und eine spätere Änderung an der Berechnung muss nur an
    **einer** Stelle gemacht werden. Ab jetzt erwarten wir, dass ihr
    erkennbar wiederholten Code in eine Funktion auslagert.

---

### Zweites Beispiel: Teiler und perfekte Zahlen <span class="zeitangabe">ca. 2 Min.</span> { data-toc-label="Zweites Beispiel: Teiler und perfekte Zahlen" }

Ein zweites Beispiel, das zeigt, dass Funktionen auch **Ergebnisse
zurückliefern** können, nicht nur Ausgaben erzeugen: Wir schreiben eine
Funktion, die alle Teiler einer Zahl ausgibt, und bauen daraus eine
zweite, die prüft, ob die Zahl eine besondere Eigenschaft hat — eine
sogenannte **perfekte Zahl**.

---

### Von der Teiler-Ausgabe zur Perfekt-Prüfung <span class="zeitangabe">ca. 15 Min.</span> { data-toc-label="Von der Teiler-Ausgabe zur Perfekt-Prüfung" }

#### Schritt 1: Teiler einer Zahl ausgeben

Eine verschachtelte Wiederholung mit Modulo-Prüfung — genau das Muster aus
Termin 2, nur jetzt in eine eigene Funktion verpackt. Ausgegeben werden
die **echten Teiler** von `zahl`, also alle Teiler außer `zahl` selbst.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-05-5-teiler.c"
    ```

    1. Es reicht, nur bis `zahl/2` zu prüfen: Ein echter Teiler von
       `zahl` (also einer, der kleiner als `zahl` ist) kann nie größer
       als `zahl/2` sein — sonst müsste der passende zweite Faktor
       kleiner als `2` sein, und das geht bei ganzen Zahlen nicht. Diese
       kleine Optimierung spart Rechenzeit, ohne dass ein echter Teiler
       verloren geht.

---

#### Schritt 2: Ist die Zahl perfekt?

Eine **perfekte Zahl** ist eine Zahl, bei der die Summe all ihrer echten
Teiler wieder genau die Zahl selbst ergibt — zum Beispiel `6 = 1 + 2 + 3`.
Statt die Teiler-Ausgabe-Funktion einfach zu erweitern, schreiben wir eine
**neue** Funktion `istPerfekt`: Sie summiert alle echten Teiler und gibt
als `int` zurück, ob diese Summe der Zahl entspricht (`1` für wahr, `0`
für falsch) — der erste **Rückgabewert**, den `main` tatsächlich
auswertet.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-05-6-istperfekt.c"
    ```

!!! tip "Clean Code: Eine Funktion, eine Aufgabe"
    `teilerAusgeben` gibt Teiler aus, `istPerfekt` prüft eine Eigenschaft
    und liefert das Ergebnis zurück — zwei unterschiedliche Aufgaben,
    zwei unterschiedliche Funktionen. Hätten wir stattdessen eine einzige
    Funktion gebaut, die Teiler ausgibt **und** nebenbei prüft, ob die
    Zahl perfekt ist, wäre sie schwerer zu verstehen, zu testen und
    wiederzuverwenden. Ab jetzt erwarten wir, dass jede eurer Funktionen
    eine klar benennbare Aufgabe hat.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

Jetzt wendet ihr Funktionen mit Parametern und Rückgabewert selbst an,
sucht einen klassischen Fehler ohne fehlenden Prototyp und teilt eine
Funktion, die zu viel auf einmal macht, in zwei fokussierte Funktionen
auf. Wer schnell fertig ist, kann sich zusätzlich an einer optionalen,
etwas anspruchsvolleren Aufgabe zu Zufallszahlen versuchen.

!!! abstract "Lernziele"
    - Ihr könnt eine Funktion, die mehrere Aufgaben übernimmt, in
      fokussierte Einzelfunktionen aufteilen.
    - Ihr könnt einen fehlenden Funktionsprototyp als Fehlerursache
      erkennen und beheben.

### Aufgabe 15: Perfekte Zahlen finden

Schreibt ein Programm, das alle perfekten Zahlen zwischen `1` und `10000`
ausgibt. Nutzt dafür eine Funktion `int istPerfekt(int zahl)` wie in der
Übung (Summe aller Teiler kleiner als `zahl`, Rückgabe `1`, wenn die Summe
der Zahl entspricht, sonst `0`) und ruft sie in einer Schleife über alle
Kandidatenzahlen auf.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/aufg-15-perfekte-zahlen.c"
    ```

    Der Kern ist die Wiederverwendung: `istPerfekt` wird für jede der
    10.000 Kandidatenzahlen erneut aufgerufen, ohne dass die
    Teiler-Summen-Logik auch nur einmal kopiert werden muss — genau das
    Argument für **DRY** aus der Übung. Ohne Funktion müsstet ihr die
    innere Schleife entweder in die äußere hineinschreiben oder an
    mehreren Stellen duplizieren.

<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 16: Fehlersuche

Das folgende Programm soll das Quadrat einer eingegebenen Zahl berechnen,
lässt sich aber nicht bauen:

```c linenums="1"
--8<-- "02-theoriephase/termin-03/code/vorgabe-16-ohne-prototyp.c"
```

Beantwortet **ohne Rechner**: Warum meldet der Compiler hier einen
Fehler, obwohl die Funktion `quadrat` doch im Quelltext steht? Wie müsst
ihr die Datei ändern, damit sie sich baut?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Der Compiler liest die Datei von oben nach unten. An der Stelle, an
    der `quadrat(zahl)` in `main` aufgerufen wird, kennt er `quadrat` noch
    nicht — die Definition steht ja erst weiter unten. Ohne vorherige
    Ankündigung (Funktionsprototyp) weiß er nicht, ob der Aufruf zu den
    Parametern und dem Rückgabetyp der Funktion passt, und meldet einen
    Fehler (in etwa "identifier not found"/"undeclared identifier").

    Die Korrektur: ein Funktionsprototyp `int quadrat(int zahl);` vor
    `main`.

    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/aufg-16-mit-prototyp.c"
    ```

<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 17: Eine Funktion, eine Aufgabe

Das folgende Programm prüft eine eingegebene Temperatur gegen eine feste
Grenze und meldet das Ergebnis — beides in einer einzigen Funktion:

```c linenums="1"
--8<-- "02-theoriephase/termin-03/code/vorgabe-17-temperaturwarnung.c"
```

Teilt die Funktion `temperaturPruefenUndMelden` in zwei Funktionen auf:
eine Funktion `int istUeberGrenze(int temperatur, int grenze)`, die **nur**
prüft und das Ergebnis zurückgibt, und die Ausgabe der passenden Meldung,
die in `main` anhand dieses Rückgabewerts entschieden wird.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/aufg-17-temperatur-aufgeteilt.c"
    ```

    `istUeberGrenze` hat jetzt genau eine Aufgabe: prüfen und das Ergebnis
    zurückgeben. Die Entscheidung, was mit diesem Ergebnis passiert (hier:
    eine Meldung ausgeben), liegt bei `main`. Dieser Schnitt lohnt sich
    doppelt: `istUeberGrenze` lässt sich jetzt auch dort wiederverwenden,
    wo keine Meldung, sondern nur die reine Ja/Nein-Information gebraucht
    wird — und genau dieses Muster habt ihr in der Übung bei `istPerfekt`
    schon gesehen.

<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 18: Zufallszahl in einem Wertebereich (optional)

Computer können keinen "echten" Zufall erzeugen — stattdessen nutzt man
einen **Pseudozufallsgenerator**: einen Algorithmus, der aus einem
Startwert (dem *Seed*) eine Zahlenfolge erzeugt, die zufällig wirkt, bei
gleichem Seed aber immer gleich abläuft. In C gehören dazu zwei Funktionen
aus `<stdlib.h>`:

- `srand(startwert)` initialisiert den Generator **einmalig** mit einem
  Seed. Damit bei jedem Programmstart eine andere Folge herauskommt, nutzt
  man dafür meist die aktuelle Uhrzeit: `srand((unsigned int)time(NULL))`
  (braucht zusätzlich `#include <time.h>`) — einmal zu Beginn von `main`
  aufgerufen, **nicht** vor jedem einzelnen Zufallswert.
- `rand()` liefert danach bei jedem Aufruf eine neue "zufällige" ganze
  Zahl zwischen `0` und `RAND_MAX`.

Um daraus eine Zufallszahl in einem bestimmten Bereich zu machen, nutzt
ihr den Rest der Ganzzahldivision: `minimum + rand() % (maximum - minimum
+ 1)` liegt immer zwischen `minimum` und `maximum` (beide eingeschlossen).

Schreibt eine Funktion `int zufallszahl(int minimum, int maximum)`, die
genau das umsetzt, und ruft sie mehrfach mit unterschiedlichen
Wertebereichen auf (z. B. einen Würfelwurf zwischen `1` und `6` sowie
einen Bereich mit negativen Zahlen).

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/aufg-18-zufallszahl.c"
    ```

    `srand` steht bewusst nur **einmal** in `main`, nicht in
    `zufallszahl` selbst — würde man vor jedem Aufruf neu säen, könnte je
    nach Seed-Quelle sogar mehrfach dieselbe Zahl herauskommen, statt
    einer fortlaufenden Zufallsfolge. `zufallszahl` selbst bleibt dagegen
    eine Funktion mit genau einer Aufgabe: aus dem nächsten Wert von
    `rand()` einen Wert im gewünschten Bereich berechnen.

<!-- MUSTERLOESUNG-ENDE -->
