#include <stdio.h>

int main(void)
{
    char zeichen = '\0';

    printf("Gib ein einzelnes Zeichen ein: ");
    scanf_s("%c", &zeichen, 1);

    printf("Als Zeichen: %c\n", zeichen);
    printf("Als Zahl (ASCII-Code): %d\n", zeichen);

    return 0;
}
