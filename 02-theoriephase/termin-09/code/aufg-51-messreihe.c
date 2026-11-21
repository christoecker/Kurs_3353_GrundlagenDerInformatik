#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int anzahl;
    double *werte; // (1)!
} Messreihe;

// Der Aufrufer gibt die Messreihe mit messreiheLoeschen wieder frei.
Messreihe *messreiheErzeugen(int id, int anzahl);
void messreiheLoeschen(Messreihe *reihe);
double messreiheMittelwert(const Messreihe *reihe);

int main(void)
{
    Messreihe *reihe = messreiheErzeugen(1, 5);
    if (reihe == NULL)
    {
        printf("Die Messreihe konnte nicht erzeugt werden.\n");
        return 1;
    }

    for (int i = 0; i < reihe->anzahl; i++)
        reihe->werte[i] = 20.0 + i * 0.5; // (2)!

    printf("Messreihe %d: Mittelwert %.2f\n", reihe->id, messreiheMittelwert(reihe));

    messreiheLoeschen(reihe);

    system("pause");

    return 0;
}

Messreihe *messreiheErzeugen(int id, int anzahl)
{
    if (anzahl <= 0)
        return NULL;

    Messreihe *reihe = malloc(sizeof(Messreihe)); // (3)!
    if (reihe == NULL)
        return NULL;

    reihe->werte = calloc(anzahl, sizeof(double)); // (4)!
    if (reihe->werte == NULL)
    {
        free(reihe); // (5)!
        return NULL;
    }

    reihe->id = id;
    reihe->anzahl = anzahl;
    return reihe;
}

void messreiheLoeschen(Messreihe *reihe)
{
    if (reihe == NULL)
        return;

    free(reihe->werte); // (6)!
    free(reihe);
}

double messreiheMittelwert(const Messreihe *reihe)
{
    double summe = 0.0;

    for (int i = 0; i < reihe->anzahl; i++)
        summe = summe + reihe->werte[i];

    return summe / reihe->anzahl;
}
