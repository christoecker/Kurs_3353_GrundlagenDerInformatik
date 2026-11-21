#include <stdio.h>
#include <stdlib.h>

int wert = 1;

void zeigeWert(void);

int main(void)
{
    printf("Vor dem Aufruf (global): %d\n", wert);
    zeigeWert();
    printf("Nach dem Aufruf (global): %d\n", wert);

    system("pause");

    return 0;
}

void zeigeWert(void)
{
    int wert = 2;
    printf("Funktionsebene: %d\n", wert);

    if (wert > 0)
    {
        int wert = 3;
        printf("Innerhalb des if-Blocks: %d\n", wert);
    }

    { // (1)!
        int wert = 4;
        printf("Isoliertes Compound Statement: %d\n", wert);
    }

    printf("Nach beiden Bloecken (wieder Funktionsebene): %d\n", wert);
}
