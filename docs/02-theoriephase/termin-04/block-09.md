---
typ: theoriephase-block
termin: 4
block_id: "09"
datum: "2026-11-11"
kurztitel: "Strings"
thema: "Strings (Zeichenketten) und string.h"
lernziele:
  - "Du kannst erklären, was ein String in C ist und welche Rolle das Stringende-Zeichen '\\0' spielt."
  - "Du kannst die Länge eines Strings (strlen) von seiner Speichergröße (sizeof) unterscheiden."
  - "Du kannst wichtige Funktionen aus string.h (strlen, strcmp, strcpy_s, strcat_s) sowie atoi und atof anwenden."
  - "Du kannst Zeichen über ihre ASCII-Codes vergleichen und umrechnen."
  - "Du kannst eine Funktion schreiben, die einen String Zeichen für Zeichen bis zum Stringende verarbeitet."
  - "Du kannst begründen, warum eine String-Funktion keine Längenangabe braucht, eine Funktion für ein int-Array aber schon — und welche Voraussetzung dafür gelten muss."
musterloesungen_sichtbar: true
ki_einsatz: stufe_0_ohne
clean_code: []
bearbeitungsstatus: in-arbeit
publish_date: "2026-11-11"
---

# Strings (11.11.2026)

## Übung { .modus-uebung }

### Worum geht es?

Text besteht aus Zeichen — und Zeichen kennt ihr schon: ein `char` speichert
genau eines. Für ein ganzes Wort oder einen Satz braucht ihr viele davon
hintereinander, also ein Array aus `char`. Ein solches Array mit einer
besonderen Endmarkierung heißt **String**. Ihr habt das im
Vorbereitungsvideo gesehen; heute setzt ihr es um und schreibt eigene
Funktionen, die Strings bearbeiten.

!!! abstract "Lernziele"
    - Ihr könnt erklären, was ein String in C ist und welche Rolle das
      Stringende-Zeichen `'\0'` spielt.
    - Ihr könnt die Länge eines Strings (`strlen`) von seiner Speichergröße
      (`sizeof`) unterscheiden.
    - Ihr könnt wichtige Funktionen aus `string.h` (`strlen`, `strcmp`,
      `strcpy_s`, `strcat_s`) sowie `atoi` und `atof` anwenden.
    - Ihr könnt Zeichen über ihre ASCII-Codes vergleichen und umrechnen.
    - Ihr könnt eine Funktion schreiben, die einen String Zeichen für
      Zeichen bis zum Stringende verarbeitet.
    - Ihr könnt begründen, warum eine String-Funktion keine Längenangabe
      braucht, eine Funktion für ein `int`-Array aber schon — und welche
      Voraussetzung dafür gelten muss.


### Was ist ein String? <span class="zeitangabe">ca. 6 Min.</span> { data-toc-label="Was ist ein String?" }

Ein **String** (Zeichenkette) ist ein `char`-Array, dessen letztes Zeichen
das **Stringende-Zeichen** `'\0'` ist (Zeichencode `0`). Man spricht von
einem **nullterminierten** String. Dieses Zeichen sieht man nicht, aber es
ist da — und es ist der Grund, warum Funktionen wie `printf` wissen, wo ein
String aufhört.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/live-09-1-string-grundlagen.c"
    ```

    1. Bei `[]` ohne Größenangabe zählt der Compiler die Zeichen und hängt
       das Stringende-Zeichen selbst an: `"Hallo"` belegt 6 Elemente.
    2. Dasselbe von Hand geschrieben: Das letzte Element ist das
       Stringende-Zeichen `'\0'`.
    3. `%s` gibt Zeichen aus, bis das erste `'\0'` kommt.
    4. `sizeof` zählt das Stringende-Zeichen mit (6 Byte), `strlen` zählt
       nur die Zeichen davor (5).
    5. Einzelne Zeichen lassen sich wie bei jedem Array ändern. Ein einzelnes
       Zeichen steht dabei in Apostrophen, ein ganzer String in
       Anführungszeichen.
    6. Ein `'\0'` mitten im String verkürzt ihn: Für `printf` und `strlen`
       endet der String jetzt dort — obwohl die restlichen Zeichen noch im
       Speicher liegen.

**Formatierungszeichen `%zu`:** `sizeof` und `strlen` liefern denselben
Typ (`size_t`), dafür gibt es `%zu` — bekannt aus dem `sizeof`-Beispiel in
Termin 3.
{: .hinweis-klein }

---

### Das Stringende selbst finden <span class="zeitangabe">ca. 4 Min.</span> { data-toc-label="Das Stringende selbst finden" }

Wie ermittelt `strlen` die Länge? Wir schreiben es selbst: einfach Zeichen
für Zeichen weitergehen, bis das Stringende-Zeichen kommt.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/live-09-2-laenge-selbst.c"
    ```

    1. Die Funktion bekommt nur den String — keinen Längenparameter, anders
       als bei den `int`-Arrays aus der Übung eben.
    2. Die Schleife läuft, bis das Stringende-Zeichen erreicht ist.

