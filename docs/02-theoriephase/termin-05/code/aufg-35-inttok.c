#include <stdio.h>
#include <stdlib.h>

int *inttok(int *A, int cmp);

int main(void)
{
    int A[] = { 4, 1, 3, 6, 5, 2, 0 };
    int cmp = 2;

    int *treffer = inttok(A, cmp);
    while (treffer != NULL)
    {
        printf("Treffer: %d\n", *treffer);
        treffer = inttok(NULL, cmp);
    }

    system("pause");

    return 0;
}

int *inttok(int *A, int cmp)
{
    static int *position; // (1)!

    if (A != NULL) // (2)!
        position = A;

    while (*position != 0) // (3)!
    {
        if (*position > cmp) // (4)!
        {
            int *treffer = position;
            position++; // (5)!
            return treffer;
        }
        position++;
    }

    return NULL; // (6)!
}
