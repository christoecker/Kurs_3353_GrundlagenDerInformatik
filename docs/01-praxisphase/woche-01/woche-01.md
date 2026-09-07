---
typ: praxisphase-woche
woche: 1
thema: "Was ist Informatik? Und wie ist ein Rechner aufgebaut?"
workload_minuten: 110
lernziele:
  - "Du kannst in eigenen Worten sagen, womit sich die Informatik beschäftigt, und die vier Teilbereiche voneinander abgrenzen."
  - "Du kannst erklären, was mit Abstraktion gemeint ist, und ein eigenes Beispiel dafür angeben."
  - "Du kannst die drei Komponenten der von-Neumann-Architektur benennen und die Aufgabe jeder Komponente beschreiben."
  - "Du kannst begründen, warum ein von-Neumann-Rechner ein Programm selbstständig abarbeiten kann."
  - "Du kannst Einzelverbindungs- und Busarchitektur gegenüberstellen und je einen Vor- und einen Nachteil nennen."
  - "Du kannst beschreiben, wie der Hauptspeicher organisiert ist und worin er sich von einer Festplatte unterscheidet."
  - "Du kannst die Funktionsgruppen eines Prozessors benennen und den Befehlsausführungszyklus Schritt für Schritt beschreiben."
  - "Du kannst einordnen, in welchem Verhältnis Maschinensprache, Assemblersprache und eine Sprache wie C zueinander stehen."
quellen:
  - "Müller, Heinrich; Weichert, Frank: Vorkurs Informatik. Der Einstieg ins Informatikstudium. 6. Auflage, Springer Vieweg, Wiesbaden 2023 — Kapitel 1 (S. 7–11), Kapitel 18 (S. 367–368), Kapitel 19 (S. 369–376)."
ki_einsatz: stufe_1_nachschlagewerk
bearbeitungsstatus: fertig
publish_date: 2026-08-11
hinweis: publish_date von dieser Einheit bewusst vorgezogen, damit die Seite als Beispiel bei der Erstsemesterbegrüßung sichtbar ist. Alle weiteren Einheiten sollen gem. Zeitlan veröffentlicht werden
---

# Woche 1: Was ist Informatik? Und wie ist ein Rechner aufgebaut?

> Zeitbedarf: ca. 2 Stunden.

## Worum geht es?

In diesem Modul wirst du eigene Programme in der Programmiersprache C schreiben. Bevor das losgeht, lohnt sich ein
Blick auf zwei Fragen, die dahinterstehen: Womit beschäftigt sich die Informatik
eigentlich — und was passiert in einem Rechner, wenn ein Programm läuft?

Die zweite Frage ist keine Nebensächlichkeit. Wer nur weiß, dass ein Programm
"irgendwie ausgeführt wird", steht später bei jedem Fehler im Dunkeln. Wer
dagegen weiß, dass ein Prozessor stur einen einzigen Befehl nach dem anderen aus
dem Speicher holt und ausführt, versteht plötzlich, warum ein Programm genau in
der Reihenfolge abläuft, in der es dasteht — und warum ein einziger falscher
Sprung alles durcheinanderbringt.

Für die Mechatronik ist das besonders greifbar: Eine speicherprogrammierbare
Steuerung, ein Mikrocontroller in einem Sensor, ein Antriebsregler — das sind
alles Rechner nach genau dem Prinzip, das du diese Woche kennenlernst.

## Das solltest du danach können

- Du kannst in eigenen Worten sagen, womit sich die Informatik beschäftigt, und
  die vier Teilbereiche voneinander abgrenzen.
- Du kannst erklären, was mit *Abstraktion* gemeint ist, und ein eigenes Beispiel
  dafür angeben.
- Du kannst die drei Komponenten der von-Neumann-Architektur benennen und sagen,
  wofür jede zuständig ist.
- Du kannst begründen, warum ein solcher Rechner ein Programm selbstständig
  abarbeiten kann.
- Du kannst Einzelverbindungs- und Busarchitektur gegenüberstellen und je einen
  Vor- und einen Nachteil nennen.
