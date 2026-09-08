---
typ: praxisphase-woche
woche: 2
thema: "Zahlensysteme"
workload_minuten: 120
lernziele:
  - "Du kannst erklären, was ein Stellenwertsystem ausmacht (Basis, Ziffernvorrat), und das auch auf ein System übertragen, das du noch nie gesehen hast."
  - "Du kannst Bit, Byte und Wortbreite unterscheiden und in eigenen Worten definieren."
  - "Du kannst eine Dualzahl in eine Oktal- oder Hexadezimalzahl umwandeln und umgekehrt — durch einfaches Gruppieren der Binärstellen."
  - "Du kannst eine Dezimalzahl mit dem Horner-Schema (Restwertmethode) in eine Dual- oder Hexadezimalzahl umwandeln."
  - "Du kannst zwei Dualzahlen von Hand addieren."
  - "Du kannst erklären, warum der Rechner negative Zahlen als Zweierkomplement darstellt, und eine einfache Zweierkomplement-Subtraktion durchführen."
  - "Du kannst beschreiben, wie Zeichen wie Buchstaben im Rechner als Zahlen codiert werden."
quellen:
  - "Youtube-Playlist, Video Nr. 1 – Zahlensysteme (9:19): https://youtu.be/y-HJjMb1q2Y"
  - "Youtube-Playlist, Video Nr. 2 – Umrechnung zwischen Zahlensystemen (10:20): https://youtu.be/Vuu_mrIy7Pc"
  - "Youtube-Playlist, Video Nr. 3 – Darstellung negativer Zahlen im Binärformat (11:46): https://youtu.be/ZtnFRjO42iU"
  - "Ernst, Hartmut; Schmidt, Jochen; Beneken, Gerd: Grundkurs Informatik. Grundlagen und Konzepte für die erfolgreiche IT-Praxis – Eine umfassende Einführung. 8. Auflage, Springer Vieweg, Wiesbaden 2023 — Abschnitt 1.4 (S. 17–34), insbesondere Abschnitt 1.4.3 'Binäre Addition' (S. 25). Ergänzende/alternative Lektüre zu den Videos, deckt denselben Stoff ab; für die binäre Addition (Schritt 4) einzige Quelle, da kein Video dieses Thema behandelt."
ki_einsatz: stufe_0_ohne
bearbeitungsstatus: fertig
publish_date: 2026-09-07
---

# Woche 2: Zahlensysteme

> Zeitbedarf: ca. 2 Stunden.

## Worum geht es?

Letzte Woche hast du gesehen, dass im Hauptspeicher eines Rechners
ausschließlich Bitmuster liegen — Folgen aus Nullen und Einsen. Egal ob es
sich dabei um eine Zahl, einen Befehl oder einen Buchstaben handelt: Am Ende
ist alles eine Folge von 0 und 1.

Diese Woche schaust du dir genauer an, wie Zahlen in dieser Form dargestellt
werden — und wie man zwischen dieser Darstellung und der gewohnten
Dezimalschreibweise hin- und herrechnet. Das ist reine Kopfarbeit, du brauchst
dafür keinen Rechner. Schließlich geht es in erster Linie darum, zu verstehen, was ein Zahlensystem ist und wie man zwischen Zahlensystemen umrechnet. Dies ist übrigens eine Fähigkeit, die dir hilft, wenn du
später zum Beispiel den Speicherinhalt eines Mikrocontrollers oder eine
Fehlermeldung mit Hexadezimalwerten vor dir hast.

!!! info "Das brauchst du dafür"
    Diese Woche arbeitest du hauptsächlich mit drei kurzen Videos von meinem
    Youtube-Kanal — sie erklären die Themen der Woche Schritt für Schritt und
    mit vielen Beispielen.

    Ergänzend wird das Buch **Ernst, Schmidt, Beneken: *Grundkurs Informatik*, 8. Auflage, Springer Vieweg 2023** empfohlen. Der
    Abschnitt 1.4 dieses Buchs deckt nahezu denselben Stoff ab. Du findest es im
    eBook-Angebot der HSBI oder als PDF im ILIAS-Kursraum zu diesem Modul.
    Alle Seitenzahlen unten beziehen sich auf die Seitenzählung des Buches.

