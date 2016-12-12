#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FRANCE +1


void afficherHeureHorloge()
{
    time_t temps;
    struct tm date;

    time(&temps);
    date = *gmtime(&temps);
    printf(" %d:%d:%d\n",(date.tm_hour+FRANCE+24)%24, date.tm_min, date.tm_sec);
}

void afficherPhraseAActualiser()
{
    int j =0;

    printf("L'heure va etre actualisée dans quelques secondes");

    fflush(stdout);

    while (j<5)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
        j++;
    }

}

int main()
{

    while (1)

    {
        afficherHeureHorloge();
        afficherPhraseAActualiser();
        system("clear");
    }


    return 0;
}
