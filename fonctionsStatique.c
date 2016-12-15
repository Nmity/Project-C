#include "statique.h"

typedef struct Pbm Pbm; // on remplace "struct Pbm" par "Pbm" pour raccourcir le code
struct Pbm              // définition de notre structure Pbm
{
    int largeurImage;   // ces deux int vont stocker la résolution de l'image
    int longueurImage;
    char chemin[255];
};

void insererImageCentreeDansTableau(char *fichier, Pbm* p, int tableauPourImage[80][24])
{
    char lectureLigneFichier[71] = ""; // on crée un char pour la lecture des lignes de fichier
    int binaireImagePBM; // variable qui permettra de stocker les différentes valeurs de code de l'image

    fgets(lectureLigneFichier, 71, fichier); // fgets permet de lire une ligne dans un fichier, ici fgets va nous permettre de passer la troisième ligne qui est inutile pour directement arrivé là où le code est définie

    while (fgets(lectureLigneFichier, 71, fichier) != NULL) // à partir d'ici, on va lire toutes le code de l'image jusqu'à la fin du fichier
    {
        for(int z = 0; z < p->longueurImage; z++) // boucle pour permettre de se positionner dans la première colonne
        {
            for(int k = 0; k < p->largeurImage; k++) // boucle pour lire toutes les données de la première ligne
            {
                fscanf(fichier, "%d", &binaireImagePBM); // on stocke l'entier lu dans notre variable "binaireImagePBM"
                //printf("%d", binaireImagePBM);
                tableauPourImage[k + ((80 - p->largeurImage)/2)][z + ((24 - p->longueurImage)/2)] = binaireImagePBM; // on stocke la valeur lue dans notre tableau 2D en partant d'un point précis pour centrer l'image grâc à un calcul
            }
            //printf("\n");
        }
    }
}

void lireResolution(char *fichier, Pbm* p) // fonction qui permet de stocker la résolution de l'image
{
    char lectureLigne[10] = ""; // char qui va permettre de stocker la ligne où est écrit la résoltuion de l'image

    for(int i = 0; i < 2; i++)
    {
        fgets(lectureLigne, 71, fichier); // on saute les deux premières lignes afin de se diriger directement là où est noté la résolution de l'image
    }
    fscanf(fichier, "%d %d", &p->largeurImage, &p->longueurImage); // on récupère les données de la résolution en les stockant dans les variables de notre structures
}

void afficherTableau(int tableauPourImage[80][24]) // fonction qui va afficher notre tableau 2D
{
	char c[] = {226, 150, 136, 0};

    for (int i = 0 ;i < 24; i++) // boucle qui va commencer par la première colonne puis la deuxième après qu'on ait fini de lire toutes les valeurs de la première colonne
    {
        for (int j = 0;j < 80; j++) // boucle qui va lire un par un les données de la première ligne du tableau jusqu'à la dernière valeur
        {
            if(tableauPourImage[j][i] == 0) // si la valeur du tableau est un 0, on va afficher "X"
            {
                printf(" ");
            }
            else // si la valeur n'est pas 0 dans le tableau, alors on affiche " " (espace)
            {
                printf("%s", c);
            }
        }
    }
}

void effacerEtImmobiliser()
{
    char touche; // va stocker le code d'une touche en char
    touche = getch(); // permet d'attendre la réponse d'une touche

    system("setterm -cursor off"); // permet de désactiver le curseur

    while(1)
    {
        if (touche) // 32 pour la barre espace
        {
            system("clear"); // fait un nettoyage de la console
            system("setterm -cursor on"); // réactive le curseur
            system("clear");
            exit(0);
        }
        else
        {
            touche = getch(); // on attends encore la bonne touche pour quitter le programme
        }
    }
}