<!--
!!! abstract "Diese Woche bitte ohne KI"
    Zahlen von Hand umzurechnen und mit dem Zweierkomplement zu rechnen ist
    genau die Fertigkeit, die in einer Klausur ohne Hilfsmittel gefragt ist.
    Der Lerneffekt entsteht dabei, die Rechenschritte selbst durchzuführen —
    nicht dabei, ein fertiges Ergebnis nachzulesen. Wenn dir beim Lesen ein
    Begriff unklar bleibt, darfst du ihn dir davon unberührt gerne von einem
    KI-Werkzeug erklären lassen. Mehr dazu unter
    [KI im Kurs](../../ki-nutzung.md).
-->

## Das solltest du danach können

- Du kannst erklären, was ein Stellenwertsystem ausmacht (Basis,
  Ziffernvorrat), und das auch auf ein System übertragen, das du noch nie
  gesehen hast.
- Du kannst Bit, Byte und Wortbreite unterscheiden und in eigenen Worten
  definieren.
- Du kannst eine Dualzahl in eine Oktal- oder Hexadezimalzahl umwandeln und
  umgekehrt — durch einfaches Gruppieren der Binärstellen.
- Du kannst eine Dezimalzahl mit dem Horner-Schema (Restwertmethode) in eine
  Dual- oder Hexadezimalzahl umwandeln.
- Du kannst zwei Dualzahlen von Hand addieren.
- Du kannst erklären, warum der Rechner negative Zahlen als Zweierkomplement
  darstellt, und eine einfache Zweierkomplement-Subtraktion durchführen.
- Du kannst beschreiben, wie Zeichen wie Buchstaben im Rechner als Zahlen
  codiert werden.

## Erarbeitung { .abschnitt-erarbeitung }

**Schritt 1:** Schau dir das Video **„Zahlensysteme"** an (9:19 Min.).

<div class="video-wrapper">
  <iframe src="https://www.youtube-nocookie.com/embed/y-HJjMb1q2Y" title="Video: Zahlensysteme" loading="lazy" allowfullscreen referrerpolicy="strict-origin-when-cross-origin"></iframe>
</div>

Das Video führt allgemein in Stellenwertsysteme zur Basis B ein und zeigt
danach konkret, wie eine Zahl im Binär- und im Hexadezimalsystem dargestellt
wird — inklusive der Frage, warum das Binärsystem für Rechner überhaupt die
naheliegende Wahl ist.

Zwei Dinge legen ein Stellenwertsystem fest: die **Basis** und der
**Ziffernvorrat**. Im Dezimalsystem sind das die Basis 10 und die zehn
Ziffern 0 bis 9 — die Zahl 3247 bedeutet deshalb nichts anderes als

`3247 = 3·10³ + 2·10² + 4·10¹ + 7·10⁰`

Die folgende Tabelle fasst die drei für uns wichtigen Systeme zusammen. Das
Oktalsystem kommt im Video nicht gesondert vor, funktioniert aber nach genau
demselben Prinzip, nur mit der Basis 8:

| System | Basis | Ziffernvorrat |
|---|---|---|
| Dualsystem (Binärsystem) | 2 | 0, 1 |
| Oktalsystem | 8 | 0, 1, 2, 3, 4, 5, 6, 7 |
| Hexadezimalsystem | 16 | 0–9, A, B, C, D, E, F |

Im Hexadezimalsystem stehen die Buchstaben A bis F für die Werte 10 bis 15 —
man braucht sie, weil der Ziffernvorrat 16 verschiedene Symbole umfassen
muss und die gewohnten zehn Ziffern dafür nicht reichen. (Ausführlicher zum
Oktalsystem: Buch, Abschnitt 1.4.1.)

