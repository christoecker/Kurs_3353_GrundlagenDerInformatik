#include <stdio.h>
#include <stdlib.h>

int summe(int n);

int main(void)
{
    int n = 0;

    printf("Bis zu welcher Zahl summieren? ");
    scanf_s("%d", &n);

    printf("Summe: %d\n", summe(n));

    system("pause");

    return 0;
}

int summe(int n)
{
    if (n == 0) // (1)!
        return 0;
    return n + summe(n - 1);
}
