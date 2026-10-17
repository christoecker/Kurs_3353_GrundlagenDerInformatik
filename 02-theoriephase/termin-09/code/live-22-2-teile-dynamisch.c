#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define DATEINAME "ersatzteile.csv"
#define MAX_TEILE 200
#define MAX_BEZEICHNUNG_LAENGE 30

typedef struct
{
    int teilenummer;
    char bezeichnung[MAX_BEZEICHNUNG_LAENGE];
    int bestand;
} Teil;

int main(void)
{
    FILE *datei = fopen(DATEINAME, "r");
    if (datei == NULL)
    {
        printf("Datei %s konnte nicht geoeffnet werden.\n", DATEINAME);
        return 1;
    }

    char zeile[100] = "";
    fgets(zeile, sizeof(zeile), datei); // (1)!
    int anzahl = atoi(zeile);

    Teil *teile = malloc(anzahl * sizeof(Teil)); // (2)!
    if (teile == NULL)
    {
        printf("Nicht genug Speicher.\n");
        fclose(datei);
        return 1;
    }

    for (int i = 0; i < anzahl; i++)
    {
        fgets(zeile, sizeof(zeile), datei);
        sscanf(zeile, "%d;%29[^;];%d", &teile[i].teilenummer, teile[i].bezeichnung, &teile[i].bestand); // (3)!
    }
    fclose(datei);

    printf("%d Teile belegen %zu Byte, ein Array fuer %d Teile waeren %zu Byte.\n", // (4)!
           anzahl, anzahl * sizeof(Teil), MAX_TEILE, MAX_TEILE * sizeof(Teil));
    for (int i = 0; i < anzahl; i++)
        printf("%4d  %-30s Bestand: %d\n", teile[i].teilenummer, teile[i].bezeichnung, teile[i].bestand);

    free(teile); // (5)!

    system("pause");

    return 0;
}
