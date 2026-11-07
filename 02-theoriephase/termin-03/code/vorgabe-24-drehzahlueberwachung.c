#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int drehzahl = 4200;

    if (drehzahl > 5000)
        printf("Warnung: Drehzahl zu hoch!\n");
    else if (drehzahl > 3000)
        printf("Hinweis: Drehzahl im oberen Bereich.\n");
    else
        printf("Drehzahl im normalen Bereich.\n");

    if (drehzahl > 5000)
        printf("Motor wird gedrosselt.\n");

    system("pause");

    return 0;
}
