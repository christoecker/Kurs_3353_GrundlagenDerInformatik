#include <stdio.h>
#include <stdlib.h>

void begruessung(char anfangsbuchstabe, int anzahl);

int main(void)
{
    system("chcp 1252");

    char anfangsbuchstabe = '\0';
    int anzahl = 0;

    printf("Anfangsbuchstabe deines Vornamens: ");
    scanf_s("%c", &anfangsbuchstabe, 1);
    printf("Wie oft sollen wir dich begruessen? ");
    scanf_s("%d", &anzahl);

    begruessung(anfangsbuchstabe, anzahl);

    system("pause");

    return 0;
}

void begruessung(char anfangsbuchstabe, int anzahl)
{
    for (int i = 1; i <= anzahl; i++)
        printf("Hallo, %c!\n", anfangsbuchstabe);
}
