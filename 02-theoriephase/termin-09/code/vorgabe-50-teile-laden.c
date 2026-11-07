#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define DATEINAME "ersatzteile.csv"
#define MAX_BEZEICHNUNG_LAENGE 30

typedef struct
{
    int teilenummer;
    char bezeichnung[MAX_BEZEICHNUNG_LAENGE];
    int bestand;
} Teil;

// Der Aufrufer gibt das zurueckgegebene Array mit free frei.
Teil *teileLaden(const char *dateiname, int *anzahl);

int main(void)
{
    int anzahl = 0;
    Teil *teile = teileLaden(DATEINAME, &anzahl);
    if (teile == NULL)
    {
        printf("Die Teile konnten nicht geladen werden.\n");
        return 1;
    }

    for (int i = 0; i < anzahl; i++)
        printf("%4d  %-30s Bestand: %d\n", teile[i].teilenummer, teile[i].bezeichnung, teile[i].bestand);

    free(teile);

    system("pause");

    return 0;
}

Teil *teileLaden(const char *dateiname, int *anzahl)
{
    FILE *datei = fopen(dateiname, "r");
    if (datei == NULL)
        return NULL;

    char zeile[100] = "";
    fgets(zeile, sizeof(zeile), datei);
    *anzahl = atoi(zeile);

    Teil *teile = malloc(*anzahl * sizeof(Teil));
    if (teile != NULL)
        for (int i = 0; i < *anzahl; i++)
        {
            fgets(zeile, sizeof(zeile), datei);
            sscanf(zeile, "%d;%29[^;];%d", &teile[i].teilenummer, teile[i].bezeichnung, &teile[i].bestand);
        }

    fclose(datei);
    return teile;
}
