#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) { int tmp = (a); (a) = (b); (b) = tmp; }

int main(void)
{
    int x = 3;
    int y = 8;

    printf("vorher:  x = %d, y = %d\n", x, y);
    SWAP(x, y);
    printf("nachher: x = %d, y = %d\n", x, y);

    system("pause");

    return 0;
}