---

### string.h im Überblick <span class="zeitangabe">ca. 8 Min.</span> { data-toc-label="string.h im Überblick" }

Die Bibliothek `string.h` enthält fertige Funktionen für Strings — ihr müsst
`strlen` & Co. also nicht jedes Mal selbst schreiben.

#### Schritt 1: Die wichtigsten Funktionen

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/live-09-3-string-h.c"
    ```

    1. `strlen` liefert die Länge ohne das Stringende-Zeichen.
    2. `strcmp` vergleicht zwei Strings und liefert `0`, wenn sie gleich sind.
       Ein Vergleich mit `==` funktioniert bei Strings **nicht** so, wie man
       es erwartet — warum, klären wir bei den Pointern.
    3. `strcpy_s(ziel, größe, quelle)` kopiert einen String samt
       Stringende-Zeichen. Die Größe des Ziels ist ein Parameter, damit nicht
       über das Ende des Ziel-Arrays hinaus geschrieben wird.
    4. `strcat_s` hängt einen String hinten an. Das Ziel muss dafür bereits
       ein gültiger String sein und genug Platz haben.

**`_s`-Varianten:** Die Funktionen `strcpy` und `strcat` ohne `_s` gibt es
auch. Visual Studio meldet sie aber als unsicher (Fehlermeldung C4996), weil
sie die Größe des Ziels nicht prüfen. Ihr nutzt deshalb wie bei `scanf_s`
die Varianten mit `_s`. Sie gehören zu Visual Studio; in anderen
Entwicklungsumgebungen können sie fehlen.
{: .hinweis-klein }

---

#### Schritt 2: Text in Zahlen umwandeln

Ein Sensor liefert seinen Messwert oft als Text, zum Beispiel `"23.5"`. Zum
Rechnen braucht ihr daraus eine Zahl. Dafür gibt es `atoi` (String → `int`)
und `atof` (String → `double`).

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/live-09-4-atoi-atof.c"
    ```

    1. `atoi` und `atof` stehen nicht in `string.h`, sondern in `stdlib.h` —
       derselben Bibliothek wie `system`.
    2. `atoi` wandelt in eine ganze Zahl um, `atof` in eine Kommazahl.
    3. Ist der Text keine Zahl, geben beide einfach `0` zurück, ohne
       Fehlermeldung. Ihr könnt so eine ungültige Eingabe nicht von einer
       echten `0` unterscheiden.

**Voraussetzung:** Fast alle Funktionen aus `string.h` erwarten einen
String **mit** Stringende-Zeichen. Warum das so wichtig ist, sehen wir am
Ende der Übung.
{: .hinweis-klein }

---

### toUpper und toLower selbst entwickeln <span class="zeitangabe">ca. 10 Min.</span> { data-toc-label="toUpper und toLower selbst entwickeln" }

Wir schreiben zwei eigene Funktionen, die einen String in Groß- bzw.
Kleinbuchstaben umwandeln. Dafür brauchen wir die ASCII-Tabelle: Jedes
Zeichen ist intern eine Zahl, und die Buchstaben stehen in
aufeinanderfolgenden Blöcken.

| Zeichen | ASCII-Code |
|---|---|
| `'A'` bis `'Z'` | 65 bis 90 |
| `'a'` bis `'z'` | 97 bis 122 |

Der Abstand zwischen `'a'` und `'A'` beträgt also immer `32`. Im Code
schreiben wir aber nicht `32`, sondern `'a' - 'A'` — eine Magic Number
weniger, und der Sinn ist sofort erkennbar.

