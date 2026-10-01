#include <stdio.h>

// Gibt die ersten n Elemente eines Arrays in einer Zeile aus
void arrayAusgeben(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
