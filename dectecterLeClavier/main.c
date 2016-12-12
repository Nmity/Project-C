#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>


int main(int argc, int *argv[])
{
    int avion, directionDeLavion, *avionActuel, *positionAvion, *deplacerAvion;
    switch(directionDeLavion)
    {
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            continuer = 0;
            break;
        case SDLK_UP:
            avionActuel = avion[HAUT];
            deplacerAvion(carte, &positionAvion, HAUT);
            break;
        case SDLK_DOWN:
            avionActuel = avion[BAS];
            deplacerAvion(carte, &positionAvion, BAS);
            break;
        case SDLK_RIGHT:
            avionActuel = avion[DROITE];
            deplacerAvion(carte, &positionAvion, DROITE);
            break;
        case SDLK_LEFT:
            avionActuel = avion[GAUCHE];
            deplacerAvion(carte, &positionAvion, GAUCHE);
            break;
        }
        break;
    }
    return 0;
}
