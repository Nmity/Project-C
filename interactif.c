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
    /*int compteurX;
    int compteurY;*/
    char toucheClavier;

    Pbm image;
    Coordonnees position;

    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    FILE* fichier3 = NULL;
    FILE* fichier4 = NULL;

    fichier1 = fopen("/home/axel3098/Documents/Project-C/PBM_Interactif/AvionDroite.pbm", "r");
    fichier2 = fopen("/home/axel3098/Documents/Project-C/PBM_Interactif/AvionGauche.pbm", "r");
    fichier3 = fopen("/home/axel3098/Documents/Project-C/PBM_Interactif/AvionHaut.pbm", "r");
    fichier4 = fopen("/home/axel3098/Documents/Project-C/PBM_Interactif/AvionBas.pbm", "r");

    lireResolutionImage(fichier2, &image);
    chargerImageAvion(fichier2, &image, tableauAvion);
    integrerAvionDansCiel(tableauCiel, tableauAvion, &position);
    afficherTableauCiel(tableauCiel);

    /*fclose(fichier1);
    fclose(fichier1);
    fclose(fichier1);
    fclose(fichier1);*/

    while (1)
    {
        toucheClavier = getch();

        if (toucheClavier == 67) //Droite
        {
            fichier1 = fopen("/home/axel3098/Documents/Project-C/PBM_Interactif/AvionDroite.pbm", "r");
            system("clear");
            position.x++;
            //memset (tableauCiel, 0, sizeof (tableauCiel));
            clearTableauCiel(tableauCiel);
            lireResolutionImage(fichier1, &image);
            chargerImageAvion(fichier1, &image, tableauAvion);
            integrerAvionDansCiel(tableauCiel, tableauAvion, &position);
            afficherTableauCiel(tableauCiel);
            fclose(fichier1);
        }

        else if (toucheClavier == 68) //Gauche
        {
            fichier2 = fopen("/home/axel3098/Documents/Project-C/PBM_Interactif/AvionGauche.pbm", "r");
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
            fichier3 = fopen("/home/axel3098/Documents/Project-C/PBM_Interactif/AvionHaut.pbm", "r");
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
            fichier4 = fopen("/home/axel3098/Documents/Project-C/PBM_Interactif/AvionBas.pbm", "r");
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
        fgets(lecture, 30, fichier);
    }

    fscanf(fichier, "%d %d", &p->largeurImage, &p->longueurImage);
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
        }
    }
}

void clearTableauCiel(int tableauCiel[80][24])
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            tableauCiel[j][i] = 0;
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
            if (tableauCiel[j][i] == 0) // si la valeur du tableau est un 0, on va afficher "X"
            {
                printf(" ");
            }

            else // si la valeur n'est pas 0 dans le tableau, alors on affiche " " (espace)
            {
                printf("%s", c);
            }
        }
        printf("\n");
    }
}
