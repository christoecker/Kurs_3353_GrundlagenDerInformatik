---
typ: theoriephase-vorbereitung
termin: 3
vorbereitung_fuer_termin: 4
datum_naechster_termin: "2026-11-11"
kurztitel: "Vorbereitung auf Termin 4"
publish_date: 2026-11-04
---

# Vorbereitung auf Termin 4 am 11.11.2026

## Worum geht es in Termin 4?

In Termin 4 lernt ihr mit **Arrays** eine neue Datenstruktur kennen, mit der
ihr mehrere Werte gleichen Typs unter einem einzigen Namen verwalten könnt
— zum Beispiel eine ganze Messreihe statt einzelner Variablen für jeden
Messwert. Direkt im Anschluss wendet ihr Arrays an einem konkreten Beispiel
an: **Sortieralgorithmen**, mit denen die Werte eines Arrays in eine
Reihenfolge gebracht werden.

Auf Arrays bereiten euch zwei Videos aus meiner YouTube-Playlist vor. Auf
die Sortieralgorithmen bereitet ihr euch mit einem Wikipedia-Artikel zu
**Bubblesort** und einem kleinen Schreibtischtest vor. Bearbeitet alles vor
dem Termin — im Termin selbst bauen wir direkt darauf auf.

> Zeitbedarf: ca. 60 Min. (zwei kurze Videos, ein Wikipedia-Artikel und
> ein Schreibtischtest)

## Videos zum Anschauen

**Video 1 — „C-Programmierung #16: Arrays" (12:45 Min.):** Arrays sind
Felder von Variablen, die in nahezu jedem Programm benötigt werden. Wie man
ein Array anlegt, dieses initialisiert, verarbeitet und an Funktionen
übergibt, erklärt dieses Video.

<div class="video-wrapper">
  <iframe src="https://www.youtube-nocookie.com/embed/Tag7S6s0CZo" title="Video: C-Programmierung #16: Arrays" loading="lazy" allowfullscreen referrerpolicy="strict-origin-when-cross-origin"></iframe>
</div>

---

**Video 2 — „C-Programmierung #17: Strings und die Bibliothek string.h"
(9:30 Min.):** Strings oder Zeichenketten sind eine besondere Klasse von
Arrays, nämlich Arrays vom Typ `char`. Diese Strings sind wichtig, weil sie
die Grundlage für Textverarbeitungen bilden. Für die Verarbeitung dieser
Strings werden in der Bibliothek `string.h` vielfältige Funktionen
angeboten, von denen hier einige vorgestellt werden.

<div class="video-wrapper">
  <iframe src="https://www.youtube-nocookie.com/embed/l3dNcqKiboE" title="Video: C-Programmierung #17: Strings und die Bibliothek string.h" loading="lazy" allowfullscreen referrerpolicy="strict-origin-when-cross-origin"></iframe>
</div>

## Sortieren vorbereiten: Bubblesort

**Schritt 1: Artikel lesen.** Lest den Wikipedia-Artikel
[Bubblesort](https://de.wikipedia.org/wiki/Bubblesort) durch. Den Abschnitt
„Abgrenzung" könnt ihr überspringen. Bubblesort ist ein einfaches Verfahren,
das die Werte einer Reihe (bei uns später: eines Arrays) durch wiederholtes
Vergleichen und Vertauschen benachbarter Elemente sortiert. Achtet beim
Lesen besonders darauf, was in einem einzelnen Durchlauf passiert und
warum ein Durchlauf mehrfach wiederholt werden muss. Mit der Komplexität
und den Optimierungen am Ende des Artikels müsst ihr noch nichts
anfangen können — ein erster Eindruck genügt.

**Schritt 2: Schreibtischtest.** Der Artikel zeigt das Verfahren an einem
Beispiel. Damit ihr es wirklich verstanden habt, spielt ihr es jetzt an
einer eigenen Zahlenreihe durch — mit Stift und Papier, ohne Rechner und
ohne KI: Nur wer jeden Schritt selbst nachvollzieht, merkt, wo er den
Algorithmus noch nicht durchschaut hat.

Sortiert die folgende Reihe mit 5 Elementen **aufsteigend** mit Bubblesort:

```text
29   8   41   15   3
```

Vergleicht in jedem Durchlauf immer ein Element mit seinem rechten
Nachbarn (von links nach rechts) und tauscht die beiden, wenn sie in der
falschen Reihenfolge stehen. Haltet nach jedem Durchlauf den Zustand der
Reihe fest und zählt die Vertauschungen:

| Durchlauf | Zustand der Reihe nach dem Durchlauf | Vertauschungen |
|---|---|---|
| Start | 29   8   41   15   3 | – |
| 1 | | |
| 2 | | |
| 3 | | |
| 4 | | |

Beantwortet dazu:

* Welches Element steht nach dem ersten Durchlauf an seinem endgültigen
  Platz, und warum steht es dort schon richtig?
* Wie viele Vertauschungen sind insgesamt nötig gewesen?

??? note "Musterlösung anzeigen"
    | Durchlauf | Zustand der Reihe nach dem Durchlauf | Vertauschungen |
    |---|---|---|
    | Start | 29   8   41   15   3 | – |
    | 1 | 8   29   15   3   41 | 3 |
    | 2 | 8   15   3   29   41 | 2 |
    | 3 | 8   3   15   29   41 | 1 |
    | 4 | 3   8   15   29   41 | 1 |

    Durchlauf 1 im Detail: `29` und `8` werden getauscht, `29` und `41`
    bleiben stehen, `41` und `15` werden getauscht, `41` und `3` werden
    getauscht. Die `41` als größtes Element wandert dabei wie eine
    aufsteigende Blase Schritt für Schritt bis ans rechte Ende.

    Nach dem ersten Durchlauf steht die `41` an ihrem endgültigen Platz:
    Sie ist das größte Element und wurde bei jedem Vergleich weitergereicht,
    bis sie am Ende der Reihe ankam. Größer als sie ist nichts, also kann
    sie nie wieder getauscht werden. Genauso steht nach Durchlauf 2 die
    `29` fest, nach Durchlauf 3 die `15` und so weiter — mit jedem
    Durchlauf ist ein Element mehr am rechten Ende endgültig sortiert.

    Insgesamt sind 3 + 2 + 1 + 1 = **7 Vertauschungen** nötig. Vier
    Durchläufe reichen für 5 Elemente aus, weil nach dem vierten
    Durchlauf schon vier Elemente an ihrem Platz stehen und das fünfte
    damit automatisch richtig liegt.
