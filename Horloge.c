#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FRANCE +1
#include <string.h>
#include <unistd.h>

void afficherHeureHorloge()
{
    time_t temps;
    struct tm date;

    time(&temps);
    date = *gmtime(&temps);
    printf("%d:%d:%d\n",(date.tm_hour+FRANCE+24)%24, date.tm_min, date.tm_sec);
}

void afficherPhraseAActualiser()
{
    int j = 0;
    char* str = getenv("EXIASAVER2_SLEEP");

    //str = NULL; //pour tester si le else fonctionne correctement

    char dodo[2];

    if(str != NULL)
        strcpy(dodo, str);

    else
    strcpy(dodo, "10");

    int n = atoi(dodo);
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
        afficherHeureHorloge();
        afficherPhraseAActualiser();
        system("clear");
    }


    return 0;
}
