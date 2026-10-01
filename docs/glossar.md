# Glossar

Kurze Erklärungen zu den Fachbegriffen, die im Kurs vorkommen — in einfachen
Worten, nicht als formale Definition. 

<!--
PFLEGEHINWEIS (nicht sichtbar auf der Seite)

Nach dem Erstellen JEDER neuen Einheit prüfen, ob dabei neue Fachbegriffe
eingeführt wurden, die hier noch fehlen — und diese ergänzen. Das ist ein
Pflichtschritt bei der Erstellung, kein optionales Aufräumen im Nachhinein
(siehe CLAUDE.md, Abschnitt "Glossar pflegen").

Regeln:
- Definitionen kurz und in eigenen Worten, niemals aus einer Quelle
  übernehmen (Urheberrecht).
- Zielgruppe sind Erstsemester ohne Vorkenntnisse. Eine Erklärung, die
  selbst wieder drei unerklärte Begriffe enthält, ist keine Erklärung.
- Durchgehend alphabetisch nach Begriff sortiert.
- Format: Markdown-Definitionsliste (def_list ist in mkdocs.yml aktiv).
-->

## A

**Abbruchbedingung**
: Der Teil einer rekursiven Funktion, der ohne weiteren rekursiven Aufruf
ein Ergebnis liefert. Ist die Abbruchbedingung erreicht, endet die Kette
der Selbstaufrufe und die Aufrufe rechnen der Reihe nach ihr Ergebnis
fertig. Fehlt sie oder wird sie nie erreicht, ruft sich die Funktion
unendlich oft selbst auf — ein Stapelüberlauf ist die Folge.  

**Abstraktion**
: Das Weglassen von allem, was für einen bestimmten Zweck unwichtig ist, damit
das Wesentliche übrig bleibt. Was wesentlich ist, hängt immer vom Zweck ab: Für
die Statik eines Hauses ist die Wandfarbe unwichtig, für den Malerbetrieb nicht.
 

**Adresse**
: Die Nummer, über die eine einzelne Speicherzelle im Hauptspeicher angesprochen
wird — vergleichbar mit der Nummer eines Schließfachs.  

**Adressoperator**
: Das Zeichen `&` vor einem Variablennamen in C. Es liefert nicht den Wert
der Variable, sondern ihre Adresse im Speicher — zum Beispiel damit
`scanf_s` weiß, wohin es einen eingelesenen Wert schreiben soll.  

**Algorithmus**
: Eine eindeutige Handlungsvorschrift, die aus gegebenen Ausgangswerten in
endlich vielen Schritten ein Ergebnis erzeugt. Ein Algorithmus muss dabei drei
Eigenschaften erfüllen: Eindeutigkeit, Endlichkeit und Determiniertheit.  

**Array**
: Eine feste Anzahl von Variablen desselben Datentyps, die unter einem
gemeinsamen Namen direkt hintereinander im Speicher liegen. Die einzelnen
Werte heißen Elemente und werden über einen Index angesprochen — zum
Beispiel eine ganze Messreihe unter dem Namen `messwerte`.  

**ASCII-Code**
: Eine weit verbreitete Zeichencodierung, die jedem Zeichen (Buchstabe, Ziffer,
Satzzeichen) eine Zahl zwischen 0 und 127 zuordnet. Diese Zahl wird dann wie
jede andere Zahl binär im Rechner gespeichert.  

**Assemblersprache**
: Eine Programmiersprache, die den Befehlen eines bestimmten Prozessors sehr nahe
kommt, statt der Bitmuster aber lesbare Namen verwendet. Sie liegt im
Ebenenmodell zwischen der Maschinensprache und Sprachen wie C.
 
**Aufzählungsdatentyp (enum)**
: Ein selbst definierter Datentyp für eine abgeschlossene Liste möglicher Werte,
zum Beispiel die Betriebszustände einer Maschine oder die Einheiten einer
Temperatur. Die Namen in der Liste sind nur Hilfsmittel für Programmierer; der
Compiler nummeriert sie automatisch ab 0 durch (sofern keine Zahl ausdrücklich
angegeben ist), und intern wird jeder Wert als ganze Zahl (`int`) gespeichert.  

## B

**Basis**
: Die Grundzahl eines Stellenwertsystems. Sie gibt an, wie viele
verschiedene Ziffern zur Verfügung stehen und wie stark der Wert einer Ziffer
von Stelle zu Stelle wächst. Das Dezimalsystem hat die Basis 10, das
Dualsystem die Basis 2.  

**Basisdatentyp**
: Einer der grundlegenden Datentypen einer Programmiersprache. In C sind
das `int` für ganze Zahlen, `float` und `double` für Zahlen mit
Nachkommaanteil (`double` mit höherer Genauigkeit als `float`) sowie
`char` für ein einzelnes Zeichen.  

**Bauen (Build)**
: Der Vorgang, bei dem eine Entwicklungsumgebung den Quelltext eines
Projekts durch den Compiler übersetzen und zu einer ausführbaren Datei
zusammenfügen lässt. Erst nach dem Bauen kann das Programm gestartet
werden.  

**Bedingte Kompilierung**
: Eine Technik des Präprozessors: Bestimmte Teile des Quelltexts werden nur
dann an den Compiler weitergegeben, wenn eine Bedingung zutrifft, etwa wenn
ein bestimmter Name per `#define` festgelegt wurde (`#ifdef`, `#ifndef`,
`#else`, `#endif`). So lässt sich Code wie mit einem Schalter ein- und
ausblenden, ohne ihn zu löschen.  

