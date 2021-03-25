#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "benaoun_et3_Multijoueur.h"


void initmap( minimap *m)
{
	m->position_mini.x=10;
	m->position_mini.y=0;
	m->p.position_perso.x=10;
	m->p.position_perso.y=100;
	m->p.sprite=NULL;
	m->sprite=NULL;
}
void afficherminimap (minimap m, SDL_Surface * screen)
{
	m.sprite=IMG_Load("map2.png");
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
    m.p.sprite=IMG_Load("1r1.png");
    SDL_BlitSurface(m.p.sprite, NULL, screen, &m.p.position_perso);

}

void initialiser_temps(temps *t)
{
 t->texte = NULL;
 t->position.x=400;
   t->position.y=300;
     t->police = NULL;
  t->police = TTF_OpenFont("avocado.ttf", 40);
    strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1));	 //temps du debut
}


void afficher_temps(temps *t,SDL_Surface *screen)
{	
SDL_Color couleurBlanche= {255, 255,255};

    	time(&(t->t2));// temps actuel

		t->secondesEcoulees = t->t2 - t->t1;

        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);
	 sprintf(t->entree,"%02d:%02d",t->min,t->sec);
	 //printf("%02d : %02d \n", t->min,t->sec);
	 
        t->texte = TTF_RenderText_Blended(t->police,t->entree, couleurBlanche);
        //printf("temps=%s   \n",t->entree);// sauvegarde dans le fichier 
      

SDL_BlitSurface(t->texte, NULL, screen, &(t->position)); /* Blit du texte */
 
 
	
}

void free_temps(temps *t,SDL_Surface *screen)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->police);
}







void affichertemps (int * temps,SDL_Surface *screen)
{
	
}
int collisionPP( Personne p, SDL_Surface * Masque)
{
	
}