---
publish_date: 2026-09-07
---

<!-- Reine Referenzseite zu Woche 2, kein eigener Arbeitsauftrag, deshalb
     keine der uebrigen Frontmatter-Felder einer Praxisphase-Woche. Das
     publish_date ist absichtlich identisch mit dem von woche-02.md: Diese
     Seite ergibt ohne den Arbeitsauftrag keinen Sinn und wird ausserdem von
     dort aus verlinkt - ein frueheres Datum wuerde entweder einen
     Vorgriff auf Woche 2 erlauben oder (bei einem spaeteren Datum als
     woche-02.md) einen toten Link erzeugen, solange nur diese Seite schon
     veroeffentlicht waere. -->

# ASCII-Code

Diese Seite gehört zu [Woche 2](woche-02.md). Sie erklärt, wie Zeichen — also
Buchstaben, Ziffern und Satzzeichen — im Rechner dargestellt werden, und dient
gleichzeitig als Nachschlagetabelle.

## Die Grundidee

Ein Rechner kann nur mit Zahlen umgehen. Wenn du also den Buchstaben `A`
speichern willst, muss ihm zuerst eine Zahl zugeordnet werden — und diese Zahl
wird dann ganz normal binär dargestellt, genau wie jede andere Zahl auch.

Diese Zuordnung "Zeichen → Zahl" nennt man eine **Zeichencodierung**. Die mit
Abstand bekannteste ist der **ASCII-Code** (*American Standard Code for
Information Interchange*). Er ordnet jedem Zeichen eine Zahl zwischen 0 und
127 zu — das sind genau 128 mögliche Werte, weil sich 128 Werte mit 7 Bit
darstellen lassen (2⁷ = 128). In der Praxis wird meist trotzdem ein ganzes
Byte (8 Bit) pro Zeichen verwendet; das achte Bit bleibt bei reinem ASCII
ungenutzt (bzw. wird 0 gesetzt).

!!! example "Beispiel"
    Der Buchstabe `A` hat den ASCII-Code 65. Mit dem, was du in Woche 2 gelernt
    hast, kannst du das selbst umrechnen:

    - dezimal: 65
    - hexadezimal: 41
    - binär (8 Bit): 0100 0001

    Der Kleinbuchstabe `a` hat übrigens den Code 97 — genau 32 mehr als `A`.
    Diese feste Differenz gilt für alle Buchstabenpaare und ist kein Zufall,
    sondern bewusst so festgelegt.

## Steuerzeichen

Die Codes 0 bis 31 sowie der Code 127 sind keine druckbaren Zeichen, sondern
**Steuerzeichen** — sie lösen eine Aktion aus, statt ein sichtbares Zeichen
darzustellen. Bekannte Beispiele sind Code 10 (Zeilenumbruch) und Code 9
(Tabulator). Diese Zeichen brauchst du für dieses Modul nicht auswendig zu
kennen.

## Tabelle der druckbaren Zeichen (32–126)

#### Satzzeichen und Ziffern (32–64)

| Dez | Hex | Zeichen | Dez | Hex | Zeichen |
|---|---|---|---|---|---|
| 32 | 20 | *(Leerzeichen)* | 49 | 31 | 1 |
| 33 | 21 | ! | 50 | 32 | 2 |
| 34 | 22 | " | 51 | 33 | 3 |
| 35 | 23 | # | 52 | 34 | 4 |
| 36 | 24 | $ | 53 | 35 | 5 |
| 37 | 25 | % | 54 | 36 | 6 |
| 38 | 26 | & | 55 | 37 | 7 |
| 39 | 27 | ' | 56 | 38 | 8 |
| 40 | 28 | ( | 57 | 39 | 9 |
| 41 | 29 | ) | 58 | 3A | : |
| 42 | 2A | * | 59 | 3B | ; |
| 43 | 2B | + | 60 | 3C | < |
| 44 | 2C | , | 61 | 3D | = |
| 45 | 2D | - | 62 | 3E | > |
| 46 | 2E | . | 63 | 3F | ? |
| 47 | 2F | / | 64 | 40 | @ |
| 48 | 30 | 0 | | | |

#### Großbuchstaben und weitere Zeichen (65–96)

| Dez | Hex | Zeichen | Dez | Hex | Zeichen |
|---|---|---|---|---|---|
| 65 | 41 | A | 81 | 51 | Q |
| 66 | 42 | B | 82 | 52 | R |
| 67 | 43 | C | 83 | 53 | S |
| 68 | 44 | D | 84 | 54 | T |
| 69 | 45 | E | 85 | 55 | U |
| 70 | 46 | F | 86 | 56 | V |
| 71 | 47 | G | 87 | 57 | W |
| 72 | 48 | H | 88 | 58 | X |
| 73 | 49 | I | 89 | 59 | Y |
| 74 | 4A | J | 90 | 5A | Z |
| 75 | 4B | K | 91 | 5B | [ |
| 76 | 4C | L | 92 | 5C | \ |
| 77 | 4D | M | 93 | 5D | ] |
| 78 | 4E | N | 94 | 5E | ^ |
| 79 | 4F | O | 95 | 5F | _ |
| 80 | 50 | P | 96 | 60 | ` |

#### Kleinbuchstaben und weitere Zeichen (97–126)

| Dez | Hex | Zeichen | Dez | Hex | Zeichen |
|---|---|---|---|---|---|
| 97 | 61 | a | 112 | 70 | p |
| 98 | 62 | b | 113 | 71 | q |
| 99 | 63 | c | 114 | 72 | r |
| 100 | 64 | d | 115 | 73 | s |
| 101 | 65 | e | 116 | 74 | t |
| 102 | 66 | f | 117 | 75 | u |
| 103 | 67 | g | 118 | 76 | v |
| 104 | 68 | h | 119 | 77 | w |
| 105 | 69 | i | 120 | 78 | x |
| 106 | 6A | j | 121 | 79 | y |
| 107 | 6B | k | 122 | 7A | z |
| 108 | 6C | l | 123 | 7B | { |
| 109 | 6D | m | 124 | 7C | \| |
| 110 | 6E | n | 125 | 7D | } |
| 111 | 6F | o | 126 | 7E | ~ |

**Warum keine deutschen Umlaute?** Im klassischen 7-Bit-ASCII-Code gibt es
keine Zeichen wie `ä`, `ö`, `ü` oder `ß` — der Code wurde in den USA
entwickelt. Erweiterte Codierungen wie ISO 8859-1 oder das heute übliche
Unicode ergänzen solche Zeichen, indem sie mehr Bits pro Zeichen verwenden.
Das ist für dieses Modul aber nicht weiter wichtig.
{: .hinweis-klein }

:material-arrow-left: Zurück zu [Woche 2](woche-02.md).