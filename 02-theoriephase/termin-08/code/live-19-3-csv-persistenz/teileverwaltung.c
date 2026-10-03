#define _CRT_SECURE_NO_WARNINGS // (1)!

#include <stdio.h>
#include <stdlib.h>
#include "teileverwaltung.h"

#define LAGER_DATEI "ersatzteile.csv" // (2)!

// Clean Code: Information Hiding - wird nur innerhalb dieser Datei
// gebraucht (von qsort), deshalb "static" und nicht im Header deklariert.
static int vergleicheTeilenummern(const void *a, const void *b)
{
    const Teil *teilA = (const Teil *)a;
    const Teil *teilB = (const Teil *)b;
    return teilA->teilenummer - teilB->teilenummer;
}

void teileAusDateiLaden(Teil lager[], int *anzahlTeile)
{
    *anzahlTeile = 0;

    FILE *datei = fopen(LAGER_DATEI, "r");
    if (datei == NULL) // (3)!
        return;

    char zeile[100];
    while (fgets(zeile, sizeof(zeile), datei) != NULL) // (4)!
    {
        Teil geladenesTeil;
        sscanf(zeile, "%d;%29[^;];%d", &geladenesTeil.teilenummer, geladenesTeil.bezeichnung, &geladenesTeil.bestand); // (5)!
        teilEinfuegen(lager, anzahlTeile, geladenesTeil); // (6)!
    }

    fclose(datei);
}

void teilAnDateiAnhaengen(const Teil *teil)
{
    FILE *datei = fopen(LAGER_DATEI, "a"); // (7)!
    if (datei == NULL)
        return;

    fprintf(datei, "%d;%s;%d\n", teil->teilenummer, teil->bezeichnung, teil->bestand);
    fclose(datei);
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

    qsort(lager, *anzahlTeile, sizeof(Teil), vergleicheTeilenummern);
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
