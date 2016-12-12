#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

//structure element
typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

//structure pile
typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};

//initialisation de la pile
Pile *initialiserlaPile()
{
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
}

//fonction emplier la pile
void emplierLaPile (Pile *pile, int nouveauNombre)
{
    Element *nouveau = malloc (sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau -> nombre = nouveauNombre;
    nouveau ->suivant = pile->premier;
    pile->premier = nouveau;
}

//fonction dépiler la pile
int depilerLaPile (Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier !=NULL)
    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }
    return nombreDepile;
}

//fonction afficher la pile
void afficherLaPile (Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("\n");
}
