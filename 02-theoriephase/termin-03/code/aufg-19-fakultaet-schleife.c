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
    int ergebnis = 1;

    for (int i = 2; i <= n; i++)
        ergebnis = ergebnis * i;

    return ergebnis;
}