!!! example "Beispiel"
    Die Dualzahl 1101 lässt sich genau wie eine Dezimalzahl auswerten, nur mit
    Basis 2 statt Basis 10:

    `1101₂ = 1·2³ + 1·2² + 0·2¹ + 1·2⁰ = 8 + 4 + 0 + 1 = 13₁₀`

---

**Schritt 2:** Kläre für dich die Begriffe **Bit**, **Byte** und
**Wortbreite**.

- Ein **Bit** ist die kleinste Informationseinheit, die ein Rechner kennt —
  eine einzelne Dualstelle, also entweder 0 oder 1.
- Ein **Byte** fasst 8 Bit zusammen. Ein Byte kann deshalb `2⁸ = 256`
  verschiedene Werte annehmen (0 bis 255).
- Die **Wortbreite** gibt an, wie viele Bit ein Prozessor in einem Rutsch
  verarbeitet — zum Beispiel 32 oder 64 Bit bei den meisten heutigen
  Prozessoren. Ein Mikrocontroller in einem Sensor kommt dagegen oft mit
  8 oder 16 Bit Wortbreite aus.

Wie Zeichen, z.B. Buchstaben, im Rechner dargestellt werden, liest du auf einer
eigenen Seite nach: [ASCII-Code](ascii-code.md). Wirf jetzt schon einen Blick
hinein, den Rest der Seite brauchst du erst bei der Selbstkontrolle wieder.

---

**Schritt 3:** Schau dir das Video **„Umrechnung zwischen Zahlensystemen"**
an (10:20 Min.).

<div class="video-wrapper">
  <iframe src="https://www.youtube-nocookie.com/embed/Vuu_mrIy7Pc" title="Video: Umrechnung zwischen Zahlensystemen" loading="lazy" allowfullscreen referrerpolicy="strict-origin-when-cross-origin"></iframe>
</div>

Das Video geht in dieser Reihenfolge vor: zuerst die Umrechnung
Dezimal → Dual mit dem Horner-Schema, danach die direkte Umrechnung zwischen
Hexadezimal und Dual durch Gruppieren der Binärstellen, und zuletzt die
Umrechnung Dezimal → Hexadezimal. Die folgenden drei Beispiele wiederholen
jeden dieser Schritte noch einmal mit eigenen Zahlen.

**Horner-Schema (Dezimal → Dual):** Man teilt die Zahl fortgesetzt durch die
Zielbasis und notiert bei jedem Schritt den Rest. Liest man die Reste von
unten nach oben, ergibt sich die gesuchte Zahl.

!!! example "Beispiel: Dezimal → Dual"
    Die Zahl `210₁₀` soll ins Dualsystem umgewandelt werden. Dazu
    wird fortgesetzt durch 2 geteilt:

    ```
    210 : 2 = 105  Rest 0
    105 : 2 =  52  Rest 1
     52 : 2 =  26  Rest 0
     26 : 2 =  13  Rest 0
     13 : 2 =   6  Rest 1
      6 : 2 =   3  Rest 0
      3 : 2 =   1  Rest 1
      1 : 2 =   0  Rest 1
    ```

    Von unten nach oben gelesen ergibt sich `210₁₀ = 1101 0010₂`.
    Probe: `128 + 64 + 16 + 2 = 210`. ✓

**Gruppieren (Hexadezimal ↔ Dual):** Zwischen Dual- und Hexadezimalsystem
umzurechnen ist besonders einfach — und zwar, weil `16 = 2⁴` gilt. Deshalb
entsprechen genau vier Binärstellen einer Hexadezimalziffer (für das
Oktalsystem wären es entsprechend drei, weil `8 = 2³` gilt).

!!! example "Beispiel: Dual → Hexadezimal"
    `1011 0101₂` in Vierergruppen von rechts: `1011` und `0101`.

    `1011₂ = 11 = B`, `0101₂ = 5` → Ergebnis: `B5₁₆`

