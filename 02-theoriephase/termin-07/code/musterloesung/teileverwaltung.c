#include <stdio.h>
#include <stdlib.h>
#include "teileverwaltung.h"

// Clean Code: Information Hiding - wird nur innerhalb dieser Datei
// gebraucht (von qsort/bsearch), deshalb "static" und nicht im Header
// deklariert.
static int vergleicheTeilenummern(const void *a, const void *b)
{
    const Teil *teilA = (const Teil *)a;
    const Teil *teilB = (const Teil *)b;
    return teilA->teilenummer - teilB->teilenummer;
}

void teileMitTestdatenBefuellen(Teil lager[], int *anzahlTeile)
{
    // Feste Testdaten im Code: Das Programm speichert (noch) nichts
    // dauerhaft (siehe Auftrag), deshalb braucht es sowohl zum
    // Entwickeln/Testen als auch fuer die Kommandozeilenparameter
    // demo/suche dieselbe feste Beispielmenge.
    Teil testdaten[] =
    {
        { 1042, "Zahnradsatz", 12 },
        { 2310, "Dichtungsring", 48 },
        { 1187, "Lagerbuchse", 25 },
        { 3056, "Antriebsriemen", 7 }
    };
    int anzahlTestdaten = sizeof(testdaten) / sizeof(testdaten[0]);

    *anzahlTeile = 0;
    for (int i = 0; i < anzahlTestdaten; i++)
        teilEinfuegen(lager, anzahlTeile, testdaten[i]);
}

void teilEinfuegen(Teil lager[], int *anzahlTeile, Teil neuesTeil)
{
    if (*anzahlTeile >= MAX_TEILE)
    {
        printf("Lager ist voll, Teil %d kann nicht aufgenommen werden.\n", neuesTeil.teilenummer);
        return;
    }

    lager[*anzahlTeile] = neuesTeil;
    (*anzahlTeile)++;

    // Nach jedem Einfuegen neu sortieren: haelt das Lager durchgehend
    // sortiert (Anforderung aus dem ersten Nachtrag) - das ist die
    // Voraussetzung dafuer, dass bsearch in teilSuchen ueberhaupt
    // funktioniert.
    qsort(lager, *anzahlTeile, sizeof(Teil), vergleicheTeilenummern);
}

Teil *teilSuchen(Teil lager[], int anzahlTeile, int teilenummer)
{
    Teil schluessel;
    schluessel.teilenummer = teilenummer;

    // bsearch statt einer selbst geschriebenen Suche: setzt voraus, dass
    // lager durchgehend sortiert ist (siehe teilEinfuegen) - dafuer auch
    // bei mehreren hundert Teilen noch schnell (zweiter Nachtrag).
    return (Teil *)bsearch(&schluessel, lager, anzahlTeile, sizeof(Teil), vergleicheTeilenummern);
}

void teilAusgeben(const Teil *teil)
{
    printf("%4d  %-30s Bestand: %d\n", teil->teilenummer, teil->bezeichnung, teil->bestand);
}

void alleTeileAnzeigen(const Teil lager[], int anzahlTeile)
{
    // Clean Code: YAGNI - der Auftrag fragte urspruenglich getrennt nach
    // "alle anzeigen" und "sortiert anzeigen". Seit das Lager wegen der
    // Performance-Anforderung aus dem ersten Nachtrag ohnehin durchgehend
    // sortiert gehalten wird (siehe teilEinfuegen), ist "sortiert
    // anzeigen" identisch mit "alle anzeigen" - eine eigene zweite
    // Funktion dafuer wuerde nur Code auf Vorrat halten, den niemand
    // braucht.
    if (anzahlTeile == 0)
    {
        printf("Das Lager ist leer.\n");
        return;
    }

    for (int i = 0; i < anzahlTeile; i++)
        teilAusgeben(&lager[i]);
}

void bestandAendern(Teil *teil, int aenderung)
{
    teil->bestand = teil->bestand + aenderung;

    if (teil->bestand < 0)
        teil->bestand = 0; // Bestand kann nicht negativ werden
}
