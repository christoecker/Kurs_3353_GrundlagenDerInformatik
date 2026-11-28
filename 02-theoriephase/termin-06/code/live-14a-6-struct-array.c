#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 2

typedef struct
{
    double x; // in mm
    double y;
} Position;

typedef struct
{
    int nummer;
    char bezeichnung[20];
    double masse; // in kg
    Position ablage;
} Werkstueck;

void werkstueckAusgeben(Werkstueck w);

int main(void)
{
    Werkstueck werkstuecke[ANZAHL] = // (1)!
    {
        { 1, "Welle", 2.5, { 100.0, 50.0 } },
        { 2, "Flansch", 1.2, { 250.0, 75.0 } }
    };

    for (int i = 0; i < ANZAHL; i++) // (2)!
        werkstueckAusgeben(werkstuecke[i]); // (3)!

    werkstuecke[1].ablage.x = 300.0; // (4)!
    werkstueckAusgeben(werkstuecke[1]);

    system("pause");

    return 0;
}

void werkstueckAusgeben(Werkstueck w)
{
    printf("Werkstueck %d (%s, %.1f kg) liegt bei x = %.1f, y = %.1f\n",
        w.nummer, w.bezeichnung, w.masse, w.ablage.x, w.ablage.y);
}
