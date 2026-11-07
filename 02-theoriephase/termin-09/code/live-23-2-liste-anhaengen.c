#include <stdio.h>
#include <stdlib.h>

typedef struct Knoten
{
    double wert;
    struct Knoten *nachfolger;
} Knoten;

typedef struct
{
    Knoten *kopf; // (1)!
    int anzahl;
} Liste;

int listeAnhaengen(Liste *liste, double wert);

int main(void)
{
    Liste messwerte = { NULL, 0 }; // (2)!

    for (int i = 0; i < 5; i++)
        if (!listeAnhaengen(&messwerte, 20.0 + i * 0.5)) // (3)!
            printf("Nicht genug Speicher.\n");

    Knoten *aktuell = messwerte.kopf;
    while (aktuell != NULL)
    {
        printf("%.2f\n", aktuell->wert);
        aktuell = aktuell->nachfolger;
    }

    system("pause");

    return 0;
}

int listeAnhaengen(Liste *liste, double wert)
{
    Knoten *neu = malloc(sizeof(Knoten)); // (4)!
    if (neu == NULL)
        return 0;

    neu->wert = wert;
    neu->nachfolger = NULL; // (5)!

    if (liste->kopf == NULL) // (6)!
        liste->kopf = neu;
    else
    {
        Knoten *letzter = liste->kopf;
        while (letzter->nachfolger != NULL) // (7)!
            letzter = letzter->nachfolger;
        letzter->nachfolger = neu;
    }

    liste->anzahl++;
    return 1;
}
