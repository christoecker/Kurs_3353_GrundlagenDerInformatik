#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5

int main(void)
{
    int messwerte[ANZAHL];

    for (int i = 0; i <= ANZAHL; i++)
        messwerte[i] = i * 10;

    printf("Letzter Wert: %d\n", messwerte[ANZAHL - 1]);

    system("pause");

    return 0;
}
