#include <stdio.h>

int main(void)
{
    int zahl = 0;

    printf("Gib eine ganze Zahl ein: ");
    scanf_s("%d", &zahl);

    printf("Dezimal:     %d\n", zahl);
    printf("Oktal:       %o\n", zahl);
    printf("Hexadezimal: %x\n", zahl);

    return 0;
}
