#include <stdio.h>

int main(void)
{
    int getraenk = 0;

    printf("Getraenk waehlen (1 = Wasser, 2 = Kaffee, 3 = Kakao): ");
    scanf_s("%d", &getraenk);

    switch (getraenk)
    {
        case 1:
            printf("Wasser: 1,00 Euro\n");
            break;
        case 2:
            printf("Kaffee: 1,50 Euro\n");
            break;
        case 3:
            printf("Kakao: 2,00 Euro\n");
            break;
        default:
            printf("Unbekannte Auswahl\n");
            break;
    }

    return 0;
}