#### Schritt 1: Ein einzelnes Zeichen umwandeln

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/live-09-5-zeichen-toupper.c"
    ```

    1. Zeichen sind Zahlen, deshalb lassen sie sich mit `>=` und `<=`
       vergleichen: Diese Bedingung ist wahr für genau die Kleinbuchstaben.
    2. Ein Kleinbuchstabe wird zum Großbuchstaben, indem der Abstand
       `'a' - 'A'` abgezogen wird. Alle anderen Zeichen bleiben unverändert.

---

#### Schritt 2: Einen ganzen String umwandeln

Jetzt wenden wir die Zeichen-Funktion auf jedes Zeichen des Strings an.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/live-09-6-toupper.c"
    ```

    1. `%s` liest ein Wort ein (bis zum ersten Leerzeichen) und hängt das
       Stringende-Zeichen selbst an. Wie bei `%c` muss die Größe des Ziels
       angegeben werden — hier 50 Byte. Das `(unsigned)` wandelt das
       Ergebnis von `sizeof` in den Typ um, den `scanf_s` an dieser Stelle
       erwartet; einfach so übernehmen.
    2. Die Schleife läuft bis zum Stringende-Zeichen. Es gibt keinen
       Längenparameter, und weil das Array an die Funktion als Original
       übergeben wird, ändert `toUpper` den String direkt.

**Umlaute und ß:** ASCII kennt sie nicht. `toUpper` lässt solche Zeichen
unverändert — dieselbe Codepage-Problematik wie bei den Umlauten in der
Konsole aus Termin 1.
{: .hinweis-klein }

---

#### Schritt 3: Die Gegenrichtung

