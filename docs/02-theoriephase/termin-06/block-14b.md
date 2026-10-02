---
typ: theoriephase-block
termin: 6
block_id: "14b"
datum: "2026-11-25"
kurztitel: "Strukturen: Vertiefung"
thema: "Strukturen (Vertiefung)"
lernziele:
  - "Ihr könnt eine Struktur per Kopie und per Pointer an eine Funktion übergeben und den Unterschied begründen."
  - "Ihr könnt auf die Member einer Struktur über einen Pointer mit dem Pfeil-Operator zugreifen und erklären, dass p->wert die Kurzform von (*p).wert ist."
  - "Ihr könnt die Funktion localtime verwenden und die Member von struct tm über den zurückgelieferten Pointer lesen."
  - "Ihr könnt Pointer-Parameter, über die nur gelesen wird, mit const kennzeichnen und das begründen."
  - "Ihr könnt beurteilen, warum es besser ist, einer Funktion nur das betroffene Element statt des ganzen Arrays zu übergeben, und die Folgen für den Code benennen."
  - "Ihr könnt eine Funktion so ändern, dass sie eine Struktur per Pointer statt eines Arrays bekommt."
  - "Ihr könnt eine Struktur mit Pointern auf Strukturen desselben Typs aufbauen und über diese Pointer auf weitere Strukturen zugreifen."
musterloesungen_sichtbar: true
ki_einsatz: stufe_2_pair_programmer
clean_code:
  - "Prinzip der minimalen Rechte (Principle of Least Privilege, PoLP)"
bearbeitungsstatus: in-arbeit
publish_date: "2026-11-25"
quiz:
  show_progress: false
---

# Strukturen: Vertiefung (25.11.2026)

## Übung { .modus-uebung }

### Worum geht es?

Im ersten Teil habt ihr Strukturen definiert, verschachtelt und in Arrays
abgelegt. Jetzt geht es darum, Strukturen zwischen Funktionen weiterzugeben,
und zwar per Kopie oder per Pointer. Dazu kommt der Pfeil-Operator `->`, den
ihr schon gesehen habt. Als echtes Beispiel nutzt ihr `struct tm` aus der
Standardbibliothek, mit der ihr Datum und Uhrzeit abfragt.

!!! abstract "Lernziele"
    - Ihr könnt eine Struktur per Kopie und per Pointer an eine Funktion
      übergeben und den Unterschied begründen.
    - Ihr könnt auf die Member einer Struktur über einen Pointer mit dem
      Pfeil-Operator zugreifen und erklären, dass `p->wert` die Kurzform von
      `(*p).wert` ist.
    - Ihr könnt die Funktion `localtime` verwenden und die Member von
      `struct tm` über den zurückgelieferten Pointer lesen.
    - Ihr könnt Pointer-Parameter, über die nur gelesen wird, mit `const`
      kennzeichnen und das begründen.

### Kurzer Rückblick <span class="zeitangabe">ca. 2 Min.</span> { data-toc-label="Kurzer Rückblick" }

1\. Was passiert, wenn eine Struktur an eine Funktion übergeben wird?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Die Funktion bekommt eine **Kopie** der Struktur. Änderungen an dieser
    Kopie wirken sich auf das Original nicht aus, ganz wie bei Call by Value
    mit einfachen Variablen.
<!-- MUSTERLOESUNG-ENDE -->

2\. Wozu dienen `&` und `*` bei Pointern?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung anzeigen"
    Der Adressoperator `&` liefert die Adresse einer Variablen und erzeugt
    damit einen Pointer darauf. Die Dereferenzierung `*` liefert den Wert, auf
    den ein Pointer zeigt, ist also der Gegenspieler dazu.
<!-- MUSTERLOESUNG-ENDE -->

---

### Schritt 1: Struktur per Kopie oder per Pointer <span class="zeitangabe">ca. 8 Min.</span> { data-toc-label="Schritt 1: Struktur per Kopie oder per Pointer" }