**Befehlsausführungszyklus**
: Die drei Schritte, die ein Prozessor immer wieder durchläuft, bis ein
Halte-Befehl kommt: den nächsten Befehl aus dem Hauptspeicher holen, den
Befehlszeiger erhöhen, den geholten Befehl ausführen.  

**Befehlsregister (BR)**
: Das Register, in dem der Befehl steht, den der Prozessor gerade ausführt. Es
enthält den Operationscode und die Operanden.  

**Befehlssatz**
: Die vollständige Menge aller Befehle, die ein bestimmter Prozessor ausführen
kann. Jede Prozessorfamilie hat ihren eigenen.  

**Befehlszeiger (BZ)**
: Das Register, das die Adresse des Befehls enthält, der als nächstes ausgeführt
wird. Nach jedem geholten Befehl wird es um eins erhöht — außer ein Sprungbefehl
schreibt eine andere Adresse hinein.  

**Bibliothek**
: Eine Sammlung fertiger Funktionen, die man per `#include` in ein eigenes
Programm einbindet, um sie nutzen zu können, ohne sie selbst zu schreiben
— zum Beispiel `stdio.h` für Ein- und Ausgabe.  

**Binäre Suche**
: Ein Algorithmus, der eine gesuchte Zahl in einem sortierten Zahlenbereich
findet, indem er den Bereich bei jedem Schritt halbiert und die Hälfte
verwirft, in der die Zahl nicht liegen kann. Ein Beispiel für das
Divide-and-Conquer-Prinzip.  

**Bit**
: Die kleinste Informationseinheit, die ein Rechner kennt: eine einzelne
Dualstelle mit dem Wert 0 oder 1.  

**Bitmaske**
: Eine Zahl, deren gesetzte Bits festlegen, welche Bits einer anderen Zahl bei
einer Bitoperation betroffen sind. Soll zum Beispiel nur das Bit an Position 3
geändert werden, hat die Maske genau dort eine 1 und sonst überall 0.

**Bitoperator**
: Ein Operator, der die einzelnen Bits von Zahlen verknüpft, statt mit dem
Zahlenwert zu rechnen, zum Beispiel `|` (ODER), `&` (UND), `~` (Invertieren) und `<<`
(Bits nach links schieben), außerdem gibt es weitere wie `^` und `>>`. Nicht zu verwechseln mit den logischen Operatoren
`||` und `&&`.  

**Brute-Force**
: Eine Lösungsstrategie, die ein Problem löst, indem sie konsequent alle
Möglichkeiten durchprobiert, ohne nach einem sparsameren Weg zu suchen.  

**Bubblesort**
: Ein einfacher Sortieralgorithmus: Benachbarte Elemente werden von links
nach rechts verglichen und vertauscht, wenn sie in der falschen Reihenfolge
stehen. Nach jedem Durchlauf steht das größte der noch unsortierten Elemente
am rechten Ende; das Verfahren wird wiederholt, bis alles sortiert ist.  

**Bus**
: Ein gemeinsamer Verbindungsweg, an den alle Komponenten eines Rechners
angeschlossen sind. Spart Verkabelung und macht Erweiterungen einfach, dafür kann
immer nur ein Paar zur Zeit darüber kommunizieren.  

**Byte**
: Eine Gruppe von 8 Bit. Ein Byte kann `2⁸ = 256` verschiedene Werte
annehmen (0 bis 255) und ist die gebräuchlichste Einheit, um die Größe von
Speicher anzugeben.  

## C

**Call by Reference**
: Eine Art, einer Funktion einen Wert zu übergeben: Die Funktion bekommt
nicht eine Kopie, sondern das Original. Änderungen in der Funktion wirken
sich deshalb auch außerhalb aus. In C passiert das bei Arrays automatisch;
wie das technisch funktioniert, klärt der Termin zu Pointern.  

**Call by Value**
: Die Normalform der Wertübergabe: Die Funktion bekommt eine Kopie des
Werts. Änderungen an diesem Parameter betreffen nur die Kopie, das Original
bleibt unverändert — so werden einfache Parameter wie `int` oder `char`
übergeben.  

**Codepage**
: Eine Zuordnung zwischen Zahlenwerten und Zeichen, die festlegt, welches
Zeichen ein Programm wie die Windows-Konsole für einen bestimmten Wert
anzeigt. Passt die eingestellte Codepage nicht zur Codierung des Textes,
erscheinen falsche Zeichen — zum Beispiel bei deutschen Umlauten.  

**Compiler**
: Ein Programm, das Quelltext einer Programmiersprache wie C in Maschinensprache
übersetzt, damit der Prozessor ihn ausführen kann.  

**Compound Statement**
: Ein mit `{` und `}` eingeschlossener Block von Anweisungen, der wie eine
einzelne Anweisung behandelt wird — zum Beispiel der Rumpf einer Funktion,
einer Verzweigung oder einer Schleife. Jedes Compound Statement eröffnet
einen eigenen Gültigkeitsbereich: Eine darin deklarierte Variable existiert
nur innerhalb dieses Blocks.  

**const**
: Ein Schlüsselwort, das einen Wert als unveränderlich kennzeichnet. Bei einem
Pointer-Parameter wie `const Bauteil *b` bedeutet es: Die Funktion darf lesen,
was am Pointer liegt, aber nichts daran verändern. Der Compiler meldet einen
Fehler, wenn sie es doch versucht.


## D

**Datentyp**
: Legt fest, welche Art von Werten eine Variable speichern kann (zum
Beispiel ganze Zahlen, Kommazahlen oder ein einzelnes Zeichen) und wie
viel Speicherplatz dafür reserviert wird. Siehe auch Basisdatentyp.  

