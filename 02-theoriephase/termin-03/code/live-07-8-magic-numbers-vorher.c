#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fuellstand = 82;

    if (fuellstand > 95)
        printf("Kritisch: Fuellstand zu hoch!\n");
    else if (fuellstand > 80)
        printf("Warnung: Fuellstand hoch.\n");
    else
        printf("Fuellstand im normalen Bereich.\n");

    system("pause");

    return 0;
}