`toLower` funktioniert genau umgekehrt: Großbuchstaben werden um den
Abstand `'a' - 'A'` nach oben verschoben.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/live-09-7-tolower.c"
    ```

    1. Hier ist die Bedingung für Großbuchstaben, und der Abstand wird
       addiert statt abgezogen.

Beide Funktionen sind bis auf diese Stellen identisch — ein Hinweis darauf,
wie schnell sich Code wiederholt (*DRY*, „Don't repeat yourself“ aus
Termin 3), sobald man ähnliche Aufgaben löst.
{: .hinweis-klein }

---

### Warum braucht die Funktion keine Länge? <span class="zeitangabe">ca. 4 Min.</span> { data-toc-label="Warum braucht die Funktion keine Länge?" }

Vergleicht `toUpper(char text[])` mit den Funktionen für `int`-Arrays aus der
Übung zu Arrays: Dort mussten wir immer die Länge mitgeben, hier übergeben
wir nur den String. Warum?

Ein `int`-Array hat kein Ende-Zeichen — jeder `int`-Wert ist ein gültiger
Wert, also könnte jeder auch ein Element sein. Die Funktion kann deshalb
nicht selbst erkennen, wo das Array aufhört. Bei einem String ist das
anders: Das Stringende-Zeichen `'\0'` markiert das Ende, und die Funktion
läuft einfach, bis sie darauf trifft.

Überlegt kurz: Was würde passieren, wenn das Stringende-Zeichen fehlt?

!!! warning "Voraussetzung: Der String muss ein Stringende-Zeichen besitzen"
    Das funktioniert nur, wenn der übergebene String **zwingend** ein
    Stringende-Zeichen hat. Fehlt es, läuft die Schleife hinter das Ende des
    Arrays hinaus und liest oder verändert fremden Speicher — dasselbe
    Problem wie bei einem Zugriff außerhalb der Array-Grenzen. Mögliche
    Folgen: Zeichenmüll in der Ausgabe oder ein Programmabsturz. Genau das ist
    die Voraussetzung für die meisten Funktionen aus `string.h`. Strings, die
    mit `"..."`, `scanf_s` oder den Funktionen aus `string.h` entstehen,
    haben das Stringende-Zeichen automatisch. Wer einen String von Hand
    zusammenbaut, muss selbst daran denken.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

Jetzt verarbeitet ihr Strings selbst: Ihr prüft, ob zwei Wörter Anagramme
sind, und rechnet römische Zahlen in Dezimalzahlen um. Beide Aufgaben
laufen über die Zeichen eines Strings bis zum Stringende.

!!! abstract "Lernziele"
    - Ihr könnt einen Algorithmus auf Strings entwerfen und als Funktion
      umsetzen.
    - Ihr könnt Zeichen über ihre ASCII-Werte verarbeiten und einen String
      bis zum Stringende durchlaufen.
    - Ihr könnt ungültige Eingaben erkennen und mit einem Fehlerwert
      melden.

### Aufgabe 30: Anagramm

Schreibt eine Funktion `_Bool istAnagramm(char erster[], char zweiter[])`,
die zwei nullterminierte Strings entgegennimmt und untersucht, ob der
zweite String ein Anagramm des ersten ist. Ein **Anagramm** eines Wortes
ist eine Zeichenfolge, die aus den Buchstaben des gegebenen Wortes gebildet
werden kann. Ein Beispiel: „Regal“ ist ein Anagramm von „Lager“. Die
Funktion soll aber sämtliche Buchstabenfolgen akzeptieren, also nicht nur
„echte“ Wörter.

Bei den übergebenen Zeichenfolgen wird nicht zwischen Groß- und
Kleinschreibung unterschieden: „SUah“ ist demnach ein gültiges Anagramm zu
„Haus“. Auch dasselbe Wort zweimal („Haus“ und „Haus“) zählt als Anagramm.
Hat die Funktion ein Anagramm erkannt, gibt sie `1` (wahr) zurück,
andernfalls `0` (falsch) — der Rückgabetyp `_Bool` ist der Datentyp aus dem
Vorbereitungsvideo zu Termin 2. Er speichert nur `0` oder `1`; ihr benutzt
ihn hier wie ein `int`.

**Voraussetzung:** Beide Strings bestehen nur aus den Buchstaben `A`–`Z`
und `a`–`z` (keine Umlaute, keine Leerzeichen). Die Funktion darf die
übergebenen Strings nicht verändern.
{: .hinweis-klein }

Die Vorgabe enthält Testaufrufe in `main` und die Funktion
`zeichenToLower` aus der Übung:

```c linenums="1"
--8<-- "02-theoriephase/termin-04/code/vorgabe-30-anagramm.c"
```

#### Teil A — Von Hand (ohne Rechner)

Zwei Wörter sind Anagramme, wenn jeder Buchstabe in beiden gleich oft
vorkommt. Legt eine Tabelle an und zählt für „Lager“ und „Regal“ von Hand,
wie oft jeder Buchstabe vorkommt (Groß- und Kleinschreibung ignorieren).
Wie erkennt ihr an der Tabelle, dass es Anagramme sind — und woran würdet
ihr „Haus“ und „Maus“ als Nicht-Anagramme erkennen?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    | Buchstabe | a | e | g | l | r |
    |---|---|---|---|---|---|
    | „Lager“ | 1 | 1 | 1 | 1 | 1 |
    | „Regal“ | 1 | 1 | 1 | 1 | 1 |

    Alle Zählwerte stimmen überein — also Anagramm. Bei „Haus“ und „Maus“
    kommt `h` nur im ersten und `m` nur im zweiten Wort vor: Die Werte
    unterscheiden sich, es ist kein Anagramm.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Als Funktion umsetzen

Setzt die Idee aus Teil A um. Legt dafür ein `int`-Array an, das für jeden
Buchstaben des Alphabets die Anzahl mitführt; den Index eines Buchstabens
erhaltet ihr aus seinem ASCII-Code (`buchstabe - 'a'`). Die Anzahl der
Buchstaben ist dabei eine benannte Konstante, keine nackte Zahl.

**Zwei Hinweise:** Alle Zähler müssen zu Beginn `0` sein — mit
`int zaehler[GROESSE] = { 0 };` setzt ihr alle Elemente von Anfang an auf
`0` (aus der Array-Übung: nicht angegebene Elemente werden mit `0`
aufgefüllt). Und überlegt euch, ob ihr für den Vergleich beider Wörter zwei
Zähl-Arrays braucht oder ob ein einziges reicht.
{: .hinweis-klein }

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil B anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/aufg-30-anagramm.c"
    ```

    Die Funktion zählt die Buchstaben des ersten Strings hoch und die des
    zweiten herunter. Sind beide Wörter Anagramme, hebt sich alles auf, und
    jeder Zähler steht am Ende wieder auf `0`. Unterschiedlich lange Wörter
    scheitern automatisch, weil dann mindestens ein Zähler nicht `0` ist.
    `{ 0 }` setzt alle Elemente des Zähl-Arrays von Anfang an auf `0`, und
    `zeichenToLower` sorgt dafür, dass Groß- und Kleinbuchstaben gleich
    behandelt werden — ohne die übergebenen Strings zu verändern.

    Gleichwertig, nur etwas ausführlicher, ist eine Lösung mit **zwei**
    Zähl-Arrays: Jedes Wort bekommt sein eigenes, am Ende werden beide
    Arrays Feld für Feld verglichen.

    Wichtig ist die Voraussetzung: Ein Zeichen, das kein Buchstabe ist,
    ergäbe einen Index außerhalb des Zähl-Arrays (siehe Aufgabe 28, Teil B).
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 31: Römische Zahlen

Römische Zahlen werden als Buchstabenfolgen dargestellt. So wird zum
Beispiel die Zahl 1983 durch `MCMLXXXIII` beschrieben (`M` = 1000, `CM` =
900, `LXXX` = 80, `III` = 3). Die einzelnen Zeichen haben die folgenden
Werte:

