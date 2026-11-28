#include <stdio.h>
#include <stdlib.h>

enum Einheit // (1)!
{
    EINHEIT_CELSIUS, // (2)!
    EINHEIT_FAHRENHEIT,
    EINHEIT_KELVIN
};

int main(void)
{
    enum Einheit einheit = EINHEIT_KELVIN; // (3)!

    printf("Wert von einheit: %d\n", einheit); // (4)!

    system("pause");

    return 0;
}
