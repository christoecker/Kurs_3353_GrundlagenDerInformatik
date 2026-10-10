#ifndef MYUTIL_H
#define MYUTIL_H

#include <stdio.h>

// Gibt die ersten n Elemente eines Arrays in einer Zeile aus
void arrayAusgeben(const int arr[], int n)
{
#ifdef RUECKWAERTS
    for (int i = n - 1; i >= 0; i--)
#else
    for (int i = 0; i < n; i++)
#endif
        printf("%d ", arr[i]);
    printf("\n");
}

#endif
