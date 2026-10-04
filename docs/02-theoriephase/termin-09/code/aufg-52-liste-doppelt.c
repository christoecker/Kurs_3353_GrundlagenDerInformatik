#include <stdio.h>
#include <stdlib.h>

typedef struct Knoten
{
    double wert;
    struct Knoten *vorgaenger; // (1)!
    struct Knoten *nachfolger;
} Knoten;

typedef struct
{
    Knoten *kopf;
    Knoten *ende; // (2)!
    int anzahl;
} Liste;

int listeAnhaengen(Liste *liste, double wert);
void listeAusgeben(const Liste *liste);
void listeRueckwaertsAusgeben(const Liste *liste);
void listeFreigeben(Liste *liste);

int main(void)
{
    Liste messwerte = { NULL, NULL, 0 };

    for (int i = 0; i < 5; i++)
        if (!listeAnhaengen(&messwerte, 20.0 + i * 0.5))
            printf("Nicht genug Speicher.\n");

    listeAusgeben(&messwerte);
    listeRueckwaertsAusgeben(&messwerte);

    listeFreigeben(&messwerte);
    listeAusgeben(&messwerte);

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
    neu->vorgaenger = liste->ende; // (3)!

    if (liste->ende == NULL) // (4)!
        liste->kopf = neu;
    else
        liste->ende->nachfolger = neu;

    liste->ende = neu; // (5)!
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
    for (const Knoten *aktuell = liste->kopf; aktuell != NULL; aktuell = aktuell->nachfolger)
        printf(" %.2f", aktuell->wert);
    printf("\n");
}

void listeRueckwaertsAusgeben(const Liste *liste)
{
    if (liste->ende == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }

    printf("Rueckwaerts:");
    for (const Knoten *aktuell = liste->ende; aktuell != NULL; aktuell = aktuell->vorgaenger) // (6)!
        printf(" %.2f", aktuell->wert);
    printf("\n");
}

void listeFreigeben(Liste *liste)
{
    Knoten *aktuell = liste->kopf;
    while (aktuell != NULL)
    {
        Knoten *naechster = aktuell->nachfolger;
        free(aktuell);
        aktuell = naechster;
    }

    liste->kopf = NULL;
    liste->ende = NULL;
    liste->anzahl = 0;
}
