#include <stdio.h>
#include <stdlib.h>

char zeichenToUpper(char zeichen);
void toUpper(char text[]);

int main(void)
{
    char wort[50];

    printf("Wort eingeben: ");
    scanf_s("%s", wort, (unsigned)sizeof(wort)); // (1)!

    toUpper(wort);
    printf("In Grossbuchstaben: %s\n", wort);

    system("pause");

    return 0;
}

char zeichenToUpper(char zeichen)
{
    if (zeichen >= 'a' && zeichen <= 'z')
        return zeichen - ('a' - 'A');

    return zeichen;
}

void toUpper(char text[])
{
    for (int i = 0; text[i] != '\0'; i++) // (2)!
        text[i] = zeichenToUpper(text[i]);
}
