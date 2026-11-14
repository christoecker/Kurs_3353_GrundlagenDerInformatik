#include <stdio.h>
#include <stdlib.h>

void intArrayKopieren(int *ziel, const int *quelle, size_t anzahlElemente); // (1)!

int main(void)
{
    int quelle[] = { 10, 20, 30, 40 };
    int ziel[4] = { 0 };

    intArrayKopieren(ziel, quelle, 4); // (2)!

    for (size_t i = 0; i < 4; i++) // (3)!
        printf("ziel[%zu] = %d\n", i, ziel[i]);

    system("pause");

    return 0;
}

void intArrayKopieren(int *ziel, const int *quelle, size_t anzahlElemente)
{
    for (size_t i = 0; i < anzahlElemente; i++) // (4)!
        ziel[i] = quelle[i];
}