- Du kannst beschreiben, wie der Hauptspeicher organisiert ist und worin er sich
  von einer Festplatte unterscheidet.
- Du kannst die Funktionsgruppen eines Prozessors benennen und den
  Befehlsausführungszyklus Schritt für Schritt beschreiben.
- Du kannst einordnen, wie Maschinensprache, Assemblersprache und eine Sprache
  wie C zusammenhängen.

## Erarbeitung { .abschnitt-erarbeitung }

!!! info "Das brauchst du dafür"
    Grundlage dieser Woche ist das Buch **Müller/Weichert: *Vorkurs Informatik.
    Der Einstieg ins Informatikstudium*, 6. Auflage, Springer Vieweg 2023**. Du
    findest es als PDF in ILIAS im Kursbereich zu diesem Modul.

    Alle Seitenzahlen unten beziehen sich auf die Seitenzählung des Buches (die
    Zahl, die im Buch selbst auf der Seite steht) — nicht auf die Seitenzahl,
    die dein PDF-Programm anzeigt. Die beiden können um einige Seiten
    auseinanderliegen.

**Schritt 1:** Lies **Kapitel 1 „Informatik" (S. 7–11)**.

Das Kapitel beantwortet die Frage, womit sich das Fach überhaupt beschäftigt.
Zwei Dinge sind hier wichtiger als der Rest:

- Der Begriff **Information** wird als *Modell* verstanden — als abstraktes
  Abbild von etwas Realem. Das Buch benutzt dafür das Beispiel eines Hauses und
  seines Bauplans. Halte kurz inne und überlege, was dieses Beispiel sagt: Der
  Bauplan *ist* nicht das Haus, aber er enthält genau die Angaben, die man für
  einen bestimmten Zweck braucht.
- **Abstraktion** heißt, das Wesentliche vom Unwesentlichen zu trennen — wobei
  „wesentlich" immer davon abhängt, wofür man das Modell braucht. Für die Statik
  eines Hauses ist die Farbe des Verputzes unwesentlich, für den Malerbetrieb
  nicht.

---

**Schritt 2:** Sieh dir in Abschnitt 1.2 vor allem **Abbildung 1.2** an (S. 10).

Abbildung 1.1 auf S. 9 ist sehr detailliert — überflieg sie nur, du musst dir
diese Aufzählung nicht merken. Abbildung 1.2 dagegen zeigt die vier großen
Teilbereiche kompakt, und die solltest du auseinanderhalten können.

Ordne dabei gleich ein, wo du dich in diesem Modul bewegst: Der Rest dieser
Woche gehört zur **technischen Informatik**. Alles, was danach kommt —
Algorithmen, Programmieren in C — gehört zur **praktischen Informatik**.

!!! info "Warum es gleich mit Kapitel 18 weitergeht"
    Die Kapitel 2 bis 17 behandeln Algorithmen und Programmierung. Damit
    beschäftigen wir uns ab Woche 3 und dann im ganzen restlichen Modul — nur
    eben nicht mit diesem Buch, sondern mit eigenem Material und in der Sprache
    C. Für diese Woche springst du deshalb direkt zu Teil 5 des Buchs, „Vom
    Programm zum Rechner".

---

**Schritt 3:** Lies **Kapitel 18 „Hardware und Programmierung" (S. 367–368)**.

Das Kapitel ist nur zwei Seiten lang, aber es liefert das Gerüst für alles
Weitere. Der Kern ist **Abbildung 18.1**: sechs Ebenen, von den Transistoren
ganz unten bis zur Programmiersprache ganz oben. Präge dir ein, welche drei
Ebenen zur Hardware gehören und welche drei zur Programmierung.

Die Grundidee dahinter ist die aus Kapitel 1: Jede Ebene ist eine Abstraktion.
Je weiter oben du bist, desto näher bist du daran, wie ein Mensch ein Problem
beschreiben würde. Je weiter unten, desto näher an dem, was die Elektronik
tatsächlich tut.

