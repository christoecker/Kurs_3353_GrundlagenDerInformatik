#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int eingabe = 0;
    int teiler = 0;
    int zahl = 0;
    int rest = 0;
    int ergebnis = 0;

    printf("Zahl eingeben: ");
    scanf_s("%d", &eingabe);
    printf("Teiler eingeben (mindestens 2): ");
    scanf_s("%d", &teiler);

    zahl = eingabe;
    rest = zahl % teiler;
    ergebnis = zahl / teiler;
    while (rest == 0 && ergebnis != 1)
    {
        zahl = ergebnis;
        rest = zahl % teiler;
        ergebnis = zahl / teiler;
    }

    if (rest == 0 && ergebnis == 1)
        printf("%d ist eine Potenz von %d\n", eingabe, teiler);
    else
        printf("%d ist keine Potenz von %d\n", eingabe, teiler);

    system("pause");

    return 0;
}
