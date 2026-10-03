#include <stdio.h>
#include <stdlib.h>

int istPerfekt(int zahl);

int main(void)
{
    for (int kandidat = 1; kandidat <= 10000; kandidat++)
        if (istPerfekt(kandidat))
            printf("%d\n", kandidat);

    system("pause");

    return 0;
}

int istPerfekt(int zahl)
{
    int summe = 0;

    for (int teiler = 1; teiler <= zahl / 2; teiler++)
        if (zahl % teiler == 0)
            summe = summe + teiler;

    return summe == zahl;
}
