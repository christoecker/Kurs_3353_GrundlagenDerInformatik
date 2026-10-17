#include <stdio.h>
#include <stdlib.h>

typedef struct Knoten
{
    double wert;
    struct Knoten *nachfolger;
} Knoten;

typedef struct
{
    Knoten *kopf;
    int anzahl;
} Liste;

int listeAnhaengen(Liste *liste, double wert);
void listeAusgeben(const Liste *liste); // (1)!
void listeFreigeben(Liste *liste); // (2)!

int main(void)
{
    Liste messwerte = { NULL, 0 };

    for (int i = 0; i < 5; i++)
        if (!listeAnhaengen(&messwerte, 20.0 + i * 0.5))
            printf("Nicht genug Speicher.\n");

    listeAusgeben(&messwerte);

    listeFreigeben(&messwerte);
    listeAusgeben(&messwerte); // (3)!

    system("pause");

    return 0;
}

int listeAnhaengen(Liste *liste, double wert)
{
    Knoten *neu = malloc(sizeof(Knoten));
    if (neu == NULL)
        return 0;

    neu->wert = wert;
    neu->nachfolger = NULL;

    if (liste->kopf == NULL)
        liste->kopf = neu;
    else
    {
        Knoten *letzter = liste->kopf;
        while (letzter->nachfolger != NULL)
            letzter = letzter->nachfolger;
        letzter->nachfolger = neu;
    }

    liste->anzahl++;
    return 1;
}

void listeAusgeben(const Liste *liste)
{
    if (liste->kopf == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }

    printf("%d Messwerte:", liste->anzahl);
    for (const Knoten *aktuell = liste->kopf; aktuell != NULL; aktuell = aktuell->nachfolger) // (4)!
        printf(" %.2f", aktuell->wert);
    printf("\n");
}

void listeFreigeben(Liste *liste)
{
    Knoten *aktuell = liste->kopf;
    while (aktuell != NULL)
    {
        Knoten *naechster = aktuell->nachfolger; // (5)!
        free(aktuell);
        aktuell = naechster;
    }

    liste->kopf = NULL; // (6)!
    liste->anzahl = 0;
}
