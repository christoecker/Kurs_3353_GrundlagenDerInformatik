#include <stdio.h>
#include <stdlib.h>

void wertVerdoppelnKopie(int wert); // (1)!
void wertVerdoppelnReferenz(int *wert); // (2)!

int main(void)
{
    int einzelwert = 12;

    wertVerdoppelnKopie(einzelwert);
    printf("Nach wertVerdoppelnKopie:    %d\n", einzelwert); // (3)!

    wertVerdoppelnReferenz(&einzelwert); // (4)!
    printf("Nach wertVerdoppelnReferenz: %d\n", einzelwert); // (5)!

    system("pause");

    return 0;
}

void wertVerdoppelnKopie(int wert)
{
    wert = wert * 2;
}

void wertVerdoppelnReferenz(int *wert)
{
    *wert = *wert * 2; // (6)!
}
