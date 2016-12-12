#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char *argv[])
{

    FILE* fichier = NULL;
    fichier = fopen("historique.txt", "a");
    int  choixAffichage, caractereActuel = 0;
    time_t t;
    struct tm ;
    t = time(NULL);

    if (fichier != NULL)
    {
        fprintf(fichier, "Date et heure : %s\n", ctime(&t));
        fputs("ScreenSaver utilisé : \n\n", fichier);

    }

    else
    {
        printf("Le fichier historique.txt a rencontré un problème\n");
    }


    printf("Voulez vous consulter l'historique?\n");
    printf("1. Oui\n");
    printf("2. Non\n");
    scanf("%d", &choixAffichage);
    printf("\n");

    switch(choixAffichage)
    {
    case 1:
        fichier = fopen("historique.txt", "r");

        if (fichier != NULL)
        {
            do
            {
                caractereActuel = fgetc(fichier);
                printf("%c", caractereActuel);

            }
            while(caractereActuel != EOF);
            {
                fclose(fichier);
            }
        }
        break;

    case 2:
        printf("L'historique ne sera pas consulté\n");
        break;

    default :
        printf ("Veuillez choisir une des deux options qui vous sont proposés\n");
        break;
    }

    return 0;
}
