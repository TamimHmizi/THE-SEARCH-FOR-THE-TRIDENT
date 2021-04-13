#ifndef PERSO_H_
#define PERSO_H_

typedef struct 
{
	SDL_Surface *personnage_marche[14],*personnage_marche_gauche[14], *vie1, *vie2, *vie3, *personnage_saut[14];
	SDL_Rect position_marche,position_marche_gauche, position_vie1, position_vie2, position_vie3, position_saut ;
	int frame_droite,frame_gauche, direction,  vitesse, acceleration, up, seuil, position_initiale, frame_saut, update; 
	SDL_Event event;
}Personne;

void init(Personne *p, int numeroperso);
void afficherperso(Personne p , SDL_Surface *ecran);
void deplacerperso(Personne *p);
void animerperso(Personne *p);
void saut(Personne *p);
void update(Personne *p, int input);
void liberation(Personne *p);
#endif