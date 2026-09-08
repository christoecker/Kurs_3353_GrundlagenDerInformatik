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

**Abstraktion**
: Das Weglassen von allem, was für einen bestimmten Zweck unwichtig ist, damit
das Wesentliche übrig bleibt. Was wesentlich ist, hängt immer vom Zweck ab: Für
die Statik eines Hauses ist die Wandfarbe unwichtig, für den Malerbetrieb nicht.
 

**Adresse**
: Die Nummer, über die eine einzelne Speicherzelle im Hauptspeicher angesprochen
wird — vergleichbar mit der Nummer eines Schließfachs.  

**Algorithmus**
: Eine eindeutige Handlungsvorschrift, die aus gegebenen Ausgangswerten in
endlich vielen Schritten ein Ergebnis erzeugt. Ein Algorithmus muss dabei drei
Eigenschaften erfüllen: Eindeutigkeit, Endlichkeit und Determiniertheit.  

**ASCII-Code**
: Eine weit verbreitete Zeichencodierung, die jedem Zeichen (Buchstabe, Ziffer,
Satzzeichen) eine Zahl zwischen 0 und 127 zuordnet. Diese Zahl wird dann wie
jede andere Zahl binär im Rechner gespeichert.  

**Assemblersprache**
: Eine Programmiersprache, die den Befehlen eines bestimmten Prozessors sehr nahe
kommt, statt der Bitmuster aber lesbare Namen verwendet. Sie liegt im
Ebenenmodell zwischen der Maschinensprache und Sprachen wie C.
 

## B

**Basis**
: Die Grundzahl eines Stellenwertsystems. Sie gibt an, wie viele
verschiedene Ziffern zur Verfügung stehen und wie stark der Wert einer Ziffer
von Stelle zu Stelle wächst. Das Dezimalsystem hat die Basis 10, das
Dualsystem die Basis 2.  

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

**Bit**
: Die kleinste Informationseinheit, die ein Rechner kennt: eine einzelne
Dualstelle mit dem Wert 0 oder 1.  

**Bus**
: Ein gemeinsamer Verbindungsweg, an den alle Komponenten eines Rechners
angeschlossen sind. Spart Verkabelung und macht Erweiterungen einfach, dafür kann
immer nur ein Paar zur Zeit darüber kommunizieren.  

**Byte**
: Eine Gruppe von 8 Bit. Ein Byte kann `2⁸ = 256` verschiedene Werte
annehmen (0 bis 255) und ist die gebräuchlichste Einheit, um die Größe von
Speicher anzugeben.  

## C

**Compiler**
: Ein Programm, das Quelltext einer Programmiersprache wie C in Maschinensprache
übersetzt, damit der Prozessor ihn ausführen kann.  

## D

**Determiniertheit**
: Eine Eigenschaft von Algorithmen: Bei denselben Ausgangswerten liefert der
Algorithmus immer dasselbe Ergebnis.  

**Dualsystem**
: Ein Stellenwertsystem mit der Basis 2 und dem Ziffernvorrat 0 und 1. Auch
Binärsystem genannt. Alle Daten in einem Rechner liegen letztlich in dieser
Form vor.  

## E

**Eindeutigkeit**
: Eine Eigenschaft von Algorithmen: Jeder Schritt ist so klar formuliert, dass
es keinen Interpretationsspielraum gibt.  

**Endlichkeit**
: Eine Eigenschaft von Algorithmen: Die Beschreibung besteht aus endlich
vielen Schritten, und ihre Ausführung kommt nach endlich vielen Schritten
tatsächlich zu einem Ende.  

## F

**Fußgesteuerte Wiederholung**
: Eine Wiederholung, bei der die Bedingung erst nach den
Schleifenanweisungen geprüft wird. Dadurch laufen die Anweisungen immer
mindestens einmal, bevor überhaupt geprüft wird.  

## H

**Hauptspeicher**
: Der Speicher, in dem ein laufendes Programm samt seinen Daten liegt. Er besteht
aus vielen gleich aufgebauten Speicherzellen, ist schnell, verliert seinen Inhalt
aber beim Ausschalten. Auch Arbeitsspeicher oder RAM genannt.
 

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

**Informatik**
: Die Wissenschaft von der systematischen — vor allem der automatischen —
Verarbeitung und Übermittlung von Information mithilfe von Rechnern.
 

**Information**
: Ein abstraktes Abbild von etwas Realem, das nur die für einen bestimmten Zweck
wichtigen Eigenschaften enthält. Ein Bauplan ist Information über ein Haus: Er
ist nicht das Haus, aber er genügt, um es zu bauen.  

## K

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

**Maschinenbefehl**
: Ein einzelner Befehl, den ein Prozessor unmittelbar ausführen kann. Er besteht
aus einem Operationscode und den Operanden.  

**Maschinensprache**
: Die Sprache, die ein Prozessor unmittelbar versteht. Ihre "Wörter" sind die
Befehle aus seinem Befehlssatz. Sie ist von Prozessor zu Prozessor
unterschiedlich.  

