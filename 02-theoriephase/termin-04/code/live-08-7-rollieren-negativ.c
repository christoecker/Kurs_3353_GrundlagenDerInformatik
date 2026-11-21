#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5

void rollieren(int a[], int n, int m);
void einmalNachRechts(int a[], int n);
void arrayAusgeben(int a[], int n);

int main(void)
{
    int a[ANZAHL] = { 1, 2, 3, 4, 5 };

    printf("Vorher:            ");
    arrayAusgeben(a, ANZAHL);

    rollieren(a, ANZAHL, -1);
    printf("Um -1 Stelle:      ");
    arrayAusgeben(a, ANZAHL);

    rollieren(a, ANZAHL, -7);
    printf("Um weitere -7:     ");
    arrayAusgeben(a, ANZAHL);

    system("pause");

    return 0;
}

void rollieren(int a[], int n, int m)
{
    m = m % n;
    if (m < 0)
        m = m + n; // (1)!

    for (int schritt = 0; schritt < m; schritt++)
        einmalNachRechts(a, n);
}

void einmalNachRechts(int a[], int n)
{
    int letztes = a[n - 1];

    for (int i = n - 1; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = letztes;
}

void arrayAusgeben(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
