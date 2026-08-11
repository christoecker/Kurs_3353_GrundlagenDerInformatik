# Glossar

Kurze Erklärungen zu den Fachbegriffen, die im Kurs vorkommen — in einfachen
Worten, nicht als formale Definition. Die Angabe in Klammern sagt, in welcher
Einheit dir der Begriff zuerst begegnet.

Das Glossar wächst mit dem Kurs. Wenn euch ein Begriff fehlt: kurz Bescheid
sagen, dann kommt er dazu.

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

Abstraktion
: Das Weglassen von allem, was für einen bestimmten Zweck unwichtig ist, damit
das Wesentliche übrig bleibt. Was wesentlich ist, hängt immer vom Zweck ab: Für
die Statik eines Hauses ist die Wandfarbe unwichtig, für den Malerbetrieb nicht.
*(Praxisphase Woche 1)*

Adresse
: Die Nummer, über die eine einzelne Speicherzelle im Hauptspeicher angesprochen
wird — vergleichbar mit der Nummer eines Schließfachs. *(Praxisphase Woche 1)*

Algorithmus
: Eine eindeutige Handlungsvorschrift, die aus Eingabewerten in endlich vielen
Schritten ein Ergebnis erzeugt. Ausführlich in Woche 3. *(Praxisphase Woche 1)*

Assemblersprache
: Eine Programmiersprache, die den Befehlen eines bestimmten Prozessors sehr nahe
kommt, statt der Bitmuster aber lesbare Namen verwendet. Sie liegt im
Ebenenmodell zwischen der Maschinensprache und Sprachen wie C.
*(Praxisphase Woche 1)*

Befehlsausführungszyklus
: Die drei Schritte, die ein Prozessor immer wieder durchläuft, bis ein
Halte-Befehl kommt: den nächsten Befehl aus dem Hauptspeicher holen, den
Befehlszeiger erhöhen, den geholten Befehl ausführen. *(Praxisphase Woche 1)*

Befehlsregister (BR)
: Das Register, in dem der Befehl steht, den der Prozessor gerade ausführt. Es
enthält den Operationscode und die Operanden. *(Praxisphase Woche 1)*

Befehlssatz
: Die vollständige Menge aller Befehle, die ein bestimmter Prozessor ausführen
kann. Jede Prozessorfamilie hat ihren eigenen. *(Praxisphase Woche 1)*

Befehlszeiger (BZ)
: Das Register, das die Adresse des Befehls enthält, der als nächstes ausgeführt
wird. Nach jedem geholten Befehl wird es um eins erhöht — außer ein Sprungbefehl
schreibt eine andere Adresse hinein. *(Praxisphase Woche 1)*

Bus
: Ein gemeinsamer Verbindungsweg, an den alle Komponenten eines Rechners
angeschlossen sind. Spart Verkabelung und macht Erweiterungen einfach, dafür kann
immer nur ein Paar zur Zeit darüber kommunizieren. *(Praxisphase Woche 1)*

Compiler
: Ein Programm, das Quelltext einer Programmiersprache wie C in Maschinensprache
übersetzt, damit der Prozessor ihn ausführen kann. *(Praxisphase Woche 1)*

Hauptspeicher
: Der Speicher, in dem ein laufendes Programm samt seinen Daten liegt. Er besteht
aus vielen gleich aufgebauten Speicherzellen, ist schnell, verliert seinen Inhalt
aber beim Ausschalten. Auch Arbeitsspeicher oder RAM genannt.
*(Praxisphase Woche 1)*

Informatik
: Die Wissenschaft von der systematischen — vor allem der automatischen —
Verarbeitung und Übermittlung von Information mithilfe von Rechnern.
*(Praxisphase Woche 1)*

Information
: Ein abstraktes Abbild von etwas Realem, das nur die für einen bestimmten Zweck
wichtigen Eigenschaften enthält. Ein Bauplan ist Information über ein Haus: Er
ist nicht das Haus, aber er genügt, um es zu bauen. *(Praxisphase Woche 1)*

