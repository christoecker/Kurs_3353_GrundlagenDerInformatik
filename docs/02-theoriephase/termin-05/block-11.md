---
typ: theoriephase-block
termin: 5
block_id: "11"
datum: "2026-11-18"
kurztitel: "Pointer"
thema: "Pointer (Zeiger)"
lernziele:
  - "Ihr könnt eine Pointer-Variable deklarieren, initialisieren, ihr über den Adressoperator `&` einen Wert zuweisen und sie über `*` dereferenzieren."
  - "Ihr könnt anhand einer Speichertabelle erklären, was eine Pointer-Variable tatsächlich enthält — nämlich eine Adresse, keinen eigenen Wert."
  - "Ihr könnt selbst eine Funktion schreiben, die einen Parameter per Call by Reference statt per Call by Value entgegennimmt und verändert."
  - "Ihr könnt begründen, warum ein als Parameter übergebenes Array automatisch per Call by Reference übergeben wird, und erklären, was hinter der eckigen-Klammer-Schreibweise `a[i]` als Pointer-Arithmetik steckt."
  - "Ihr könnt einen void-Pointer erklären und ihn per Typumwandlung in einen konkreten Pointertyp umwandeln, bevor ihr ihn dereferenziert."
  - "Ihr könnt anhand von strtok erklären, wie sich eine Funktion mit static zwischen mehreren Aufrufen merken kann, und selbst eine Funktion nach diesem Prinzip schreiben."
musterloesungen_sichtbar: true
ki_einsatz: stufe_0_ohne
clean_code: []
bearbeitungsstatus: in-arbeit
publish_date: "2026-11-18"
---

# Pointer (18.11.2026)

## Übung { .modus-uebung }

### Worum geht es?

In der letzten Einheit habt ihr in der Vergleichsfunktion von `qsort`
schon Pointer benutzt, ohne dass wir uns im Detail Gedanken gemacht haben, was dahintersteckt — und
aus eurem Vorbereitungsvideo kennt ihr Pointer bereits als "Variablen, die
Adressen speichern". Heute arbeitet ihr das aus: Ihr seht, was ein Pointer
im Speicher tatsächlich enthält, wie er die in Termin 4 nur beobachtete
Call-by-Reference-Übergabe technisch möglich macht, und wendet das Ganze in
einer eigenen kleinen Kopierfunktion an.

!!! abstract "Lernziele"
    - Ihr könnt eine Pointer-Variable deklarieren, initialisieren, ihr über
      den Adressoperator `&` einen Wert zuweisen und sie über `*`
      dereferenzieren.
    - Ihr könnt anhand einer Speichertabelle erklären, was eine
      Pointer-Variable tatsächlich enthält — nämlich eine Adresse, keinen
      eigenen Wert.
    - Ihr könnt selbst eine Funktion schreiben, die einen Parameter per
      Call by Reference statt per Call by Value entgegennimmt und
      verändert.
    - Ihr könnt begründen, warum ein als Parameter übergebenes Array
      automatisch per Call by Reference übergeben wird, und erklären, was
      hinter der eckigen-Klammer-Schreibweise `a[i]` als Pointer-Arithmetik
      steckt.
    - Ihr könnt einen void-Pointer erklären und ihn per Typumwandlung in
      einen konkreten Pointertyp umwandeln, bevor ihr ihn dereferenziert.

### Kurzer Rückblick <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Kurzer Rückblick" }

**1. Wozu dient das Konzept, dass eine Variable neben ihrem Wert auch eine Adresse im Speicher hat, an der sie zu finden ist?**

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Über die Adresse lässt sich eine Speicherstelle gezielt ansprechen,
    unabhängig davon, welcher Wert dort gerade liegt. Das ist die
    Grundlage dafür, dass sich eine Adresse selbst weitergeben lässt — zum
    Beispiel damit `scanf_s` weiß, wohin es einen eingelesenen Wert
    schreiben soll (Adressoperator `&`, aus Termin 1 bekannt), oder damit
    eine Funktion direkt auf eine Variable außerhalb von sich selbst
    zugreifen kann.