!!! info "Bezug zu unserem Modul"
    Das Buch nennt Java als Beispiel für eine problemorientierte
    Programmiersprache. **C**, die Sprache dieses Moduls, steht auf derselben
    Ebene. Auch ein C-Programm muss also erst in Maschinensprache übersetzt
    werden, bevor ein Prozessor damit etwas anfangen kann. Dieses Übersetzen
    erledigt ein *Compiler* — den lernst du in Woche 6 in der Praxis kennen.

---

**Schritt 4:** Lies **Abschnitt 19.1 „Rechnerarchitektur" (S. 369–371)**.

Hier kommt der wichtigste Begriff der Woche: die **von-Neumann-Architektur**.
Drei Komponenten, mehr nicht — Prozessor, Speicher, Ein-/Ausgabe.

Achte besonders auf einen Satz, der leicht zu überlesen ist: Im Speicher liegen
**sowohl die Daten als auch das Programm**. Das klingt harmlos, ist aber der
entscheidende Punkt. Frag dich beim Lesen: Was könnte der Rechner *nicht*, wenn
das Programm nicht im Speicher läge?

Danach geht es um die Frage, wie die drei Komponenten miteinander verbunden
sind. Abbildung 19.1 zeigt zwei Bauformen: Einzelverbindungen und den Bus.

Lass dich von der Formel für die Anzahl der Verbindungswege nicht aufhalten.
Rechne sie einfach einmal für vier Komponenten durch — du kommst auf sechs
Verbindungswege bei Einzelverbindungen und auf genau einen beim Bus. Mehr musst
du dazu nicht wissen; entscheidend sind die Vor- und Nachteile, die das Buch
daraus ableitet.

---

**Schritt 5:** Lies **Abschnitt 19.2 „Hauptspeicher" (S. 371–372)**.

Kurzer Abschnitt, zwei Kernaussagen: Der Hauptspeicher besteht aus lauter
gleich aufgebauten **Speicherzellen**, und jede davon hat eine **Adresse**, über
die man sie ansprechen kann.

!!! info "Ein Begriff, den du noch nicht brauchst"
    Das Buch vergleicht den Hauptspeicher an dieser Stelle mit einem *Array*.
    Diesen Begriff lernst du erst später im Modul kennen — überlies ihn
    einfach. Für jetzt genügt ein anderes Bild: eine sehr lange Reihe
    durchnummerierter Schließfächer. Die Nummer ist die Adresse, der Inhalt des
    Fachs ist der gespeicherte Wert.

Zum Schluss vergleicht der Abschnitt Hauptspeicher und Festplatte. Halte fest,
worin sie sich unterscheiden — es sind drei Dinge: Geschwindigkeit, Kosten und
was beim Ausschalten passiert.

---

**Schritt 6:** Lies **Abschnitt 19.3 „Prozessor, Befehlssatz und
Maschinensprache" (S. 372–375)**, bis einschließlich Zusammenfassung 19.4.

Das ist der längste und dichteste Abschnitt der Woche. Nimm ihn dir in drei
Portionen vor:

- Zuerst der **Befehlssatz**: Ein Prozessor beherrscht eine feste Menge von
  Befehlen, und die lassen sich in drei Klassen einteilen (Abbildung 19.3).
  Merke dir die drei Klassen und je ein Beispiel.
- Dann der **Aufbau des Prozessors** (Abbildung 19.4). Vier Registernamen
  tauchen hier auf, die auf den ersten Blick verwirrend ähnlich klingen. Wenn
  du dir merkst, wofür die Abkürzungen stehen, sortiert sich das von selbst:
  Befehls**zeiger** zeigt auf den nächsten Befehl, das Befehls**register** hält
  den aktuellen Befehl, das Speicher**adress**register hält eine Adresse, das
  Speicher**daten**register hält einen Wert.
- Zuletzt der **Befehlsausführungszyklus** (S. 375). Drei Schritte, die sich
  wiederholen, bis ein Halte-Befehl kommt. Das ist die zentrale Erkenntnis der
  ganzen Woche — nimm dir dafür Zeit.

