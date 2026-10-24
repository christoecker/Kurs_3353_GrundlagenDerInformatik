#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    ROT,
    GELB = 5,
    GRUEN,
    BLAU = 2,
    WEISS
} Farbe;

int main(void)
{
    Farbe f = GRUEN;

    printf("%d\n", ROT);
    printf("%d\n", GRUEN);
    printf("%d\n", WEISS);

    if (f > GELB)
        printf("f ist groesser als GELB\n");
    else
        printf("f ist nicht groesser als GELB\n");

    f = f + 1;
    printf("%d\n", f);

    system("pause");

    return 0;
}
