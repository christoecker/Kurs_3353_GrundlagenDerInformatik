#include <stdio.h>
#include <stdlib.h>

#define DREHZAHL_WARNGRENZE 5000
#define DREHZAHL_HINWEISGRENZE 3000

int main(void)
{
    int drehzahl = 4200;

    if (drehzahl > DREHZAHL_WARNGRENZE)
        printf("Warnung: Drehzahl zu hoch!\n");
    else if (drehzahl > DREHZAHL_HINWEISGRENZE)
        printf("Hinweis: Drehzahl im oberen Bereich.\n");
    else
        printf("Drehzahl im normalen Bereich.\n");

    if (drehzahl > DREHZAHL_WARNGRENZE)
        printf("Motor wird gedrosselt.\n");

    system("pause");

    return 0;
}
