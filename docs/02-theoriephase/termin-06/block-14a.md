---
typ: theoriephase-block
termin: 6
block_id: "14a"
datum: "2026-11-25"
kurztitel: "Strukturen: Grundlagen"
thema: "Strukturen (Grundlagen)"
lernziele:
  - "Ihr könnt eine Struktur mit struct definieren, mit und ohne typedef, und auf ihre Member mit dem Punkt-Operator zugreifen."
  - "Ihr könnt erklären, welche Datentypen eine Struktur enthalten kann und warum sie sich nicht selbst enthalten darf, wohl aber einen Pointer auf sich selbst."
  - "Ihr könnt Strukturen ineinander verschachteln und deren Member initialisieren und lesen."
  - "Ihr könnt Namenskonventionen für Typen, Variablen und Konstanten anwenden."
  - "Ihr könnt ein Array von Strukturen anlegen, in Schleifen verarbeiten und an Funktionen übergeben."
musterloesungen_sichtbar: true
ki_einsatz: stufe_1_nachschlagewerk
clean_code:
  - "Konvention vor Konfiguration"
bearbeitungsstatus: in-arbeit
publish_date: "2026-11-25"
---

# Strukturen: Grundlagen (25.11.2026)

## Übung { .modus-uebung }

### Worum geht es?

Ein Array fasst viele Werte desselben Typs zusammen. Oft gehört aber
Verschiedenartiges zusammen: Zu einem Messpunkt gehören eine Nummer (`int`)
und ein Messwert (`double`), zu einem Werkstück eine Nummer, eine Masse und
eine Position. Dafür gibt es in C die **Struktur** (`struct`). Ihr habt sie in
den Vorbereitungsvideos schon gesehen. Heute wiederholen wir die Syntax,
klären, was eine Struktur enthalten darf, und verschachteln Strukturen
ineinander.

!!! abstract "Lernziele"
    - Ihr könnt eine Struktur mit `struct` definieren, mit und ohne
      `typedef`, und auf ihre Member mit dem Punkt-Operator zugreifen.
    - Ihr könnt erklären, welche Datentypen eine Struktur enthalten kann
      und warum sie sich nicht selbst enthalten darf, wohl aber einen
      Pointer auf sich selbst.
    - Ihr könnt Strukturen ineinander verschachteln und deren Member
      initialisieren und lesen.
    - Ihr könnt ein Array von Strukturen anlegen und durchlaufen.
    - Ihr könnt Namenskonventionen für Typen, Variablen und Konstanten
      anwenden.

### Kurzer Rückblick <span class="zeitangabe">ca. 2 Min.</span> { data-toc-label="Kurzer Rückblick" }

1\. Wozu dient ein Array, und welche Einschränkung hat es?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Ein Array fasst eine feste Anzahl von Variablen unter einem Namen zusammen
    und spricht sie über einen Index an. Die Einschränkung: Alle Elemente
    haben denselben Datentyp. Wer verschiedene Typen zusammenfassen will,
    braucht etwas anderes, nämlich eine Struktur.
<!-- MUSTERLOESUNG-ENDE -->

2\. Was ist grundsätzlich der Unterschied zwischen Call by Value und Call by Reference?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Bei Call by Value bekommt eine Funktion nur eine **Kopie** des
    übergebenen Werts, Änderungen daran wirken sich nicht auf das Original
    aus. Bei Call by Reference bekommt die Funktion Zugriff auf das
    **Original** selbst.
<!-- MUSTERLOESUNG-ENDE -->

---

### Schritt 1: Eine Struktur ohne typedef <span class="zeitangabe">ca. 4 Min.</span> { data-toc-label="Schritt 1: Eine Struktur ohne typedef" }

