#include "historique.h"

void faireTriDeHistorique ()
{
    FILE* fichierHistorique = NULL;
    fichierHistorique = fopen ("historiqueTrie.txt", "w+"); //ouvrir le fichier et "w+" permet d'écrire par dessus les écritures précedentes
    system("sort -o historiqueTrie.txt historique.txt"); //permet de faire executer sort qui fait un tri par ordre alphabétique
    fclose(fichierHistorique); //ferme le fichier et libère la mémoire utilisée pou le fichier
    printf("Le tri a ete effectue\n");
    system("clear"); //appel systeme permettant d'effacer la console
}



void demandeDeLaffichageDeHistoriqueTrie ()
{
    int choixAfficherHistoriqueTrieOuNon;
    int compteur;
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
}



void affichageDesStatistiques ()
{
    int compteur;
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
}

