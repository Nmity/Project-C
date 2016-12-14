#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//#include ""

int historique()
{

    FILE* fichierDeHistorique = NULL;
    fichierDeHistorique = fopen("historique.txt", "a");
    int  choixAffichage, typeDeScreenSaver, screenSaverUtilise, caractereActuel = 0;
    time_t t;
    struct tm ;
    t = time(NULL);

    if (fichierDeHistorique != NULL)
    {
        fprintf(fichierDeHistorique, "Date et heure : %s", ctime(&t));

        if (screenSaverUtilise == 0)
        {
            fprintf(fichierDeHistorique, "Ecran statique");
            fprintf(fichierDeHistorique, ";%c");
        }

        if (screenSaverUtilise == 1)
        {
            fprintf(fichierDeHistorique, "Ecran dynamique\n");
        }

        if (screenSaverUtilise == 2)
        {
            fprintf(fichierDeHistorique, "Ecran interactif\n");
        }
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
        fichierDeHistorique = fopen("historique.txt", "r");

        if (fichierDeHistorique != NULL)
        {
            do
            {
                caractereActuel = fgetc(fichierDeHistorique);
                printf("%c", caractereActuel);

            }
            while(caractereActuel != EOF);
            {
                fclose(fichierDeHistorique);
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
