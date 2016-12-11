#include <stdlib.h>
#include <stdio.h>

#define NOMBRE_LIGNE_CONSOLE 80
#define NOMBRE_COLONNE_CONSOLE 24
#define TAILLE_NOM_FICHIER 1000
#define TAILLE_LECTURE_FICHIER_PBM 70

int main()
{
    int tableauDeuxDimensions[][NOMBRE_LIGNE_CONSOLE] = {[NOMBRE_COLONNE_CONSOLE]= {0}};
    char fichierChoisi[TAILLE_NOM_FICHIER] = "j.pbm";

    afficherTableau(tableauDeuxDimensions);
    ouvertureFichier(fichierChoisi);

    return 0;
}

void ouvertureFichier(char *fichierChoisi)
{
    char nomFichier[TAILLE_NOM_FICHIER];
    FILE* fichier = NULL;

    sprintf(nomFichier,"%s", fichierChoisi);
    fichier = fopen(nomFichier, "r");

    if(fichier != NULL)
    {
        printf("Le fichier a bien été ouvert\n");
        lectureFichier(fichier);
        fclose(fichier);
    }
    else
    {
        printf("Le fichier n'a pas été ouvert");
    }

}

void afficherTableau(int tableauDeuxDimensions[NOMBRE_COLONNE_CONSOLE][NOMBRE_LIGNE_CONSOLE])
{
    for (int i = 0 ;i < NOMBRE_LIGNE_CONSOLE; i++)
    {
        for (int j = 0;j < NOMBRE_COLONNE_CONSOLE; j++)
        {
            printf("%d ", tableauDeuxDimensions[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void lectureFichier(char *fichier)
{
    char chaine[TAILLE_LECTURE_FICHIER_PBM] = "";

    for (int i = 0; i < 3; i++)
    {
        fgets(chaine, TAILLE_LECTURE_FICHIER_PBM, fichier);
    }

    while (fgets(chaine, TAILLE_LECTURE_FICHIER_PBM, fichier) != NULL)
    {
        printf("%s", chaine);
    }
}

