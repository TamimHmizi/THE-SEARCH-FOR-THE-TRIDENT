#ifndef FONCTIONS_H_
#define FONCTIONS_H_

typedef struct Background
{

SDL_Surface *background;
SDL_Rect scrolling;

}Background;

void Chargermap(Background *b);
void afficherBackground(Background *b, SDL_Surface *ecran);
void Scrolling(Background *b, int sens_deplacement);


#endif

