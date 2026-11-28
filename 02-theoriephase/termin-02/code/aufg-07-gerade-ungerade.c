#include <stdio.h>

int main(void)
{
    int zahl = 0;

    printf("Ganze Zahl eingeben: ");
    scanf_s("%d", &zahl);

    // Rest 0 heisst: zahl ist ohne Rest durch 2 teilbar, also gerade
    if (zahl % 2 == 0)
    {
        printf("%d ist gerade\n", zahl);
    }
    else
    {
        printf("%d ist ungerade\n", zahl);
    }

    return 0;
}
