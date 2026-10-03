#include <stdio.h>
#include <stdlib.h>

void linieZeichnen(char zeichen, int laenge);

int main(void)
{
    linieZeichnen('-', 20);

    system("pause");

    return 0;
}

void linieZeichnen(char zeichen, int laenge)
{
    for (int i = 1; i <= laenge; i++)
        printf("%c", zeichen);
    printf("\n");
}
