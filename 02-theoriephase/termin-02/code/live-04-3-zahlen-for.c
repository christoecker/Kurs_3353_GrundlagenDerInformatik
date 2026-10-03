#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int grenze = 0;

    printf("Bis zu welcher Zahl zaehlen? ");
    scanf_s("%d", &grenze);

    for (int zahl = 1; zahl <= grenze; zahl++)
        printf("%d\n", zahl);

    system("pause");

    return 0;
}
