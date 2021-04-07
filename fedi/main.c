#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "benaoun_et3_Multijoueur.h"


int main()
{
	int collision ,distance =100 ;
    SDL_Event event;
	minimap m;
    Personne p , pM , pMprochaine;
	temps t;
	SDL_Surface *screen = NULL,*imageDeFond=NULL , *masked=NULL;
	SDL_Rect position_BG ;
   int longueurM=6268 , largeurM=800 , longueur =1254 , largeur=160;
	screen = SDL_SetVideoMode(1600, 800 , 32, SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	TTF_Init();
    if(screen==NULL)
    	{
        	printf("ERREUR: %s\n", SDL_GetError());
        	return 1;
       }


position_BG.x=0;
position_BG.y=0;

	imageDeFond = IMG_Load("map1.png");
       int continuer= 1;
       initmap( &m);
       initialiser_temps(&t);

       masked=IMG_Load("map1_masked.png");

    p.sprite=IMG_Load("1r1.png");
    p.position_perso.x=100;
    p.position_perso.y=50;



    pM.sprite=IMG_Load("1r1.png");
    pM.position_perso.x=0;
    pM.position_perso.y=300;

    pMprochaine.position_perso.x=pM.position_perso.x;
    pMprochaine.position_perso.y=pM.position_perso.y;
    
	while (continuer)
{
	

    SDL_BlitSurface(imageDeFond, NULL, screen, &position_BG);
	afficherminimap ( m,screen);
    SDL_BlitSurface(p.sprite, NULL, screen, &p.position_perso);
    SDL_BlitSurface(pM.sprite, NULL, screen, &pM.position_perso);
	afficher_temps(&t,screen);


    //mapCollision(Hero *entity);
	while(SDL_PollEvent(&event))
	{
     switch(event.type)
    {
            case SDL_QUIT:
                continuer = 0;
        break ;
        case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                	case SDLK_ESCAPE:
                            continuer = 0;
             		break;
                	case SDLK_RIGHT :
                    pMprochaine.position_perso.x+=distance;
                    if(collisionPP( pMprochaine, masked)==0)
                    {
                		update(&pMprochaine.position_perso , &pM.position_perso,&p.position_perso,distance,longueur,longueurM);
                    }
                    else{
                        pMprochaine.position_perso.x=pM.position_perso.x;
                    } 
                	break;

                	case SDLK_LEFT :
                    pMprochaine.position_perso.x-=distance;
                    if(collisionPP( pMprochaine, masked)==0)
                    {
                        pM.position_perso.x=pMprochaine.position_perso.x;
                        p.position_perso.x-=distance*longueur/longueurM;
                    }
                    else{
                        pMprochaine.position_perso.x=pM.position_perso.x;
                    }     		
                	
                    break;
                }
            }
            	
            }SDL_Flip(screen);

}
free_minimap (&m);
SDL_FreeSurface(p.sprite);
free_temps(&t,screen);
SDL_FreeSurface(screen);
TTF_Quit();
SDL_Quit();
	return EXIT_SUCCESS;
}
