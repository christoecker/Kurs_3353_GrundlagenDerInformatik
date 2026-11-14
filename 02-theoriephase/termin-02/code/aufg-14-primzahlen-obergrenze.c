#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int obergrenze = 0;

    printf("Primzahlen kleiner als welche Zahl? ");
    scanf_s("%d", &obergrenze);

    for (int kandidat = 2; kandidat < obergrenze; kandidat++)
    {
        int ist_primzahl = 1;

        for (int teiler = 2; teiler < kandidat; teiler++)
            if (kandidat % teiler == 0)
                ist_primzahl = 0;

        if (ist_primzahl)
            printf("%d\n", kandidat);
    }

    system("pause");

    return 0;
}
