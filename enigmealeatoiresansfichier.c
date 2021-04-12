#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigmealeatoiresansfichier.h"
void initialiserEnigme(enigme *e)
{
e->police = TTF_OpenFont("Ubuntu-Bold.ttf", 20);

e->positionenigme.x =300;
e->positionenigme.y =10;

e->positionscore.x=300;
e->positionscore.y=50;


e->position1.x=300;
e->position1.y=100;

e->position2.x=300;
e->position2.y=200;

e->position3.x=300;
e->position3.y=300;

e->score=100;

}
void genererEnigme(enigme *e)
{

e->a= (rand() % 9) + 1;
e->b= (rand() % 9) + 1;
e->c= (rand() % 9) + 1;
e->x=(float) (e->c-e->b)/e->a;
e->x1=(float) e->x+3;
e->x2=(float) e->x-3;

  sprintf(e->str,"Equation:%d*x+%d=%d",e->a,e->b,e->c);
  e->equationtexte = TTF_RenderText_Blended(e->police,e->str, e->couleurNoire);   
  sprintf(e->strscore,"Score:%d",e->score);
    e->scoretexte = TTF_RenderText_Blended(e->police,e->strscore, e->couleurNoire);
    
    e->val=(rand() % 2) + 0;
    if(e->val==0)
    {
     sprintf(e->str1,"a->%.2f",e->x);
     sprintf(e->str2,"z->%.2f",e->x1);
     sprintf(e->str3,"e->%.2f",e->x2); 
    }
    else if (e->val==1)
    {
     sprintf(e->str1,"a->%.2f",e->x1);
     sprintf(e->str2,"z->%.2f",e->x);
     sprintf(e->str3,"e->%.2f",e->x2);    
    }
    else if (e->val==2)
    {
     sprintf(e->str1,"a->%.2f",e->x1);
     sprintf(e->str2,"z->%.2f",e->x2);
     sprintf(e->str3,"e->%.2f",e->x);  
    }
        e->str1texte = TTF_RenderText_Blended(e->police,e->str1, e->couleurNoire);
        e->str2texte = TTF_RenderText_Blended(e->police,e->str2, e->couleurNoire);
        e->str3texte = TTF_RenderText_Blended(e->police,e->str3, e->couleurNoire);
    
}
void afficherenigme(enigme e,SDL_Surface *screen,int continuer)
{

SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255,255,255)); 
SDL_BlitSurface(e.equationtexte,NULL,screen,&e.positionenigme);
SDL_BlitSurface(e.scoretexte,NULL,screen,&e.positionscore);
SDL_BlitSurface(e.str1texte, NULL,screen, &e.position1);
SDL_BlitSurface(e.str2texte, NULL,screen, &e.position2);
SDL_BlitSurface(e.str3texte, NULL,screen, &e.position3);
}


void updateEnigme(enigme *e, int *input)
{
if (*input ==11)
  {              if(e->val==0)
                {
                e->score+=20;
                }
                else
                {
                e->score-=20;           
                }
}
else if(*input ==12)
  {              
                if(e->val==1)
                {
                e->score+=20;
                }
                else
                {
                e->score-=20;             
                }    
 }            
else if (*input ==13)

    {            if(e->val==2)
                {
                 e->score+=20;
                }
                else
                {
                e->score-=20;            
                }                
        }
        *input=0;
}