Die Seite 376 mit Aufgabe 19.2 kannst du überspringen. Wenn dich das Thema
gepackt hat, ist sie aber eine schöne Zugabe.

## Zum Ausprobieren { .abschnitt-ausprobieren }

Diese kleine Übung ist **ohne Rechner** zu lösen — Zettel und Stift genügen.

!!! abstract "Diese Übung bitte ohne KI"
    Geh den Zyklus selbst durch. Der Lerneffekt entsteht genau dabei, ihn einmal
    von Hand mitzugehen — nicht dabei, ein fertiges Ergebnis zu lesen.

    Davon unberührt: Wenn beim Lesen der Kapitel eine Stelle unklar geblieben
    ist, darfst du dir den Begriff natürlich auch von einem KI-Werkzeug erklären
    lassen. Mehr dazu unter [KI im Kurs](../../ki-nutzung.md).

Im Hauptspeicher eines Rechners steht ab Adresse 0 das folgende kleine Programm:

| Adresse | Befehl |
|---|---|
| 0 | `setze r1, 7` |
| 1 | `setze r2, 5` |
| 2 | `addiere r3, r1, r2` |
| 3 | `speichere a10, r3` |
| 4 | `halt` |

Die vier verwendeten Befehle bedeuten:

- `setze rk, w` — schreibt die Zahl `w` in das Register `rk`
- `addiere rk, ri, rj` — addiert die Werte aus den Registern `ri` und `rj` und
  legt das Ergebnis in `rk` ab
- `speichere ak, ri` — schreibt den Wert aus Register `ri` in die Speicherzelle
  mit der Adresse `k`
- `halt` — beendet das Programm

Der Befehlszeiger (BZ) steht am Anfang auf 0. In den Befehlsregister (BR) wird der nächste auszuführende Befehl geladen. Geh nun den
Befehlsausführungszyklus durch und fülle für jeden Durchlauf eine Zeile aus:

| Durchlauf | BZ vor Schritt 1 | Inhalt des BR nach Schritt 1 | BZ nach Schritt 2 | Wirkung von Schritt 3 |
|---|---|---|---|---|
| 1 | 0 | | | |
| 2 | | | | |
| 3 | | | | |
| 4 | | | | |
| 5 | | | | |

Beantworte danach zwei Fragen:

**a)** Welcher Wert steht am Ende in der Speicherzelle mit der Adresse 10?

**b)** Im Zyklus wird der Befehlszeiger erhöht, *bevor* der Befehl ausgeführt
wird. Warum ist diese Reihenfolge sinnvoll? Denk dabei an die Sprungbefehle.

??? note "Musterlösung anzeigen"
    | Durchlauf | BZ vor Schritt 1 | Inhalt des BR nach Schritt 1 | BZ nach Schritt 2 | Wirkung von Schritt 3 |
    |---|---|---|---|---|
    | 1 | 0 | `setze r1, 7` | 1 | r1 enthält 7 |
    | 2 | 1 | `setze r2, 5` | 2 | r2 enthält 5 |
    | 3 | 2 | `addiere r3, r1, r2` | 3 | r3 enthält 12 |
    | 4 | 3 | `speichere a10, r3` | 4 | Speicherzelle 10 enthält 12 |
    | 5 | 4 | `halt` | 5 | Das Programm endet |

    **a)** In der Speicherzelle mit der Adresse 10 steht am Ende der Wert
    **12**.

    **b)** Weil der Prozessor sonst nach jedem Sprung durcheinanderkäme. Der
    Normalfall ist, dass der nächste Befehl direkt hinter dem aktuellen steht —
    deshalb wird der Befehlszeiger gleich nach dem Holen um eins erhöht. Nur ein
    Sprungbefehl weicht davon ab, und er tut das, indem er in Schritt 3 einfach
    eine andere Adresse in den Befehlszeiger schreibt. Diese Reihenfolge sorgt
    also dafür, dass der Sprung das letzte Wort hat: Was der Sprungbefehl
    einträgt, überschreibt den zuvor hochgezählten Wert und bleibt stehen. Würde
    der Zähler *nach* der Ausführung erhöht, würde er das Sprungziel wieder
    kaputtmachen.

    Genau das ist übrigens der Grund, warum ein Programm überhaupt Schleifen und
    Verzweigungen enthalten kann und nicht bloß stur von oben nach unten läuft.

