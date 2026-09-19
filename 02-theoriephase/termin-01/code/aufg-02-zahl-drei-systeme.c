#include <stdio.h>

int main(void)
{
    int zahl = 0; // vom Benutzer eingelesene Zahl, in vier Formen ausgegeben

    printf("Gib eine ganze Zahl ein: ");
    scanf_s("%d", &zahl);

    printf("Dezimal:             %d\n", zahl);
    printf("Oktal:               %o\n", zahl);
    printf("Hexadezimal:         %x\n", zahl);
    printf("Als Zeichen (ASCII): %c\n", zahl);

    return 0;
}
