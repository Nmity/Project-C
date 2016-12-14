#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int choixMenu;
    char lecture[50];
    FILE* fichierHistorique = NULL;

    do
    {
        printf("                                  === MENU ===\n\n1. Consulter l'historique\n\n2. Quitter le programme\n\nQue voulez-vous faire? ");
        scanf("%d", &choixMenu);

        switch(choixMenu)
        {
        case 1:
            fichierHistorique = fopen("historique.txt", "a+");

            system("clear");
            printf("                              ==== HISTORIQUE ===\n\n");
            /*do
            {
                fgets(lecture, 50, fichierHistorique);
                printf("%s", lecture);
            }
            while(fgets(lecture, 50, fichierHistorique) != NULL);*/
            while(fgets(lecture, 50, fichierHistorique) != NULL)
            {
                printf("%s", lecture);
            }


            fclose(fichierHistorique);
            break;
        case 2:
            system("clear");
            exit(0);
            break;
        default:
            system("clear");
            printf("Vous vous etes trompe\n\n");
            break;
        };
    }while (choixMenu != 1 || choixMenu != 2);

    return 0;
}
