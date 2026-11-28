#include <stdio.h>
#include <stdlib.h>

int addieren(int a, int b);
int subtrahieren(int a, int b);
int rechne(int (*operation)(int, int), int a, int b); // (1)!

int main(void)
{
    printf("rechne mit addieren:     %d\n", rechne(addieren, 4, 3)); // (2)!
    printf("rechne mit subtrahieren: %d\n", rechne(subtrahieren, 4, 3)); // (3)!

    system("pause");

    return 0;
}

int rechne(int (*operation)(int, int), int a, int b)
{
    return operation(a, b); // (4)!
}

int addieren(int a, int b)
{
    return a + b;
}

int subtrahieren(int a, int b)
{
    return a - b;
}
