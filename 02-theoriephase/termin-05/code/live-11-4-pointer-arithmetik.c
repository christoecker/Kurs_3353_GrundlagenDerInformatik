#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 4

int main(void)
{
    int messwerte[ANZAHL] = { 3, 7, 2, 9 };

    printf("messwerte[1]:     %d\n", messwerte[1]); // (1)!
    printf("*(messwerte + 1): %d\n", *(messwerte + 1)); // (2)!

    printf("messwerte[3]:     %d\n", messwerte[3]);
    printf("*(messwerte + 3): %d\n", *(messwerte + 3)); // (3)!

    system("pause");

    return 0;
}
