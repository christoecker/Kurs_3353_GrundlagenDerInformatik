#include <stdio.h>
#include <stdlib.h>

#define UNGUELTIG -1

int wertVonZeichen(char zeichen);
int roemischZuDezimal(char zahl[]);

int main(void)
{
    char mcmlxxxiii[] = "MCMLXXXIII";
    char mmxxvi[] = "MMXXVI";
    char xiv[] = "XIV";
    char ix[] = "IX";
    char cdxliv[] = "CDXLIV";
    char abc[] = "ABC";
    char xiia[] = "XIIA";
    char kleinbuchstaben[] = "xiv";

    printf("MCMLXXXIII: %d (erwartet: 1983)\n", roemischZuDezimal(mcmlxxxiii));
    printf("MMXXVI:     %d (erwartet: 2026)\n", roemischZuDezimal(mmxxvi));
    printf("XIV:        %d (erwartet: 14)\n", roemischZuDezimal(xiv));
    printf("IX:         %d (erwartet: 9)\n", roemischZuDezimal(ix));
    printf("CDXLIV:     %d (erwartet: 444)\n", roemischZuDezimal(cdxliv));
    printf("ABC:        %d (erwartet: -1)\n", roemischZuDezimal(abc));
    printf("XIIA:       %d (erwartet: -1)\n", roemischZuDezimal(xiia));
    printf("xiv:        %d (erwartet: -1)\n", roemischZuDezimal(kleinbuchstaben));

    system("pause");

    return 0;
}

int wertVonZeichen(char zeichen)
{
    switch (zeichen)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return UNGUELTIG;
    }
}

int roemischZuDezimal(char zahl[])
{
    int summe = 0;

    for (int i = 0; zahl[i] != '\0'; i++)
    {
        int wert = wertVonZeichen(zahl[i]);

        if (wert == UNGUELTIG)
            return UNGUELTIG;

        if (zahl[i + 1] != '\0' && wert < wertVonZeichen(zahl[i + 1])) // (1)!
            summe = summe - wert;
        else
            summe = summe + wert;
    }

    return summe;
}
