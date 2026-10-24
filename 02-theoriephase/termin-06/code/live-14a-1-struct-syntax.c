#include <stdio.h>
#include <stdlib.h>

struct Messpunkt // (1)!
{
    int id; // (2)!
    double wert;
};

int main(void)
{
    struct Messpunkt p = { 1, 23.5 }; // (3)!

    printf("Messpunkt %d: %.1f\n", p.id, p.wert); // (4)!

    p.wert = 24.1; // (5)!
    printf("Messpunkt %d: %.1f\n", p.id, p.wert);

    system("pause");

    return 0;
}
