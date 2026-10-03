#include <stdio.h>
#include <stdlib.h>

void linieZeichnen(char zeichen, int laenge);
void begruessung(char anfangsbuchstabe);

int main(void)
{
    char anfangsbuchstabe = '\0';

    printf("Anfangsbuchstabe deines Vornamens: ");
    scanf_s("%c", &anfangsbuchstabe, 1);

    begruessung(anfangsbuchstabe);

    system("pause");

    return 0;
}

void linieZeichnen(char zeichen, int laenge)
{
    for (int i = 1; i <= laenge; i++)
        printf("%c", zeichen);
    printf("\n");
}

void begruessung(char anfangsbuchstabe)
{
    linieZeichnen('-', 20);
    printf("Hallo, %c!\n", anfangsbuchstabe);
    linieZeichnen('-', 20);
}