<!-- MUSTERLOESUNG-ENDE -->

**2. Was ist grundsätzlich der Unterschied zwischen Call by Value und Call by Reference?**

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Bei Call by Value bekommt eine Funktion nur eine **Kopie** des
    übergebenen Werts — Änderungen daran wirken sich nicht auf das
    Original aus. Bei Call by Reference bekommt die Funktion dagegen
    Zugriff auf das **Original** selbst; Änderungen wirken sich also auch
    außerhalb der Funktion aus.
<!-- MUSTERLOESUNG-ENDE -->

---

### Pointer im Speicher: eine Variable und ihr Pointer <span class="zeitangabe">ca. 10 Min.</span> { data-toc-label="Pointer im Speicher" }

Um zu verstehen, was ein Pointer wirklich ist, hilft ein Blick auf den
Speicher selbst. Die folgende Tabelle stellt einen Ausschnitt davon dar —
die Adressen sind frei erfunden, um das Prinzip zu zeigen:

| Adresse | Name            | Inhalt |
|---------|-----------------|--------|
| 1000    | `zahl`          | 42     |
| 1004    | `zeigerAufZahl` | 1000   |

`zahl` ist eine ganz normale `int`-Variable: An Adresse 1000 liegt ihr
Wert, `42`. `zeigerAufZahl` ist dagegen ein **Pointer** — auch er ist eine
Variable mit eigener Adresse (1004), aber sein *Inhalt* ist nicht `42`,
sondern die Zahl `1000`: die Adresse von `zahl`. Ein Pointer speichert also
nie einen "normalen" Wert, sondern immer eine Adresse.

**Achtung, erfundene Zahlen:** `1000` und `1004` sind frei gewählt, damit
sich das Prinzip leicht merken lässt. Echte Adressen, die euch das
Programm gleich mit `%p` ausgibt, sehen ganz anders aus (lange
Hexadezimalzahlen), und ein Pointer selbst belegt auf den meisten
heutigen Rechnern 8 Byte, nicht 4 — er ist also nicht automatisch "genauso
groß" wie die Variable, auf die er zeigt.
{: .hinweis-klein }

Zwei Operatoren verbinden beide Zeilen der Tabelle miteinander:

- Der **Adressoperator** `&` liefert zu einer Variable ihre Adresse: `&zahl`
  ergibt `1000` — genau der Inhalt, den `zeigerAufZahl` gespeichert hat.
