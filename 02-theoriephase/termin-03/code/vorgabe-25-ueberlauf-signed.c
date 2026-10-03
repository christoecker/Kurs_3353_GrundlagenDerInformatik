#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    signed char wert = 125;

    for (int i = 0; i < 6; i++)
    {
        printf("Wert: %d\n", wert);
        wert++;
    }

    system("pause");

    return 0;
}