**Debugger**
: Ein Werkzeug, mit dem sich ein Programm Schritt für Schritt beobachten
lässt, statt es nur am Stück laufen zu lassen. Wird in diesem Kurs erst
später genauer eingeführt.  

**Deklaration**
: Das Anlegen einer Variable mit einem festgelegten Datentyp im Speicher —
zum Beispiel `int anzahl;`. Ab diesem Zeitpunkt existiert die Variable,
hat aber noch keinen sinnvollen Wert, solange ihr keiner zugewiesen wurde.  

**Dereferenzierung**
: Der Zugriff auf den Wert, auf den ein Pointer zeigt, über den Operator
`*` vor dem Pointernamen. `*p` liefert also nicht die Adresse selbst,
sondern den Wert an dieser Adresse — bei Pointern der Gegenspieler zum
Adressoperator `&`.  

**Determiniertheit**
: Eine Eigenschaft von Algorithmen: Bei denselben Ausgangswerten liefert der
Algorithmus immer dasselbe Ergebnis.  

**Differenzenquotient**
: Eine Formel, mit der sich die Ableitung einer Funktion an einer Stelle
`x` näherungsweise berechnen lässt, ohne die Ableitungsregeln der Analysis
zu benutzen: `(f(x + h) − f(x − h)) / (2h)` für eine sehr kleine
Schrittweite `h`. Grafisch entspricht das der Steigung einer Sekante durch
zwei nahe beieinanderliegende Punkte des Funktionsgraphen, die sich für
kleiner werdendes `h` immer mehr der Tangentensteigung annähert.  

**Divide-and-Conquer**
: Zu Deutsch "Teile und herrsche": eine Lösungsstrategie, die ein Problem
bei jedem Schritt in kleinere Teile zerlegt und diese Teile unabhängig
voneinander weiterbearbeitet. Manchmal lässt sich dabei gezielt ein Teil
verwerfen, der für die Lösung nicht mehr infrage kommt (so bei der binären
Suche), manchmal werden stattdessen beide Teile parallel weiterbehandelt
(so bei Quicksort, das nach dem Partitionieren beide Teilreihen rekursiv
sortiert). Oft deutlich sparsamer als Brute-Force.  

**Dualsystem**
: Ein Stellenwertsystem mit der Basis 2 und dem Ziffernvorrat 0 und 1. Auch
Binärsystem genannt. Alle Daten in einem Rechner liegen letztlich in dieser
Form vor.  

## E

**Eindeutigkeit**
: Eine Eigenschaft von Algorithmen: Jeder Schritt ist so klar formuliert, dass
es keinen Interpretationsspielraum gibt.  

**Element (eines Arrays)**
: Ein einzelner Wert in einem Array, angesprochen über seinen Index — zum
Beispiel `messwerte[2]`.  

**Endlichkeit**
: Eine Eigenschaft von Algorithmen: Die Beschreibung besteht aus endlich
vielen Schritten, und ihre Ausführung kommt nach endlich vielen Schritten
tatsächlich zu einem Ende.  

**Endlosschleife**
: Eine Wiederholung, deren Bedingung nie unwahr wird, sodass sie nie von
selbst endet — meist ein Programmierfehler, zum Beispiel wenn vergessen
wird, die geprüfte Variable im Schleifenrumpf zu verändern.  

**ESC-Sequenz**
: Eine Zeichenfolge, die mit dem Escape-Zeichen beginnt und der Konsole
statt eines auszugebenden Textes einen Steuerbefehl übermittelt — zum
Beispiel eine andere Textfarbe oder eine neue Cursorposition. Geht über den
eigentlichen C-Standard hinaus, funktioniert in der Windows-Konsole aber
zuverlässig.  

## F

**Fallthrough**
: Wenn in einer `switch`/`case`-Anweisung nach einem Fall das `break`
fehlt, "fällt" die Ausführung einfach in den nächsten Fall durch, statt
die Anweisung zu verlassen — meist ein Fehler, kein gewolltes Verhalten.  

**Formatierungszeichen**
: Ein Platzhaltersymbol mit vorangestelltem `%` in einer `printf`- oder
`scanf_s`-Zeichenkette, das angibt, welcher Datentyp an dieser Stelle
ausgegeben bzw. eingelesen werden soll — zum Beispiel `%d` für eine ganze
Zahl oder `%c` für ein einzelnes Zeichen.  

**Funktion**
: Ein benannter, in sich abgeschlossener Abschnitt eines Programms, der
bestimmte Anweisungen ausführt. Über Parameter lässt sie sich mit
unterschiedlichen Werten aufrufen, über einen Rückgabewert kann sie ein
Ergebnis liefern. `main` ist die besondere Funktion, mit der jedes
C-Programm startet.  

**Funktionspointer**
: Ein Pointer, der nicht auf eine Variable, sondern auf eine Funktion
zeigt — genauer: auf eine Funktion mit einer bestimmten Signatur (Anzahl
und Typ der Parameter, Rückgabetyp). Ein Funktionspointer lässt sich wie
ein normaler Pointer als Parameter übergeben, sodass eine Funktion selbst
zur austauschbaren Zutat einer anderen Funktion wird.  

**Funktionsprototyp**
: Eine Ankündigung von Name, Parametern und Rückgabetyp einer Funktion,
noch bevor die eigentliche Definition (der Funktionskörper) im Quelltext
folgt. Nötig, damit der Compiler einen Aufruf schon kennt, bevor er die
Definition gelesen hat — üblicherweise steht der Prototyp vor `main`, die
Definition danach.  

