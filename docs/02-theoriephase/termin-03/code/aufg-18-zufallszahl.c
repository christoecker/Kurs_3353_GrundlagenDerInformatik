#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int zufallszahl(int minimum, int maximum);

int main(void)
{
    srand((unsigned int)time(NULL));

    printf("Wuerfelwurf (1-6): %d\n", zufallszahl(1, 6));
    printf("Zufallszahl (0-100): %d\n", zufallszahl(0, 100));
    printf("Zufallszahl (-10 bis 10): %d\n", zufallszahl(-10, 10));

    system("pause");

    return 0;
}

int zufallszahl(int minimum, int maximum)
{
    return minimum + rand() % (maximum - minimum + 1);
}
