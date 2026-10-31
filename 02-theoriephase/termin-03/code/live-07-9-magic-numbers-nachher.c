#include <stdio.h>
#include <stdlib.h>

#define FUELLSTAND_KRITISCHGRENZE 95
#define FUELLSTAND_WARNGRENZE 80

int main(void)
{
    int fuellstand = 82;

    if (fuellstand > FUELLSTAND_KRITISCHGRENZE)
        printf("Kritisch: Fuellstand zu hoch!\n");
    else if (fuellstand > FUELLSTAND_WARNGRENZE)
        printf("Warnung: Fuellstand hoch.\n");
    else
        printf("Fuellstand im normalen Bereich.\n");

    system("pause");

    return 0;
}
