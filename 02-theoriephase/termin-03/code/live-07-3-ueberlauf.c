#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned char distanz = 250;

    for (int i = 0; i < 10; i++)
    {
        printf("Distanz: %d\n", distanz);
        distanz++;
    }

    system("pause");

    return 0;
}
