#include <stdio.h>

int main(void)
{
    printf("\x1b[31mDieser Text ist rot.\x1b[0m\n");
    printf("\x1b[44;97mWeisse Schrift auf blauem Hintergrund.\x1b[0m\n");
    printf("\x1b[10;20HHallo an Zeile 10, Spalte 20!\n");

    return 0;
}
