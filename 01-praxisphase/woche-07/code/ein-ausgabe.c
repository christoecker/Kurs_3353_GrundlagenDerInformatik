#include <stdio.h>

int main(void)
{
    int zahl = 0;

    printf("Gib eine Zahl ein: ");
    scanf_s("%d", &zahl); // (1)!

    printf("Dezimal: %d\n", zahl);
    printf("Hexadezimal: %x\n", zahl); // (2)!
    printf("Als Zeichen (ASCII): %c\n", zahl); // (3)!

    return 0;
}
