#include <stdio.h>
#include <stdlib.h>

#define SWAP(typ, a, b) { typ tmp = (a); (a) = (b); (b) = tmp; }

int main(void)
{
    int x = 3;
    int y = 8;
    char c1 = 'A';
    char c2 = 'B';
    float f1 = 1.5f;
    float f2 = 7.25f;

    SWAP(int, x, y);
    SWAP(char, c1, c2);
    SWAP(float, f1, f2);

    printf("x = %d, y = %d\n", x, y);
    printf("c1 = %c, c2 = %c\n", c1, c2);
    printf("f1 = %.2f, f2 = %.2f\n", f1, f2);

    system("pause");

    return 0;
}