Eine Funktion soll den Messwert eines Messpunkts verdoppeln. Wir probieren es
auf beide Arten aus: erst mit einer Kopie, dann mit einem Pointer.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-06/code/live-14b-1-kopie-pointer.c"
    ```

    1. Die Struktur wird als Wert übergeben, die Funktion arbeitet mit einer
       Kopie.
    2. Hier bekommt die Funktion einen Pointer auf die Struktur, also deren
       Adresse.
    3. Der Messwert hat sich nicht geändert, denn die Funktion hat nur an
       ihrer Kopie gerechnet.
    4. Beim Aufruf wird die Adresse der Variablen mit `&` übergeben.
    5. Über den **Pfeil-Operator** `->` greift die Funktion auf das Member
       `wert` der Struktur zu, auf die der Pointer zeigt. Jetzt ändert sich das
       Original.

**Was bedeutet der Pfeil-Operator?** `p->wert` ist eine Kurzschreibweise für
`(*p).wert`: Erst wird der Pointer dereferenziert (`*p` ist die Struktur, auf
die er zeigt), dann wird auf deren Member zugegriffen. Die Klammern sind nötig,
weil der Punkt Vorrang hat und zuerst ausgewertet wird. Ohne sie würde `*p.wert`
zuerst `p.wert` bilden, aber `p` ist ein Pointer und hat kein Member `wert`.
Das wäre ein Fehler.
{: .hinweis-klein }

**Wann Kopie, wann Pointer?** Eine Kopie ist sicher, weil die Funktion das
Original nicht verändern kann. Bei großen Strukturen kostet sie aber Zeit und
Speicher. Ein Pointer ist schnell, erlaubt der Funktion aber, das Original zu
ändern. Beides muss man bewusst wählen.
{: .hinweis-klein }

---

### Schritt 2: Ein echtes Beispiel, struct tm <span class="zeitangabe">ca. 6 Min.</span> { data-toc-label="Schritt 2: Ein echtes Beispiel, struct tm" }

Die Standardbibliothek `time.h` liefert Datum und Uhrzeit. Die Funktion
`localtime` gibt dafür einen **Pointer auf eine `struct tm`** zurück, die die
einzelnen Angaben (Tag, Monat, Jahr, Stunde ...) als Member enthält. Die
Struktur selbst gehört der Bibliothek, wir bekommen nur ihre Adresse.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1"
    --8<-- "02-theoriephase/termin-06/code/live-14b-2-struct-tm.c"
    ```

    1. Wie schon bei `strtok` gilt `localtime` in Visual Studio als unsicher
       und löst eine Warnung aus. Mit diesem `#define` in der ersten Zeile
       schalten wir sie ab, so wie ihr es aus Termin 5 kennt.
    2. `time(NULL)` liefert die aktuelle Zeit als Zahl (Sekunden seit dem
       1.1.1970). `time_t` ist der passende Datentyp dafür.
    3. `localtime` wandelt diese Zahl in die lokale Zeit um und liefert einen
       Pointer auf eine `struct tm`. Wir bekommen also keine Kopie, sondern
       die Adresse.
    4. Die Member lesen wir mit `->`. `%02d` schreibt eine Zahl immer zweistellig
       mit führender Null. Zwei Eigenheiten: `tm_mon` zählt die Monate ab 0, und
       `tm_year` zählt die Jahre seit 1900. Deshalb steht dort `+ 1` und
       `+ 1900`.

Die Ausgabe zeigt natürlich eure aktuelle Zeit und sieht deshalb bei jedem anders
aus.
{: .hinweis-klein }

---

### Aufgabe 42: Datum ausgeben, Wochenende erkennen <span class="zeitangabe">ca. 12 Min.</span> { data-toc-label="Aufgabe 42: Datum ausgeben, Wochenende erkennen" }

Das Programm aus Schritt 2 soll aufgeräumt werden. Schreibt zwei Funktionen:

- `datumAusgeben` gibt Datum und Uhrzeit aus, wie eben in `main`.
- `istWochenende` liefert `1`, wenn heute Samstag oder Sonntag ist, sonst `0`.
  Das Member `tm_wday` zählt die Wochentage ab Sonntag: `0` ist Sonntag, `6` ist
  Samstag.

Beide Funktionen bekommen den Pointer auf die `struct tm`, die `localtime`
liefert. Wir setzen das gemeinsam um.

??? quote livecoding "Beispiel-Code"
    ```c linenums="1" hl_lines="7-8 15 17-20 27-31 33-36"
    --8<-- "02-theoriephase/termin-06/code/live-14b-3-struct-tm-funktion.c"
    ```

    1. Der Pointer-Parameter ist mit `const` gekennzeichnet: Die Funktion
       darf die Struktur lesen, aber nicht verändern.
    2. Der Pointer von `localtime` wird einfach weitergereicht. Es ist keine
       Kopie nötig.
    3. Ein Vergleich liefert `1` oder `0`. Deshalb lässt sich das Ergebnis
       direkt zurückgeben.