Die Rückrichtung funktioniert genauso, nur umgekehrt: Jede Hexadezimalziffer
wird einzeln durch ihre vierstellige Dualdarstellung ersetzt.

!!! example "Beispiel: Hexadezimal → Dual"
    `3E₁₆` einzeln ersetzt: `3 → 0011`, `E → 1110`.

    Ergebnis: `0011 1110₂ = 11 1110₂`

    Die beiden führenden Nullen dürfen am Ende weggelassen werden, ohne dass
    sich der Wert ändert.

**Dezimal ↔ Hexadezimal:** Das Horner-Schema von oben funktioniert für jede
beliebige Zielbasis — für das Hexadezimalsystem teilst du entsprechend
fortgesetzt durch 16 statt durch 2. Ein durchgerechnetes Beispiel dazu zeigt
das Video ab Minute 8:17.

---

**Schritt 4:** Lies im Buch **Abschnitt 1.4.3 „Binäre Arithmetik", den Teil
„Binäre Addition" (S. 25)**.

Mit Dualzahlen lässt sich genauso rechnen wie mit Dezimalzahlen — nur mit
einem sehr kleinen Ziffernvorrat. Die Regeln für die Addition zweier
Binärstellen lauten:

`0+0=0`, `0+1=1`, `1+0=1`, `1+1=0 Übertrag 1`

Genau wie im Dezimalsystem wird ein Übertrag in die nächste Stelle
weitergereicht — mit dem einzigen Unterschied, dass hier schon `1+1` einen
Übertrag auslöst und nicht erst, wenn eine Stelle zweistellig würde. Addiert
man von rechts nach links Stelle für Stelle, kann so ein einziger Übertrag
über mehrere Stellen hinweg weiterlaufen, wenn dort ebenfalls schon eine 1
steht.

!!! example "Beispiel: einfache Addition"
    `1011₂ + 0110₂ = 1 0001₂`

    Probe im Dezimalsystem: `11 + 6 = 17`, und `1 0001₂ = 16+1 = 17`. ✓

!!! example "Beispiel: Übertragskette"
    `0111₂ + 0001₂` — hier läuft der Übertrag durch alle vier Stellen:

    ```
      0111
    + 0001
    ------
      1000
    ```

    Rechte Stelle: `1+1=0`, Übertrag 1. Nächste Stelle: `1+0+1=0`, Übertrag
    1. Nächste Stelle: `1+0+1=0`, Übertrag 1. Letzte Stelle: `0+0+1=1`, kein
    weiterer Übertrag. Ergebnis: `1000₂`.

    Probe im Dezimalsystem: `7 + 1 = 8`, und `1000₂ = 8`. ✓

---

**Schritt 5:** Schau dir das Video **„Darstellung negativer Zahlen im
Binärformat"** an (11:46 Min.).

<div class="video-wrapper">
  <iframe src="https://www.youtube-nocookie.com/embed/ZtnFRjO42iU" title="Video: Darstellung negativer Zahlen im Binärformat" loading="lazy" allowfullscreen referrerpolicy="strict-origin-when-cross-origin"></iframe>
</div>

Das Video zeigt zunächst den Wertebereich von Dualzahlen und die Idee des
Vorzeichenbits, führt darüber das **Einerkomplement** als Zwischenschritt
ein und kommt darüber zum **Zweierkomplement** — mit mehreren
durchgerechneten Beispielen. Die Kurzfassung als Nachschlagehilfe:

Ein Rechner muss auch negative Zahlen darstellen können. Naheliegend wäre,
einfach ein Bit als Vorzeichen zu reservieren — das macht man in der Praxis
aber nicht, weil dann Addition und Subtraktion getrennt behandelt werden
müssten. Stattdessen verwendet man das Zweierkomplement. Bei einer
festen Stellenzahl `n` (zum Beispiel `n=8`) geht man so vor:

1. Die positive Zahl wird ganz normal binär dargestellt.
2. Alle Bits werden **invertiert** (aus 0 wird 1, aus 1 wird 0).
3. Auf das Ergebnis wird **1 addiert**.

