#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    fichier = fopen("historique.txt", "a");
    int  choixAffichage, caractereActuel = 0;
    if (fichier != NULL)
    {
        fputs ("Date : \n", fichier);
        fputs ("Heure : %d\n", fichier);
        fputs ("ScreenSaver utilisé : \n", fichier);

    }

    else
    {
        printf("Le fichier historique.txt a rencontré un problème\n");
    }


    printf("Voulez vous consulter l'historique?\n");
    printf("1. Oui\n");
    printf("2. Non\n");
    scanf("%d", &choixAffichage);

    do
    {
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
    }

    while (choixAffichage != 1 || 2);



    return 0;
}
