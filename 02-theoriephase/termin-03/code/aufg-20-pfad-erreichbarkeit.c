#include <stdio.h>
#include <stdlib.h>

int erreichbar(int x1, int y1, int x2, int y2);

int main(void)
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    printf("Startpunkt x1 y1: ");
    scanf_s("%d %d", &x1, &y1);
    printf("Zielpunkt x2 y2: ");
    scanf_s("%d %d", &x2, &y2);

    if (erreichbar(x1, y1, x2, y2))
        printf("Der Zielpunkt ist erreichbar.\n");
    else
        printf("Der Zielpunkt ist NICHT erreichbar.\n");

    system("pause");

    return 0;
}

int erreichbar(int x1, int y1, int x2, int y2)
{
    if (x2 == x1 && y2 == y1)
        return 1;

    if (x2 + y2 < x1 + y1)
        return 0;

    if (x2 > y2)
        return erreichbar(x1, y1, x2 - y2, y2);
    if (y2 > x2)
        return erreichbar(x1, y1, x2, y2 - x2);

    return 0;
}
