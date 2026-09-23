---
typ: theoriephase-block
termin: 3
block_id: "07"
datum: "2026-11-04"
kurztitel: "Variablen im Detail"
thema: "Variablen (Größe, Modifizierer, Sichtbarkeit, ...)"
lernziele:
  - "Du kannst mit dem sizeof-Operator die Speichergröße eines Datentyps oder einer Variable bestimmen."
  - "Du kannst an einem Beispiel erklären, wie ein Überlauf entsteht und welche Folgen er hat."
  - "Du kannst begründen, wann Typen aus stdint.h (z. B. int8_t) gegenüber int von Vorteil sind."
  - "Du kannst den Gültigkeitsbereich einer Variable abhängig von ihrem Deklarationsort bestimmen (global, Funktion, einzelner {}-Block)."
  - "Du kannst mit dem Schlüsselwort static eine Variable über mehrere Funktionsaufrufe hinweg persistieren lassen."
  - "Du kannst Magic Numbers im Code erkennen und durch sprechend benannte Konstanten ersetzen."
musterloesungen_sichtbar: true
ki_einsatz: stufe_0_ohne
clean_code:
  - "Magic Numbers vermeiden"
bearbeitungsstatus: in-arbeit
publish_date: "2026-11-04"
---

# Variablen im Detail (04.11.2026)

## Übung { .modus-uebung }

### Worum geht es?

Ihr kennt Variablen schon länger, aber bisher eher oberflächlich: anlegen,
einen Wert zuweisen, damit rechnen. Heute schaut ihr genauer hin — wie groß
eine Variable im Speicher eigentlich ist, was passiert, wenn ein Wert nicht
mehr in ihren Datentyp passt, und wo genau eine Variable überhaupt sichtbar
ist.

!!! abstract "Lernziele"
    - Ihr könnt mit dem `sizeof`-Operator die Speichergröße eines Datentyps
      oder einer Variable bestimmen.
    - Ihr könnt an einem Beispiel erklären, wie ein Überlauf entsteht und
      welche Folgen er hat.
    - Ihr könnt begründen, wann Typen aus `stdint.h` (z. B. `int8_t`) gegenüber
      int von Vorteil sind.
    - Ihr könnt den Gültigkeitsbereich einer Variable abhängig von ihrem
      Deklarationsort bestimmen (global, Funktion, einzelner {}-Block).
    - Ihr könnt mit dem Schlüsselwort `static` eine Variable über mehrere
      Funktionsaufrufe hinweg persistieren lassen.

### Kurzer Rückblick <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Kurzer Rückblick" }

1\. Was unterscheidet eine rekursive Lösung grundsätzlich von einer
iterativen (Schleifen-)Lösung für dasselbe Problem?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Beide führen letztlich zum selben Ergebnis. Eine rekursive Lösung ruft
    sich selbst mit einem kleineren Argument auf und wartet auf dessen
    Rückkehr (Aufrufstapel), eine iterative Lösung wiederholt denselben
    Speicherplatz einfach in einer Schleife. Nach KISS ist die iterative
    Lösung meist vorzuziehen, außer ein Problem zerlegt sich von Natur aus
    rekursiv.
<!-- MUSTERLOESUNG-ENDE -->

2\. Was passiert, wenn die Abbruchbedingung einer rekursiven Funktion nie
erreicht wird, und wie heißt der daraus resultierende Programmabsturz?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Die Funktion ruft sich immer weiter selbst auf, ohne je zurückzukehren.
    Jeder wartende Aufruf belegt dabei Platz auf dem Aufrufstapel — dieser
    Platz ist irgendwann erschöpft, das Programm stürzt mit einem
    **Stapelüberlauf** ab.
<!-- MUSTERLOESUNG-ENDE -->

---

### Wie groß ist so ein Datentyp eigentlich? <span class="zeitangabe">ca. 6 Min.</span> { data-toc-label="Wie groß ist so ein Datentyp eigentlich?" }

