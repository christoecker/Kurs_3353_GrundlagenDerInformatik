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
    int regal;
    int fach;
} Lagerplatz; // (1)!

typedef struct
{
    int nummer;
    char name[20];
    double preis; // in Euro
    int bestand;
    Kategorie kategorie;
    Lagerplatz platz; // (2)!
} Bauteil;

void kategorieAusgeben(Kategorie kategorie);
void bauteilAusgeben(Bauteil b);
double lagerwert(Bauteil lager[], int anzahl);
void auffuellen(Bauteil lager[], int anzahl, int nummer, int menge);

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

    for (int i = 0; i < ANZAHL; i++)
    {
        lager[i].platz.regal = lager[i].nummer / 100; // (3)!
        lager[i].platz.fach = i + 1;
    }

    printf("Lager vor dem Auffuellen:\n");
    for (int i = 0; i < ANZAHL; i++)
        bauteilAusgeben(lager[i]);
    printf("Lagerwert: %.2f Euro\n\n", lagerwert(lager, ANZAHL));

    for (int i = 0; i < ANZAHL; i++)
        if (lager[i].bestand < MINDESTBESTAND)
            auffuellen(lager, ANZAHL, lager[i].nummer, 20);

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
    printf("%d  %-16s %6.2f Euro  Bestand %3d  Regal %d, Fach %d  ",
        b.nummer, b.name, b.preis, b.bestand, b.platz.regal, b.platz.fach); // (4)!
    kategorieAusgeben(b.kategorie);
}

double lagerwert(Bauteil lager[], int anzahl)
{
    double summe = 0.0;

    for (int i = 0; i < anzahl; i++)
        summe = summe + lager[i].preis * lager[i].bestand;

    return summe;
}

void auffuellen(Bauteil lager[], int anzahl, int nummer, int menge)
{
    for (int i = 0; i < anzahl; i++)
        if (lager[i].nummer == nummer)
            lager[i].bestand = lager[i].bestand + menge;
}
