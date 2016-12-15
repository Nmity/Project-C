#include "historique.h"
#include "fonctionsHistorique.c"


int main(int argc, char* argv[])
{
    int choixMenu, choixTriOuNon;
    char lecture[50];
    FILE* fichierHistorique = NULL;

    do
    {
        printf("                                  === MENU ===\n\n1. Consulter l'historique\n\n2. Afficher les statistiques\n\n3. Quitter le programme\n\nQue voulez-vous faire? ");
        scanf("%d", &choixMenu);
        switch(choixMenu) // choix du menu
        {
        case 1:
            fichierHistorique = fopen("historique.txt", "a+"); // on ouvre le fichier historique

            system("clear");//appel systeme permettant d'effacer la console
            printf("                              ==== HISTORIQUE ===\n\n");

            while(fgets(lecture, 50, fichierHistorique) != NULL)
            {
                printf("%s", lecture); // on lit toutes les lignes du fichier jusqu'à la fin
            }

            fclose(fichierHistorique);

            printf("                                  === MENU ===\n\n1. Trier l'historique\n\n2. Ne pas trier l'historique et fermer le programme\n\nQue voulez-vous faire? ");
            scanf ("%d", &choixTriOuNon);

            if (choixTriOuNon == 1)
            {
                faireTriDeHistorique ();
            }
            else if (choixTriOuNon == 2)
            {
                printf("Le tri n'est pas effectué\n");
                exit(0);
            }

            demandeDeLaffichageDeHistoriqueTrie();
            exit(0);
            break;
        case 2:
            affichageDesStatistiques ();
        case 3:
            system("clear");//appel systeme permettant d'effacer la console
            exit(0);
            break;
        default:
            system("clear");//appel systeme permettant d'effacer la console
            printf("Vous vous etes trompe\n\n");
            break;
        };
    }
    while (choixMenu != 1 || choixMenu != 2); // on reste dans la boucle tant que les touches ne sont pas utilisées

    return 0;
}
