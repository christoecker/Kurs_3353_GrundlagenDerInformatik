#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teileverwaltung.h"

#define LAGER_DATEI "ersatzteile.csv"
#define ZEILE_LAENGE 100

// Clean Code: Information Hiding - wird nur innerhalb dieser Datei
// gebraucht (von qsort/bsearch), deshalb "static" und nicht im Header
// deklariert.
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
    if (datei == NULL)
        return;

    char zeile[ZEILE_LAENGE];
    while (fgets(zeile, sizeof(zeile), datei) != NULL)
    {
        Teil geladenesTeil;
        int gelesen = sscanf(zeile, "%d;%29[^;];%d", &geladenesTeil.teilenummer, geladenesTeil.bezeichnung, &geladenesTeil.bestand); // (1)!

        if (gelesen != 3 || strchr(zeile, '\n') == NULL) // (2)!
        {
            printf("Warnung: beschaedigte Zeile in %s ignoriert: %s", LAGER_DATEI, zeile);
            continue;
        }

        teilEinfuegen(lager, anzahlTeile, geladenesTeil);
    }

    fclose(datei);
}

void teilAnDateiAnhaengen(const Teil *teil)
{
    FILE *datei = fopen(LAGER_DATEI, "a");
    if (datei == NULL)
        return;

    fprintf(datei, "%d;%s;%d\n", teil->teilenummer, teil->bezeichnung, teil->bestand);
    fclose(datei);
}

void lagerInDateiSpeichern(const Teil lager[], int anzahlTeile)
{
    // Komplett neu schreiben statt eine einzelne Zeile zu aendern: Eine
    // Textdatei laesst sich nicht "mittendrin" ueberschreiben, ohne die
    // Zeilenlaenge exakt gleich zu halten. Da das Array ohnehin den
    // aktuellen Stand enthaelt, ist das Neuschreiben hier einfacher als
    // der Versuch, nur die eine betroffene Zeile zu patchen.
    FILE *datei = fopen(LAGER_DATEI, "w"); // (3)!
    if (datei == NULL)
        return;

    for (int i = 0; i < anzahlTeile; i++)
        fprintf(datei, "%d;%s;%d\n", lager[i].teilenummer, lager[i].bezeichnung, lager[i].bestand);

    fclose(datei);
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

Teil *teilSuchen(Teil lager[], int anzahlTeile, int teilenummer)
{
    Teil schluessel;
    schluessel.teilenummer = teilenummer;
    return (Teil *)bsearch(&schluessel, lager, anzahlTeile, sizeof(Teil), vergleicheTeilenummern);
}

void bestandAendern(Teil *teil, int aenderung)
{
    teil->bestand = teil->bestand + aenderung;

    if (teil->bestand < 0)
        teil->bestand = 0; // Bestand kann nicht negativ werden
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
