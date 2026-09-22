#include <stdio.h>
#include <stdlib.h>

void begruessung(char anfangsbuchstabe);

int main(void)
{
    system("chcp 1252");

    char anfangsbuchstabe = '\0';

    printf("Anfangsbuchstabe deines Vornamens: ");
    scanf_s("%c", &anfangsbuchstabe, 1);

    begruessung(anfangsbuchstabe);

    system("pause");

    return 0;
}

void begruessung(char anfangsbuchstabe)
{
    printf("Hallo, %c!\n", anfangsbuchstabe);
}