- Die **Dereferenzierung** `*` liefert zu einem Pointer den Wert, der an
  der gespeicherten Adresse liegt: `*zeigerAufZahl` folgt der `1000` und
  liefert `42`.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-11-1-pointer-basis.c"
    ```

    1. `zeigerAufZahl` ist selbst eine Variable — ihr Datentyp `int *`
       bedeutet "Pointer auf int". Initialisiert wird sie mit der Adresse
       von `zahl`, geliefert vom Adressoperator `&`.
    2. `&zahl` liefert die Adresse von `zahl` — der Wert, den ihr euch in
       der Speichertabelle als `1000` vorgestellt habt. Für die Ausgabe
       einer Adresse braucht `printf` das Formatierungszeichen `%p`.
    3. `zeigerAufZahl` selbst gibt genau diese Adresse aus — er ist ja
       nichts anderes als eine Kopie davon.
    4. `*zeigerAufZahl` (Dereferenzierung) liefert den Wert, der an der
       gespeicherten Adresse liegt — also den Wert von `zahl`.
    5. Über die Dereferenzierung lässt sich der Wert an dieser Adresse auch
       **verändern**: `*zeigerAufZahl = 100` verändert `zahl` selbst,
       obwohl im Code an dieser Stelle gar nicht `zahl` steht.

---

### Call by Reference: wertVerdoppeln endlich reparieren <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Call by Reference reparieren" }

Erinnert euch an `wertVerdoppeln` aus Termin 4: Der Parameter war eine
einfache `int`-Variable, die Funktion bekam also nur eine Kopie (Call by
Value) und der Aufrufer hat von der Verdopplung nichts gemerkt. Mit Pointern
lässt sich das jetzt reparieren.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-11-2-wertverdoppeln-call-by-reference.c"
    ```

    1. Genau wie in Termin 4: Der Parameter ist eine einfache
       `int`-Variable, die Funktion bekommt also nur eine Kopie (Call by
       Value).
    2. Jetzt ist der Parameter ein `int *` — ein Pointer auf `int`. Die
       Funktion bekommt keine Kopie des Werts mehr, sondern die Adresse
       der Originalvariable.
    3. Wie in Termin 4 beobachtet: unverändert, weil nur die Kopie
       verdoppelt wurde.
    4. Beim Aufruf wird diesmal nicht der Wert, sondern mit `&einzelwert`
       seine Adresse übergeben.
    5. Diesmal hat sich `einzelwert` tatsächlich verändert — die Funktion
       hatte über die Adresse Zugriff auf das Original.
    6. Im Funktionskörper wird zuerst dereferenziert (`*wert`), um an den
       Wert an dieser Adresse zu kommen, verdoppelt, und über dieselbe
       Dereferenzierung wieder zurückgeschrieben.

---

### Warum Arrays automatisch Call by Reference sind <span class="zeitangabe">ca. 10 Min.</span> { data-toc-label="Arrays und Call by Reference" }

Jetzt lässt sich auflösen, was in Termin 4 offenblieb: Warum verändert eine
Funktion wie `arrayVerdoppeln(int werte[], int laenge)` das übergebene
Array, obwohl `wertVerdoppeln` mit einem einzelnen `int`-Parameter das
Original unangetastet ließ?

#### Schritt 1: Zwei Schreibweisen für denselben Parameter

Die Antwort: **Ein Array-Parameter ist in Wirklichkeit immer ein Pointer.**
Die Schreibweise `int werte[]` und die Schreibweise `int *werte` bedeuten
als Parameter exakt dasselbe — der Compiler behandelt sie identisch.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-11-3-array-pointer-notation.c"
    ```

    1. Die Schreibweise, die ihr seit Termin 4 kennt: ein Array als
       Parameter.
    2. Exakt dieselbe Funktion, nur mit `int *werte` statt `int werte[]`
       als Parameter.
    3. Beide Funktionen liefern dasselbe Ergebnis — es ist buchstäblich
       derselbe Maschinencode, nur anders geschrieben.
    4. Auch mit `int *werte` als Parameter funktioniert die gewohnte
       eckige-Klammer-Schreibweise `werte[i]` ganz normal weiter — was
       dahintersteckt, seht ihr im nächsten Schritt.

**Auflösung Termin 4:** Wird ein Array an eine Funktion übergeben, zerfällt
der Array-Name automatisch zu einem Pointer auf sein erstes Element — die
Funktion bekommt also, genau wie eben bei `wertVerdoppelnReferenz`, eine
Adresse statt einer Kopie. Deshalb verändert `arrayVerdoppeln` das
Original, obwohl dort nirgends ein `*` zu sehen war.
{: .hinweis-klein }

---

#### Schritt 2: Was hinter `a[i]` wirklich steckt

Die eckige Klammer ist selbst nur eine bequemere Schreibweise für etwas,
das direkt mit Pointern zu tun hat: **Pointer-Arithmetik**.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-11-4-pointer-arithmetik.c"
    ```

    1. `messwerte[1]` — die gewohnte Schreibweise für das zweite Element.
    2. `messwerte + 1` ist die Adresse des zweiten Elements — eine Adresse
       plus `1` zeigt in C automatisch auf das *nächste* Element desselben
       Typs, nicht eine einzelne Speicherzelle weiter. `*(messwerte + 1)`
       dereferenziert diese Adresse — das Ergebnis ist identisch zu
       `messwerte[1]`.
    3. Dasselbe Prinzip beim Index `3`: `a[i]` ist also, egal an welcher
       Stelle, nur eine bequemere Schreibweise für `*(a + i)` — hinter
       jeder eckigen Klammer stecken immer Pointer-Arithmetik (`+ i`) und
       Dereferenzierung (`*`).

