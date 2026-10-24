#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int zahl = 42;

    printf("char:      %zu Byte\n", sizeof(char));
    printf("short:     %zu Byte\n", sizeof(short));
    printf("int:       %zu Byte\n", sizeof(int));
    printf("long:      %zu Byte\n", sizeof(long));
    printf("long long: %zu Byte\n", sizeof(long long));
    printf("float:     %zu Byte\n", sizeof(float));
    printf("double:    %zu Byte\n", sizeof(double));
    printf("zahl:      %zu Byte\n", sizeof(zahl));

    system("pause");

    return 0;
}
