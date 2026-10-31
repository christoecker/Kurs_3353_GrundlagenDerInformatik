#include <stdio.h>
#include <stdlib.h>

char zeichenToLower(char zeichen);
_Bool istAnagramm(char erster[], char zweiter[]);

int main(void)
{
    char lager[] = "Lager";
    char regal[] = "Regal";
    char suah[] = "SUah";
    char haus[] = "Haus";
    char maus[] = "Maus";
    char ei[] = "Ei";
    char eier[] = "Eier";

    printf("Lager / Regal: %d (erwartet: 1)\n", istAnagramm(lager, regal));
    printf("SUah / Haus:   %d (erwartet: 1)\n", istAnagramm(suah, haus));
    printf("Haus / Haus:   %d (erwartet: 1)\n", istAnagramm(haus, haus));
    printf("Haus / Maus:   %d (erwartet: 0)\n", istAnagramm(haus, maus));
    printf("Ei / Eier:     %d (erwartet: 0)\n", istAnagramm(ei, eier));

    system("pause");

    return 0;
}

char zeichenToLower(char zeichen)
{
    if (zeichen >= 'A' && zeichen <= 'Z')
        return zeichen + ('a' - 'A');

    return zeichen;
}

_Bool istAnagramm(char erster[], char zweiter[])
{
    // TODO
    return 0;
}