**Fußgesteuerte Wiederholung**
: Eine Wiederholung, bei der die Bedingung erst nach den
Schleifenanweisungen geprüft wird. Dadurch laufen die Anweisungen immer
mindestens einmal, bevor überhaupt geprüft wird.  

## H

**Hauptspeicher**
: Der Speicher, in dem ein laufendes Programm samt seinen Daten liegt. Er besteht
aus vielen gleich aufgebauten Speicherzellen, ist schnell, verliert seinen Inhalt
aber beim Ausschalten. Auch Arbeitsspeicher oder RAM genannt.
 

**Header-Datei**
: Eine Textdatei mit der Endung `.h`, in der steht, was eine andere Datei an
Funktionen, Typen und Makros anbietet, zum Beispiel `stdio.h`. Man bindet sie
per `#include` ein. Eigene Header-Dateien bindet man mit Anführungszeichen
ein: `#include "myUtil.h"`.  

**Hexadezimalsystem**
: Ein Stellenwertsystem mit der Basis 16. Der Ziffernvorrat besteht aus den
zehn Ziffern 0 bis 9 sowie den Buchstaben A bis F für die Werte 10 bis 15.
Wird in der Informatik oft verwendet, weil sich damit lange Dualzahlen sehr
viel kompakter aufschreiben lassen (vier Binärstellen entsprechen genau
einer Hexadezimalziffer).  

**Horner-Schema**
: Auch Restwertmethode genannt: ein Verfahren, um eine Dezimalzahl in ein
anderes Stellenwertsystem umzuwandeln. Man teilt die Zahl fortgesetzt durch
die Zielbasis und liest die dabei entstehenden Reste von unten nach oben.  

## I

**IDE**
: Abkürzung für *Integrated Development Environment*, zu Deutsch
integrierte Entwicklungsumgebung. Ein Programm, das Editor, Compiler und
weitere Werkzeuge zur Programmentwicklung an einem Ort vereint — zum
Beispiel Visual Studio.  

**Include-Guard**
: Ein Schutz in einer Header-Datei, der verhindert, dass ihr Inhalt zweimal in
dieselbe `.c`-Datei eingefügt wird. Er besteht aus `#ifndef NAME`, `#define NAME`
am Anfang und `#endif` am Ende der Header-Datei.  

**Index**
: Die Nummer, mit der ein Element eines Arrays angesprochen wird. In C hat
das erste Element den Index `0`, bei `n` Elementen ist `n - 1` der letzte
gültige Index.  

**Informatik**
: Die Wissenschaft von der systematischen — vor allem der automatischen —
Verarbeitung und Übermittlung von Information mithilfe von Rechnern.
 

**Information**
: Ein abstraktes Abbild von etwas Realem, das nur die für einen bestimmten Zweck
wichtigen Eigenschaften enthält. Ein Bauplan ist Information über ein Haus: Er
ist nicht das Haus, aber er genügt, um es zu bauen.  

**Initialisierung**
: Das Vergeben eines ersten Werts direkt bei der Deklaration einer
Variable — zum Beispiel `int anzahl = 3;`. Im Unterschied zur reinen
Deklaration hat die Variable danach sofort einen sinnvollen Wert.  

## K

**Kommandozeilenparameter**
: Ein Wert, der einem Programm schon beim Start mitgegeben wird, statt
ihn erst während der Ausführung abzufragen — zum Beispiel `programm.exe
suche 42`. In C kommen diese Parameter über die beiden zusätzlichen
`main`-Parameter `int argc` (Anzahl der Parameter, `argv[0]` mitgezählt)
und `char *argv[]` (die Parameter selbst, als Strings) ins Programm.  

**Kommentar**
: Text im Quellcode, den der Compiler vollständig ignoriert — nur für
Menschen gedacht, die den Code lesen. Ein Zeilenkommentar beginnt mit `//`
und gilt bis zum Zeilenende, ein Blockkommentar steht zwischen `/*` und
`*/` und kann sich über mehrere Zeilen erstrecken.  

**Konsolenanwendung**
: Ein Programm, das ausschließlich über ein Textfenster (die Konsole) mit
seinen Nutzern kommuniziert — Eingaben über die Tastatur, Ausgaben als
Text. Alle Programme in diesem Kurs sind Konsolenanwendungen.  

**Kopfgesteuerte Wiederholung**
: Eine Wiederholung, bei der die Bedingung vor den Schleifenanweisungen
geprüft wird. Ist sie von Anfang an nicht erfüllt, laufen die Anweisungen
kein einziges Mal.  

## L

**Leitwerk**
: Die Funktionsgruppe im Prozessor, die den Ablauf des Programms steuert: Sie
sorgt dafür, dass Befehle geholt und in der richtigen Reihenfolge ausgeführt
werden.  

## M

**Linker**
: Das Werkzeug, das nach dem Compiler die einzelnen übersetzten Dateien eines
Projekts zusammen mit den Bibliotheken zu einer ausführbaren Datei
verbindet.  

**Magic Number**
: Eine Zahl, die direkt im Code steht, ohne dass ihre Bedeutung erkennbar ist,
zum Beispiel `if (zustand == 2)`. Sie macht den Code schwer lesbar und fehleranfällig;
besser ist eine sprechend benannte Konstante oder ein `enum`.  

**Makro**
: Ein Name, den der Präprozessor im Quelltext durch einen anderen Text ersetzt,
bevor der Compiler den Code sieht. Definiert wird es mit `#define`. Ein
Makro ist reine Textersetzung, es hat keinen Datentyp und keinen
Speicherplatz.  

