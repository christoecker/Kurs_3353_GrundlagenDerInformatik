#include <stdio.h>
#include <stdlib.h>

#define TAKTE 10

typedef enum
{
    TOR_ZU,
    TOR_OEFFNET,
    TOR_OFFEN,
    TOR_SCHLIESST
} Tor;

typedef enum
{
    EREIGNIS_KEINES,
    EREIGNIS_TASTER,
    EREIGNIS_ENDE_OBEN,
    EREIGNIS_ENDE_UNTEN,
    EREIGNIS_HINDERNIS
} Ereignis;

void torAusgeben(Tor tor);
Tor naechsterZustand(Tor tor, Ereignis ereignis);

int main(void)
{
    Ereignis ereignisse[TAKTE] =
    {
        EREIGNIS_TASTER, EREIGNIS_KEINES, EREIGNIS_ENDE_OBEN, EREIGNIS_KEINES, EREIGNIS_TASTER,
        EREIGNIS_KEINES, EREIGNIS_HINDERNIS, EREIGNIS_ENDE_OBEN, EREIGNIS_TASTER, EREIGNIS_ENDE_UNTEN
    };
    Tor tor = TOR_ZU;

    for (int takt = 0; takt < TAKTE; takt++)
    {
        printf("Takt %d: ", takt);
        torAusgeben(tor);
        tor = naechsterZustand(tor, ereignisse[takt]);
    }

    system("pause");

    return 0;
}

void torAusgeben(Tor tor)
{
    // TODO: Statt der Zahl soll hier der Zustand als Text ausgegeben werden
    //       (Zu, Oeffnet, Offen, Schliesst).
    printf("Zustand %d\n", tor);
}

Tor naechsterZustand(Tor tor, Ereignis ereignis)
{
    switch (tor)
    {
        case TOR_ZU:
            if (ereignis == EREIGNIS_TASTER)
                return TOR_OEFFNET;
            return TOR_ZU;
        case TOR_OEFFNET:
            if (ereignis == EREIGNIS_ENDE_OBEN)
                return TOR_OFFEN;
            return TOR_OEFFNET;
        case TOR_OFFEN:
            // TODO: Mit dem Taster wird das Tor geschlossen.
            return TOR_OFFEN;
        case TOR_SCHLIESST:
            // TODO: Der untere Endschalter meldet "zu". Ein Hindernis laesst das
            //       Tor wieder oeffnen.
            return TOR_SCHLIESST;
        default:
            return TOR_ZU;
    }
}
