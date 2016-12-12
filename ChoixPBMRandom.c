#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>    //permet d'utiliser srand() et rand()

int main(void)

{
    int nombre_aleatoire;
    int nombre;

    srand(time(NULL));      //initialisation de rand
    nombre_aleatoire = rand();    //nombre_aleatoire prend la valeur d'un nombre aleatoire grace a la fonction rand()
    nombre = nombre_aleatoire %3;    //on souhaite un nombre aleatoire de 5 valeurs possible, on utilise donc modulo 5
    printf("%d\n", nombre);        //on verifie la valeur du nombre aleatoire avec un printf

    char *programme[] = {"statique.c","dynamique.c","interactif.c", NULL};//on stock le nom des programmes dans un tableau char

    system("clear"); //Vide la console avant de lancer les autres programmes
    if (nombre == 0)

    {                        //selon la valeur du nombre aleatoire
        execv("./statique", programme);        //on execute la commande permettant de lancer un programme
    }                        //le nom de ce programme est stocke dans le tableau char

    else if (nombre == 1)

    {
        execv("./dynamique", programme);
    }

    else if (nombre == 2)

    {
        execv("./interactif", programme);
    }

}