Jeder Datentyp braucht eine bestimmte Anzahl Byte im Speicher — das habt
ihr bisher einfach so hingenommen. Mit dem **sizeof-Operator** könnt ihr
das direkt im Code nachschlagen, statt es auswendig zu lernen.

#### Schritt 1: Größen mit sizeof anzeigen

`sizeof` liefert die Größe eines Datentyps in Byte zurück. Angewendet auf
alle bisher bekannten Basisdatentypen sowie die zusätzlichen Ganzzahltypen
`short`, `long` und `long long` aus eurem Vorbereitungsvideo ergibt sich ein
vollständiges Bild.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-1-sizeof.c"
    ```

**Neues Formatierungszeichen `%zu`:** `sizeof` liefert keinen normalen
`int`, sondern einen eigenen (garantiert nicht-negativen) Ganzzahltyp
namens `size_t`. Dafür gibt es ein eigenes Formatierungszeichen, `%zu`,
statt des bekannten `%d` (zuverlässig verfügbar ab Visual Studio 2015).
Die letzte Zeile zeigt außerdem: `sizeof` funktioniert nicht nur auf einem
Datentyp, sondern genauso auf einer Variable — praktisch, wenn euch nur
ihre Größe interessiert, nicht ihr genauer Typname.
{: .hinweis-klein }

---

#### Schritt 2: Garantierte Größen mit stdint.h

Die Größe von `int` & Co. ist im C-Standard nicht fest vorgeschrieben — auf
einer Plattform kann `int` 2 Byte groß sein, auf einer anderen 4. Für die
meisten Programme ist das egal, aber sobald ihr mit einem Mikrocontroller
oder einem Sensor-Register arbeitet, das *exakt* 8 oder 16 Bit breit ist,
wird das zum Problem. Genau dafür gibt es die Bibliothek `stdint.h` mit
Typen wie `int8_t` oder `uint8_t`, deren Größe **garantiert** ist.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-2-stdint.c"
    ```

**Bei Zeitdruck:** Dieser Schritt lässt sich live überspringen — der Code
bleibt hier als Nachschlagereferenz stehen, für Sichtbarkeit gleich ist
mehr Zeit wichtiger.
{: .hinweis-klein }

---

### Wenn der Wertebereich nicht reicht: Überlauf <span class="zeitangabe">ca. 6 Min.</span> { data-toc-label="Wenn der Wertebereich nicht reicht: Überlauf" }

Jeder Datentyp hat wegen seiner festen Größe auch einen festen
Wertebereich. Ohne besondere Kennzeichnung sind Ganzzahltypen wie `char`
oder `int` in C **signed** (vorzeichenbehaftet) — sie können auch negative
Werte speichern. Der Modifizierer `unsigned` vor einem Datentyp entfernt
diese Möglichkeit und nutzt den dadurch frei werdenden Speicherplatz für
einen größeren positiven Wertebereich: Ein `unsigned char` reicht von `0`
bis `255`, statt wie der normale (signed) `char` von `-128` bis `127`.

Was passiert, wenn eine Berechnung diesen Wertebereich verlässt? Stellt
euch einen Distanzzähler vor, der seinen Wert in einem `unsigned char`
speichert und immer weiterzählt.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-3-ueberlauf.c"
    ```

Der Zähler springt nach `255` nicht etwa auf `256`, sondern zurück auf
`0` — ein **Überlauf**. Der Speicherplatz eines `unsigned char` reicht
schlicht nicht für `256`, deshalb "beginnt er von vorn". Bei den
vorzeichenbehafteten Datentypen aus Termin 1 passiert dasselbe am anderen
Ende des Wertebereichs, mit dem Zweierkomplement als Ursache.

---

### Sichtbarkeit: von global bis ins innerste { } <span class="zeitangabe">ca. 14 Min.</span> { data-toc-label="Sichtbarkeit: von global bis ins innerste { }" }

Bisher habt ihr Variablen meist in `main` oder direkt in einer Funktion
angelegt. Wo genau eine Variable **sichtbar** ist, hängt aber vom Ort ihrer
Deklaration ab — und das gilt nicht nur für Funktionen.

#### Schritt 1: Global und lokal — wer gewinnt?

Eine Variable, die außerhalb jeder Funktion deklariert wird, ist **global**
— sie ist im ganzen Programm sichtbar. Eine Variable innerhalb einer
Funktion ist **lokal** — sie existiert nur dort. Tragen beide denselben
Namen, gewinnt innerhalb der Funktion die lokale Variable: Sie **verdeckt**
die globale, ohne sie zu verändern.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-4-sichtbarkeit-global-lokal.c"
    ```

    1. Die globale Deklaration von `stand` — außerhalb jeder Funktion, im
       ganzen Programm sichtbar.
    2. Die lokale Deklaration von `stand` innerhalb von `zeigeStand` —
       verdeckt die globale Variable, aber nur innerhalb dieser Funktion.