## Selbstkontrolle { .abschnitt-selbstkontrolle }

### Frage 1

<quiz>
Ordne die vier Teilbereiche der Informatik ihrer Beschreibung zu (Abbildung 1.2 im Lehrbuch):

| Nr. | Teilbereich |
|---|---|
| 1 | Technische Informatik |
| 2 | Praktische Informatik |
| 3 | Angewandte Informatik |
| 4 | Theoretische Informatik |

- [[2]] Beschäftigt sich mit den Prinzipien und Techniken der Programmierung.
- [[4]] Entwickelt mathematische Modelle von Rechnern und Mittel, um sie präzise zu beschreiben.
- [[1]] Beschäftigt sich mit dem inneren Aufbau von Rechnern und allen technischen Fragen dazu.
- [[3]] Schlägt die Brücke zwischen den Methoden der Informatik und konkreten Anwendungsproblemen.

</quiz>

### Frage 2

<quiz>
Ein Konstrukteur zeichnet einen Schaltplan für eine Förderanlage. Der Plan zeigt Motoren, Sensoren und deren Verdrahtung, aber weder die Farbe der Anlage noch das Gewicht der Bauteile. Was ist das ein Beispiel für?

- [ ] Für einen Fehler, denn ein vollständiges Modell müsste alle Eigenschaften enthalten.
- [x] Für Abstraktion: Es bleibt nur das übrig, was für den Zweck des Modells wesentlich ist.
> Genau. Was "wesentlich" ist, entscheidet sich immer am Zweck.
- [ ] Für Informationsverarbeitung, weil Daten in eine andere Form gebracht werden.
- [ ] Für ein Programm, weil eine Handlungsanweisung beschrieben wird.

Abstraktion heißt, das Wesentliche vom Unwesentlichen zu trennen. Entscheidend ist dabei, dass "wesentlich" keine feste Eigenschaft der Sache ist, sondern vom Zweck des Modells abhängt.
</quiz>

### Frage 3

<quiz>
Welche Aussagen über die von-Neumann-Architektur treffen zu? (Mehrere Antworten können richtig sein.)

- [x] Programm und Daten liegen gemeinsam im Speicher.
> Richtig, und das ist der entscheidende Punkt der ganzen Architektur.
- [x] Der Prozessor führt das Programm aus und verarbeitet dabei die Daten.
- [ ] Das Programm liegt im Prozessor, im Speicher stehen nur die Daten.
> Nein. Gerade weil auch das Programm im Speicher liegt, kann der Rechner es selbstständig Befehl für Befehl abarbeiten.
- [x] Die Ein-/Ausgabe dient der Kommunikation mit Benutzern und anderen Rechnern.
- [ ] Jede der drei Komponenten benötigt einen eigenen Prozessor.

Ein von-Neumann-Rechner besteht aus genau drei Komponenten: Prozessor, Speicher und Ein-/Ausgabe. Sie sind über Kommunikationswege miteinander verbunden.
</quiz>

### Frage 4

<quiz>
Ein Rechner ist nach dem Busprinzip (Sammelschiene) aufgebaut. Welche Aussagen treffen zu? (Mehrere Antworten können richtig sein.)

- [ ] Eine Bussteuerung wird nicht benötigt.
- [x] Es werden deutlich weniger Verbindungswege gebraucht als bei Einzelverbindungen.
- [x] Neue Komponenten lassen sich vergleichsweise einfach ergänzen.
> Richtig — dafür sorgen die Steckplätze am Bus. Genau deshalb ist das Busprinzip im PC verbreitet.
- [ ] Beliebig viele Komponentenpaare können gleichzeitig miteinander kommunizieren.
> Nein, das ist gerade der Nachteil: Alle teilen sich einen Kanal, die Kommunikation muss deshalb nacheinander ablaufen.
- [x] Die Kommunikation zwischen zwei Einheiten läuft nacheinander statt gleichzeitig ab.

