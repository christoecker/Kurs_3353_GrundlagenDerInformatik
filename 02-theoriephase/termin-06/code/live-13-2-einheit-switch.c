#include <stdio.h>
#include <stdlib.h>

enum Einheit
{
    EINHEIT_CELSIUS,
    EINHEIT_FAHRENHEIT,
    EINHEIT_KELVIN
};

double inCelsius(double wert, enum Einheit einheit);

int main(void)
{
    printf("20 C    = %.2f C\n", inCelsius(20.0, EINHEIT_CELSIUS));
    printf("100 F   = %.2f C\n", inCelsius(100.0, EINHEIT_FAHRENHEIT));
    printf("300 K   = %.2f C\n", inCelsius(300.0, EINHEIT_KELVIN));

    system("pause");

    return 0;
}

double inCelsius(double wert, enum Einheit einheit) // (1)!
{
    switch (einheit)
    {
        case EINHEIT_CELSIUS: // (2)!
            return wert;
        case EINHEIT_FAHRENHEIT:
            return (wert - 32.0) * 5.0 / 9.0;
        case EINHEIT_KELVIN:
            return wert - 273.15;
        default: // (3)!
            return wert;
    }
}
