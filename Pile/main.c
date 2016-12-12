#include <stdio.h>
#include <stdlib.h>
#include "pile.c"

int main()
{
    int i, j, valeurDeLaPile, valeurADepiler, nombreDelements;

    Pile *maPile = initialiserlaPile();

    printf ("Quelle est la taille de votre pile?\n");
    scanf("%d", &nombreDelements);

    for (i=0; i<nombreDelements; i++)
    {
        printf("Valeur %d : ", i+1);
        scanf("%d", &valeurDeLaPile);
        emplierLaPile(maPile, valeurDeLaPile);
    }

    printf("\nVoila votre pile :\n");
    afficherLaPile(maPile);

    printf("Combien d'element voulez-vous depiler?\n"),
    scanf("%d", &valeurADepiler);

    for (j=0; j<valeurADepiler; j++)
    {
        depilerLaPile(maPile);
    }

    printf("\nVoila votre pile :\n");
    afficherLaPile(maPile);

    free(maPile);
    return 0;
}