Leitwerk
: Die Funktionsgruppe im Prozessor, die den Ablauf des Programms steuert: Sie
sorgt dafür, dass Befehle geholt und in der richtigen Reihenfolge ausgeführt
werden. *(Praxisphase Woche 1)*

Maschinenbefehl
: Ein einzelner Befehl, den ein Prozessor unmittelbar ausführen kann. Er besteht
aus einem Operationscode und den Operanden. *(Praxisphase Woche 1)*

Maschinensprache
: Die Sprache, die ein Prozessor unmittelbar versteht. Ihre "Wörter" sind die
Befehle aus seinem Befehlssatz. Sie ist von Prozessor zu Prozessor
unterschiedlich. *(Praxisphase Woche 1)*

Operand
: Der Teil eines Maschinenbefehls, der angibt, womit gearbeitet werden soll —
etwa ein Registername, eine Speicheradresse oder ein direkt angegebener Wert.
*(Praxisphase Woche 1)*

Operationscode
: Der Teil eines Maschinenbefehls, der angibt, *was* getan werden soll — zum
Beispiel addieren, holen oder speichern. *(Praxisphase Woche 1)*

Peripherie
: Sammelbegriff für alles, was über die Ein-/Ausgabe an einen Rechner
angeschlossen ist: Tastatur und Maus, Festplatten, Netzwerkkarten.
*(Praxisphase Woche 1)*

Prozessor
: Die Komponente eines Rechners, die ein Programm ausführt und dabei Daten
verarbeitet. Er besteht im Wesentlichen aus Leitwerk, Rechenwerk und Registern.
*(Praxisphase Woche 1)*

RAM
: Abkürzung für *Random Access Memory*, zu Deutsch Speicher mit wahlfreiem
Zugriff. Gemeint ist, dass auf jede Speicherzelle gleich schnell zugegriffen
werden kann, egal welche Adresse sie hat. Übliche Bezeichnung für den
Hauptspeicher. *(Praxisphase Woche 1)*

Rechenwerk
: Die Funktionsgruppe im Prozessor, die rechnet: arithmetische Operationen wie
Addition und Multiplikation sowie logische Verknüpfungen.
*(Praxisphase Woche 1)*

Register
: Eine sehr kleine, sehr schnelle Speicherstelle direkt im Prozessor. Register
nehmen die Werte auf, mit denen gerade gerechnet wird, sowie Zwischenergebnisse.
Der Zugriff darauf ist deutlich schneller als auf den Hauptspeicher.
*(Praxisphase Woche 1)*

Speicheradressregister (SAR)
: Das Register, das die Adresse derjenigen Speicherzelle enthält, auf die der
Prozessor gerade zugreift. *(Praxisphase Woche 1)*

Speicherdatenregister (SDR)
: Das Register, über das Werte zwischen Prozessor und Hauptspeicher ausgetauscht
werden — es nimmt den gelesenen Wert auf oder hält den Wert, der geschrieben
werden soll. *(Praxisphase Woche 1)*

Speicherzelle
: Die kleinste über eine Adresse ansprechbare Einheit des Hauptspeichers. Alle
Speicherzellen sind gleich aufgebaut; was ihr Inhalt bedeutet, ergibt sich erst
daraus, wie er verwendet wird. *(Praxisphase Woche 1)*

Sprungbefehl
: Ein Befehl, der die normale Reihenfolge unterbricht und die Ausführung an einer
anderen Stelle des Programms fortsetzt. Er tut das, indem er eine neue Adresse in
den Befehlszeiger schreibt. Grundlage für Verzweigungen und Schleifen.
*(Praxisphase Woche 1)*

von-Neumann-Architektur
: Das Bauprinzip, nach dem heutige Rechner aufgebaut sind: Prozessor, Speicher
und Ein-/Ausgabe, verbunden über Kommunikationswege. Entscheidend ist, dass
Programm **und** Daten gemeinsam im Speicher liegen — nur deshalb kann der
Rechner ein Programm selbstständig abarbeiten. *(Praxisphase Woche 1)*