!!! tip "Clean Code: Prinzip der minimalen Rechte (PoLP)"
    Eine Funktion, die Daten nur liest, bekommt den Pointer mit `const`
    übergeben. Der Compiler meldet dann einen Fehler, falls sie die Daten
    versehentlich doch ändert. Außerdem sieht man schon an der Signatur, dass
    die Funktion nichts verändert. Das ist das **Prinzip der minimalen
    Rechte** (englisch *Principle of Least Privilege*, kurz **PoLP**): Eine
    Funktion bekommt nur die Daten und Rechte, die sie wirklich braucht, und
    nicht mehr.

    Ab jetzt erwarten wir in euren Aufgaben: Pointer-Parameter, über die nur
    gelesen wird, sind `const`.

---

## Betreutes Selbststudium { .modus-selbststudium }

### Worum geht es?

Jetzt wendet ihr Pointer auf Strukturen selbst an. In Aufgabe 43 greifen wir nochmal Aufgabe 41 auf: Ihr ändert
eine Funktion so, dass sie nur noch ein einzelnes Bauteil bekommt statt das
ganze Lager, und überlegt vorher, was das für den Code bedeutet. In Aufgabe 44
baut ihr Lerngruppen aus Studierenden, die sich gegenseitig über Pointer
kennen.

!!! abstract "Lernziele"
    - Ihr könnt beurteilen, warum es besser ist, einer Funktion nur das
      betroffene Element statt des ganzen Arrays zu übergeben, und die Folgen
      für den Code benennen.
    - Ihr könnt eine Funktion so ändern, dass sie eine Struktur per Pointer
      statt eines Arrays bekommt.
    - Ihr könnt eine Struktur mit Pointern auf Strukturen desselben Typs
      aufbauen, über diese Pointer auf weitere Strukturen zugreifen und sie
      dabei auch verändern (Partnerwechsel).

### Aufgabe 43: Bauteillager, nur das Bauteil übergeben

Ausgangspunkt ist das Bauteillager aus Aufgabe 41. Hier steht der vollständige
Stand, bei dem `auffuellen` noch das ganze Lager bekommt und das Bauteil über die
Nummer sucht:

```c linenums="1" hl_lines="26 93-98"
--8<-- "02-theoriephase/termin-06/code/vorgabe-43-bauteillager.c"
```

Die Funktion `auffuellen` soll sich ändern: Sie bekommt künftig **nur noch einen
Pointer auf das betroffene Bauteil** und die Menge, nicht mehr das ganze Lager.

#### Teil A — Einschätzung

Gebt eine Einschätzung in ein bis zwei Sätzen ab, ohne Rechner: Warum ist es
besser, einer Funktion nur das betroffene Bauteil zu übergeben, statt das ganze
Array?

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    Wenn das ganze Array übergeben wird, kann die Funktion theoretisch **alles**
    darin verändern, nicht nur das eine Bauteil, das sie ändern soll. Man kann
    nicht einzelne Felder zum Verändern freigeben, sondern nur das ganze Array.
    Bei einem Pointer auf ein einzelnes Bauteil hat die Funktion dagegen nur
    Zugriff auf genau dieses eine. Das ist das **Prinzip der minimalen Rechte** aus
    der Übung.

    Weitere Vorteile: Die Funktion braucht weniger Parameter (keine Anzahl, keine
    Nummer), sie muss nichts suchen, und sie ist leichter zu verstehen und zu
    testen, weil sie nur eine Sache tut.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Konsequenzen für den Code

Bevor ihr die Funktion ändert, überlegt ohne Rechner, was die Änderung für den
Code bedeutet. Die Funktion soll künftig nur noch das betroffene Bauteil und die
Menge bekommen.

<quiz>
Welche Aussagen über die Folgen für den Code treffen zu? (Mehrere Antworten können richtig sein.)