**Maschinenbefehl**
: Ein einzelner Befehl, den ein Prozessor unmittelbar ausführen kann. Er besteht
aus einem Operationscode und den Operanden.  

**Maschinensprache**
: Die Sprache, die ein Prozessor unmittelbar versteht. Ihre "Wörter" sind die
Befehle aus seinem Befehlssatz. Sie ist von Prozessor zu Prozessor
unterschiedlich.  

**Mehrdimensionales Array**
: Ein Array, dessen Elemente selbst wieder Arrays sind — zum Beispiel eine
Tabelle mit Zeilen und Spalten. Angesprochen wird ein Element mit einem
Index pro Dimension, etwa `matrix[1][2]`.  

**Member**
: Eine einzelne Variable innerhalb einer Struktur, mit eigenem Namen und
Datentyp. Auf ein Member greift man mit dem Punkt-Operator zu, zum Beispiel
`p.wert`.  

**Mockup**
: Ein früher, noch unfertiger Entwurf einer Software, der schon Bedienung
und Ablauf zeigt, aber bewusst noch nicht alle Teile enthält — zum
Beispiel eine Anwendung ohne dauerhafte Datenspeicherung, weil diese
Frage erst später geklärt wird. Dient dazu, eine Idee früh auszuprobieren
und Rückmeldung dazu einzuholen, bevor der volle Aufwand investiert wird.  

**Modulo-Operator**
: Das Zeichen `%` in C. Es liefert den Rest einer Ganzzahldivision — zum
Beispiel ist `17 % 5` gleich `2`. Zusammen mit der normalen Division `/`
lässt sich damit eine Zahl in Stellen unterschiedlicher Größenordnung
zerlegen, etwa Sekunden in Stunden, Minuten und Restsekunden.  

**MSB**
: Abkürzung für *Most Significant Bit*, zu Deutsch das höchstwertige Bit
einer Dualzahl. Bei der Zweierkomplement-Darstellung zeigt es das Vorzeichen
an: 0 für positiv (oder null), 1 für negativ.  

## N

**Newton-Verfahren**
: Ein numerisches Verfahren, um eine Nullstelle einer Funktion
anzunähern: Ausgehend von einem Startwert `x` wird wiederholt
`x := x − f(x) / f'(x)` berechnet, bis der Funktionswert `f(x)` nahe genug
an `0` liegt.  

**NULL-Pointer**
: Ein Pointer, der bewusst auf keine gültige Adresse zeigt, gekennzeichnet
durch den Wert `NULL`. Wird zum Beispiel benutzt, um "hier gibt es (noch)
nichts" auszudrücken, oder um einer Funktion beim Aufruf mitzuteilen, dass
sie sich an einen vorherigen Aufruf erinnern soll, statt neu zu beginnen.  

## O

**Objektdatei**
: Das Zwischenergebnis, das der Compiler aus einer einzelnen `.c`-Datei erzeugt:
übersetzter Code, der noch nicht lauffähig ist. Erst der Linker fügt alle
Objektdateien zu einem ausführbaren Programm zusammen.  

**Oktalsystem**
: Ein Stellenwertsystem mit der Basis 8 und dem Ziffernvorrat 0 bis 7. Drei
Binärstellen entsprechen genau einer Oktalziffer.  

**O-Notation**
: Eine Schreibweise, mit der man ausdrückt, wie stark die Zeitkomplexität
eines Algorithmus mit wachsender Eingabemenge zunimmt. Damit lassen sich
zwei Algorithmen für dasselbe Problem miteinander vergleichen.  

**Operand**
: Der Teil eines Maschinenbefehls, der angibt, womit gearbeitet werden soll —
etwa ein Registername, eine Speicheradresse oder ein direkt angegebener Wert.
 

**Operationscode**
: Der Teil eines Maschinenbefehls, der angibt, *was* getan werden soll — zum
Beispiel addieren, holen oder speichern.  

## P

**Parameter**
: Ein Wert, der beim Aufruf einer Funktion übergeben wird und innerhalb
der Funktion wie eine ganz normale Variable zur Verfügung steht. Über
Parameter lässt sich derselbe Funktionscode mit unterschiedlichen Werten
wiederverwenden, statt ihn für jeden Fall neu zu schreiben.  

**Parametriertes Makro**
: Ein Makro mit Parametern in Klammern, zum Beispiel `QUADRAT(x)`. Der
Präprozessor setzt die beim Aufruf angegebenen Texte an den Stellen der
Parameter ein. Es ist keine Funktion: Es gibt keinen Aufruf und keine
Typprüfung.  

**Peripherie**
: Sammelbegriff für alles, was über die Ein-/Ausgabe an einen Rechner
angeschlossen ist: Tastatur und Maus, Festplatten, Netzwerkkarten.
 

**Pfeil-Operator**
: Der Operator `->`. Er greift auf ein Member einer Struktur zu, auf die ein
Pointer zeigt: `zeiger->wert`. Er ist die Kurzform von `(*zeiger).wert`, also
erst dereferenzieren, dann auf das Member zugreifen.

**Pivot-Element**
: Das Element, das beim Sortieren mit Quicksort als Referenzwert für einen
Partitionierungsschritt ausgewählt wird. Nach dem Partitionieren stehen
links vom Pivot-Element nur kleinere oder gleiche Werte, rechts davon nur
größere — das Pivot-Element selbst steht damit schon an seiner endgültigen
Position. Welches Element als Pivot gewählt wird, beeinflusst nicht, ob am
Ende richtig sortiert wird, aber wie schnell das geht.  

