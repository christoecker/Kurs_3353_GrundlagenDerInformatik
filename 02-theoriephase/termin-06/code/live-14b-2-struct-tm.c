#define _CRT_SECURE_NO_WARNINGS // (1)!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t jetzt = time(NULL); // (2)!
    struct tm *lokal = localtime(&jetzt); // (3)!

    printf("Datum: %02d.%02d.%d\n", lokal->tm_mday, lokal->tm_mon + 1, lokal->tm_year + 1900); // (4)!
    printf("Uhrzeit: %02d:%02d:%02d\n", lokal->tm_hour, lokal->tm_min, lokal->tm_sec);

    system("pause");

    return 0;
}