Eine Struktur fasst mehrere Variablen, die **Member**, zu einem neuen
Datentyp zusammen. Als Beispiel dient ein Messpunkt mit Nummer und Messwert.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-06/code/live-14a-1-struct-syntax.c"
    ```

    1. `struct` ist das Schlüsselwort für den neuen Datentyp, danach folgt
       sein Name. Der Datentyp heißt jetzt `struct Messpunkt`.
    2. In den geschweiften Klammern stehen die Member, jedes mit Typ und
       Namen wie eine ganz normale Variablendeklaration. Das Semikolon
       hinter der schließenden Klammer nicht vergessen.
    3. Eine Variable dieses Typs wird angelegt und initialisiert. Die Werte
       in den geschweiften Klammern gehören der Reihe nach zu den Membern:
       `id` ist `1`, `wert` ist `23.5`.
    4. Auf ein Member greift ihr mit dem **Punkt-Operator** zu:
       `Variable.Member`.
    5. Auf dieselbe Weise lässt sich ein Member auch ändern.

---

### Schritt 2: Mit typedef <span class="zeitangabe">ca. 3 Min.</span> { data-toc-label="Schritt 2: Mit typedef" }

Ihr kennt `typedef` aus dem Abschnitt über `enum`: Es gibt einem Typ einen
kürzeren Namen, sodass das Wort `struct` nicht mehr überall stehen muss. Ab
jetzt definieren wir Strukturen nur noch so.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1" hl_lines="4 8 12"
    --8<-- "02-theoriephase/termin-06/code/live-14a-2-struct-typedef.c"
    ```

    1. `typedef` gibt der Struktur einen zusätzlichen Namen. Anders als in
       Schritt 1 steht hinter `struct` kein Name mehr, die Struktur bleibt
       selbst namenlos.
    2. Der neue Name steht hinter der schließenden Klammer: `Messpunkt`.
    3. Ab jetzt genügt `Messpunkt`, ganz ohne `struct` davor.

!!! tip "Clean Code: Konvention vor Konfiguration"
    Für vieles gibt es feste Gepflogenheiten, an die sich alle halten, statt
    dass jeder eigene Regeln erfindet. In C-Programmen gilt üblicherweise:
    **Typnamen** beginnen mit einem Großbuchstaben (`Messpunkt`, `Zustand`,
    `Einheit`), **Variablen und Funktionen** mit einem Kleinbuchstaben
    (`messpunkt`, `werkstueckAusgeben`) und **Konstanten** werden ganz groß
    geschrieben (`ANZAHL`, `TAKTE`). Wer sich daran hält, liest fremden Code
    schneller und erkennt auf einen Blick, ob ein Name einen Typ, eine
    Variable oder eine Konstante bezeichnet. Ab jetzt erwarten wir diese
    Konventionen in euren Aufgaben.

---

### Schritt 3: Was kann eine Struktur enthalten? <span class="zeitangabe">ca. 4 Min.</span> { data-toc-label="Schritt 3: Was kann eine Struktur enthalten?" }

Eine Struktur kann praktisch jeden Datentyp zusammenfassen: einfache Typen
wie `int` und `double`, Arrays (zum Beispiel `char name[20]` für einen Text),
Aufzählungstypen (`enum`), andere Strukturen und Pointer.

Es gibt nur **eine Ausnahme: Eine Struktur kann sich nicht selbst enthalten.**
Sie würde ein Exemplar von sich in sich tragen, das wieder ein Exemplar von
sich trägt und so weiter. Der Compiler könnte nie festlegen, wie viel Speicher
sie braucht.

