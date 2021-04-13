#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigmealeatoiresansfichier.h"

int main()
{

SDL_Surface * screen=NULL;
SDL_Event event;
int continuer=1,scorea;
int input=0 , i=1; 
enigme e;
    SDL_Init(SDL_INIT_VIDEO);
    
    TTF_Init();
    
    screen=SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE| SDL_DOUBLEBUF );
   
    srand(time(NULL));
    
   initialiserEnigme(&e);
   genererEnigme(&e);
     while (continuer) 
    {
    if(e.score>0)
    {
    if(i==0)
    {
         genererEnigme(&e);
         i=1;
         }
    afficherenigme(e,screen,continuer);
        SDL_WaitEvent(&event); 
        switch(event.type) 
        {
            case SDL_QUIT: 
                continuer = 0; 
                break;
            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_a:
                   input =11;
                   i=0;

                break;
                case SDLK_z:
                input =12;
                   i=0;
                break;
                case SDLK_e:
                input =13;
                    i=0;
             break;
            }
            
            break;
    
    
        }
        updateEnigme(&e,&input);
   }
   else
   continuer=0;
    
    
SDL_Flip(screen); 
    }
    SDL_FreeSurface(e.equationtexte);
    SDL_FreeSurface(e.scoretexte);
    SDL_FreeSurface(e.str1texte);
    SDL_FreeSurface(e.str2texte);
    SDL_FreeSurface(e.str3texte);
    TTF_CloseFont(e.police);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}

