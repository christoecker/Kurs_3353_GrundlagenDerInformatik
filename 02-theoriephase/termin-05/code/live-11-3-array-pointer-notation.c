#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 4

int summeMitKlammern(int werte[], int laenge); // (1)!
int summeMitStern(int *werte, int laenge); // (2)!

int main(void)
{
    int messwerte[ANZAHL] = { 3, 7, 2, 9 };

    printf("Summe (mit []): %d\n", summeMitKlammern(messwerte, ANZAHL));
    printf("Summe (mit *):  %d\n", summeMitStern(messwerte, ANZAHL)); // (3)!

    system("pause");

    return 0;
}

int summeMitKlammern(int werte[], int laenge)
{
    int summe = 0;
    for (int i = 0; i < laenge; i++)
        summe += werte[i];
    return summe;
}

int summeMitStern(int *werte, int laenge)
{
    int summe = 0;
    for (int i = 0; i < laenge; i++)
        summe += werte[i]; // (4)!
    return summe;
}