- [ ] Die Funktion muss das geänderte Bauteil mit `return` zurückgeben, damit der Bestand im Lager ankommt.
> Nein. Die Funktion arbeitet über den Pointer direkt am Original, das Ergebnis muss nicht zurückgegeben werden.
- [x] Der Aufruf in `main` wird zu `auffuellen(&lager[i], 20)`, die Schleife mit der Bedingung für `MINDESTBESTAND` bleibt.
> Richtig. `main` entscheidet weiterhin, welche Bauteile aufgefüllt werden, und übergibt jetzt die Adresse des gewählten Bauteils.
- [ ] Der Prototyp wird zu `void auffuellen(Bauteil b, int menge)`, weil ein einzelnes Bauteil nur ein Wert ist.
> Nein. Mit einem Wert bekäme die Funktion nur eine Kopie, und die Änderung ginge verloren. Es muss ein Pointer sein.
- [x] Im Funktionsrumpf greift man über den Pfeil-Operator `->` auf den Bestand zu.
> Richtig. Über den Pointer greift man mit dem Pfeil-Operator auf das Member zu.
- [ ] Beim Zugriff über den Pfeil-Operator wird das Bauteil zuerst kopiert, damit das Original geschützt bleibt.
> Nein. Der Pfeil-Operator greift direkt auf das Original zu, es wird nichts kopiert. Genau deshalb ändert sich der Bestand im Lager.
- [x] In der Funktion entfällt die Suchschleife, weil das richtige Bauteil schon ausgewählt übergeben wird.
> Richtig. Die Suche über die Nummer erledigt jetzt der Aufrufer, indem er das passende Bauteil auswählt.

Mit einem Pointer auf ein einzelnes Element bekommt die Funktion genau das, was sie ändern soll, und sonst nichts. Die Auswahl des Bauteils liegt beim Aufrufer.
</quiz>

---

#### Teil C — Umsetzen

Ändert `auffuellen` so, dass die Funktion nur noch einen Pointer auf ein
`Bauteil` und die Menge bekommt, und passt den Aufruf in `main` an.

Lasst die Vorgabe zuerst einmal laufen. Die Ausgabe des Programms soll nach
eurer Änderung genau dieselbe sein.

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil C anzeigen"
    ```c linenums="1" hl_lines="26 46 93 95"
    --8<-- "02-theoriephase/termin-06/code/aufg-43-bauteillager-pointer.c"
    ```

    1. `auffuellen` bekommt nur noch den Pointer auf ein Bauteil und die
       Menge. `anzahl` und `nummer` sind nicht mehr nötig.
    2. `main` wählt weiterhin per Schleife aus, welche Bauteile aufgefüllt
       werden, und übergibt die Adresse des gewählten Elements: `&lager[i]`.
    3. Über den Pointer greift die Funktion mit `->` auf das Original zu.
       Die Suchschleife ist weggefallen.

    Typische Fehler: den Bauteil-Parameter ohne Pointer lassen (die Änderung
    kommt dann nicht im Lager an), `b.bestand` statt `b->bestand` schreiben oder
    `&lager[i]` im Aufruf vergessen.
<!-- MUSTERLOESUNG-ENDE -->

---

### Aufgabe 44: Lerngruppen

Studierende bilden Lerngruppen. Jeder `Student` hat einen Namen und kennt seine
Lernpartner über **Pointer auf andere Studierende**. Es wird also nichts kopiert:
Der Partner ist derselbe Student, der auch in `main` angelegt wurde. Die Struktur
enthält damit einen Pointer auf ihren eigenen Typ. Dafür wird hier die Variante
mit `typedef struct Student Student;` vor der Definition verwendet. In den
Signaturen der Vorgaben ist `const` schon gesetzt, dort müsst ihr nichts
ergänzen.

**Mit KI:** Diese Aufgabe darf ausdrücklich mit KI bearbeitet werden, auch zum
Schreiben des Codes, zum Beispiel um die Funktionen aus der Vorgabe ausfüllen zu
lassen. Der Fokus liegt auf dem Verständnis: Ihr müsst jede übernommene Zeile
erklären können, besonders, wie die Pointer der Studierenden aufeinander zeigen
und wie `s->partner[i]->name` gelesen wird. Prüft das Ergebnis immer gegen die
erwartete Ausgabe. Mehr dazu in [KI im Kurs](../../ki-nutzung.md).

#### Teil A — Ein Partner

Jeder Student hat höchstens einen Partner:

```c linenums="1"
--8<-- "02-theoriephase/termin-06/code/vorgabe-44-lerngruppe-a.c"
```

Schreibt die beiden Funktionen:

- `lerngruppeBilden(Student *a, Student *b)` trägt `a` und `b` gegenseitig als
  Partner ein. Ihr dürft annehmen, dass beide noch keinen Partner haben.
- `partnerAusgeben(const Student *s)` gibt `"<Name> lernt mit <Name des
  Partners>."` aus oder `"<Name> hat noch keinen Partner."`, falls `partner`
  gleich `NULL` ist.

Der interessante Punkt ist die Ausgabe: Der Name des Partners steht nicht in `s`
selbst, sondern in dem Student, auf den `s->partner` zeigt.