**Pointer (Zeiger)**
: Eine Variable, die nicht selbst einen Wert speichert, sondern die
Adresse einer anderen Variable im Speicher. Über den Adressoperator `&`
entsteht ein Pointer, über die Dereferenzierung `*` gelangt man vom
Pointer zurück zum Wert, auf den er zeigt.  

**Pointer-Arithmetik**
: Das Rechnen mit Pointern, z. B. `zeiger + 1`. Anders als bei einer
gewöhnlichen Zahl bedeutet `+ 1` hier nicht "eine Speicherzelle weiter",
sondern "das nächste Element desselben Datentyps" — bei einem `int *`
also vier Byte weiter, bei einem `unsigned char *` nur ein Byte. Die
vertraute Array-Schreibweise mit eckigen Klammern ist nur eine bequemere
Schreibweise dafür: `a[i]` bedeutet dasselbe wie `*(a + i)`.  

**Präprozessor**
: Das Programm, das den Quelltext vor dem Compiler bearbeitet. Es führt die
Präprozessordirektiven aus: Es fügt Dateien ein, ersetzt Makros und blendet
Textteile ein oder aus. Es führt kein Programm aus und kennt keine Variablen, es
arbeitet nur auf Text.

**Präprozessordirektive**
: Eine Anweisung an den Präprozessor. Sie beginnt mit `#`, zum Beispiel
`#include`, `#define` oder `#ifdef`, und steht allein auf ihrer Zeile.
Sie ist kein C-Code, der beim Programmlauf ausgeführt wird.  

**Programmablaufplan (PAP)**
: Eine grafische Beschreibung eines Algorithmus als Folge von Symbolen, die
durch Pfeile verbunden sind — zum Beispiel Ovale für Start und Ende, Rechtecke
für Verarbeitungsschritte und Parallelogramme für Ein- und Ausgabe.  

**Projekt**
: In einer Entwicklungsumgebung wie Visual Studio die Sammlung aller
Dateien und Einstellungen, aus denen ein einzelnes Programm gebaut wird.  

**Projektmappe (Solution)**
: Ein Container in Visual Studio, der ein oder mehrere Projekte
zusammenfasst. Für die Aufgaben in diesem Kurs reicht eine Projektmappe mit
genau einem Projekt.  

**Prozessor**
: Die Komponente eines Rechners, die ein Programm ausführt und dabei Daten
verarbeitet. Er besteht im Wesentlichen aus Leitwerk, Rechenwerk und Registern.
 

**Pseudocode**
: Eine textuelle Beschreibung eines Algorithmus als nummerierte Schritte mit
festen Schlüsselwörtern, zum Beispiel `INPUT` für eine Eingabe. Näher an einer
Programmiersprache als reiner Fließtext, aber noch nicht an eine bestimmte
Sprache gebunden.  

**Pseudozufallsgenerator**
: Ein Algorithmus, der aus einem Startwert (Seed) eine Zahlenfolge
erzeugt, die zufällig wirkt, bei gleichem Seed aber immer gleich abläuft
— echten Zufall kann ein Computer nicht erzeugen. In C wird der Generator
einmalig mit `srand` initialisiert, danach liefert `rand` bei jedem Aufruf
eine neue Zahl.  

**Punkt-Operator**
: Der Operator `.` zwischen einer Strukturvariable und dem Namen eines Members,
zum Beispiel `p.wert`. Bei verschachtelten Strukturen steht er mehrfach,
zum Beispiel `w.ablage.x`.  

## R

**RAM**
: Abkürzung für *Random Access Memory*, zu Deutsch Speicher mit wahlfreiem
Zugriff. Gemeint ist, dass auf jede Speicherzelle gleich schnell zugegriffen
werden kann, egal welche Adresse sie hat. Übliche Bezeichnung für den
Hauptspeicher.  

**Rechenwerk**
: Die Funktionsgruppe im Prozessor, die rechnet: arithmetische Operationen wie
Addition und Multiplikation sowie logische Verknüpfungen.
 

**Rekursion**
: Wenn eine Funktion sich selbst aufruft — meist mit einem Argument, das
der Abbruchbedingung jedes Mal ein Stück näher kommt. Jeder Aufruf wartet
dabei, bis der von ihm gestartete Aufruf vollständig zurückgekehrt ist,
bevor er selbst fertig rechnet (Aufrufstapel).  

**Register**
: Eine sehr kleine, sehr schnelle Speicherstelle direkt im Prozessor. Register
nehmen die Werte auf, mit denen gerade gerechnet wird, sowie Zwischenergebnisse.
Der Zugriff darauf ist deutlich schneller als auf den Hauptspeicher.
 

**Rückgabewert**
: Ein Wert, den eine Funktion an die Stelle zurückliefert, von der aus sie
aufgerufen wurde — zum Beispiel ein Ergebnis oder eine Ja/Nein-Antwort. Der
Rückgabetyp einer Funktion (z. B. `int`) legt fest, von welchem Datentyp
dieser Wert ist. Eine Funktion ohne Rückgabewert hat den Rückgabetyp
`void`.  

**Rücksprung**
: Ein Pfeil in einem Programmablaufplan, der zu einem bereits durchlaufenen
Schritt zurückführt, statt weiter nach unten. Grundlage dafür, wie
Wiederholungen im PAP ohne eigenes Schleifensymbol dargestellt werden.  

## S

**Schreibtischtest**
: Das gedankliche Durchrechnen eines Algorithmus für eine konkrete Eingabe,
Schritt für Schritt, ohne ihn tatsächlich auszuführen — etwa um
nachzuvollziehen, welchen Weg ein gegebener PAP nimmt und was er ausgibt.  

