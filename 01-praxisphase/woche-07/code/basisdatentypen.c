#include <stdio.h>

int main(void)
{
    int anzahl = 3; // (1)!
    float genauigkeit = 3.14f; // (2)!
    double praezision = 3.14159265; // (3)!
    char zeichen = 'A'; // (4)!

    printf("int: %d\n", anzahl);
    printf("float: %f\n", genauigkeit);
    printf("double: %f\n", praezision);
    printf("char: %c\n", zeichen);

    anzahl = 3.99; // (5)!
    printf("anzahl nach der Zuweisung: %d\n", anzahl);

    return 0;
}
