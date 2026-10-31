#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5

void wertVerdoppeln(int wert);
void arrayVerdoppeln(int werte[], int laenge);
void arrayAusgeben(int werte[], int laenge);

int main(void)
{
    int einzelwert = 12;
    int messwerte[ANZAHL] = { 12, 15, 9, 20, 17 };

    wertVerdoppeln(einzelwert); // (1)!
    printf("einzelwert nach dem Aufruf: %d\n", einzelwert);

    arrayVerdoppeln(messwerte, ANZAHL); // (2)!
    printf("messwerte nach dem Aufruf: ");
    arrayAusgeben(messwerte, ANZAHL);

    system("pause");

    return 0;
}

void wertVerdoppeln(int wert)
{
    wert = wert * 2;
}

void arrayVerdoppeln(int werte[], int laenge) // (3)!
{
    for (int i = 0; i < laenge; i++)
        werte[i] = werte[i] * 2;
}

void arrayAusgeben(int werte[], int laenge)
{
    for (int i = 0; i < laenge; i++)
        printf("%d ", werte[i]);
    printf("\n");
}
