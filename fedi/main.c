#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "benaoun_et3_Multijoueur.h"

int main()
{
	SDL_Event event;
	minimap m;
	temps t;
	SDL_Surface *screen = NULL,*imageDeFond=NULL ;
	SDL_Rect position_BG ;
	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	TTF_Init();
    if(screen==NULL)
    	{
        	printf("ERREUR: %s\n", SDL_GetError());
        	return 1;
       }

position_BG.x=0;
position_BG.y=0;

	imageDeFond = IMG_Load("champions.jpg");
       int continuer= 1;
       initmap( &m);
       initialiser_temps(&t);
	while (continuer)
{
	

    SDL_BlitSurface(imageDeFond, NULL, screen, &position_BG);
	afficherminimap ( m,screen);
	afficher_temps(&t,screen);
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
                		m.p.position_perso.x+=10;
                	break;
                	case SDLK_LEFT :
       					m.p.position_perso.x-=10;         		
                	break;
                }
            }
            	
            }SDL_Flip(screen);
}

free_temps(&t,screen);
SDL_FreeSurface(screen);
TTF_Quit();
SDL_Quit();
	return EXIT_SUCCESS;
}
