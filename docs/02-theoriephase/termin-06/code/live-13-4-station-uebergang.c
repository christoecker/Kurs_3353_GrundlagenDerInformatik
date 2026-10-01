#include <stdio.h>
#include <stdlib.h>

typedef enum // (1)!
{
    ZUSTAND_INIT,
    ZUSTAND_WAITING,
    ZUSTAND_PROCESSING,
    ZUSTAND_ERROR
} Zustand;

typedef enum // (2)!
{
    EREIGNIS_KEINES,
    EREIGNIS_INIT_FERTIG,
    EREIGNIS_WERKSTUECK,
    EREIGNIS_FERTIG,
    EREIGNIS_STOERUNG,
    EREIGNIS_RESET
} Ereignis;

Zustand naechsterZustand(Zustand zustand, Ereignis ereignis);

int main(void)
{
    Zustand zustand = ZUSTAND_INIT;

    zustand = naechsterZustand(zustand, EREIGNIS_INIT_FERTIG); // (3)!
    zustand = naechsterZustand(zustand, EREIGNIS_WERKSTUECK);

    system("pause");

    return 0;
}

Zustand naechsterZustand(Zustand zustand, Ereignis ereignis)
{
    switch (zustand)
    {
        case ZUSTAND_INIT:
            printf("INIT: Station wird initialisiert\n"); // (4)!
            if (ereignis == EREIGNIS_INIT_FERTIG)
                return ZUSTAND_WAITING;
            return ZUSTAND_INIT;
        case ZUSTAND_WAITING:
            printf("WAITING: warte auf Werkstueck\n");
            if (ereignis == EREIGNIS_WERKSTUECK)
                return ZUSTAND_PROCESSING;
            return ZUSTAND_WAITING;
        case ZUSTAND_PROCESSING:
            printf("PROCESSING: bearbeite Werkstueck\n");
            if (ereignis == EREIGNIS_FERTIG)
                return ZUSTAND_WAITING;
            if (ereignis == EREIGNIS_STOERUNG)
                return ZUSTAND_ERROR;
            return ZUSTAND_PROCESSING;
        case ZUSTAND_ERROR:
            printf("ERROR: Stoerung, warte auf Reset\n");
            if (ereignis == EREIGNIS_RESET)
                return ZUSTAND_INIT;
            return ZUSTAND_ERROR;
        default: // (5)!
            return ZUSTAND_ERROR;
    }
}
