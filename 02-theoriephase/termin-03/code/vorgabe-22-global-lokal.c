#include <stdio.h>
#include <stdlib.h>

int stand = 10;

void ausgabe(void);

int main(void)
{
    printf("B: %d\n", stand);
    ausgabe();
    printf("C: %d\n", stand);

    system("pause");

    return 0;
}

void ausgabe(void)
{
    int stand = 3;
    printf("A: %d\n", stand);
}
