#include <stdio.h>
#include <stdlib.h>

void faireTriDeHistorique ()
{
    FILE* fichierHistorique = NULL;
    fichierHistorique = fopen ("historiqueTrie.txt", "w+"); //ouvrir le fichier et "w+" permet d'écrire par dessus les écritures précedentes
    system("sort -o historiqueTrie.txt historique.txt"); //permet de faire executer sort qui fait un tri par ordre alphabétique
    fclose(fichierHistorique); //ferme le fichier et libère la mémoire utilisée pou le fichier
    printf("Le tri a ete effectue\n");
    system("clear"); //appel systeme permettant d'effacer la console
}




int main(int argc, char* argv[])
{
    int choixMenu, choixTriOuNon;
    char lecture[50];
    int compteur;
    FILE* fichierHistorique = NULL;

    do
    {
        printf("                                  === MENU ===\n\n1. Consulter l'historique\n\n2. Afficher les statistiques\n\n3. Quitter le programme\n\nQue voulez-vous faire? ");
        scanf("%d", &choixMenu);

        switch(choixMenu)
        {
        case 1:
            fichierHistorique = fopen("historique.txt", "a+");

            system("clear");//appel systeme permettant d'effacer la console
            printf("                              ==== HISTORIQUE ===\n\n");

            while(fgets(lecture, 50, fichierHistorique) != NULL)
            {
                printf("%s", lecture);
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


    int choixAfficherHistoriqueTrieOuNon;
    printf("                                  === MENU ===\n\n1. Consulter l'historique trie\n\n2. Quitter le programme\n\n");
    scanf ("%d", &choixAfficherHistoriqueTrieOuNon);

    if (choixAfficherHistoriqueTrieOuNon == 1)//si la réponse de l'utilisateur est 1 (oui)
    {
        system("clear");//appel systeme permettant d'effacer la console
        FILE* fichierHistorique = NULL;
        char lecture[50];
        fichierHistorique = fopen ("historiqueTrie.txt", "r"); //permet de lire le fichier historiqueTrie.txt

        if (fichierHistorique != NULL)//si le fichier historique
        {
            printf("                              ==== HISTORIQUE TRIE ===\n\n");
            while(fgets(lecture, 50, fichierHistorique) != NULL)
            {
                printf("%s", lecture);
                compteur++;
            }
            fclose(fichierHistorique);//permet de fermer le fichier ouvert ainsi que libérer la mémoire allouer pour celui ci
            printf("\nL'eXiaSaver a été lancé %d fois au total\n\n", compteur);
        }
    }

    int choixAfficherStatistiquesTrieOuNon;
    printf("                                  === MENU ===\n\n1. Consulter statistiques\n\n2. Quitter le programme\n\n");
    scanf ("%d", &choixAfficherStatistiquesTrieOuNon);

    if (choixAfficherStatistiquesTrieOuNon == 1)
    {
        system("clear");//appel systeme permettant d'effacer la console
        printf("L'ecran statique a ete utilise .. fois, qui correspond a ... pourcent du total\n");
        printf("L'ecran dynamique a ete utilise .. fois, qui correspond a ... pourcent du total\n");
        printf("L'ecran interactif a ete utilise .. fois, qui correspond a ... pourcent du total\n");
        printf("\nL'eXiaSaver a été lancé %d fois au total\n\n", compteur);
        exit(0);
    }


    else if (choixAfficherStatistiquesTrieOuNon == 2)
    {
        printf("Les statistiques ne seront pas affichees\n");
        exit(0);
    }
            break;
        case 2:
            system("clear");//appel systeme permettant d'effacer la console
            printf("L'ecran statique a ete utilise .. fois, qui correspond a ... pourcent du total\n");
            printf("L'ecran dynamique a ete utilise .. fois, qui correspond a ... pourcent du total\n");
            printf("L'ecran interactif a ete utilise .. fois, qui correspond a ... pourcent du total\n");
            system("clear");
        FILE* fichierHistorique = NULL;
        char lecture[50];
        fichierHistorique = fopen ("historiqueTrie.txt", "r"); //permet de lire le fichier historiqueTrie.txt

        if (fichierHistorique != NULL)//si le fichier historique
        {
            while(fgets(lecture, 50, fichierHistorique) != NULL)
            {
                //printf("%s", lecture);
                compteur++;
            }
            fclose(fichierHistorique);//permet de fermer le fichier ouvert ainsi que libérer la mémoire allouer pour celui ci
            printf("\nL'eXiaSaver a été lancé %d fois au total\n\n", compteur);
        }
            exit(0);
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
    while (choixMenu != 1 || choixMenu != 2);

    return 0;
}
