#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5
#define GRENZWERT 15

int main(void)
{
    int messwerte[ANZAHL] = { 12, 15, 9, 20, 17 };

    for (int i = 0; i < ANZAHL; i++)
    {
        if (messwerte[i] > GRENZWERT)
            printf("messwerte[%d] = %d ueberschreitet den Grenzwert %d\n", i, messwerte[i], GRENZWERT);
    }

    system("pause");

    return 0;
}
