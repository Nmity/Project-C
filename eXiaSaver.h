#include <stdio.h> // pour l'affichage sur l'écran avec printf()
#include <stdlib.h> // pour les constantes EXIT_SUCCESS et EXIT_FAILURE
#include <unistd.h> // pour fork()
#include <time.h>    //permet d'utiliser srand() et rand()
#include <string.h> // pour la gestion des chaîne de caractères
#include <sys/wait.h> // pour wait()
#include <sys/types.h> // pour le type pid_t
#include <errno.h> // pour perror() et errno


#ifndef EXIASAVER_H_INCLUDED
#define EXIASAVER_H_INCLUDED

typedef struct Aleatoire Aleatoire;
void fonctionAleatoire(Aleatoire* p);
void ouvrirProgrammeHistorique(char* nomArgv);
void executerEcranStatique(char* nomArgv);
void executerEcranDynamique();
void executerEcranInteractif();

#endif // EXIASAVER_H_INCLUDED
