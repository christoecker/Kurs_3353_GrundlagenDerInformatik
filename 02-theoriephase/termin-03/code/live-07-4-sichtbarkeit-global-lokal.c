#include <stdio.h>
#include <stdlib.h>

int stand = 10; // (1)!

void zeigeStand(void);

int main(void)
{
    printf("Vor dem Aufruf: %d\n", stand);
    zeigeStand();
    printf("Nach dem Aufruf: %d\n", stand);

    system("pause");

    return 0;
}

void zeigeStand(void)
{
    int stand = 3; // (2)!
    printf("Innerhalb der Funktion: %d\n", stand);
}
