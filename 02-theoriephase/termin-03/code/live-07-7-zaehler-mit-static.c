#include <stdio.h>
#include <stdlib.h>

void motorGestartet(void);

int main(void)
{
    motorGestartet();
    motorGestartet();
    motorGestartet();

    system("pause");

    return 0;
}

void motorGestartet(void)
{
    static int aufrufe = 0; // (1)!
    aufrufe++;
    printf("Motor gestartet (Aufruf Nr. %d).\n", aufrufe);
}
