#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 4

void aendere(int werte[], int laenge, int zahl);

int main(void)
{
    int daten[ANZAHL] = { 3, 6, 9, 12 };
    int zahl = 10;

    aendere(daten, ANZAHL, zahl);

    printf("zahl: %d\n", zahl);
    for (int i = 0; i < ANZAHL; i++)
        printf("daten[%d]: %d\n", i, daten[i]);

    system("pause");

    return 0;
}

void aendere(int werte[], int laenge, int zahl)
{
    zahl = zahl + 5;

    for (int i = 0; i < laenge; i++)
        werte[i] = werte[i] + zahl;
}
