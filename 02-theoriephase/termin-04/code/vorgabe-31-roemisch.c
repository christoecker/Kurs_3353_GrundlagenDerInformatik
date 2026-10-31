#include <stdio.h>
#include <stdlib.h>

// TODO: fuer den Fehlerwert -1 eine benannte Konstante festlegen

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

int roemischZuDezimal(char zahl[])
{
    // TODO
    return 0;
}
