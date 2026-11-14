#include <stdio.h>

int main(void)
{
    int akkustand = 0;

    printf("Akkustand in Prozent eingeben: ");
    scanf_s("%d", &akkustand);

    // Unter 10 % ist der Akku so knapp, dass bald ein Herunterfahren
    // droht - deshalb eine deutliche Warnung statt nur eines Hinweises
    if (akkustand <= 10)
    {
        printf("Warnung: Akku fast leer!\n");
    }
    // Zwischen 10 % und 30 % reicht die Zeit meist noch - ein Hinweis
    // genuegt, eine Warnung waere hier uebertrieben
    else if (akkustand <= 30)
    {
        printf("Akku wird schwach.\n");
    }
    else
    {
        printf("Akkustand ausreichend.\n");
    }

    return 0;
}
