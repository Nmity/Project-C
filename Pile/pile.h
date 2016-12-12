#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

typedef struct Element Element;

typedef struct Pile Pile;

Pile *initialiserlaPile();

void emplierLaPile (Pile *pile, int nouveauNombre);

int depilerLaPile (Pile *pile);

void afficherLaPile (Pile *pile);

#endif // PILE_H_INCLUDED