**Sichtbarkeit**
: Legt fest, in welchem Teil eines Programms auf eine Variable zugegriffen
werden kann. Eine global deklarierte Variable ist im ganzen Programm
sichtbar, eine lokale Variable nur innerhalb der Funktion oder des
Compound Statement, in dem sie deklariert wurde. Tragen zwei Variablen
unterschiedlicher Sichtbarkeitsebenen denselben Namen, verdeckt die
innere die äußere (siehe Verdecken).  

**sizeof-Operator**
: Ein Operator, der die Größe eines Datentyps oder einer Variable in Byte
liefert, z. B. `sizeof(int)`. Nützlich, um nachzuvollziehen, wie viel
Speicherplatz ein Datentyp tatsächlich braucht, ohne es nachschlagen zu
müssen.  

**Sortieralgorithmus**
: Ein Algorithmus, der die Elemente einer Reihe, zum Beispiel eines Arrays,
in eine bestimmte Reihenfolge bringt — etwa aufsteigend nach Größe.  

**Speicheradressregister (SAR)**
: Das Register, das die Adresse derjenigen Speicherzelle enthält, auf die der
Prozessor gerade zugreift.  

**Speicherdatenregister (SDR)**
: Das Register, über das Werte zwischen Prozessor und Hauptspeicher ausgetauscht
werden — es nimmt den gelesenen Wert auf oder hält den Wert, der geschrieben
werden soll.  

**Speicherklasse**
: Legt fest, wie lange eine Variable existiert. In C gibt es dafür die
Schlüsselwörter `auto`, `extern`, `static` und `register` — am wichtigsten
in diesem Kurs ist `static`: Eine als `static` deklarierte lokale
Variable behält ihren Wert über mehrere Funktionsaufrufe hinweg, statt bei
jedem Aufruf neu angelegt zu werden.  

**Speicherzelle**
: Die kleinste über eine Adresse ansprechbare Einheit des Hauptspeichers. Alle
Speicherzellen sind gleich aufgebaut; was ihr Inhalt bedeutet, ergibt sich erst
daraus, wie er verwendet wird.  

**Sprungbefehl**
: Ein Befehl, der die normale Reihenfolge unterbricht und die Ausführung an einer
anderen Stelle des Programms fortsetzt. Er tut das, indem er eine neue Adresse in
den Befehlszeiger schreibt. Grundlage für Verzweigungen und Schleifen.
 

**Stapelüberlauf**
: Ein Programmabsturz, der entsteht, wenn sich eine rekursive Funktion zu
oft (im Extremfall unendlich oft) selbst aufruft, weil ihre
Abbruchbedingung nie erreicht wird. Jeder wartende Aufruf belegt Platz auf
dem Aufrufstapel — irgendwann ist dieser Platz erschöpft.  

**Stetigkeit**
: Eine Eigenschaft einer Funktion: Ihr Graph hat keine Sprünge oder Lücken
— er lässt sich also in einem Zug durchzeichnen, ohne den Stift abzusetzen.
Nötig, damit sich an einer Stelle sinnvoll von einer Ableitung sprechen
lässt.  

**String**
: Eine Zeichenkette, also ein Text. In C ist ein String ein `char`-Array,
dessen letztes Element das Stringende-Zeichen ist. Strings entstehen zum
Beispiel durch Text in Anführungszeichen wie `"Hallo"`.  

**Stringende-Zeichen**
: Das unsichtbare Zeichen `'\0'` (Zeichencode 0) am Ende eines Strings. Es
markiert, wo der Text aufhört, und wird deshalb von Funktionen wie `printf`
und `strlen` erwartet — man spricht von einem nullterminierten String. Fehlt
es, laufen diese Funktionen über das Ende des Arrays hinaus.  

**Struktur (struct)**
: Ein selbst definierter Datentyp, der mehrere Variablen, die Member,
unterschiedlicher Datentypen unter einem Namen zusammenfasst, zum Beispiel
Nummer und Messwert eines Messpunkts. Eine Struktur darf andere Strukturen
enthalten, aber nicht sich selbst. Ein Pointer auf die eigene Struktur ist
dagegen erlaubt.  

## T

**typedef**
: Ein Schlüsselwort in C, mit dem ein vorhandener Datentyp einen zusätzlichen,
oft kürzeren Namen bekommt. Bei einer Aufzählung erlaubt es, statt
`enum Zustand` nur noch `Zustand` zu schreiben.  

**Typumwandlung (Cast)**
: Das ausdrückliche Umdeuten eines Werts oder eines Pointers in einen
anderen Datentyp, geschrieben als Datentyp in runden Klammern direkt vor
dem Wert, z. B. `(unsigned char *) zeiger`. Nötig, wenn der Compiler den
gewünschten Typ nicht von selbst kennt — etwa bei einem void-Pointer, der
vor der Dereferenzierung erst wieder einen konkreten Typ bekommen muss.  

## U

**unsigned**
: Ein Modifizierer vor einem Ganzzahl-Datentyp (z. B. `unsigned char`,
`unsigned int`), der festlegt, dass die Variable **keine negativen Werte**
speichern kann. Der dadurch frei werdende Speicherplatz wird stattdessen
für einen größeren positiven Wertebereich genutzt — ein `unsigned char`
reicht z. B. von `0` bis `255` statt wie ein normaler (signed) `char` von
`-128` bis `127`. Ohne diesen Modifizierer sind Ganzzahl-Datentypen in C
standardmäßig **signed** (vorzeichenbehaftet).  

