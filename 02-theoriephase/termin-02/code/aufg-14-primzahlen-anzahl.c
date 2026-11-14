#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int anzahl_gewuenscht = 0;
    int gefunden = 0;
    int kandidat = 2;

    printf("Wie viele Primzahlen sollen berechnet werden? ");
    scanf_s("%d", &anzahl_gewuenscht);

    while (gefunden < anzahl_gewuenscht)
    {
        int ist_primzahl = 1;

        for (int teiler = 2; teiler < kandidat; teiler++)
            if (kandidat % teiler == 0)
                ist_primzahl = 0;

        if (ist_primzahl)
        {
            printf("%d\n", kandidat);
            gefunden++;
        }

        kandidat++;
    }

    system("pause");

    return 0;
}
