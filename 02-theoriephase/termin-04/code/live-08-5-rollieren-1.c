#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5

void einmalNachRechts(int a[], int n);
void arrayAusgeben(int a[], int n);

int main(void)
{
    int a[ANZAHL] = { 1, 2, 3, 4, 5 };

    printf("Vorher:  ");
    arrayAusgeben(a, ANZAHL);

    einmalNachRechts(a, ANZAHL);

    printf("Nachher: ");
    arrayAusgeben(a, ANZAHL);

    system("pause");

    return 0;
}

void einmalNachRechts(int a[], int n)
{
    int letztes = a[n - 1]; // (1)!

    for (int i = n - 1; i > 0; i--) // (2)!
        a[i] = a[i - 1];

    a[0] = letztes;
}

void arrayAusgeben(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
