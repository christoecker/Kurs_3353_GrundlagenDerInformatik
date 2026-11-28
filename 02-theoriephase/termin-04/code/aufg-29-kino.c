#include <stdio.h>
#include <stdlib.h>

#define REIHEN 4
#define SITZE 6

#define FREI 0
#define BELEGT 1

void saalAnzeigen(int saal[][SITZE], int reihen);
int sitzBuchen(int saal[][SITZE], int reihe, int sitz);
int sitzStatus(int saal[][SITZE], int reihe, int sitz);
void sitzFreigeben(int saal[][SITZE], int reihe, int sitz);
void saalFreigeben(int saal[][SITZE], int reihen);
int sitzeBuchen(int saal[][SITZE], int reihe, int ersterSitz, int anzahl);
void saalGrafischAnzeigen(int saal[][SITZE], int reihen);

int main(void)
{
    int saal[REIHEN][SITZE];

    saalFreigeben(saal, REIHEN);

    printf("Leerer Saal:\n");
    saalAnzeigen(saal, REIHEN);

    sitzBuchen(saal, 1, 2);
    sitzBuchen(saal, 1, 3);
    printf("\nNach zwei Buchungen:\n");
    saalAnzeigen(saal, REIHEN);

    if (sitzBuchen(saal, 1, 2))
        printf("\nSitz (1|2) gebucht.\n");
    else
        printf("\nSitz (1|2) war bereits belegt.\n");

    printf("Status (1|2): %d\n", sitzStatus(saal, 1, 2));
    printf("Status (0|0): %d\n", sitzStatus(saal, 0, 0));

    sitzFreigeben(saal, 1, 2);
    printf("Status (1|2) nach der Freigabe: %d\n", sitzStatus(saal, 1, 2));

    if (sitzeBuchen(saal, 1, 1, 3))
        printf("\nDrei Sitze ab (1|1) gebucht.\n");
    else
        printf("\nDrei Sitze ab (1|1) nicht buchbar (Sitz (1|3) ist belegt).\n");

    if (sitzeBuchen(saal, 2, 4, 3))
        printf("Drei Sitze ab (2|4) gebucht.\n");
    else
        printf("Drei Sitze ab (2|4) nicht buchbar (Reihe endet zu frueh).\n");

    if (sitzeBuchen(saal, 2, 0, 3))
        printf("Drei Sitze ab (2|0) gebucht.\n");
    saalAnzeigen(saal, REIHEN);

    printf("\nGrafische Ausgabe:\n");
    saalGrafischAnzeigen(saal, REIHEN);

    saalFreigeben(saal, REIHEN);
    printf("\nNach der Freigabe des Saals:\n");
    saalAnzeigen(saal, REIHEN);

    system("pause");

    return 0;
}

void saalAnzeigen(int saal[][SITZE], int reihen)
{
    for (int reihe = 0; reihe < reihen; reihe++)
    {
        for (int sitz = 0; sitz < SITZE; sitz++)
            printf("%d ", saal[reihe][sitz]);
        printf("\n");
    }
}

int sitzBuchen(int saal[][SITZE], int reihe, int sitz)
{
    if (saal[reihe][sitz] == BELEGT)
        return 0;

    saal[reihe][sitz] = BELEGT;
    return 1;
}

int sitzStatus(int saal[][SITZE], int reihe, int sitz)
{
    return saal[reihe][sitz];
}

void sitzFreigeben(int saal[][SITZE], int reihe, int sitz)
{
    saal[reihe][sitz] = FREI;
}

void saalFreigeben(int saal[][SITZE], int reihen)
{
    for (int reihe = 0; reihe < reihen; reihe++)
        for (int sitz = 0; sitz < SITZE; sitz++)
            saal[reihe][sitz] = FREI;
}

int sitzeBuchen(int saal[][SITZE], int reihe, int ersterSitz, int anzahl)
{
    if (ersterSitz + anzahl > SITZE)
        return 0;

    for (int sitz = ersterSitz; sitz < ersterSitz + anzahl; sitz++)
        if (sitzStatus(saal, reihe, sitz) == BELEGT)
            return 0;

    for (int sitz = ersterSitz; sitz < ersterSitz + anzahl; sitz++)
        sitzBuchen(saal, reihe, sitz);

    return 1;
}

void saalGrafischAnzeigen(int saal[][SITZE], int reihen)
{
    printf("    ");
    for (int sitz = 0; sitz < SITZE; sitz++)
        printf(" %d  ", sitz);
    printf("\n");

    for (int reihe = 0; reihe < reihen; reihe++)
    {
        printf("R%d  ", reihe);
        for (int sitz = 0; sitz < SITZE; sitz++)
            if (saal[reihe][sitz] == BELEGT)
                printf("[X] ");
            else
                printf("[ ] ");
        printf("\n");
    }
}
