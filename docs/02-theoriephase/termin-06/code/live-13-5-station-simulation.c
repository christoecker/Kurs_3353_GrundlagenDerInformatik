#include <stdio.h>
#include <stdlib.h>

#define TAKTE 8 // (1)!

typedef enum
{
    ZUSTAND_INIT,
    ZUSTAND_WAITING,
    ZUSTAND_PROCESSING,
    ZUSTAND_ERROR
} Zustand;

typedef enum
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
    Ereignis ereignisse[TAKTE] = // (2)!
    {
        EREIGNIS_KEINES, EREIGNIS_INIT_FERTIG, EREIGNIS_WERKSTUECK, EREIGNIS_FERTIG,
        EREIGNIS_WERKSTUECK, EREIGNIS_STOERUNG, EREIGNIS_RESET, EREIGNIS_INIT_FERTIG
    };
    Zustand zustand = ZUSTAND_INIT;

    for (int takt = 0; takt < TAKTE; takt++)
    {
        printf("Takt %d: ", takt);
        zustand = naechsterZustand(zustand, ereignisse[takt]); // (3)!
    }

    system("pause");

    return 0;
}

Zustand naechsterZustand(Zustand zustand, Ereignis ereignis)
{
    switch (zustand)
    {
        case ZUSTAND_INIT:
            printf("INIT: Station wird initialisiert\n");
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
        default:
            return ZUSTAND_ERROR;
    }
}
