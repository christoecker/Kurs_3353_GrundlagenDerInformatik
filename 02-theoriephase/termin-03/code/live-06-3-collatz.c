#include <stdio.h>
#include <stdlib.h>

void collatz(int n);

int main(void)
{
    int n = 0;

    printf("Startzahl eingeben (> 0): ");
    scanf_s("%d", &n);

    collatz(n);

    system("pause");

    return 0;
}

void collatz(int n)
{
    printf("%d\n", n);

    if (n == 1) // (1)!
        return;

    if (n % 2 == 0)
        collatz(n / 2);
    else
        collatz(3 * n + 1);
}
