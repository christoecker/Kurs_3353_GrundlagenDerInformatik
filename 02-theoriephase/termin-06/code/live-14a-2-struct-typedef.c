#include <stdio.h>
#include <stdlib.h>

typedef struct // (1)!
{
    int id;
    double wert;
} Messpunkt; // (2)!

int main(void)
{
    Messpunkt p = { 1, 23.5 }; // (3)!

    printf("Messpunkt %d: %.1f\n", p.id, p.wert);

    p.wert = 24.1;
    printf("Messpunkt %d: %.1f\n", p.id, p.wert);

    system("pause");

    return 0;
}