---

#### Schritt 2: Compound Statement als eigener Gültigkeitsbereich

Nicht nur eine Funktion, sondern **jeder** mit `{` und `}` eingeschlossene
Block — ein sogenanntes **Compound Statement**, zum Beispiel der Rumpf
eines `if` oder einer Schleife — eröffnet einen eigenen
Gültigkeitsbereich. Das Prinzip aus Schritt 1 gilt hier genauso, nur eine
Ebene kleiner: eine Variable, die innerhalb eines `if`-Blocks deklariert
wird, existiert nur dort.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-5-sichtbarkeit-block.c"
    ```

    1. Ein **isoliertes Compound Statement** — ein `{ }`-Block ganz ohne
       `if`, `for` oder Ähnliches drumherum. Das ist ungewöhnlich (in der
       Praxis steht ein Compound Statement fast immer im Rumpf einer
       Kontrollstruktur oder Funktion), aber gültiges C: Auch ein
       einzelner `{ }`-Block für sich eröffnet einen eigenen
       Gültigkeitsbereich.

Hier trägt `wert` auf vier Ebenen denselben Namen — global, Funktionsebene,
`if`-Block und das isolierte Compound Statement — und jede Ebene verdeckt
nur die jeweils äußere, ohne sie zu verändern:

```text
Vor dem Aufruf (global): 1
Funktionsebene: 2
Innerhalb des if-Blocks: 3
Isoliertes Compound Statement: 4
Nach beiden Bloecken (wieder Funktionsebene): 2
Nach dem Aufruf (global): 1
```

**Kein Vorbild für sauberen Code:** Dieses Beispiel ist bewusst zugespitzt,
um Sichtbarkeit sichtbar zu machen — in der Praxis solltet ihr dieselbe
Variable möglichst nicht auf mehreren Ebenen gleich benennen, das macht
Code schwerer nachvollziehbar.
{: .hinweis-klein }

---

### static: Der Aufrufzähler <span class="zeitangabe">ca. 8 Min.</span> { data-toc-label="static: Der Aufrufzähler" }

Neben ihrem Gültigkeitsbereich hat jede Variable auch eine
**Speicherklasse**, die unter anderem festlegt, wie lange sie existiert.
Der mit Abstand wichtigste Fall dafür ist das Schlüsselwort `static`.

#### Schritt 1: Ohne static — jedes Mal bei null

Eine Funktion, die zählen soll, wie oft sie schon aufgerufen wurde: Ein
Motor, der mehrfach gestartet wird, soll mitzählen, der wievielte Start das
gerade ist.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-6-zaehler-ohne-static.c"
    ```

Das Ergebnis ist ernüchternd: Die Ausgabe zeigt bei jedem Aufruf "Aufruf
Nr. 1" — die lokale Variable `aufrufe` wird bei jedem Funktionsaufruf neu
angelegt und mit `0` initialisiert, sie "vergisst" also, was beim letzten
Aufruf passiert ist.

---

#### Schritt 2: Mit static — der Zähler merkt sich seinen Stand

