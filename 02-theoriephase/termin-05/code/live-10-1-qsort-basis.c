#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 8

int vergleicheAufsteigend(const void *a, const void *b); // (1)!

int main(void)
{
    int daten[ANZAHL] = { 42, 7, 19, 3, 56, 23, 8, 15 };

    qsort(daten, ANZAHL, sizeof(int), vergleicheAufsteigend); // (2)!

    for (int i = 0; i < ANZAHL; i++)
        printf("%d ", daten[i]);
    printf("\n");

    system("pause");

    return 0;
}

int vergleicheAufsteigend(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b; // (3)!
}
