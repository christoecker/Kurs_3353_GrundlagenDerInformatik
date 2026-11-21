#include <stdio.h>
#include <stdlib.h>

char zeichenToLower(char zeichen);
void toLower(char text[]);

int main(void)
{
    char wort[50];

    printf("Wort eingeben: ");
    scanf_s("%s", wort, (unsigned)sizeof(wort));

    toLower(wort);
    printf("In Kleinbuchstaben: %s\n", wort);

    system("pause");

    return 0;
}

char zeichenToLower(char zeichen)
{
    if (zeichen >= 'A' && zeichen <= 'Z') // (1)!
        return zeichen + ('a' - 'A');

    return zeichen;
}

void toLower(char text[])
{
    for (int i = 0; text[i] != '\0'; i++)
        text[i] = zeichenToLower(text[i]);
}
