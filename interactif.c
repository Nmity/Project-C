#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "conio.h"

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x;
    int y;
};

typedef struct Pbm Pbm;
struct Pbm
{
    int largeurImage;
    int longueurImage;
    char nomFichier[100];
};

int main()
{
    int tableauCiel[80][24] = {0};
    int tableauAvion[10][10] = {0};
    char toucheClavier;

    Pbm image;
    Coordonnees position;

    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    FILE* fichier3 = NULL;
    FILE* fichier4 = NULL;

    fichier1 = fopen("/home/mobeestone/Project-C/PBM_Interactif/AvionDroite.pbm", "r");
    fichier2 = fopen("/home/mobeestone/Project-C/PBM_Interactif/AvionGauche.pbm", "r");
    fichier3 = fopen("/home/mobeestone/Project-C/PBM_Interactif/AvionHaut.pbm", "r");
    fichier4 = fopen("/home/mobeestone/Project-C/PBM_Interactif/AvionBas.pbm", "r");

    lireResolutionImage(fichier2, &image); //nous allons stocker la résolution e l'image qui est stocké dans le PBM
    chargerImageAvion(fichier2, &image, tableauAvion); // on va ensuite charger l'avion dans un petit tableau 2D
    integrerAvionDansCiel(tableauCiel, tableauAvion, &position); // on écrit le tableau 2D de l'avion dans le tableau 2D du ciel en commençant à un endroit précis
    afficherTableauCiel(tableauCiel); // puis on affiche notre ciel

    /*fclose(fichier1);
    fclose(fichier1);
    fclose(fichier1);
    fclose(fichier1);*/

    while (1)
    {
        toucheClavier = getch(); // on attend une entrée de touche

        if (toucheClavier == 67) //Droite
        {
            fichier1 = fopen("/home/mobeestone/Project-C/PBM_Interactif/AvionDroite.pbm", "r"); // on va charger l'image pour l'avion qui va à droite
            system("clear");
            position.x++;
            //memset (tableauCiel, 0, sizeof (tableauCiel));
            clearTableauCiel(tableauCiel); // on réinitialise le tableau2D du ciel à 0
            lireResolutionImage(fichier1, &image); // on stocke la résolution de la nouvelle image
            chargerImageAvion(fichier1, &image, tableauAvion); // on le met dans un petit tableau 2D
            integrerAvionDansCiel(tableauCiel, tableauAvion, &position); // on le stocke dans le ciel à un autre endroit déterminé pour simuler le déplacement
            afficherTableauCiel(tableauCiel); // et enfin on afficher le ciel contenant l'avion
            fclose(fichier1);
        }

        else if (toucheClavier == 68) //Gauche
        {
            fichier2 = fopen("/home/mobeestone/Project-C/PBM_Interactif/AvionGauche.pbm", "r");
            system("clear");
            position.x--;
            position.x = (position.x + 80) %80;
            //memset (tableauCiel, 0, sizeof (tableauCiel));
            clearTableauCiel(tableauCiel);
            lireResolutionImage(fichier2, &image);
            chargerImageAvion(fichier2, &image, tableauAvion);
            integrerAvionDansCiel(tableauCiel, tableauAvion, &position);
            afficherTableauCiel(tableauCiel);
            fclose(fichier2);
        }

        else if (toucheClavier == 65) //Haut
        {
            fichier3 = fopen("/home/mobeestone/Project-C/PBM_Interactif/AvionHaut.pbm", "r");
            system("clear");
            position.y--;
            //memset (tableauCiel, 0, sizeof (tableauCiel));
            clearTableauCiel(tableauCiel);
            lireResolutionImage(fichier3, &image);
            chargerImageAvion(fichier3, &image, tableauAvion);
            integrerAvionDansCiel(tableauCiel, tableauAvion, &position);
            afficherTableauCiel(tableauCiel);
            fclose(fichier3);
        }

        else if (toucheClavier == 66) //Bas
        {
            fichier4 = fopen("/home/mobeestone/Project-C/PBM_Interactif/AvionBas.pbm", "r");
            system("clear");
            position.y++;
            //memset (tableauCiel, 0, sizeof (tableauCiel));
            clearTableauCiel(tableauCiel);
            lireResolutionImage(fichier4, &image);
            chargerImageAvion(fichier4, &image, tableauAvion);
            integrerAvionDansCiel(tableauCiel, tableauAvion, &position);
            afficherTableauCiel(tableauCiel);
            fclose(fichier4);
        }

        else if (toucheClavier == 32)
        {
            system("clear");
            exit(0);
        }
    }

    return 0;
}

void lireResolutionImage (char *fichier, Pbm* p)
{
    char lecture[30] = "";

    for (int i = 0; i < 2; i++)
    {
        fgets(lecture, 30, fichier); // on saute les 2 premières lignes qui nous servent à rien
    }

    fscanf(fichier, "%d %d", &p->largeurImage, &p->longueurImage); // on stocke la résoltion de l'image dans des variables situées dans une structure
}

void chargerImageAvion(char *fichier, Pbm* p, int tableauAvion[10][10])
{
    char lectureLigneFichier[71] = "";
    int binaireImagePBM;

    while (fgets(lectureLigneFichier, 71, fichier) != NULL)// à partir d'ici, on va lire toutes le code de l'image jusqu'à la fin du fichier
    {
        for (int z = 0; z < p->longueurImage; z++) // boucle pour permettre de se positionner dans la première colonne
        {
            for (int k = 0; k < p->largeurImage; k++) // boucle pour lire toutes les données de la première ligne
            {
                fscanf(fichier, "%d ", &binaireImagePBM); // on stocke l'entier lu dans notre variable "binaireImagePBM"
                tableauAvion[k][z] = binaireImagePBM; // on stocke la valeur lue dans notre tableau 2D en partant d'un point précis pour centrer l'image grâc à un calcul
            }
        }
    }
}

void integrerAvionDansCiel(int tableauCiel[80][24], int tableauAvion[10][10], Coordonnees* pos)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0;j < 10; j++)
        {
            tableauCiel[j + (pos->x)%80][i + (pos->y)%24] = tableauAvion[j][i];
        } // on stocke l'avion dans le ciel à un endroite précis et on met un modulo pour qu'il puisse ressortir de l'autre côté du tableau
    }
}

void clearTableauCiel(int tableauCiel[80][24])
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            tableauCiel[j][i] = 0; // on remet les cases du ciel à 0
        }
    }
}

void afficherTableauCiel(int tableauCiel[80][24])
{
    char c[] = {226, 150, 136, 0};

    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            if (tableauCiel[j][i] == 0) // si la valeur du tableau est un 0, on va afficher " " (espace = case noire)
            {
                printf(" ");
            }

            else // si la valeur n'est pas 0 dans le tableau, alors on affiche " " (ASCII = case blanche)
            {
                printf("%s", c);
            }
        }
        printf("\n");
    }
}
