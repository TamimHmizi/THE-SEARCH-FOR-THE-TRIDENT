#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_Event.h>
#include <SDL/SDL_ttf.h>
#include "scroll.h"

void Chargermap(Background *b)
{

b->background = IMG_Load("map1.png");


b->scrolling.x=0;
b->scrolling.y=0;

myMus = Mix_LoadMUS ("SONG.mp3");

}

void afficherBackground(Background *b, SDL_Surface *ecran )
{

SDL_BlitSurface(b->background, NULL, ecran, &b->scrolling);

}

void Scrolling(Background *b, int sens_deplacement)
{
 if(SDLK_LEFT)
{
     b->scrolling.x--;
}
if(SDLK_RIGHT)
{
     b->scrolling.x++;
}
if(SDLK_UP)
{
     b->scrolling.y++;
}
if(SDLK_DOWN)
{
     b->scrolling.y--;
}
}

