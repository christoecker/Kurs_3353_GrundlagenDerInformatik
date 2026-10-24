#include <stdio.h>
#include <stdlib.h>

typedef struct Knoten
{
    double wert;
    struct Knoten *nachfolger; // (1)!
} Knoten;

int main(void)
{
    Knoten *a = malloc(sizeof(Knoten)); // (2)!
    Knoten *b = malloc(sizeof(Knoten));
    Knoten *c = malloc(sizeof(Knoten));

    a->wert = 21.5;
    a->nachfolger = b; // (3)!
    b->wert = 22.0;
    b->nachfolger = c;
    c->wert = 23.25;
    c->nachfolger = NULL; // (4)!

    Knoten *kopf = a; // (5)!

    Knoten *aktuell = kopf;
    while (aktuell != NULL) // (6)!
    {
        printf("%.2f\n", aktuell->wert);
        aktuell = aktuell->nachfolger;
    }

    free(a); // (7)!
    free(b);
    free(c);

    system("pause");

    return 0;
}
