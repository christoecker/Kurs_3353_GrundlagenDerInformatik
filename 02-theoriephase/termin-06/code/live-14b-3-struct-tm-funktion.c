#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void datumAusgeben(const struct tm *zeit); // (1)!
int istWochenende(const struct tm *zeit);

int main(void)
{
    time_t jetzt = time(NULL);
    struct tm *lokal = localtime(&jetzt);

    datumAusgeben(lokal); // (2)!

    if (istWochenende(lokal))
        printf("Heute ist Wochenende.\n");
    else
        printf("Heute ist ein Werktag.\n");

    system("pause");

    return 0;
}

void datumAusgeben(const struct tm *zeit)
{
    printf("Datum: %02d.%02d.%d\n", zeit->tm_mday, zeit->tm_mon + 1, zeit->tm_year + 1900);
    printf("Uhrzeit: %02d:%02d:%02d\n", zeit->tm_hour, zeit->tm_min, zeit->tm_sec);
}

int istWochenende(const struct tm *zeit)
{
    return zeit->tm_wday == 0 || zeit->tm_wday == 6; // (3)!
}