Erlaubt ist aber ein **Pointer auf die eigene Struktur**: Ein Pointer hat
immer dieselbe, feste Größe, egal worauf er zeigt. Damit lassen sich Strukturen
zu Ketten verbinden, in denen jedes Glied seinen Nachfolger kennt, und so
Listen bauen, die beliebig wachsen können. Dazu kommt später mehr, heute nur
der Grundgedanke.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-06/code/live-14a-3-struct-selbstbezug.c"
    ```

    1. Hier braucht die Struktur ausnahmsweise einen eigenen Namen,
       `Knoten`, denn sie wird in ihrer eigenen Definition noch gebraucht. Das
       `typedef` gibt es trotzdem.
    2. Ein Pointer auf einen weiteren `Knoten`. Innerhalb der Definition
       muss dafür noch `struct Knoten` geschrieben werden, weil der Compiler
       den `typedef`-Namen `Knoten` an dieser Stelle noch nicht kennt.
    3. Der erste Knoten hat keinen Nachfolger, `NULL` ist der Pointer auf
       „nichts".
    4. Der zweite Knoten zeigt mit `&erster` auf den ersten.
    5. Der **Pfeil-Operator** `->` greift auf ein Member einer Struktur zu,
       auf die ein Pointer zeigt: `zweiter.nachfolger` ist der Pointer, `->wert` der Wert, auf den er
       zeigt. Mit dem Punkt-Operator geht das nicht, denn
       `zweiter.nachfolger` ist nur eine Adresse. Details dazu folgen im zweiten Teil.

**Eine Alternative:** Das `struct Knoten` innerhalb der Definition lässt sich
auch vermeiden. Schreibt man vor die Strukturdefinition
`typedef struct Knoten Knoten;`, kennt der Compiler den Namen `Knoten` schon
und die Struktur darf sich innen mit `Knoten *nachfolger;` auf sich selbst
beziehen. Beide Wege sind gleichwertig, viele Wege führen nach Rom.
{: .hinweis-klein }

---

### Aufgabe 40: Werkstück mit Ablageposition <span class="zeitangabe">ca. 12 Min.</span> { data-toc-label="Aufgabe 40: Werkstück mit Ablageposition" }

Ein Roboter legt Werkstücke an einer bestimmten Position ab. Zu einem Werkstück
gehören eine Nummer, eine Bezeichnung (ein Text), seine Masse in Kilogramm und
die Position, an der es liegt (x und y in Millimetern). Eine Position besteht also selbst aus zwei
Werten und ist deshalb eine eigene Struktur, die im Werkstück als Member
steckt. Das ist eine **Struktur in einer Struktur**. Am Ende verwalten wir
mehrere Werkstücke in einem Array.

Wir setzen das gemeinsam in drei Schritten um, ihr verfolgt die Umsetzung am
Bildschirm und könnt sie danach selbst ausprobieren.

#### Die verschachtelte Struktur

Erst die beiden Typen, dann ein Werkstück mit Anfangswerten.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-06/code/live-14a-4-struct-in-struct.c"
    ```

    1. Ein `char`-Array als Member speichert einen Text mit bis zu 19
       Zeichen (das 20. ist die Endmarke `\0`).
    2. `Position` ist ein ganz normaler Datentyp und kann deshalb als Typ
       eines Members verwendet werden. `Position` muss dafür vor
       `Werkstueck` definiert sein.
    3. Die verschachtelte Initialisierung: Der Text steht in
       Anführungszeichen, und für den Member `ablage` gibt es ein eigenes Paar
       geschweifter Klammern in den äußeren Klammern.
    4. Der Text wird mit `%s` ausgegeben. Auf ein Member der inneren Struktur
       greift ihr mit zwei Punkten zu, von außen nach innen: `w.ablage.x`.
    5. Die Zuweisung funktioniert genauso und ändert nur dieses eine
       Member.

---

#### Eine Ausgabefunktion

Der Code zur Ausgabe soll wiederverwendbar sein. Dafür wird er in eine
Funktion ausgelagert, die die Struktur als Parameter bekommt.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1" hl_lines="18 24 27 34-38"
    --8<-- "02-theoriephase/termin-06/code/live-14a-5-struct-ausgabe.c"
    ```

    1. Eine Struktur lässt sich wie jeder andere Datentyp als Parameter
       übergeben.
    2. Die Funktion bekommt dabei eine **Kopie** der Struktur, ganz wie bei
       Call by Value. Sie könnte `w` ändern, ohne dass sich das Original
       in `main` ändert.

---

#### Mehrere Werkstücke in einem Array

Ein Roboter legt mehr als ein Werkstück ab. Ein Array fasst Strukturen
desselben Typs zusammen, wie ihr es von `int`-Arrays kennt.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1" hl_lines="4 24-28 30-31 33-34"
    --8<-- "02-theoriephase/termin-06/code/live-14a-6-struct-array.c"
    ```

    1. Ein Array aus zwei Werkstücken. Jedes Element bekommt sein eigenes
       Paar geschweifter Klammern.
    2. Eine ganz normale Schleife über alle Elemente.
    3. `werkstuecke[i]` ist ein ganzes Werkstück und wird als Kopie an die
       Funktion übergeben.
    4. Zugriff auf ein Member eines Elements: erst der Index, dann die
       Punkte. `werkstuecke[1].ablage.x` ist die x-Position des zweiten
       Werkstücks.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