**Die Pointer-Arithmetik im Code noch einmal im Zusammenhang:** `messwerte + 1`
ist eine Adresse — die Adresse des zweiten Elements. Weil ein Pointer weiß,
auf welchen Datentyp er zeigt (hier `int`), bedeutet `+ 1` dabei "ein
Element weiter", nicht "ein Byte weiter". `*(messwerte + 1)` dereferenziert
diese Adresse und liefert den Wert dort — exakt denselben Wert wie
`messwerte[1]`. Und weil `i` selbst eine Variable sein kann, funktioniert
das genauso mit `*(messwerte + 3)` bzw. `messwerte[3]`: Allgemein ist
`a[i]` für jeden Pointer und jedes Array nur eine andere Schreibweise für
`*(a + i)`.
{: .hinweis-klein }

---

### void-Pointer und Typumwandlung <span class="zeitangabe">ca. 8 Min.</span> { data-toc-label="void-Pointer und Typumwandlung" }

Bisher hat jeder Pointer genau festgelegt, auf welchen Datentyp er zeigt
(`int *`, `double *`, ...). Ein **void-Pointer** (`void *`) zeigt dagegen
auf eine Adresse, **ohne** festzulegen, welcher Datentyp dort liegt — genau
das habt ihr bei `qsort` schon gesehen (`const void *`). Bevor sich ein
void-Pointer dereferenzieren lässt, muss er per **Typumwandlung (Cast)**
erst wieder in einen konkreten Pointertyp verwandelt werden.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-11-5-void-pointer.c"
    ```

    1. Der Parameter ist ein `void *` — ein Pointer, der auf **irgendeinen**
       Datentyp zeigen kann. `adresseAusgeben` lässt sich deshalb mit jeder
       Adresse aufrufen, egal worauf sie zeigt.
    2. Eine `void *`-Variable speichert nur eine Adresse, ohne festzulegen,
       welcher Datentyp dort liegt.
    3. Ein `int *` (die Adresse von `ganzzahl`) lässt sich ohne
       ausdrückliche Typumwandlung einem `void *` zuweisen.
    4. Ein `void *` lässt sich nicht ohne Weiteres dereferenzieren — der
       Compiler wüsste nicht, wie viele Bytes er lesen soll. Die
       Typumwandlung `(int *)` sagt ihm: "Behandle diese Adresse als
       Adresse eines `int`". Erst danach, in der eigenen Variable
       `alsIntPointer`, ist die Dereferenzierung `*alsIntPointer` erlaubt.
    5. Dieselbe Dereferenzierung lässt sich auch ohne die Zwischenvariable
       in einer Zeile schreiben. Lest sie dabei von innen nach außen:
       zuerst der Cast `(int *)irgendeineAdresse` (macht daraus einen
       `int *`), danach erst der `*` davor (dereferenziert diesen
       Pointer). Beide Schreibweisen liefern dasselbe Ergebnis.
    6. Dieselbe Adressvariable, jetzt mit einer anderen Typumwandlung —
       dieselbe Speicherstelle lässt sich also je nach Cast völlig
       unterschiedlich deuten.

---

### Aufgabe 34: Byte-weises Kopieren <span class="zeitangabe">ca. 10 Min.</span> { data-toc-label="Aufgabe 34: Byte-weises Kopieren" }

Gesucht ist eine Funktion, die den Inhalt einer Speicherstelle an eine
andere kopiert — unabhängig davon, welcher Datentyp dort eigentlich liegt.
Genau das macht in echten C-Programmen zum Beispiel `memcpy` aus
`string.h`; heute nähert ihr euch einer eigenen, einfacheren Version davon
in zwei Schritten.

#### Schritt 1: Erst nur für int-Arrays

Eine erste Version kopiert nur `int`-Arrays:

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-11-6-byteweise-kopieren-typisiert.c"
    ```

    1. `const int *quelle` heißt: Die Funktion darf lesen, was an `quelle`
       liegt, aber nichts daran verändern.
    2. Diese Funktion kopiert nur `int`-Arrays — funktioniert also nur für
       genau diesen einen Datentyp.
    3. `size_t` ist derselbe vorzeichenlose Ganzzahltyp, den ihr schon von
       `sizeof` und `strlen`/`%zu` aus Termin 4 kennt — hier als
       Schleifenzähler für eine Anzahl verwendet.
    4. Die eigentliche Kopierschleife: Für jedes Element wird der Wert von
       `quelle` nach `ziel` übertragen.

