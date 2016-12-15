#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FRANCE +1
#include <string.h>
#include <unistd.h>
#include "conio.h"

void afficherHeureHorloge()
{
    int i, j;
    time_t temps;
    struct tm date;

    time(&temps);
    date = *gmtime(&temps);
    for(j=0; j<11; j++)
    {
        printf("\n");
    }

    for(i=0; i<37; i++)
    {
        printf(" ");
    }
    printf("%d:%d:%d\n",(date.tm_hour+FRANCE+24)%24, date.tm_min, date.tm_sec);

}

void afficherPhraseAActualiser()
{
    int j= 0, k;
    char* str = getenv("EXIASAVER2_SLEEP");

    //str = NULL; //pour tester si le else fonctionne correctement

    char dodo[2];

    if(str != NULL)
        strcpy(dodo, str);

    else
    strcpy(dodo, "10");

    int n = atoi(dodo);

    for(k=0; k<11; k++)
    {
        printf("\n");
    }

    printf("L'heure va etre actualisée dans quelques secondes");

    fflush(stdout);

    while (j<n)
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
        system("clear");
        afficherHeureHorloge();
        afficherPhraseAActualiser();
    }

    system("clear");
    return 0;
}
