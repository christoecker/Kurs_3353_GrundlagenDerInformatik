#include <stdio.h>
#include <stdlib.h>

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

void werkstueckAusgeben(Werkstueck w); // (1)!

int main(void)
{
    Werkstueck w = { 1, "Welle", 2.5, { 100.0, 50.0 } };

    werkstueckAusgeben(w); // (2)!

    w.ablage.x = 120.0;
    werkstueckAusgeben(w);

    system("pause");

    return 0;
}

void werkstueckAusgeben(Werkstueck w)
{
    printf("Werkstueck %d (%s, %.1f kg) liegt bei x = %.1f, y = %.1f\n",
        w.nummer, w.bezeichnung, w.masse, w.ablage.x, w.ablage.y);
}
