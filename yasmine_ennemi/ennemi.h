#ifndef ennemi_H_INCLUDED
#define ennemi_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct ennemi
	{
        SDL_Surface *image;
        SDL_Rect position;
        int direction;
        /*
        0 : gauche
        1 : droite
        2 : attack gauche
        3 : attack droite
        */
        SDL_Rect pos_sprite;

	}ennemi;

void initEnnemi(ennemi*e);
void afficherEnnemi(ennemi e, SDL_Surface * screen);
void animerEnnemi( ennemi * e);
void deplacer( ennemi * e);
int collisionBB( SDL_Rect E,  SDL_Rect p) ;





#endif // DS_H_INCLUDED
