#include <stdio.h>
#include <stdlib.h>

#define REIHEN 4
#define SITZE 6

// TODO: Zustaende eines Sitzes als benannte Konstanten festlegen

void saalAnzeigen(int saal[][SITZE], int reihen);
int sitzBuchen(int saal[][SITZE], int reihe, int sitz);
int sitzStatus(int saal[][SITZE], int reihe, int sitz);
void sitzFreigeben(int saal[][SITZE], int reihe, int sitz);
void saalFreigeben(int saal[][SITZE], int reihen);

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
    // TODO
    return 0;
}

int sitzStatus(int saal[][SITZE], int reihe, int sitz)
{
    // TODO
    return 0;
}

void sitzFreigeben(int saal[][SITZE], int reihe, int sitz)
{
    // TODO
}

void saalFreigeben(int saal[][SITZE], int reihen)
{
    // TODO
}
