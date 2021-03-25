#ifndef benaoun_et3_Multijoueur_H_
#define benaoun_et3_Multijoueur_H_
#include <time.h>

typedef struct 
{
	SDL_Rect position_perso;
 	SDL_Surface *sprite;
}Personne;



typedef struct 
{
	SDL_Rect position_mini;
	SDL_Surface *sprite;
	Personne p ;
}minimap;



typedef struct temps
{
SDL_Surface *texte;
 SDL_Rect position;
  
    TTF_Font *police ;

 char entree[100];
 int secondesEcoulees;
SDL_Color couleurBlanche;
time_t t1,t2;
int min, sec;
}temps;









void initmap( minimap *m);
void afficherminimap (minimap m, SDL_Surface * screen);
void affichertemps (int * temps,SDL_Surface *screen);
int collisionPP( Personne p, SDL_Surface * Masque);


void initialiser_temps(temps *t);
void afficher_temps(temps *t,SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);


#endif