Mit dem Schlüsselwort `static` vor der Deklaration bleibt eine lokale
Variable über das Ende der Funktion hinaus erhalten — bei einem erneuten
Aufruf startet sie nicht neu, sondern macht dort weiter, wo sie
aufgehört hat.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-7-zaehler-mit-static.c"
    ```

    1. Das Schlüsselwort `static`: Ohne es würde `aufrufe` bei jedem
       Aufruf neu bei `0` anfangen (siehe Schritt 1) — mit `static` wird
       die Variable nur beim allerersten Aufruf initialisiert und behält
       ihren Wert über alle weiteren Aufrufe hinweg.

Jetzt zählt die Ausgabe korrekt "Aufruf Nr. 1", "Aufruf Nr. 2", "Aufruf Nr.
3" — `aufrufe` wird nur beim allerersten Aufruf mit `0` initialisiert und
behält ihren Wert danach bei. Sichtbar ist die Variable weiterhin nur
innerhalb von `motorGestartet` — nur ihre **Lebensdauer** hat sich
geändert, nicht ihre Sichtbarkeit.

**Andere Speicherklassen:** Neben `static` kennt C noch `auto`, `extern`
und `register` — für diesen Kurs bleibt `static` aber mit Abstand die
wichtigste, die anderen drei braucht ihr hier nicht aktiv.
{: .hinweis-klein }

---

### Clean Code: Magic Numbers vermeiden <span class="zeitangabe">ca. 8 Min.</span> { data-toc-label="Clean Code: Magic Numbers vermeiden" }

Zum Schluss ein Themenwechsel: weg davon, wie sich eine Variable verhält,
hin dazu, wie ihr die Werte in eurem Code so schreibt, dass sie für andere
nachvollziehbar bleiben.

#### Schritt 1: Füllstandsüberwachung mit "nackten" Zahlen

Ein Tank-Füllstand wird gegen zwei Schwellwerte geprüft — direkt als
Zahlenliterale im Code:

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-8-magic-numbers-vorher.c"
    ```

Ohne Kontext ist `95` nur eine Zahl — niemand, der diesen Code zum ersten
Mal liest, sieht ihr an, dass sie die kritische Füllstandsgrenze bedeutet.

---

#### Schritt 2: Dieselbe Prüfung mit benannten Konstanten

Dieselbe Logik, jetzt mit `#define`-Konstanten anstelle der Zahlenliterale:

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/live-07-9-magic-numbers-nachher.c"
    ```

!!! tip "Clean Code: Magic Numbers vermeiden"
    Eine *Magic Number* ist ein Zahlenwert, der direkt im Code auftaucht,
    ohne dass seine Bedeutung erkennbar ist. Das Problem ist doppelt: Der
    Code ist schwerer zu lesen (was bedeutet `95`?), und taucht dieselbe
    Zahl mehrfach auf, muss bei einer Änderung **jede** Stelle einzeln
    gefunden und angepasst werden — leicht wird dabei eine vergessen.
    Ersetzt ihr die Zahl stattdessen einmalig durch eine sprechend benannte
    Konstante (`#define` oder `const`), ist ihre Bedeutung sofort klar, und
    eine Änderung braucht nur noch eine einzige Stelle. Ab jetzt erwarten
    wir, dass Zahlen mit eigener Bedeutung in eurem Code als benannte
    Konstanten geschrieben werden — reine Zähl- oder Indexwerte wie die `0`
    in einer Schleifeninitialisierung sind davon ausgenommen.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

Jetzt wendet ihr die Sichtbarkeitsregeln selbst an, um zwei Programmfehler
zu finden, setzt `static` eigenständig ein, um euch über mehrere Aufrufe
hinweg einen Wert zu merken, und räumt in einem vorgegebenen Programm
Magic Numbers auf. Wer noch Zeit hat, kann sich an zwei optionalen
Zusatzaufgaben versuchen.

