#include <stdio.h>
#include <stdlib.h>

#define ZEILEN 2
#define SPALTEN 3

void matrixAusgeben(int matrix[][SPALTEN], int zeilen); // (1)!

int main(void)
{
    int matrix[ZEILEN][SPALTEN] = { { 1, 2, 3 }, { 4, 5, 6 } }; // (2)!

    printf("matrix[1][2] = %d\n", matrix[1][2]);
    matrixAusgeben(matrix, ZEILEN);

    system("pause");

    return 0;
}

void matrixAusgeben(int matrix[][SPALTEN], int zeilen)
{
    for (int zeile = 0; zeile < zeilen; zeile++)
    {
        for (int spalte = 0; spalte < SPALTEN; spalte++)
            printf("%d ", matrix[zeile][spalte]);
        printf("\n");
    }
}