**MSB**
: Abkürzung für *Most Significant Bit*, zu Deutsch das höchstwertige Bit
einer Dualzahl. Bei der Zweierkomplement-Darstellung zeigt es das Vorzeichen
an: 0 für positiv (oder null), 1 für negativ.  

## O

**Oktalsystem**
: Ein Stellenwertsystem mit der Basis 8 und dem Ziffernvorrat 0 bis 7. Drei
Binärstellen entsprechen genau einer Oktalziffer.  

**Operand**
: Der Teil eines Maschinenbefehls, der angibt, womit gearbeitet werden soll —
etwa ein Registername, eine Speicheradresse oder ein direkt angegebener Wert.
 

**Operationscode**
: Der Teil eines Maschinenbefehls, der angibt, *was* getan werden soll — zum
Beispiel addieren, holen oder speichern.  

## P

**Peripherie**
: Sammelbegriff für alles, was über die Ein-/Ausgabe an einen Rechner
angeschlossen ist: Tastatur und Maus, Festplatten, Netzwerkkarten.
 

**Programmablaufplan (PAP)**
: Eine grafische Beschreibung eines Algorithmus als Folge von Symbolen, die
durch Pfeile verbunden sind — zum Beispiel Ovale für Start und Ende, Rechtecke
für Verarbeitungsschritte und Parallelogramme für Ein- und Ausgabe.  

**Prozessor**
: Die Komponente eines Rechners, die ein Programm ausführt und dabei Daten
verarbeitet. Er besteht im Wesentlichen aus Leitwerk, Rechenwerk und Registern.
 

**Pseudocode**
: Eine textuelle Beschreibung eines Algorithmus als nummerierte Schritte mit
festen Schlüsselwörtern, zum Beispiel `INPUT` für eine Eingabe. Näher an einer
Programmiersprache als reiner Fließtext, aber noch nicht an eine bestimmte
Sprache gebunden.  

## R

**RAM**
: Abkürzung für *Random Access Memory*, zu Deutsch Speicher mit wahlfreiem
Zugriff. Gemeint ist, dass auf jede Speicherzelle gleich schnell zugegriffen
werden kann, egal welche Adresse sie hat. Übliche Bezeichnung für den
Hauptspeicher.  

**Rechenwerk**
: Die Funktionsgruppe im Prozessor, die rechnet: arithmetische Operationen wie
Addition und Multiplikation sowie logische Verknüpfungen.
 

**Register**
: Eine sehr kleine, sehr schnelle Speicherstelle direkt im Prozessor. Register
nehmen die Werte auf, mit denen gerade gerechnet wird, sowie Zwischenergebnisse.
Der Zugriff darauf ist deutlich schneller als auf den Hauptspeicher.
 

**Rücksprung**
: Ein Pfeil in einem Programmablaufplan, der zu einem bereits durchlaufenen
Schritt zurückführt, statt weiter nach unten. Grundlage dafür, wie
Wiederholungen im PAP ohne eigenes Schleifensymbol dargestellt werden.  

## S

**Schreibtischtest**
: Das gedankliche Durchrechnen eines Algorithmus für eine konkrete Eingabe,
Schritt für Schritt, ohne ihn tatsächlich auszuführen — etwa um
nachzuvollziehen, welchen Weg ein gegebener PAP nimmt und was er ausgibt.  

**Speicheradressregister (SAR)**
: Das Register, das die Adresse derjenigen Speicherzelle enthält, auf die der
Prozessor gerade zugreift.  

**Speicherdatenregister (SDR)**
: Das Register, über das Werte zwischen Prozessor und Hauptspeicher ausgetauscht
werden — es nimmt den gelesenen Wert auf oder hält den Wert, der geschrieben
werden soll.  

**Speicherzelle**
: Die kleinste über eine Adresse ansprechbare Einheit des Hauptspeichers. Alle
Speicherzellen sind gleich aufgebaut; was ihr Inhalt bedeutet, ergibt sich erst
daraus, wie er verwendet wird.  

**Sprungbefehl**
: Ein Befehl, der die normale Reihenfolge unterbricht und die Ausführung an einer
anderen Stelle des Programms fortsetzt. Er tut das, indem er eine neue Adresse in
den Befehlszeiger schreibt. Grundlage für Verzweigungen und Schleifen.
 

## V

**Verzweigung**
: Eine Raute in einem Programmablaufplan, bei der der Ablauf abhängig von
einer Bedingung einen von zwei Wegen nimmt — dargestellt mit den
beschrifteten Pfeilen "ja" und "nein". Entspricht im Pseudocode den
Schlüsselwörtern `IF` und `ELSE`.  

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

**Ziffernvorrat**
: Die Menge der Symbole, die in einem Stellenwertsystem als Ziffern verwendet
werden dürfen. Im Dezimalsystem sind das die zehn Ziffern 0 bis 9, im
Dualsystem nur 0 und 1.  

**Zweierkomplement**
: Die Art, wie negative ganze Zahlen im Rechner dargestellt werden. Man
bildet sie, indem man die Bits der positiven Zahl invertiert und
anschließend 1 addiert. Der Vorteil: Eine Subtraktion lässt sich damit als
gewöhnliche Addition durchführen.  
