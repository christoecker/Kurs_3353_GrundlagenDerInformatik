#include <stdio.h>
#include <stdlib.h>

int fakultaet(int n);

int main(void)
{
    int n = 0;

    printf("Zahl eingeben: ");
    scanf_s("%d", &n);

    printf("Fakultaet: %d\n", fakultaet(n));

    system("pause");

    return 0;
}

int fakultaet(int n)
{
    if (n <= 1)
        return 1;
    return n * fakultaet(n - 1);
}
