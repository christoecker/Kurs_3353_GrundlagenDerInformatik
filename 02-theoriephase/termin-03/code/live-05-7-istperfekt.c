#include <stdio.h>
#include <stdlib.h>

int istPerfekt(int zahl);

int main(void)
{
    int zahl = 0;

    printf("Zahl eingeben: ");
    scanf_s("%d", &zahl);

    if (istPerfekt(zahl))
        printf("%d ist eine perfekte Zahl.\n", zahl);
    else
        printf("%d ist keine perfekte Zahl.\n", zahl);

    system("pause");

    return 0;
}

int istPerfekt(int zahl)
{
    int summe = 0;

    for (int teiler = 1; teiler <= zahl/2; teiler++)
        if (zahl % teiler == 0)
            summe = summe + teiler;

    return summe == zahl;
}