In der Übung habt ihr gesehen, wie sich Strukturen definieren und
verschachteln lassen. Jetzt verwaltet ihr in Aufgabe 41 viele Strukturen auf
einmal, nämlich die Bauteile eines Lagers in einem Array. Das Array wird an
Funktionen übergeben, die Daten auswerten und ändern.

!!! abstract "Lernziele"
    - Ihr könnt ein Array von Strukturen anlegen und in Schleifen
      verarbeiten.
    - Ihr könnt ein Array von Strukturen an eine Funktion übergeben und dort
      Daten auswerten und ändern.
    - Ihr könnt eine eigene Struktur definieren und in eine andere einbauen
      (Teil D).
    - Ihr könnt die Namenskonventionen für Typen, Variablen und Konstanten
      anwenden.

### Aufgabe 41: Bauteillager

Ein kleines Lager verwaltet Bauteile. Zu jedem Bauteil gehören eine Nummer, ein
Name, ein Preis in Euro, der Bestand und eine Kategorie (Mechanik, Elektrik,
Elektronik). Die Kategorie ist ein `enum`, den Namen speichert ein
`char`-Array. Das Lager ist ein Array aus fünf Bauteilen. Achtet in euren
Lösungen auf die Namenskonventionen aus der Übung.

Die Vorgabe enthält die Typen, ein vollständiges `main` und die Funktion
`kategorieAusgeben`. Drei Funktionen sind nur als Rahmen angelegt und müssen
von euch geschrieben werden. Bei `lagerwert` ist das Lager als `const`
gekennzeichnet, denn die Funktion darf es nur lesen (`const` kennt ihr aus
Termin 5):

```c linenums="1"
--8<-- "02-theoriephase/termin-06/code/vorgabe-41-bauteillager.c"
```

#### Teil A — Ausgabe

Schreibt `bauteilAusgeben(Bauteil b)`. Die Funktion gibt eine Zeile pro Bauteil
aus: Nummer, Name, Preis, Bestand und Kategorie. Die Kategorie schreibt
`kategorieAusgeben` für euch, auch mit Zeilenumbruch. Zur Formatierung: Eine
Zahl hinter dem `%` legt die Mindestbreite fest, `%3d` schreibt also eine
ganze Zahl mindestens dreistellig, `%-16s` einen Text linksbündig in 16
Zeichen Breite. Wollt ihr das nicht verwenden, genügen auch einfach `%d`, `%s`
und `%.2f`.

---

#### Teil B — Lagerwert

Schreibt `double lagerwert(Bauteil lager[], int anzahl)`. Sie liefert die Summe
aus Preis mal Bestand über alle Bauteile.

---

#### Teil C — Auffüllen

Schreibt `void auffuellen(Bauteil lager[], int anzahl, int nummer, int menge)`.
Die Funktion bekommt das ganze Lager und die Nummer eines Bauteils (die es im
Lager garantiert gibt), sucht dieses Bauteil im Array und erhöht seinen
Bestand um `menge`. `main` ruft sie
bereits für jedes Bauteil auf, dessen Bestand unter `MINDESTBESTAND` liegt.

Erwartete Ausgabe, wenn alle drei Funktionen fertig sind:

```text
Lager vor dem Auffuellen:
101  Schraube M4        0.05 Euro  Bestand 120  Mechanik
102  Kugellager         4.80 Euro  Bestand   8  Mechanik
201  Relais 24V         3.20 Euro  Bestand  15  Elektrik
202  Sicherung 10A      0.40 Euro  Bestand   4  Elektrik
301  Mikrocontroller    6.50 Euro  Bestand  22  Elektronik
Lagerwert: 237.00 Euro

Lager nach dem Auffuellen:
101  Schraube M4        0.05 Euro  Bestand 120  Mechanik
102  Kugellager         4.80 Euro  Bestand  28  Mechanik
201  Relais 24V         3.20 Euro  Bestand  15  Elektrik
202  Sicherung 10A      0.40 Euro  Bestand  24  Elektrik
301  Mikrocontroller    6.50 Euro  Bestand  22  Elektronik
Lagerwert: 341.00 Euro
```