!!! abstract "Lernziele"
    - Ihr könnt einen Sichtbarkeitsfehler in verschachtelten
      Gültigkeitsbereichen erkennen und beheben.
    - Ihr könnt `static` eigenständig einsetzen, um einen Wert über
      mehrere Funktionsaufrufe hinweg zu speichern.
    - Ihr könnt Magic Numbers in vorgegebenem Code durch sprechend
      benannte Konstanten ersetzen.

### Aufgabe 22: Wenn Variablen sich verstecken

#### Teil A — Global oder lokal? (Schreibtischtest)

Gegeben ist das folgende Programm:

```c linenums="1"
--8<-- "02-theoriephase/termin-03/code/vorgabe-22-global-lokal.c"
```

Die Ausgaben sind absichtlich mit `A`, `B` und `C` beschriftet — **nicht**
in der Reihenfolge, in der sie tatsächlich ausgegeben werden. Notiert
**ohne Rechner**, in welcher Reihenfolge die drei Zeilen auf der Konsole
erscheinen und mit welchem Wert, und begründet, warum `ausgabe()` einen
anderen Wert ausgibt als `main`.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    Tatsächliche Ausgabe-Reihenfolge:

    ```text
    B: 10
    A: 3
    C: 10
    ```

    `main` läuft zuerst bis zu seinem ersten `printf` — zu diesem Zeitpunkt
    existiert nur die globale Variable `stand` mit dem Wert `10` (Zeile
    `B`). Erst danach wird `ausgabe()` aufgerufen: Dort verdeckt die lokale
    Variable `stand` (Wert `3`) die globale, deshalb `A: 3`. Nach der
    Rückkehr aus `ausgabe()` ist die globale Variable unverändert
    geblieben — die lokale Variable existierte nur innerhalb von
    `ausgabe()` und ist danach verschwunden, deshalb wieder `C: 10`.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Warum lässt sich das nicht bauen?

Gegeben ist das folgende Programm, das eine Temperatur prüfen und danach
melden soll, ob eine Warnung ausgelöst wurde:

```c linenums="1"
--8<-- "02-theoriephase/termin-03/code/vorgabe-22-block-sichtbarkeit.c"
```

Der Compiler lässt sich das Programm nicht bauen. Erklärt **ohne Rechner**,
woran das liegt, und korrigiert den Code so, dass er kompiliert und
weiterhin sinnvoll funktioniert.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil B anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/aufg-22-block-sichtbarkeit-korrigiert.c"
    ```

    `meldung` wird innerhalb des `if`-Blocks deklariert — ihr
    Gültigkeitsbereich endet mit dessen schließender geschweifter Klammer.
    Beim zweiten `printf`, außerhalb des Blocks, existiert die Variable
    also gar nicht mehr; der Compiler meldet einen Fehler (etwa
    "undeclared identifier"). Die Korrektur: `meldung` **vor** dem
    `if`-Block deklarieren, mit `0` initialisieren (für den Fall, dass die
    Bedingung gar nicht zutrifft) und innerhalb des Blocks nur noch
    zuweisen statt erneut zu deklarieren.
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 23: Der bisherige Höchstwert

Schreibt eine Funktion `void neuerMesswert(int wert)`, die bei jedem
Aufruf einen neuen Sensor-Messwert entgegennimmt und mitteilt, ob es sich
um den bisher größten seit Programmstart gemessenen Wert handelt:

- Ist `wert` ein neuer Höchstwert (oder der allererste Messwert
  überhaupt), gibt die Funktion z. B. `Neuer Hoechstwert: 87` aus.
- Andernfalls gibt sie z. B. `Kein neuer Hoechstwert (bisheriges Maximum:
  87)` aus.

Anders als beim Motor-Beispiel aus der Übung, das nur die Anzahl der
Aufrufe zählte, soll sich eure `static`-Variable diesmal den bisher
größten übergebenen Wert merken. Ruft die Funktion in `main` mehrfach mit
unterschiedlichen Werten auf — auch mal absteigend —, um euer Programm zu
testen.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/aufg-23-hoechstwert-messreihe.c"
    ```

    Damit auch der allererste Messwert korrekt als Höchstwert erkannt
    wird — egal ob positiv oder negativ —, merkt sich eine zweite
    `static`-Variable `ersterAufruf`, ob überhaupt schon ein Wert
    vorlag. Ein naheliegender, aber fehlerhafter Ansatz wäre, `maximum`
    einfach mit `0` zu initialisieren: Das funktioniert nur, solange alle
    Messwerte positiv sind, und liefert ein falsches Ergebnis, sobald
    auch nur ein negativer Messwert dabei ist.
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 24: Magic Numbers aufräumen