Das höchstwertige Bit (das **MSB**, *Most Significant Bit*) zeigt danach das
Vorzeichen an: 0 bedeutet positiv (oder null), 1 bedeutet negativ.

!!! example "Beispiel: -5 mit n = 8 Bit darstellen"
    ```
      00000101   =  5
      11111010   Bits invertiert
    +        1
    ------------
      11111011   = -5 im Zweierkomplement
    ```

Der entscheidende Vorteil: Mit dem Zweierkomplement wird aus jeder
Subtraktion eine Addition. Um `a - b` zu berechnen, addiert man einfach `a`
und das Zweierkomplement von `b`.

!!! example "Beispiel: 9 − 5 als Addition"
    Zuerst wird `-5` wie oben gebildet: `11111011₂`. Dann wird
    addiert:

    ```
      00001001   =  9
    + 11111011   = -5
    ------------
    1 00000100
    ```

    Die 9. Stelle (der Übertrag ganz links) wird bei fester Stellenzahl
    `n=8` verworfen. Es bleibt `0000 0100₂ = 4` — und `9-5=4`
    stimmt. ✓

## Zum Ausprobieren { .abschnitt-ausprobieren }

Beide Übungen sind **ohne Rechner** zu lösen — Zettel und Stift genügen.

**Übung A — Hexadezimal und Dual hin und zurück:**

a) Wandle die Binärzahl `1110 1001` in eine Hexadezimalzahl um.

b) Wandle die Hexadezimalzahl `5D` in eine Binärzahl um.

??? note "Musterlösung anzeigen"
    **a)** In Vierergruppen zusammenfassen (von rechts beginnend): `1110`
    und `1001`.

    `1110₂ = E`, `1001₂ = 9` → Ergebnis: `1110 1001₂ = E9₁₆`

    **b)** Jede Hexadezimalziffer einzeln durch ihre vierstellige
    Dualdarstellung ersetzen: `5 → 0101`, `D → 1101`.

    Ergebnis: `5D₁₆ = 0101 1101₂`

**Übung B — Horner-Schema:**

Wandle die Dezimalzahl `150` mit der Restwertmethode (fortgesetzte Division
durch 2) in eine Dualzahl um. Notiere wie im Beispiel aus Schritt 3 jeden
Rechenschritt einzeln.

??? note "Musterlösung anzeigen"
    ```
    150 : 2 = 75  Rest 0
     75 : 2 = 37  Rest 1
     37 : 2 = 18  Rest 1
     18 : 2 =  9  Rest 0
      9 : 2 =  4  Rest 1
      4 : 2 =  2  Rest 0
      2 : 2 =  1  Rest 0
      1 : 2 =  0  Rest 1
    ```

    Von unten nach oben gelesen: `150₁₀ = 1001 0110₂`.

    Probe: `128 + 16 + 4 + 2 = 150`. ✓

## Selbstkontrolle { .abschnitt-selbstkontrolle }

### Frage 1

<quiz>
Ordne jedem Zahlensystem seine Basis und seinen Ziffernvorrat zu:

| Nr. | System |
|---|---|
| 1 | Dezimalsystem |
| 2 | Dualsystem |
| 3 | Oktalsystem |
| 4 | Hexadezimalsystem |

- [[4]] Basis 16, Ziffernvorrat 0–9 und A–F.
- [[1]] Basis 10, Ziffernvorrat 0–9.
- [[3]] Basis 8, Ziffernvorrat 0–7.
- [[2]] Basis 2, Ziffernvorrat 0 und 1.

</quiz>

### Frage 2

<quiz>
Welche Aussagen zu Bit, Byte und Wortbreite treffen zu? (Mehrere Antworten können richtig sein.)