Die Spaltenbreiten in der Ausgabe dürfen leicht abweichen, wichtig sind die
Werte. Solange ihr die Funktionen noch nicht geschrieben habt, kann der
Compiler vor ungenutzten Parametern warnen. Die Warnungen verschwinden, sobald
ihr die Funktionen ausfüllt.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    ```c linenums="1" hl_lines="79-80 85 87-88 90 95-97"
    --8<-- "02-theoriephase/termin-06/code/aufg-41-bauteillager.c"
    ```

    1. Die Ausgabe nutzt die Punkt-Schreibweise für jedes Member.
       `%-16s` schreibt den Namen linksbündig in einer festen Breite, damit
       die Spalten untereinanderstehen. Die Kategorie gibt die fertige
       Funktion aus.
    2. `lager[i].preis` heißt: das Element `i` des Arrays, davon das Member
       `preis`. Die Summe wird in einer Schleife über alle Bauteile
       gesammelt.
    3. `auffuellen` sucht das Bauteil über seine `nummer` und wertet dafür in
       einer Schleife ein Member jedes Elements aus.
    4. Die Funktion ändert das Original. Das geht ohne weiteren Aufwand, weil
       ein Array an eine Funktion immer als Adresse übergeben wird (Call by
       Reference, wie in Termin 4 gesehen). `bauteilAusgeben` bekommt dagegen
       ein einzelnes Bauteil als Wert, also eine Kopie.

    Typische Fehler: den Bestand nur in einer lokalen Kopie ändern (zum
    Beispiel mit einer Hilfsvariablen vom Typ `Bauteil`, die ein Element
    kopiert), oder die Länge des Arrays als feste Zahl in die Funktion zu
    schreiben statt `anzahl` zu verwenden.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil D — Lagerplatz (optional)

Für alle, die früher fertig sind: Jedes Bauteil liegt in einem Regal und einem
Fach. Dafür braucht ihr eine **eigene Struktur** und müsst sie in `Bauteil`
einbauen.

1. Definiert einen Typ `Lagerplatz` mit `typedef` und den Membern `regal` und
   `fach`. Achtet auf die Namenskonventionen.
2. Baut `Lagerplatz` als Member `platz` in `Bauteil` ein.
3. Setzt in `main` nach dem Anlegen des Lagers für jedes Bauteil den Lagerplatz
   in einer Schleife: Das Regal ist die Hunderterstelle der Bauteilnummer
   (`101` liegt in Regal `1`), das Fach ist die laufende Nummer ab `1`.
4. Erweitert `bauteilAusgeben` um die Angabe `Regal x, Fach y` vor der
   Kategorie.

Die erste Zeile der Ausgabe sieht dann so aus:

```text
101  Schraube M4        0.05 Euro  Bestand 120  Regal 1, Fach 1  Mechanik
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil D anzeigen"
    ```c linenums="1" hl_lines="14-18 27 46-50 92-93"
    --8<-- "02-theoriephase/termin-06/code/aufg-41-bauteillager-lagerplatz.c"
    ```

    1. Die neue Struktur ist ein ganz normaler Datentyp mit `typedef`.
       Typname groß, Member klein: `Lagerplatz`, `regal`, `fach`.
    2. Sie wird wie jeder andere Typ als Member eingebaut. Das Lager ist jetzt
       ein Array aus Strukturen, die selbst eine Struktur enthalten.
    3. Die Zuweisung geht mit zwei Punkten: `lager[i].platz.regal`. Die
       Hunderterstelle erhält man mit der ganzzahligen Division durch `100`.
    4. Die Ausgabe nutzt dieselbe Punkt-Schreibweise.

    Bei einer Initialisierung direkt im Array hättet ihr den Lagerplatz in
    jedem Element mit einem eigenen Klammernpaar angeben müssen. Hier ist die
    Zuweisung in einer Schleife kürzer, weil sich der Platz aus den anderen
    Werten ergibt.
<!-- MUSTERLOESUNG-ENDE -->
