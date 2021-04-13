#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct 
{
SDL_Surface *equationtexte,*scoretexte,*str1texte,*str2texte,*str3texte;
SDL_Rect positionenigme,positionscore,position1,position2,position3;
SDL_Color couleurNoire; 
TTF_Font* police;
char str[20],str1[20],str2[20],str3[20],strscore[20];
int a,b,c,score,val;
float x,x1,x2;
}enigme;
void initialiserEnigme(enigme *e);
void afficherenigme(enigme e,SDL_Surface *screen,int continuer);
void genererEnigme(enigme *e);
void updateEnigme(enigme *e, int *input);
#endif