| Zeichen | I | V | X | L | C | D | M |
|---|---|---|---|---|---|---|---|
| Wert | 1 | 5 | 10 | 50 | 100 | 500 | 1000 |

Bei der Bildung der Zahlen gilt die **Subtraktionsregel**: Die Zeichen `I`,
`X` und `C` dürfen einem ihrer beiden jeweils nächstgrößeren Zeichen
vorangestellt werden und werden dann von dessen Wert abgezogen: `IV` (4),
`IX` (9), `XL` (40), `XC` (90), `CD` (400) und `CM` (900). Ein Beispiel:
`MCMXCIV` ergibt `1000 - 100 + 1000 - 10 + 100 - 1 + 5 = 1994`. Vergleicht
beim Umrechnen jedes Zeichen mit seinem Nachfolger, um zu entscheiden, ob
sein Wert addiert oder abgezogen wird.

Schreibt eine Funktion `int roemischZuDezimal(char zahl[])`, die eine
römische Zahl als nullterminierten String übergeben bekommt und den
Dezimalwert berechnet und zurückgibt. Enthält der String unerlaubte
Zeichen, gibt die Funktion den Wert `-1` zurück. Legt für diesen Fehlerwert
eine benannte Konstante fest — mit `#define` am Dateianfang, wie bei
`REIHEN` und `SITZE` in der Kino-Aufgabe (die TODO-Zeile in der Vorgabe).
Im ganzen Code soll kein nacktes `-1` stehen.

**Voraussetzungen:** Der String ist nicht leer und eine korrekt gebildete
römische Zahl, soweit er nur erlaubte Zeichen enthält — ob die Reihenfolge
der Zeichen zulässig ist (zum Beispiel `IIII`), müsst ihr nicht prüfen.
Erlaubt sind nur die sieben Großbuchstaben aus der Tabelle (ein Kleinbuchstabe
wie in `xiv` ist also ungültig). Tipp: Eine eigene kleine Funktion, die den
Wert eines einzelnen Zeichens liefert, macht die Hauptfunktion deutlich
übersichtlicher. Denkt beim Vergleich mit dem Nachfolger auch an das
**letzte** Zeichen: Sein Nachfolger ist das Stringende-Zeichen.
{: .hinweis-klein }

```c linenums="1"
--8<-- "02-theoriephase/termin-04/code/vorgabe-31-roemisch.c"
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-04/code/aufg-31-roemisch.c"
    ```

    1. Ein Zeichen wird abgezogen, wenn das **nächste** Zeichen größeren Wert
       hat (`IV`: `I` < `V`), sonst addiert. Die Prüfung
       `zahl[i + 1] != '\0'` macht ausdrücklich klar, dass es beim letzten
       Zeichen keinen Nachfolger gibt. Ganz ohne sie würde
       `wertVonZeichen` das Stringende-Zeichen bewerten und `UNGUELTIG`
       liefern — das ist kleiner als jeder gültige Wert, die Rechnung ginge
       also zufällig trotzdem auf. Verlasst euch nicht auf solche
       Zufälle, sondern prüft das Stringende ausdrücklich.

    `wertVonZeichen` übernimmt die Zuordnung Zeichen → Wert (*eine Funktion,
    eine Aufgabe*) und meldet ungültige Zeichen mit `UNGUELTIG`. Sobald
    `roemischZuDezimal` einen solchen Wert sieht, bricht sie sofort mit
    demselben Fehlerwert ab.

    **Alternative Lösungswege:** Man kann den String auch von **rechts nach
    links** durchlaufen (Startindex `strlen(zahl) - 1`) und sich den Wert
    des rechten Nachbarn merken: Ist der aktuelle Wert kleiner, wird er
    abgezogen, sonst addiert. Dann entfällt die Sonderbehandlung des letzten
    Zeichens ganz. Ebenfalls möglich ist es, die erlaubten Paare (`IV`, `IX`,
    `XL`, `XC`, `CD`, `CM`) einzeln in einer `switch`-Anweisung abzufragen.
    Das folgt dem Aufgabentext sehr direkt, wiederholt sich aber in drei
    fast gleichen Zweigen (*DRY*). Wer dort mehrere Bedingungen mit `&&` und
    `||` mischt, sollte klammern: `&&` bindet stärker als `||`, ohne Klammern
    gilt die Bedingung `i < len - 1` nur für den ersten Teil.
<!-- MUSTERLOESUNG-ENDE -->
