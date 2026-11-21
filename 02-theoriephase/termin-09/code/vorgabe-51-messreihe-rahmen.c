#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int anzahl;
    double *werte;
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
        reihe->werte[i] = 20.0 + i * 0.5;

    printf("Messreihe %d: Mittelwert %.2f\n", reihe->id, messreiheMittelwert(reihe));

    messreiheLoeschen(reihe);

    system("pause");

    return 0;
}

Messreihe *messreiheErzeugen(int id, int anzahl)
{
    // TODO: Struktur und Array fuer die Werte anlegen
    return NULL;
}

void messreiheLoeschen(Messreihe *reihe)
{
    // TODO: alles wieder freigeben
}

double messreiheMittelwert(const Messreihe *reihe)
{
    // TODO: Mittelwert der Werte berechnen
    return 0.0;
}
