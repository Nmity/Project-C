#ifndef STATIQUE_H_INCLUDED
#define STATIQUE_H_INCLUDED

void choixAleatoireImage(Pbm* p); // fonction qui va permettre de choisir un PBM aléatoirement
void lireResolution(char *fichier, Pbm* p); // permet de stocker la résolution de notre image
void insererImageCentreeDansTableau(char *fichier, Pbm* p, int tableauPourImage[80][24]); // permet de charger l'image dans le tableau à deux dimensions tout en la centrant
void afficherTableau(int tableauPourImage[80][24]); // va nous permettre d'afficher le tableau 2D
void effacerEtImmobiliser();
void choixAleatoireImage(Pbm* p); // "Pbm* p" est un pointeur sur la structure
void insererImageCentreeDansTableau(char *fichier, Pbm* p, int tableauPourImage[80][24]);
void lireResolution(char *fichier, Pbm* p);
void afficherTableau(int tableauPourImage[80][24]);
void effacerEtImmobiliser();



#endif // STATIQUE_H_INCLUDED