## Ü

**Überlauf**
: Wenn eine Berechnung einen Wert ergeben würde, der außerhalb des
Wertebereichs seines Datentyps liegt, "springt" der Wert stattdessen an
das andere Ende dieses Wertebereichs — zum Beispiel wird aus `255` bei
einem `unsigned char` wieder `0`. Ursache ist die feste Anzahl an Bits,
mit der der Datentyp im Speicher dargestellt wird.  

## V

**Variable**
: Ein benannter Speicherplatz für einen Wert. Beim Anlegen (Deklaration)
muss festgelegt werden, von welchem Datentyp die Variable ist — das
bestimmt, welche Werte sie speichern kann und wie viel Speicherplatz sie
braucht.  

**Verdecken (Shadowing)**
: Wenn eine Variable in einem inneren Gültigkeitsbereich (z. B. innerhalb
einer Funktion oder eines Compound Statement) denselben Namen trägt wie
eine Variable in einem äußeren Bereich, ist innerhalb des inneren
Bereichs nur noch die innere Variable ansprechbar — sie verdeckt die
äußere, ohne sie zu verändern.  

**Verschachtelte Schleife**
: Eine Schleife, die vollständig im Rumpf einer anderen Schleife steht. Bei
jedem Durchlauf der äußeren Schleife läuft die innere komplett durch —
praktisch, um zweidimensionale Muster wie Tabellen oder Figuren aus
Zeichen zu erzeugen.  

**Verzweigung**
: Eine Raute in einem Programmablaufplan, bei der der Ablauf abhängig von
einer Bedingung einen von zwei Wegen nimmt — dargestellt mit den
beschrifteten Pfeilen "ja" und "nein". Entspricht im Pseudocode den
Schlüsselwörtern `IF` und `ELSE`.  

**void-Pointer**
: Ein Pointer vom Typ `void *`, der auf eine Adresse zeigt, ohne
festzulegen, welcher Datentyp dort liegt. Nützlich für Funktionen, die mit
beliebigen Datentypen arbeiten sollen (z. B. eine allgemeine
Kopierfunktion) — vor der Dereferenzierung muss er aber immer erst per
Typumwandlung in einen konkreten Pointertyp umgewandelt werden.  

**von-Neumann-Architektur**
: Das Bauprinzip, nach dem heutige Rechner aufgebaut sind: Prozessor, Speicher
und Ein-/Ausgabe, verbunden über Kommunikationswege. Entscheidend ist, dass
Programm **und** Daten gemeinsam im Speicher liegen — nur deshalb kann der
Rechner ein Programm selbstständig abarbeiten.  

## W

**Wiederholung**
: Ein Ablaufteil, der so lange erneut ausgeführt wird, wie eine Bedingung
erfüllt ist. Im PAP dargestellt über dieselbe Raute wie bei einer
Verzweigung, kombiniert mit einem Rücksprung — unterschieden wird zwischen
kopf- und fußgesteuerter Wiederholung. Im Pseudocode: `WHILE`/`DO`/`END
WHILE` für die kopfgesteuerte, `DO`/`WHILE` für die fußgesteuerte
Variante.  

**Wortbreite**
: Die Anzahl der Bit, die ein Prozessor in einem Rechenschritt auf einmal
verarbeitet — bei den meisten heutigen PCs 32 oder 64 Bit, bei kleinen
Mikrocontrollern oft weniger.  

## Z

**Zählschleife**
: Eine kopfgesteuerte Wiederholung mit einer besonders regelmäßigen
Struktur: eine Zählvariable bekommt einen Startwert, wird bei jedem
Durchlauf mit einer Grenze verglichen und am Ende um eine feste
Schrittweite verändert. Im Pseudocode dafür das eigene Schlüsselwort
`FOR`, das Startwert, Grenze und Schrittweite in einer Kopfzeile
zusammenfasst.  

**Zeitkomplexität**
: Ein Maß dafür, wie stark die Anzahl der nötigen Rechenschritte eines
Algorithmus mit der Größe der Eingabe wächst. Ausgedrückt wird das mit der
O-Notation.  

**Ziffernvorrat**
: Die Menge der Symbole, die in einem Stellenwertsystem als Ziffern verwendet
werden dürfen. Im Dezimalsystem sind das die zehn Ziffern 0 bis 9, im
Dualsystem nur 0 und 1.  

**Zustandsautomat**
: Ein Programm oder Gerät, das sich zu jedem Zeitpunkt in genau einem von
endlich vielen Zuständen befindet und je nach Lage (etwa einer Störung) in
einen anderen Zustand wechselt. Typisch in der Automatisierung, zum Beispiel
bei einer Ampel oder der Schrittkette einer Anlage.  

**Zustandsdiagramm**
: Eine Zeichnung, die einen Zustandsautomaten darstellt: Jedes Kästchen ist ein
Zustand, jeder Pfeil ein Übergang, und die Beschriftung am Pfeil nennt das
Ereignis, das den Übergang auslöst. Ein Punkt mit Pfeil markiert den
Startzustand.  

**Zuweisung**
: Das nachträgliche Verändern des Werts einer bereits deklarierten
Variable mit `=` — zum Beispiel `anzahl = 5;`. Anders als bei der
Initialisierung existiert die Variable dabei schon.  

**Zweierkomplement**
: Die Art, wie negative ganze Zahlen im Rechner dargestellt werden. Man
bildet sie, indem man die Bits der positiven Zahl invertiert und
anschließend 1 addiert. Der Vorteil: Eine Subtraktion lässt sich damit als
gewöhnliche Addition durchführen.  