Erwartete Ausgabe:

```text
Anna hat noch keinen Partner.
Anna lernt mit Ben.
Ben lernt mit Anna.
Chris hat noch keinen Partner.
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil A anzeigen"
    ```c linenums="1" hl_lines="36-37 42-45"
    --8<-- "02-theoriephase/termin-06/code/aufg-44-lerngruppe-a.c"
    ```

    1. Beide Zuweisungen laufen über die Pointer `a` und `b`, sie ändern also
       die Original-Studierenden aus `main`. Mit einer Kopie wäre das nicht
       möglich.
    2. Ohne Partner steht in `partner` der Wert `NULL`. Diesen Fall muss man
       abfragen, bevor man dem Pointer folgt.
    3. `s->partner->name` heißt: `s` zeigt auf einen Student, dessen Member
       `partner` ist wieder ein Pointer, und über den greift man auf `name` zu.
       Das `const` bei `s` sagt, dass die Funktion nur liest.

    Typische Fehler: den `NULL`-Fall vergessen (das Programm stürzt ab, sobald
    es `NULL` dereferenziert) oder die Partner nur in eine Richtung eintragen.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil B — Partnerwechsel

Bisher durfte man annehmen, dass beide Studierenden noch keinen Partner haben.
Jetzt wechselt ein Student auch mal die Lerngruppe: Sucht sich jemand einen neuen
Partner, wird die Verbindung zum alten Partner gelöst. Der alte Partner hat dann
wieder keinen Partner mehr, und dafür müsst ihr über den Pointer auf ihn
zugreifen und dessen `partner` auf `NULL` setzen.

Erweitert `lerngruppeBilden` in dieser Vorgabe entsprechend. Hat `a` oder `b`
schon einen Partner, wird diese Verbindung zuerst gelöst. `partnerAusgeben` ist
schon fertig.

```c linenums="1"
--8<-- "02-theoriephase/termin-06/code/vorgabe-44-lerngruppe-b.c"
```

Erwartete Ausgabe:

```text
Anna und Ben bilden eine Lerngruppe:
Anna lernt mit Ben.
Ben lernt mit Anna.

Anna wechselt zu Chris:
Anna lernt mit Chris.
Ben hat noch keinen Partner.
Chris lernt mit Anna.

Ben geht zu Dora, dann wechselt Dora zu Chris:
Anna hat noch keinen Partner.
Ben hat noch keinen Partner.
Chris lernt mit Dora.
Dora lernt mit Chris.
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil B anzeigen"
    ```c linenums="1" hl_lines="48-51"
    --8<-- "02-theoriephase/termin-06/code/aufg-44-lerngruppe-b.c"
    ```

    1. Hat `a` einen Partner, zeigt `a->partner` auf ihn. Über diesen Pointer
       geht es einen Schritt weiter: `a->partner->partner = NULL` setzt beim
       **alten Partner** den Pointer zurück, er kennt `a` danach nicht mehr.
    2. Dasselbe passiert für den alten Partner von `b`. Erst danach werden `a`
       und `b` gegenseitig eingetragen.

    Die Reihenfolge ist wichtig: Würde man zuerst `a->partner = b` setzen, ginge
    der Pointer auf den alten Partner verloren, und man könnte ihn nicht mehr
    lösen. Sind `a` und `b` schon Partner voneinander, funktioniert der Code
    trotzdem: Die Verbindung wird gelöst und sofort wieder hergestellt.

    Typische Fehler: nur `a->partner = NULL` setzen (der alte Partner glaubt dann
    noch, er lerne mit `a`) oder die `NULL`-Abfrage vergessen und damit einen
    Pointer auf `NULL` dereferenzieren.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil C — Bis zu drei Partner

Jetzt kann ein Student mit bis zu drei anderen lernen, ohne dass dabei eine alte
Verbindung gelöst wird. Die Struktur bekommt dafür ein **Array von Pointern** auf
Studierende und einen Zähler. `partner` hat drei Plätze, und in jedem steht die
Adresse eines Studenten, oder `NULL`, wenn der Platz frei ist. Bei `{ NULL }` in
der Initialisierung werden die übrigen Plätze automatisch ebenfalls auf `NULL`
gesetzt. Der Zähler `anzahlPartner` merkt sich, wie viele Plätze belegt sind:

```c linenums="1"
--8<-- "02-theoriephase/termin-06/code/vorgabe-44-lerngruppe-c.c"
```

