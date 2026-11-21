#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int zahl = 0;
    int ziffer = 0;
    int quersumme = 0;

    printf("Zahl eingeben: ");
    scanf_s("%d", &zahl);

    do
    {
        ziffer = zahl % 10;
        quersumme = quersumme + ziffer;
        zahl = zahl / 10;
    } while (zahl != 0);

    printf("Quersumme: %d\n", quersumme);

    system("pause");

    return 0;
}