Diese Funktion funktioniert nur für `int`-Arrays. Für jeden weiteren
Datentyp (`double`, eine Struktur, ...) bräuchtet ihr eine eigene, fast
identische Kopierfunktion — ein klassischer DRY-Verstoß. Mit einem
void-Pointer lässt sich das vermeiden: eine einzige Funktion für **jeden**
Datentyp.
{: .hinweis-klein }

---

#### Schritt 2: Verallgemeinert mit void-Pointer

Die Funktion soll `void meinKopieren(void *ziel, const void *quelle,
size_t anzahlBytes)` heißen und `anzahlBytes` Bytes ab der Adresse `quelle`
an die Adresse `ziel` kopieren.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-11-7-byteweise-kopieren-void.c"
    ```

    1. Wie eben bei `intArrayKopieren`: `const` beim `quelle`-Parameter
       heißt, die Funktion darf lesen, aber nichts verändern. Neu ist:
       Beide Parameter sind jetzt `void *`, nicht mehr `int *`.
    2. `sizeof(int)` liefert genau die Anzahl Bytes, die ein `int` belegt
       — üblicherweise 4.
    3. Dieselbe Funktion, diesmal mit `sizeof(double)`: Sie weiß nichts
       über `int` oder `double`, sie kopiert einfach die passende Anzahl
       Bytes.
    4. Beide `void *`-Parameter werden zuerst per Typumwandlung in
       `unsigned char *` verwandelt — erst dadurch lässt sich byteweise
       (in Einer-Schritten) durch den Speicher bewegen. Ein `void *`
       selbst lässt sich weder dereferenzieren noch mit `+` verschieben.
    5. `zielBytes[i]` ist, wie weiter oben gezeigt, nur eine bequemere
       Schreibweise für `*(zielBytes + i)` — hier wird also mit
       Pointer-Arithmetik byteweise durch beide Speicherbereiche
       gewandert.

**Verständnisfrage:** Warum funktioniert `meinKopieren` allgemeingültig für
beliebige Datentypen — ihr könntet mit ihr genauso gut ein `int`-Array wie
eine `double`-Variable kopieren —, obwohl C doch sonst so streng typisiert
ist?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Im Speicher ist jeder Datentyp letztlich nur eine Folge von Bytes —
    der Unterschied liegt allein darin, wie diese Bytes *interpretiert*
    werden. `meinKopieren` interessiert sich gar nicht für die
    Interpretation, sondern kopiert die reinen Bytes unverändert von einer
    Adresse zur anderen. Möglich wird das durch den `void *`-Parameter: Er
    überträgt keine Typinformation, sondern nur eine Adresse. Der Cast auf
    `unsigned char *` macht daraus einen Pointer, mit dem sich einzeln
    byteweise zugreifen lässt (`unsigned char` ist immer genau 1 Byte
    groß) — egal, welcher Datentyp an dieser Adresse eigentlich liegt.
<!-- MUSTERLOESUNG-ENDE -->

---

### Zeichenketten zerlegen: strtok <span class="zeitangabe">ca. 5 Min.</span> { data-toc-label="Zeichenketten zerlegen: strtok" }

Zum Abschluss ein Ausblick auf eine nützliche Funktion aus `string.h`:
`strtok` zerlegt einen String an Trennzeichen in einzelne Teilstücke — zum
Beispiel praktisch, wenn ihr eine Zeile aus einer CSV-Datei mit Messwerten
auslesen wollt. Referenz:
[devdocs.io/c/string/byte/strtok](https://devdocs.io/c/string/byte/strtok).

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/live-11-8-strtok-csv.c"
    ```

    1. Diese Zeile muss vor allen `#include`-Zeilen stehen (sonst wirkt sie
       nicht). Sie schaltet in Visual Studio die Fehlermeldung für
       "unsichere" Standardfunktionen wie `strtok` ab — mehr dazu im
       Hinweis direkt unter dem Code.
    2. Eine Zeile, wie sie zum Beispiel aus einer CSV-Datei mit Messwerten
       stammen könnte, mit `;` als Trennzeichen.
    3. Der **erste** Aufruf von `strtok` bekommt den zu durchsuchenden
       String selbst. Er liefert einen Pointer auf das erste gefundene
       Teilstück, bis zum ersten Trennzeichen.
    4. `strtok` gibt `NULL` zurück, wenn kein weiteres Teilstück mehr
       gefunden wird — Abbruchbedingung der Schleife.
    5. **Jeder weitere** Aufruf bekommt statt des Strings den
       `NULL`-Pointer übergeben — `strtok` liefert trotzdem das nächste
       Teilstück. Wie das funktioniert, überlegt ihr euch gleich selbst im
       betreuten Selbststudium.

