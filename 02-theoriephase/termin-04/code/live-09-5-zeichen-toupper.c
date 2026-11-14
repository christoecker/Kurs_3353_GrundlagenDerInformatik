#include <stdio.h>
#include <stdlib.h>

char zeichenToUpper(char zeichen);

int main(void)
{
    printf("a -> %c\n", zeichenToUpper('a'));
    printf("z -> %c\n", zeichenToUpper('z'));
    printf("G -> %c\n", zeichenToUpper('G'));
    printf("5 -> %c\n", zeichenToUpper('5'));

    system("pause");

    return 0;
}

char zeichenToUpper(char zeichen)
{
    if (zeichen >= 'a' && zeichen <= 'z') // (1)!
        return zeichen - ('a' - 'A'); // (2)!

    return zeichen;
}
