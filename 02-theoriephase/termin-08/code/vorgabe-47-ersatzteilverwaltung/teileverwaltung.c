#include <stdio.h>
#include <stdlib.h>
#include "teileverwaltung.h"

// Clean Code: Information Hiding - wird nur innerhalb dieser Datei
// gebraucht (von qsort), deshalb "static" und nicht im Header deklariert.
static int vergleicheTeilenummern(const void *a, const void *b)
{
    const Teil *teilA = (const Teil *)a;
    const Teil *teilB = (const Teil *)b;
    return teilA->teilenummer - teilB->teilenummer;
}

int teilEinfuegen(Teil lager[], int *anzahlTeile, Teil neuesTeil)
{
    if (*anzahlTeile >= MAX_TEILE)
    {
        printf("Lager ist voll, Teil %d kann nicht aufgenommen werden.\n", neuesTeil.teilenummer);
        return 0;
    }

    lager[*anzahlTeile] = neuesTeil;
    (*anzahlTeile)++;

    qsort(lager, *anzahlTeile, sizeof(Teil), vergleicheTeilenummern);
    return 1;
}

void teilAusgeben(const Teil *teil)
{
    printf("%4d  %-30s Bestand: %d\n", teil->teilenummer, teil->bezeichnung, teil->bestand);
}

void alleTeileAnzeigen(const Teil lager[], int anzahlTeile)
{
    if (anzahlTeile == 0)
    {
        printf("Das Lager ist leer.\n");
        return;
    }

    for (int i = 0; i < anzahlTeile; i++)
        teilAusgeben(&lager[i]);
}
