#include <stdio.h>
#include <stdlib.h>

typedef enum // (1)!
{
    EINHEIT_CELSIUS,
    EINHEIT_FAHRENHEIT,
    EINHEIT_KELVIN
} Einheit; // (2)!

double inCelsius(double wert, Einheit einheit); // (3)!

int main(void)
{
    printf("20 C    = %.2f C\n", inCelsius(20.0, EINHEIT_CELSIUS));
    printf("100 F   = %.2f C\n", inCelsius(100.0, EINHEIT_FAHRENHEIT));
    printf("300 K   = %.2f C\n", inCelsius(300.0, EINHEIT_KELVIN));

    system("pause");

    return 0;
}

double inCelsius(double wert, Einheit einheit)
{
    switch (einheit)
    {
        case EINHEIT_CELSIUS:
            return wert;
        case EINHEIT_FAHRENHEIT:
            return (wert - 32.0) * 5.0 / 9.0;
        case EINHEIT_KELVIN:
            return wert - 273.15;
        default:
            return wert;
    }
}
