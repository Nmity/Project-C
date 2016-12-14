#include <stdio.h>
#include <stdlib.h>
#include <string.h> // bibliothèque pour l'utilisation des différentes fonctions de traitement de chaîne de caractères
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "conio.h"

#ifndef STATIQUE_H_INCLUDED
#define STATIQUE_H_INCLUDED

typedef struct Pbm Pbm; // on remplace "struct Pbm" par "Pbm" pour raccourcir le code
void lireResolution(char *fichier, Pbm* p); // permet de stocker la résolution de notre image
void insererImageCentreeDansTableau(char *fichier, Pbm* p, int tableauPourImage[80][24]); // permet de charger l'image dans le tableau à deux dimensions tout en la centrant
void afficherTableau(int tableauPourImage[80][24]); // va nous permettre d'afficher le tableau 2D
void effacerEtImmobiliser();

#endif // STATIQUE_H_INCLUDED
