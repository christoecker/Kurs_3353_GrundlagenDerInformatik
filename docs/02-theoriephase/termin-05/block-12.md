---
typ: theoriephase-block
termin: 5
block_id: "12"
datum: "2026-11-18"
kurztitel: "Funktionspointer"
thema: "Funktionspointer"
lernziele:
  - "Ihr könnt einen Funktionspointer deklarieren, ihm eine passende Funktion zuweisen und die Funktion darüber aufrufen."
  - "Ihr könnt eine Funktion so verallgemeinern, dass sie eine andere Funktion per Funktionspointer als Parameter entgegennimmt, statt eine feste Funktion einzubauen."
  - "Ihr könnt einen gegebenen Sortieralgorithmus so umbauen, dass sein Sortierkriterium über einen Funktionspointer austauschbar wird."
  - "Ihr könnt anhand zweier unterschiedlich formulierter Entwicklungsvorschläge beurteilen, welcher eine vorhandene, generalisierte Lösung sinnvoll wiederverwendet und welcher unnötig dupliziert."
musterloesungen_sichtbar: true
ki_einsatz: stufe_0_ohne
clean_code: []
bearbeitungsstatus: in-arbeit
publish_date: "2026-11-18"
---

# Funktionspointer (18.11.2026)

## Übung { .modus-uebung }

### Worum geht es?

Ihr kennt aus dem letzten Abschnitt Pointer auf Variablen — Pointer können
in C aber auch auf **Funktionen** zeigen. Damit lässt sich eine Funktion
selbst als Parameter an eine andere Funktion übergeben. Ihr seht heute die
Notation dafür und wendet sie an einem konkreten Beispiel an: einer
Funktion, die die Ableitung einer beliebigen mathematischen Funktion
numerisch berechnet.

!!! abstract "Lernziele"
    - Ihr könnt einen Funktionspointer deklarieren, ihm eine passende
      Funktion zuweisen und die Funktion darüber aufrufen.
    - Ihr könnt eine Funktion so verallgemeinern, dass sie eine andere
      Funktion per Funktionspointer als Parameter entgegennimmt, statt
      eine feste Funktion einzubauen.

### Notation von Funktionspointern <span class="zeitangabe">ca. 12 Min.</span> { data-toc-label="Notation von Funktionspointern" }

Ein Funktionspointer ist eine Variable, die nicht auf einen Wert, sondern
auf eine **Funktion** zeigt — genauer: auf eine Funktion mit einer
bestimmten Signatur (Anzahl und Typ der Parameter, Rückgabetyp).

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-12-1-funktionspointer-notation.c"
    ```

    1. Zwei ganz normale Funktionen mit identischer Signatur: zwei
       `int`-Parameter, `int`-Rückgabewert.
    2. Die Deklaration eines Funktionspointers: `operation` ist eine
       Variable, die auf eine Funktion mit genau dieser Signatur zeigen
       kann.
    3. Die Zuweisung: Ein Funktionsname ohne Klammern ist die Adresse
       dieser Funktion — genau wie ein Array-Name ohne Index die Adresse
       des ersten Elements ist.
    4. Der Aufruf über den Funktionspointer sieht aus wie ein ganz
       normaler Funktionsaufruf.
    5. `operation` lässt sich jederzeit neu zuweisen — zeigt jetzt auf
       eine andere Funktion mit derselben Signatur.

**Die Klammern sind Pflicht:** `int (*operation)(int, int);` deklariert
einen Pointer auf eine Funktion. Ohne die Klammern um `*operation` würde
`int *operation(int, int);` etwas ganz anderes bedeuten: eine Funktion
namens `operation`, die einen `int *` zurückgibt.
{: .hinweis-klein }

**Auflösung Block 10:** Der letzte Parameter von `qsort`,
`int (*compar)(const void *, const void *)`, ist nichts anderes als ein
Funktionspointer — eine Variable, die auf eine Vergleichsfunktion mit
genau dieser Signatur zeigt. `qsort` ruft diese Funktion über den Pointer
selbst auf, jedes Mal, wenn es zwei Elemente vergleichen muss.
{: .hinweis-klein }

---

### Funktionspointer als Parameter <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Funktionspointer als Parameter" }

Bisher war `operation` eine lokale Variable. Ein Funktionspointer lässt
sich aber genauso gut als **Parameter** einer anderen Funktion verwenden —
und genau das braucht ihr gleich für die Ableitung.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-12-2-funktionspointer-als-parameter.c"
    ```

    1. Jetzt ist der Funktionspointer nicht mehr nur eine lokale Variable,
       sondern selbst ein Parameter von `rechne` — dieselbe Syntax wie
       eben, nur an anderer Stelle.
    2. Beim Aufruf wird der Funktionsname direkt als Argument übergeben —
       kein Umweg mehr über eine eigene Pointer-Variable wie im vorigen
       Beispiel.
    3. Derselbe Aufruf von `rechne`, jetzt mit einer anderen Funktion —
       `rechne` selbst bleibt dabei unverändert.
    4. Innerhalb von `rechne` wird `operation` genauso aufgerufen wie eben
       `operation` in `main` — der Parameter verhält sich wie jeder andere
       Funktionspointer auch.

