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
    int ergebnis = 0;

    for (int i = 1; i <= n; i++)
        ergebnis = ergebnis + i;

    return ergebnis;
}