**Achtung:** `strtok` verändert den übergebenen String selbst (es ersetzt
jedes gefundene Trennzeichen durch `'\0'`) — deshalb hier ein veränderbares
`char`-Array (`char zeile[] = ...`), kein `const char *`.
{: .hinweis-klein }

**Achtung, Visual Studio:** Genau wie schon bei `strcpy`/`strcat` in
Termin 4 markiert Visual Studio auch `strtok` als "unsicher" (Warnung
C4996) — mit den Standardeinstellungen eines neuen Visual-Studio-Projekts
bricht der Build dabei sogar mit einem **Fehler** ab, nicht nur mit einer
Warnung. Die Zeile `#define _CRT_SECURE_NO_WARNINGS` ganz am Anfang des
Programms (vor allen `#include`-Zeilen) schaltet diese Fehlermeldung
gezielt ab. Anders als bei `strcpy_s`/`strcat_s` steigt dieser Kurs hier
aber bewusst **nicht** auf `strtok_s` um: `strtok_s` merkt sich die
Position nicht mehr selbst, sondern verlangt dafür einen eigenen
Kontext-Parameter — genau das `static`-Gedächtnis, um das es im betreuten
Selbststudium gleich geht, wäre damit gar nicht mehr zu entdecken.
{: .hinweis-klein }

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

In der Übung habt ihr gesehen, *dass* `strtok` sich zwischen den Aufrufen
merkt, wo es weitermachen muss — jetzt überlegt ihr euch selbst, *wie* das
funktionieren könnte, und schreibt danach eine eigene, einfachere Funktion
nach demselben Prinzip.

!!! abstract "Lernziele"
    - Ihr könnt anhand von strtok erklären, wie sich eine Funktion mit
      static zwischen mehreren Aufrufen merken kann, und selbst eine
      Funktion nach diesem Prinzip schreiben.

