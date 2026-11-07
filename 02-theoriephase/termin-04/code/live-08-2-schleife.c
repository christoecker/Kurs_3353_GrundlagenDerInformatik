#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5

int main(void)
{
    int messwerte[ANZAHL] = { 12, 15, 9, 20, 17 };
    int summe = 0;
    int maximum = messwerte[0];

    for (int i = 0; i < ANZAHL; i++) // (1)!
    {
        printf("messwerte[%d] = %d\n", i, messwerte[i]);
        summe = summe + messwerte[i];
        if (messwerte[i] > maximum)
            maximum = messwerte[i];
    }

    printf("Summe: %d, Maximum: %d\n", summe, maximum);
    printf("Laenge per sizeof: %zu\n", sizeof(messwerte) / sizeof(messwerte[0])); // (2)!

    system("pause");

    return 0;
}
