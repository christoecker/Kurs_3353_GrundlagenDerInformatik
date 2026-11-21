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
    char bezeichnung[20]; // (1)!
    double masse; // in kg
    Position ablage; // (2)!
} Werkstueck;

int main(void)
{
    Werkstueck w = { 1, "Welle", 2.5, { 100.0, 50.0 } }; // (3)!

    printf("Werkstueck %d (%s, %.1f kg) liegt bei x = %.1f, y = %.1f\n",
        w.nummer, w.bezeichnung, w.masse, w.ablage.x, w.ablage.y); // (4)!

    w.ablage.x = 120.0; // (5)!
    printf("Neue Position: x = %.1f, y = %.1f\n", w.ablage.x, w.ablage.y);

    system("pause");

    return 0;
}
