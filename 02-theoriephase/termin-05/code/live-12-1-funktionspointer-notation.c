#include <stdio.h>
#include <stdlib.h>

int addieren(int a, int b); // (1)!
int subtrahieren(int a, int b);

int main(void)
{
    int (*operation)(int, int); // (2)!

    operation = addieren; // (3)!
    printf("addieren:     %d\n", operation(4, 3)); // (4)!

    operation = subtrahieren; // (5)!
    printf("subtrahieren: %d\n", operation(4, 3));

    system("pause");

    return 0;
}

int addieren(int a, int b)
{
    return a + b;
}

int subtrahieren(int a, int b)
{
    return a - b;
}
