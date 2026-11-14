#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5
#define MINDESTBESTAND 10

typedef enum
{
    KATEGORIE_MECHANIK,
    KATEGORIE_ELEKTRIK,
    KATEGORIE_ELEKTRONIK
} Kategorie;

typedef struct
{
    int nummer;
    char name[20];
    double preis; // in Euro
    int bestand;
    Kategorie kategorie;
} Bauteil;

void kategorieAusgeben(Kategorie kategorie);
void bauteilAusgeben(Bauteil b);
double lagerwert(const Bauteil lager[], int anzahl);
void auffuellen(Bauteil *b, int menge); // (1)!

int main(void)
{
    Bauteil lager[ANZAHL] =
    {
        { 101, "Schraube M4", 0.05, 120, KATEGORIE_MECHANIK },
        { 102, "Kugellager", 4.80, 8, KATEGORIE_MECHANIK },
        { 201, "Relais 24V", 3.20, 15, KATEGORIE_ELEKTRIK },
        { 202, "Sicherung 10A", 0.40, 4, KATEGORIE_ELEKTRIK },
        { 301, "Mikrocontroller", 6.50, 22, KATEGORIE_ELEKTRONIK }
    };

    printf("Lager vor dem Auffuellen:\n");
    for (int i = 0; i < ANZAHL; i++)
        bauteilAusgeben(lager[i]);
    printf("Lagerwert: %.2f Euro\n\n", lagerwert(lager, ANZAHL));

    for (int i = 0; i < ANZAHL; i++)
        if (lager[i].bestand < MINDESTBESTAND)
            auffuellen(&lager[i], 20); // (2)!

    printf("Lager nach dem Auffuellen:\n");
    for (int i = 0; i < ANZAHL; i++)
        bauteilAusgeben(lager[i]);
    printf("Lagerwert: %.2f Euro\n", lagerwert(lager, ANZAHL));

    system("pause");

    return 0;
}

void kategorieAusgeben(Kategorie kategorie)
{
    switch (kategorie)
    {
        case KATEGORIE_MECHANIK:
            printf("Mechanik\n");
            break;
        case KATEGORIE_ELEKTRIK:
            printf("Elektrik\n");
            break;
        case KATEGORIE_ELEKTRONIK:
            printf("Elektronik\n");
            break;
        default:
            printf("Unbekannte Kategorie\n");
            break;
    }
}

void bauteilAusgeben(Bauteil b)
{
    printf("%d  %-16s %6.2f Euro  Bestand %3d  ", b.nummer, b.name, b.preis, b.bestand);
    kategorieAusgeben(b.kategorie);
}

double lagerwert(const Bauteil lager[], int anzahl)
{
    double summe = 0.0;

    for (int i = 0; i < anzahl; i++)
        summe = summe + lager[i].preis * lager[i].bestand;

    return summe;
}

void auffuellen(Bauteil *b, int menge)
{
    b->bestand = b->bestand + menge; // (3)!
}
