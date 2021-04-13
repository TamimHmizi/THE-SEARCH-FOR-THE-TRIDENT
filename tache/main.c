#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL;
    int continuer, poseidon=1, input;
    Personne p;
    SDL_Event event;
   


    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    TTF_Init();

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    SDL_WM_SetCaption("Tache personnage", NULL);
    
    
    if(ecran==NULL)
    	{
        	printf("ERREUR: %s\n", SDL_GetError());
        	return 1;
        }
      
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024 );

    init(&p, poseidon);

    
	continuer= 1;
	while (continuer)
    {    
        afficherperso( p , ecran);
        SDL_Delay(83);

        SDL_PollEvent(&event);
        switch (event.type)
        {

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT: 
                    input = 1;
                    break;
                case SDLK_LEFT: 
                    input = (-1);
                    break;
                case SDLK_a:
                    input = 2;
                    break;
                case SDLK_UP: 
                    input = 3;
                    break;
            }
            break;

        case SDL_QUIT: 
            continuer = 0; 
            break;   
        } 

        update(&p, input);
        deplacerperso(&p) ;
       // saut(&p);
        animerperso(&p);
        SDL_Flip(ecran);  
    }

    //SDL_FreeSurface( p.personnage_marche[0]);
    liberation(&p);
    
    SDL_Quit();

    return EXIT_SUCCESS;
}