Gegeben ist das folgende Programm zur Drehzahlüberwachung eines Motors:

```c linenums="1"
--8<-- "02-theoriephase/termin-03/code/vorgabe-24-drehzahlueberwachung.c"
```

Ersetzt alle Zahlenliterale, die eine eigene Bedeutung tragen (die
Schwellwerte `5000` und `3000`), durch sprechend benannte Konstanten.
Achtet darauf, dass jeder Schwellwert nur an **einer** Stelle im Code
steht, auch wenn er mehrfach verwendet wird.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-03/code/aufg-24-magic-numbers-drehzahl.c"
    ```

    `DREHZAHL_WARNGRENZE` und `DREHZAHL_HINWEISGRENZE` machen sofort
    erkennbar, was `5000` und `3000` bedeuten. Der Wert `5000` kam im
    Original zweimal vor — jetzt genügt eine Änderung an der
    `#define`-Zeile, um beide Prüfungen konsistent anzupassen, statt beide
    Stellen einzeln suchen zu müssen.
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 25: Überlauf-Schreibtischtest

Gegeben ist das folgende Programm:

```c linenums="1"
--8<-- "02-theoriephase/termin-03/code/vorgabe-25-ueberlauf-signed.c"
```

Notiert **ohne Rechner**, welche sechs Zahlen dieses Programm nacheinander
ausgibt. Was passiert beim Übergang von `127` auf den nächsten Wert, und
warum?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Ausgabe:

    ```text
    125
    126
    127
    -128
    -127
    -126
    ```

    `signed char` ist nur 1 Byte groß und kann daher nur Werte von `-128`
    bis `127` darstellen. Nach `127` reicht der Wertebereich nicht mehr
    für `128` — auf praktisch allen heute gebräuchlichen Systemen (wie
    hier) wird dafür intern die Zweierkomplement-Darstellung verwendet,
    wodurch der Wert stattdessen auf `-128`, den kleinsten darstellbaren
    Wert, springt und von dort weiterzählt. Derselbe Mechanismus wie beim
    `unsigned char` aus der Übung, nur an der anderen Grenze des
    Wertebereichs.
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 26: Recherche — Warum feste Bitbreiten? (optional)

Recherchiert kurz (z. B. in der Dokumentation von `stdint.h` oder einer
anderen verlässlichen Quelle), warum in eingebetteten Systemen — etwa
Mikrocontrollern in der Mechatronik/Automatisierung — häufig Typen wie
`int8_t` oder `uint16_t` verwendet werden statt einfach `int`. Haltet eure
Antwort in drei bis fünf eigenen Sätzen fest.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Eine mögliche Antwort: Auf einem Mikrocontroller ist Speicher oft sehr
    knapp — ein unnötig großer Datentyp verschwendet dort Platz, der
    fehlt. Außerdem sind viele Sensor- und Aktor-Register mit einer exakt
    festgelegten Bitbreite aufgebaut (z. B. ein 8-Bit-Register); nur ein
    Typ mit garantierter Größe wie `uint8_t` passt zuverlässig genau
    hinein, während `int` je nach Plattform unterschiedlich groß sein
    kann. `stdint.h` macht Code damit auch **portabel**: Er verhält sich
    auf unterschiedlicher Hardware gleich, weil die Größen nicht mehr vom
    jeweiligen Compiler oder Prozessor abhängen.
<!-- MUSTERLOESUNG-ENDE -->