- [x] Ein Byte besteht aus 8 Bit.
- [ ] Ein Bit kann die Werte 0, 1 oder 2 annehmen.
> Nein — ein Bit kennt nur zwei Zustände: 0 oder 1.
- [x] Die Wortbreite gibt an, wie viele Bit ein Prozessor auf einmal verarbeitet.
- [ ] Byte und Wortbreite bedeuten immer dasselbe.
> Nein: Ein Byte ist immer 8 Bit, die Wortbreite hängt dagegen vom jeweiligen Prozessor ab und kann z. B. 8, 32 oder 64 Bit betragen.

</quiz>

### Frage 3

Erkläre in eigenen Worten, warum man zur Umrechnung einer Dualzahl in eine
Hexadezimalzahl die Binärstellen immer zu **Vierer**gruppen zusammenfasst —
und nicht zu Dreier- oder Fünfergruppen.

??? note "Musterlösung anzeigen"
    Weil `16 = 2⁴` gilt. Mit vier Binärstellen lassen sich genau `2⁴ = 16`
    verschiedene Werte darstellen — genauso viele, wie eine einzelne
    Hexadezimalziffer haben kann (0 bis F). Deshalb entspricht jede
    Vierergruppe an Binärstellen exakt einer Hexadezimalziffer. Bei
    Dreier- oder Fünfergruppen kämen 8 bzw. 32 mögliche Werte heraus, was
    nicht zu den 16 Ziffern des Hexadezimalsystems passt.

### Frage 4

<quiz>
Um eine Dezimalzahl in eine Dualzahl umzuwandeln, teilt man sie fortgesetzt durch [[2]] und notiert bei jedem Schritt den [[Rest]]; die gesuchte Dualzahl ergibt sich, wenn man diese Reste von [[unten]] nach oben liest.

---
Das ist die Restwertmethode bzw. das Horner-Schema aus Schritt 3.
</quiz>

### Frage 5

Berechne von Hand: `1101₂ + 0101₂`.

??? note "Musterlösung anzeigen"
    ```
      1101
    + 0101
    ------
     10010
    ```

    Stellenweise von rechts: `1+1=10` (0, Übertrag 1); `0+0+1=1`;
    `1+1=10` (0, Übertrag 1); `1+0+1=10` (0, Übertrag 1); der letzte
    Übertrag ergibt die führende 1. Ergebnis: `10010₂`.

    Probe im Dezimalsystem: `13 + 5 = 18`, und `10010₂ = 16+2 = 18`. ✓

### Frage 6

<quiz>
Welche Aussagen zum Zweierkomplement treffen zu? (Mehrere Antworten können richtig sein.)

- [ ] Zur Bildung des Zweierkomplements werden alle Bits invertiert — damit ist man fertig.
> Nein — nach dem Invertieren muss noch 1 addiert werden. Das reine Invertieren ergibt erst das sogenannte Einerkomplement.
- [ ] Das Zweierkomplement wird nur bei geraden Zahlen verwendet.
> Diese Aussage ergibt keinen Sinn: Das Zweierkomplement betrifft das Vorzeichen einer Zahl, nicht ihre Gerad- oder Ungeradheit.
- [x] Das höchstwertige Bit (MSB) zeigt an, ob die Zahl negativ ist.
- [x] Mit dem Zweierkomplement lässt sich eine Subtraktion als Addition durchführen.

</quiz>

### Frage 7

Stelle die Zahl `-3` im Zweierkomplement mit `n = 8` Bit dar. Gehe dabei
Schritt für Schritt vor.

??? note "Musterlösung anzeigen"
    ```
      00000011   =  3
      11111100   Bits invertiert
    +        1
      11111101   = -3 im Zweierkomplement
    ```

### Frage 8

<quiz>
Wie viele verschiedene Zeichen lassen sich mit dem klassischen 7-Bit-ASCII-Code darstellen?

- [ ] 64
- [x] 128
> Richtig — mit 7 Bit lassen sich `2⁷ = 128` verschiedene Werte darstellen.
- [ ] 256
> Das wären 8 Bit — ASCII in seiner ursprünglichen Form nutzt nur 7 Bit, das achte Bit bleibt ungenutzt.
- [ ] 16

</quiz>
