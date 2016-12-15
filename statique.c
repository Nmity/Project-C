#include "statique.h"
#include "fonctionsStatique.c"

int main()
{
    struct dirent * ent;

    Pbm image; // "image" va contenir toutes nos variables situées dans la structure Pbm

    int tableauPourImage[80][24] = {0}; // on créer un tableau à deux dimensions rempli de 0

    char rep_pbm[1024];

    char* str = getenv("EXIASAVER1_PBM"); // getenv sert à stocker le chemin d'une variable environnement dans un char

    if(str != NULL)
        strcpy(rep_pbm, str);

    else
    {
        getcwd(rep_pbm, 1024);
    }

    DIR* rep = opendir(rep_pbm); // on ouvre le répertoire défini dans rep_pbm

    if(rep != NULL)
    {
        srand(time(NULL));
        int n = 0;
        int nbr = rand() % 5 + 1; // on fait un tirage au sort pour tirer une image pour l'écran statique

        while (n != nbr && (ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
            {
                n++;
            }
        }

        char chemin[255];
        strcpy(chemin, rep_pbm);
        strcat(chemin, ent->d_name);

        FILE* fichier = NULL;
        fichier = fopen(chemin, "r");

        if(fichier != NULL) // permet de s'assurer que le fichier s'est bien ouvert
        {
            //printf("Le fichier a bien été ouvert\n");
            lireResolution(fichier, &image); // cette fonction va permettre de stocker la résolution de l'image PBM
            //printf("Votre image a une résolution de : %dx%d\n\n", image.largeurImage, image.longueurImage); // ici on va stocker les deux entiers de résoltuion (longueur x largeur) dans les variables de notre structure Pbm
            insererImageCentreeDansTableau(fichier, &image, tableauPourImage); // cette fonction va nous permettre d'insérer le code de l'image PBM dans notre tableau à deux dimensions tout en centrant l'image
            fclose(fichier); // après avoir fini de manipuler le fichier, il faut fermer le fichier pour libérer la mémoire vive
        }
        else // permet de savoir si le fichier ne s'est pas ouvert
        {
            printf("Le fichier n'a pas été ouvert");
        }

        afficherTableau(tableauPourImage); // on va afficher le tableau à deux dimensions qui contient le code de l'image PBM, on va afficher un "X" quand la valeur est 0 et un " " quand la valeur est 1
        effacerEtImmobiliser();
        return 0;
    }

    else
    {
        perror("");
        return 0;
    }
}