### Aufgabe 35: Wie merkt sich strtok, wo es weitermachen muss?

#### Teil A — Diskussion und PAP (ohne Rechner)

Diskutiert zu zweit oder zu dritt, wie `strtok` es schafft, sich beim
zweiten Aufruf (mit `NULL` statt dem String) zu merken, (a) welchen String
es überhaupt durchsucht, (b) an welcher Stelle im String es beim letzten
Mal aufgehört hat, und (c) woran es merkt, dass gar kein weiteres
Trennzeichen mehr da ist. Skizziert eure Idee als PAP.

Nutzt bei Bedarf die folgenden Hinweise — schaut erst bei Hinweis 2 nach,
wenn ihr mit Hinweis 1 allein nicht weiterkommt, und bei Hinweis 3, wenn
euch noch die Rückgabe fehlt.

??? tip "Hinweis 1"
    Überlegt zunächst nur: Woher weiß die Funktion beim zweiten Aufruf
    überhaupt noch etwas von eurem String, obwohl ihr ihr dabei nur `NULL`
    übergebt? Sie muss sich also zwischen zwei Aufrufen irgendetwas
    gemerkt haben. Ihr kennt aus Termin 3 bereits ein Sprachmittel, mit dem
    eine lokale Variable ihren Wert über mehrere Funktionsaufrufe hinweg
    behalten kann, statt bei jedem Aufruf neu (und leer) angelegt zu
    werden. Welches?

??? tip "Hinweis 2"
    Genau: Mit `static` lässt sich innerhalb von `strtok` eine
    Pointer-Variable anlegen, die zwischen den Aufrufen erhalten bleibt.
    Sie merkt sich, an welcher Stelle im String die nächste Suche beginnen
    soll. Bekommt `strtok` einen echten String übergeben, wird diese
    Variable auf dessen Anfang gesetzt. Bekommt es stattdessen `NULL`,
    bleibt sie unverändert — die Suche geht dann genau dort weiter, wo sie
    beim letzten Mal aufgehört hat. Ab dieser Position sucht `strtok` das
    nächste Trennzeichen. Überlegt: Was passiert, wenn gar keines mehr
    gefunden wird?

??? tip "Hinweis 3"
    Bleibt noch die Frage, *was* `strtok` bei einem Treffer eigentlich
    zurückgibt. Ihr müsst dafür keine Kopie des gefundenen Teilstücks
    irgendwo zwischenspeichern: Es reicht, einen Pointer auf den Anfang
    des Teilstücks **direkt im ursprünglichen String** zurückzugeben.
    Damit dieser Teilstring für sich genommen korrekt endet (und nicht bis
    zum Ende der ganzen Zeile weiterläuft), überschreibt `strtok` an der
    Fundstelle das Trennzeichen mit dem Stringende-Zeichen `'\0'` — genau
    der Grund, warum weiter oben in der Übung stand, dass `strtok` den
    übergebenen String selbst verändert.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```mermaid
    %%{init: {'flowchart': {'htmlLabels': false}}}%%
    flowchart TD
        A(["Aufruf von strtok"])
        B{"Parameter = NULL?"}
        C["static Position := Anfang des uebergebenen Strings"]
        D["Ab der gemerkten static Position weitersuchen"]
        E{"Noch ein Trennzeichen gefunden?"}
        F["Teilstueck bis zum Trennzeichen bestimmen"]
        G["static Position := Stelle nach dem gefundenen Trennzeichen"]
        H[/"Ausgabe: Pointer auf das gefundene Teilstueck"/]
        I[/"Ausgabe: NULL"/]
        A --> B
        B -->|nein| C --> E
        B -->|ja| D --> E
        E -->|ja| F --> G --> H
        E -->|nein| I
    ```

    Der entscheidende Punkt ist die `static`-Variable "Position": Sie
    existiert nur ein einziges Mal und überlebt zwischen zwei Aufrufen von
    `strtok`. Beim ersten Aufruf (Parameter ungleich `NULL`) wird sie neu
    auf den Anfang des übergebenen Strings gesetzt. Bei jedem weiteren
    Aufruf mit `NULL` bleibt sie unverändert und zeigt genau dorthin, wo
    die Suche beim letzten Mal aufgehört hat — dadurch kann `strtok` sich
    "erinnern", obwohl ihm beim zweiten Aufruf gar keine Information mehr
    über den String mitgegeben wird. Zusätzlich prüft die Funktion bei
    jedem Aufruf, ob überhaupt noch ein weiteres Trennzeichen zu finden
    ist: Ist das nicht der Fall, gibt sie `NULL` zurück, statt
    weiterzusuchen — genau das beendet die `while`-Schleife in der Übung.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — inttok programmieren (mit Rechner)

