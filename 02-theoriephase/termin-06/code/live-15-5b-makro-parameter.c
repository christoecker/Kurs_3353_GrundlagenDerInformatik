#include <stdio.h>
#include <stdlib.h>

#define QUADRAT_FALSCH(x) x * x
#define QUADRAT(x) ((x) * (x))

int main(void)
{
    int a = 3;

    // wird ersetzt durch: a + 1 * a + 1
    printf("QUADRAT_FALSCH(a + 1) = %d\n", QUADRAT_FALSCH(a + 1));
    // wird ersetzt durch: ((a + 1) * (a + 1))
    printf("QUADRAT(a + 1)        = %d\n", QUADRAT(a + 1));

    system("pause");

    return 0;
}