Schreibt die drei Funktionen:

- `partnerHinzufuegen(Student *s, Student *neu)` trägt `neu` bei `s` ein und
  liefert `1`. Ist `s` schon voll (drei Partner), ist `neu` schon eingetragen
  oder sind `s` und `neu` derselbe Student, trägt sie nichts ein und liefert `0`.
- `lerngruppeBilden(Student *a, Student *b)` trägt beide gegenseitig ein und
  liefert `1`. Ist das nicht möglich (einer ist voll oder sie sind schon
  verbunden), wird keiner von beiden verändert, und die Funktion liefert `0`.
- `partnerAusgeben(const Student *s)` gibt `"<Name> lernt mit: <Partner> ..."`
  aus, oder `"<Name> hat noch keine Partner."`.

In `main` der Vorgabe steht ein Aufruf direkt in `printf` hinter einem `?`. Der
Aufruf wird dabei ausgeführt, und sein Ergebnis (`1` oder `0`) entscheidet, welcher
der beiden Texte ausgegeben wird.

Beim Lesen eines Partners kombiniert ihr Pfeil-Operator und Index:
`s->partner[i]->name`. Erst wählt `partner[i]` den i-ten Pointer aus, dann folgt
`->name` dem Pointer.

Erwartete Ausgabe:

```text
Anna und Emil: nicht moeglich
Anna und Ben erneut: nicht moeglich
Anna lernt mit: Ben Chris Dora
Ben lernt mit: Anna Chris
Chris lernt mit: Anna Ben
Dora lernt mit: Anna
Emil hat noch keine Partner.
```

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil C anzeigen"
    ```c linenums="1" hl_lines="48-49 51-53 55-56 58 63-64 66-67 69 71 76-80 82-85"
    --8<-- "02-theoriephase/termin-06/code/aufg-44-lerngruppe-c.c"
    ```

    1. Der Student wird sich nicht selbst als Partner hinzugefügt, und bei
       drei Partnern ist Schluss.
    2. Die Schleife vergleicht die **Pointer**. Zeigt ein Eintrag schon auf
       `neu`, ist es derselbe Student.
    3. Der neue Partner kommt an die erste freie Stelle, der Zähler zeigt auf
       sie. Danach wird der Zähler erhöht.
    4. `lerngruppeBilden` prüft **vor** dem Eintragen, ob bei beiden noch Platz
       ist. So wird nie nur einer von beiden verändert.
    5. `s->partner[i]->name`: Index wählt den Pointer aus, der Pfeil folgt
       ihm.

    Typische Fehler: nur in eine Richtung eintragen, den Platz erst nach dem
    ersten Eintrag prüfen (dann steht ein Student halb eingetragen da) oder
    Namen statt Pointer vergleichen.
<!-- MUSTERLOESUNG-ENDE -->

---

#### Teil D — Gemeinsame Partner (optional)

Für alle, die früher fertig sind: Schreibt in eurem Programm aus Teil C die
Funktion `int gemeinsamePartner(const Student *a, const Student *b)`. Sie zählt,
wie viele Partner `a` und `b` gemeinsam haben, also wie viele Pointer in beiden
Listen auf denselben Student zeigen. Ruft sie in `main` nach den Aufrufen von
`partnerAusgeben` auf, und zwar mit diesen beiden Zeilen. Falls eure Lösung von
Teil C nicht läuft, könnt ihr hier mit der Musterlösung von Teil C weiterarbeiten:

```c
printf("Gemeinsame Partner von Ben und Chris: %d\n", gemeinsamePartner(&ben, &chris));
printf("Gemeinsame Partner von Ben und Dora: %d\n", gemeinsamePartner(&ben, &dora));
```

Die Ausgabe wächst um die zwei Zeilen `Gemeinsame Partner von Ben und Chris: 1`
und `Gemeinsame Partner von Ben und Dora: 1` (in beiden Fällen ist Anna die
gemeinsame Partnerin).

<!-- MUSTERLOESUNG-START -->
??? note "Musterlösung Teil D anzeigen"
    ```c linenums="1" hl_lines="18 42-43 92-94 96-99 101-102"
    --8<-- "02-theoriephase/termin-06/code/aufg-44-lerngruppe-d.c"
    ```

    1. Zwei verschachtelte Schleifen vergleichen jeden Partner von `a` mit
       jedem Partner von `b`. Verglichen werden die **Adressen**: Sind sie
       gleich, ist es derselbe Student.
<!-- MUSTERLOESUNG-ENDE -->