---

### Ableitung berechnen: Grundidee <span class="zeitangabe">ca. 6 Min.</span> { data-toc-label="Ableitung berechnen: Grundidee" }

Die Ableitung einer Funktion an einer Stelle `x` beschreibt, wie steil ihr
Graph dort verläuft. Vorausgesetzt, die Funktion ist **stetig** (ihr Graph
hat also keine Sprünge oder Lücken), lässt sich diese Steigung auch ohne
Formelsammlung **numerisch** annähern: Man wertet die Funktion ganz knapp
links und rechts von `x` aus (Abstand `h`, eine sehr kleine Zahl) und
schaut, wie stark sich der Funktionswert zwischen diesen beiden Punkten
verändert — das ist der sogenannte **Differenzenquotient**:

![Numerische Ableitung über den Differenzenquotienten: An den Stellen x-h und x+h werden die Funktionswerte f(x-h) und f(x+h) bestimmt. Die Steigung der grauen Verbindungsgeraden zwischen diesen beiden Punkten nähert die tatsächliche Ableitung f'(x) an der Stelle x an.](numerischeAbleitung.png){: style="width: 80%; display: block; margin: 0 auto;" }

Je kleiner `h` gewählt wird, desto genauer nähert sich dieser Wert der
tatsächlichen Ableitung an.

---

### Schritt 1: Ableitung für eine feste Funktion <span class="zeitangabe">ca. 8 Min.</span> { data-toc-label="Schritt 1: Ableitung für eine feste Funktion" }

Eine erste Version berechnet die Ableitung von `cos` an einer Stelle `x`.
`cos` (und gleich auch `sin`) kommen aus der Bibliothek `math.h` — einer
weiteren Standardbibliothek mit fertigen mathematischen Funktionen, genau
wie `string.h` für Strings oder `stdlib.h` für `rand`/`system`.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-12-3-ableitung-hartcodiert.c"
    ```

    1. Nur ein `double`-Parameter — die Stelle `x`, an der die Ableitung
       berechnet werden soll.
    2. Das numerisch berechnete Ergebnis.
    3. Zum Vergleich der bekannte analytische Wert: Die Ableitung von
       `cos` ist `-sin`.
    4. Der Differenzenquotient von eben — `cos` ist hier fest eingebaut.

**Problem:** Diese Funktion kann nur die Ableitung von `cos` berechnen.
Für `sin` oder eine andere Funktion bräuchtet ihr eine komplette Kopie mit
nur einer geänderten Zeile.
{: .hinweis-klein }

---

### Schritt 2: Ableitung für eine beliebige Funktion <span class="zeitangabe">ca. 12 Min.</span> { data-toc-label="Schritt 2: Ableitung für eine beliebige Funktion" }

Die Lösung: `ableitung` bekommt die zu untersuchende Funktion selbst als
Funktionspointer übergeben — genau wie eben `rechne` eine
Rechenoperation bekommen hat.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-12-4-ableitung-verallgemeinert.c"
    ```

    1. `ableitung` bekommt jetzt zusätzlich einen Funktionspointer `f` —
       die zu untersuchende Funktion selbst wird zum Parameter.
    2. Eine eigene Funktion für das Polynom `x³ − 2x + 1`, mit derselben
       Signatur `double -> double` wie `cos` und `sin`.
    3. `cos` und `sin` aus `math.h` haben genau die passende Signatur —
       sie lassen sich direkt als Funktionspointer übergeben, ohne
       Klammern, genau wie eben bei `addieren`/`subtrahieren`.
    4. Die analytische Ableitung von `x³ − 2x + 1` ist `3x² − 2`.
    5. Dieselbe Formel wie eben, jetzt aber mit `f(...)` statt `cos(...)`
       — funktioniert für jede Funktion, die hier übergeben wird.
    6. `polynom` selbst ist eine ganz gewöhnliche Funktion — nichts an ihr
       weiß, dass sie später per Funktionspointer aufgerufen wird.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

In der Übung habt ihr `ableitung` so verallgemeinert, dass sie für jede
Funktion mit passender Signatur funktioniert. Jetzt baut ihr in Aufgabe 36
diese Idee weiter aus — allerdings nicht selbst, sondern indem ihr zwei
fertige Entwicklungsvorschläge kritisch bewertet. Danach wendet ihr
Funktionspointer in Aufgabe 37 auf einen euch bereits bekannten
Sortieralgorithmus an.

!!! abstract "Lernziele"
    - Ihr könnt anhand zweier unterschiedlich formulierter
      Entwicklungsvorschläge beurteilen, welcher eine vorhandene,
      generalisierte Lösung sinnvoll wiederverwendet und welcher unnötig
      dupliziert.
    - Ihr könnt einen gegebenen Sortieralgorithmus so umbauen, dass sein
      Sortierkriterium über einen Funktionspointer austauschbar wird.

### Aufgabe 36: Den nächsten Entwicklungsschritt bewerten

Gegeben ist der aktuelle Stand einer kleinen Sammlung numerischer
Werkzeuge — unter anderem eure `ableitung`-Funktion aus der Übung:

```c linenums="1"
--8<-- "02-theoriephase/termin-05/code/vorgabe-36-ableitung-newton-ausgangslage.c"
```

Lest euch den Code in Ruhe durch, bevor ihr weiterlest.

**Der nächste geplante Schritt:** Die Sammlung soll um eine Funktion
`nullstelleNewton` erweitert werden, die für eine beliebige stetige,
differenzierbare Funktion eine Nullstelle in der Nähe eines Startwerts
`x0` mit dem **Newton-Verfahren** findet: Ausgehend von `x0` wird
wiederholt `x := x − f(x) / f'(x)` berechnet, bis `f(x)` nahe genug an `0`
liegt.

Zwei Entwicklungsvorschläge liegen vor, wie dieser Schritt umgesetzt werden
könnte:

=== "Vorschlag A"
    Ich lege für die Nullstellensuche zwei maßgeschneiderte
    Implementierungen an: `nullstelleNewtonCos` und `nullstelleNewtonSin`.
    Beide arbeiten nach demselben Newton-Schema, tragen aber jeweils
    direkt die mathematisch bekannte Ableitungsformel ein (`-sin` bzw.
    `cos`) — dadurch ist in jeder der beiden Funktionen auf einen Blick zu
    sehen, mit welcher Ableitung tatsächlich gerechnet wird, ohne dass man
    dafür eine andere Stelle im Programm nachschlagen müsste. Sobald ein
    Ergebnis vorliegt, teste ich beide Implementierungen an mehreren
    Startwerten und prüfe, wie zuverlässig sie konvergieren; den Fall
    einer Ableitung nahe `0` nehme ich dabei als einen von mehreren
    Sonderfällen mit auf, deren Behandlung sich am besten anhand der
    Testergebnisse entscheiden lässt.

=== "Vorschlag B"
    Ich ergänze eine einzige Funktion
    `double nullstelleNewton(double (*f)(double), double startwert)`, die
    für die Steigung die bereits vorhandene, bewährte Funktion
    `ableitung(f, x)` nutzt. Dadurch steht die Nullstellensuche sofort für
    `cos`, `sin`, `polynom` und jede künftige Funktion zur Verfügung, ohne
    dass an dieser Stelle noch einmal Code ergänzt werden muss. Zusätzlich
    baue ich eine Sicherheitsprüfung ein: Wird die Ableitung an einer
    Stelle nahezu `0`, bricht die Funktion kontrolliert mit einer
    Fehlermeldung ab, statt unkontrolliert durch eine Division durch
    (nahezu) `0` zu laufen.

**Verständnisfrage:** Welcher der beiden Vorschläge eignet sich besser als
nächster Entwicklungsschritt? Begründet eure Entscheidung mit mindestens
drei inhaltlichen Gründen.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    **Vorschlag B ist die deutlich bessere Wahl**, aus mehreren
    unabhängigen Gründen:

    1. **Vermeidet Duplikation (DRY):** Vorschlag A legt für jede
       untersuchte Funktion eine komplett neue, fast identische Funktion
       an. Vorschlag B braucht dafür nur eine einzige, generische
       Funktion.
    2. **Nutzt vorhandene, bereits getestete Arbeit:** Vorschlag A leitet
       die Ableitung für jede Funktion von Hand neu her, obwohl mit
       `ableitung` bereits eine generalisierte, funktionierende Lösung für
       genau dieses Problem existiert. Die Begründung "auf einen Blick zu
       sehen, mit welcher Ableitung gerechnet wird" klingt zunächst nach
       einem echten Vorteil (Nachvollziehbarkeit) — tatsächlich ist
       `ableitung(f, x)` genauso nachvollziehbar und zusätzlich bereits
       getestet. Vorschlag B verwendet diese vorhandene Arbeit einfach
       wieder, statt sie unnötig zu wiederholen.
    3. **Bleibt erweiterbar:** Kommt eine weitere Funktion hinzu (z. B.
       `polynom` oder eine ganz neue), funktioniert Vorschlag B ohne
       jede Codeänderung. Bei Vorschlag A müsste für jede neue Funktion
       wieder eine eigene `nullstelleNewton...`-Funktion geschrieben
       werden — genau das Problem, das die Übung mit Funktionspointern
       bereits gelöst hat, taucht hier wieder auf.
    4. **Behandelt einen echten Sonderfall, statt ihn zu vertagen:**
       Vorschlag A erwähnt den Fall "Ableitung nahe 0" zwar, verschiebt
       eine Entscheidung darüber aber auf spätere Testergebnisse — dabei
       ist der Fall vorhersehbar und nicht bloß theoretisch: Die Ableitung
       von `cos` ist `-sin`, und `sin(0) = 0` — startet die Suche also in
       der Nähe von `x = 0`, führt Vorschlag A ohne Behandlung direkt zu
       einer Division durch (nahezu) `0`. Vorschlag B behandelt genau
       diesen Fall.

    Wichtig für den Umgang mit KI-generierten Plänen ganz allgemein: Beide
    Vorschläge sind gleich selbstbewusst formuliert. Nur ein genauer Blick
    auf den **Inhalt** — nicht auf den Ton — zeigt, welcher tatsächlich
    tragfähig ist.
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 37: Bubblesort mit austauschbarem Sortierkriterium

#### Teil A — Das Kriterium finden (ohne Rechner)

Gegeben ist ein Bubblesort für `int`-Arrays, der aufsteigend sortiert:

```c linenums="1"
--8<-- "02-theoriephase/termin-05/code/vorgabe-37-bubblesort-aufsteigend.c"
```

An welcher Zeile ist das Sortierkriterium "aufsteigend" im Code
festgelegt? Was müsstet ihr an genau dieser Stelle ändern, damit
stattdessen absteigend sortiert wird — und warum ist das noch keine gute
Lösung, wenn ihr künftig mehrere Kriterien austauschbar haben wollt?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    Das Kriterium steckt in Zeile 26, der Bedingung `a[j] > a[j + 1]`. Für
    absteigend müsste sie zu `a[j] < a[j + 1]` geändert werden. Das ist
    aber keine gute Lösung für mehrere austauschbare Kriterien: Jede
    Änderung des Kriteriums bedeutet, den Quelltext von `bubblesort`
    selbst zu verändern — für zwei, drei oder mehr Kriterien bräuchte man
    entweder mehrere fast identische Kopien der ganzen Funktion oder
    müsste bei jedem Wechsel den Code neu anpassen und neu übersetzen.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Kriterium auslagern

Baut `bubblesort` so um, dass es einen dritten Parameter bekommt: einen
Funktionspointer `int (*kriterium)(int, int)` auf eine Vergleichsfunktion,
die `1` zurückgibt, wenn die beiden übergebenen Elemente in der falschen
Reihenfolge stehen (also getauscht werden müssen), sonst `0`. Lagert das
bisherige Kriterium "aufsteigend" in eine eigene Funktion `aufsteigend`
aus und übergebt sie beim Aufruf an `bubblesort`.

**Anders als bei `qsort`:** Die Vergleichsfunktion von `qsort` (Block 10)
lieferte einen von drei möglichen Werten (negativ/`0`/positiv). Hier
reicht ein einfaches Ja/Nein (`1`/`0`) für "tauschen" — Bubblesort
vergleicht immer nur benachbarte Elemente und muss nicht wissen, *wie
viel* größer oder kleiner sie sind.
{: .hinweis-klein }

---

#### Teil C — Weitere Kriterien ergänzen

Ergänzt zwei weitere Kriterien-Funktionen mit derselben Signatur:

- `absteigend`: sortiert in umgekehrter Reihenfolge.
- `geradeVorUngerade`: sortiert so um, dass alle geraden Zahlen vor allen
  ungeraden Zahlen stehen (die Reihenfolge innerhalb der beiden Gruppen
  spielt keine Rolle).

Testet `bubblesort` mit allen drei Kriterien am selben Array (Kopie des
Arrays vor jedem Aufruf nicht vergessen, sonst sortiert ihr ein bereits
verändertes Array).

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil B und C anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/aufg-37-bubblesort-funktionspointer.c"
    ```

    1. `bubblesort` kennt jetzt kein festes Kriterium mehr, sondern ruft
       das übergebene Kriterium über den Funktionspointer auf.
    2. Drei Kriterien-Funktionen mit identischer Signatur — austauschbar,
       ohne `bubblesort` selbst anzufassen.
    3. Jeder Aufruf übergibt ein anderes Kriterium — derselbe
       `bubblesort`-Code sortiert dadurch unterschiedlich.
    4. Genau die Stelle, die in Teil A noch fest `a[j] > a[j + 1]` war,
       ruft jetzt das übergebene Kriterium auf.
    5. `aufsteigend`/`absteigend` sind nur noch der Vergleich selbst — die
       Tausch-Logik bleibt zentral in `bubblesort`.
    6. `geradeVorUngerade`: Ein Tausch ist nötig, wenn das linke Element
       ungerade und das rechte gerade ist — bei gleicher Parität bleibt
       die Reihenfolge unverändert.

    Ein typischer Fehler: dasselbe Array mehrfach hintereinander sortieren
    zu lassen, ohne es zwischendurch neu zu befüllen — dann sortiert der
    zweite und dritte Aufruf ein bereits (anders) sortiertes statt des
    ursprünglichen Arrays.
<!-- MUSTERLOESUNG-ENDE -->