Gegeben ist ein `int`-Array `A[]` der Länge `n > 0`, dessen Elemente alle
bis auf das letzte größer als `0` sind, zum Beispiel:

```c
int A[] = { 4, 1, 3, 6, 5, 2, 0 };
```

Schreibt eine Funktion `int *inttok(int *A, int cmp)`. Der zweite Parameter
`cmp` ist ein Vergleichswert.

- Wird die Funktion mit dem Array aufgerufen (`A` ist nicht `NULL`), soll
  sie einen Pointer auf das erste Element zurückgeben, das größer als
  `cmp` ist.
- Wird die Funktion danach erneut aufgerufen, diesmal mit dem
  `NULL`-Pointer anstelle des Arrays, soll sie einen Pointer auf das
  nächste Element liefern, das wieder größer als `cmp` ist.
- Trifft die Funktion dabei auf ein Array-Element mit dem Wert `0`, soll
  sie `NULL` zurückgeben.

Nutzt dieselbe Idee wie in Teil A: eine `static`-Variable, die sich
zwischen den Aufrufen merkt, wo die Suche weitergeht. Das folgende,
bereits vollständige Testprogramm ruft `inttok` mit `cmp = 2` so lange auf,
bis `NULL` zurückkommt — ihr müsst nur noch die Funktion selbst ergänzen:

```c linenums="1"
--8<-- "02-theoriephase/termin-05/code/vorgabe-35-inttok.c"
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-05/code/aufg-35-inttok.c"
    ```

    1. `static` sorgt dafür, dass `position` ihren Wert über mehrere
       Aufrufe hinweg behält, statt bei jedem Aufruf neu (und
       uninitialisiert) angelegt zu werden — genau wie beim Aufrufzähler
       aus Termin 3.
    2. Nur beim **ersten** Aufruf (mit dem echten Array) wird `position`
       neu gesetzt; bei allen folgenden Aufrufen mit `NULL` bleibt der
       zuletzt gemerkte Stand erhalten.
    3. `0` markiert wie in der Aufgabenstellung vorgegeben das Ende des
       Arrays — die Schleife läuft, solange noch gültige Elemente kommen.
    4. Sobald ein Element größer als `cmp` gefunden wird, ist ein Treffer
       da.
    5. `position` wird schon jetzt einen Schritt weitergeschoben
       (Pointer-Arithmetik, wie in der Übung), damit der **nächste**
       Aufruf genau danach weitersucht — nicht wieder beim selben Treffer.
    6. Wird `0` erreicht, ohne dass noch ein Treffer gefunden wurde, gibt
       es nichts mehr zu finden — Rückgabe `NULL`.

    Ein typischer Fehler ist, `position` schon **vor** der
    Treffer-Prüfung zu erhöhen: Dann würde beim Rückgabewert `treffer` auf
    das falsche (nämlich das übernächste) Element zeigen, statt auf das
    gerade gefundene.
<!-- MUSTERLOESUNG-ENDE -->