Bei vier Komponenten braucht die Einzelverbindungsarchitektur sechs Verbindungswege, die Busarchitektur genau einen. Der Preis dafür ist die geringere Kommunikationsgeschwindigkeit, weil immer nur ein Paar zur Zeit den Bus nutzen kann.
</quiz>

### Frage 5

Ein Rechner hat sowohl einen Hauptspeicher als auch eine Festplatte. Warum kommt man nicht mit einem von beiden aus? Nenne für jede der beiden Speicherarten eine Eigenschaft, die die andere nicht hat.

??? note "Musterlösung anzeigen"
    Die beiden ergänzen sich, weil jede genau die Schwäche der anderen ausgleicht.

    **Der Hauptspeicher** ist deutlich schneller, vor allem beim wahlfreien
    Zugriff — also dann, wenn kreuz und quer auf beliebige Adressen zugegriffen
    wird, und genau das tut ein laufendes Programm ständig. Ohne ihn wäre der
    Prozessor dauernd am Warten.

    **Die Festplatte** behält ihren Inhalt beim Ausschalten. Der Hauptspeicher
    verliert ihn. Außerdem ist Speicherplatz auf der Festplatte deutlich
    billiger, weshalb sie viel größer ausfallen kann.

    Man braucht also beide: die Festplatte, damit Programme und Daten das
    Ausschalten überleben und viel Platz haben — den Hauptspeicher, damit
    schnell genug damit gearbeitet werden kann. Beim Starten eines Programms
    wird es deshalb von der Festplatte in den Hauptspeicher geladen.

### Frage 6

<quiz>
Ordne die vier Register eines Prozessors ihrer Aufgabe zu:

| Nr. | Register |
|---|---|
| 1 | Befehlszeiger (BZ) |
| 2 | Befehlsregister (BR) |
| 3 | Speicheradressregister (SAR) |
| 4 | Speicherdatenregister (SDR) |

- [[3]] Enthält die Adresse der Speicherzelle, auf die gerade zugegriffen wird.
- [[1]] Enthält die Adresse des Befehls, der als nächstes ausgeführt wird.
- [[4]] Nimmt den Wert auf, der aus der adressierten Speicherzelle gelesen wurde.
- [[2]] Enthält den Befehl, der gerade ausgeführt wird — bestehend aus Operationscode und Operanden.

</quiz>

### Frage 7

<quiz>
Ergänze die Beschreibung des Befehlsausführungszyklus: 

Solange kein Halte-Befehl aufgetreten ist, holt der Prozessor zuerst den nächsten Befehl aus dem [[Hauptspeicher]] in das Befehlsregister, erhöht danach den [[Befehlszeiger]] um eins und führt zuletzt den Befehl aus, der im [[Befehlsregister]] steht.

---
Alle drei Lücken sind Begriffe aus Abschnitt 19.3. Achte auf die Reihenfolge der drei Schritte — sie ist nicht beliebig.
</quiz>

### Frage 8

<quiz>
Du hast ein Programm in C geschrieben. Welche Aussage trifft zu?

- [ ] Der Prozessor kann den C-Quelltext direkt ausführen.
- [x] Der C-Quelltext muss erst in Maschinensprache übersetzt werden, bevor der Prozessor ihn ausführen kann.
> Richtig. Diese Übersetzung übernimmt ein Compiler.
- [ ] Maschinensprache ist bei allen Prozessoren identisch, deshalb läuft übersetzter Code überall.
> Nein, Maschinensprachen sind prozessorabhängig. Deshalb muss ein Programm für jede Prozessorfamilie neu übersetzt werden.
- [ ] Die Assemblersprache steht im Ebenenmodell oberhalb von C.

Im Ebenenmodell liegt C als problemorientierte Programmiersprache ganz oben, darunter die Assemblersprache, darunter die Maschinensprache. Nach unten wird es maschinennäher, nach oben näher an der Art, wie Menschen ein Problem beschreiben.
</quiz>
