#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_Event.h>
#include <SDL/SDL_ttf.h>
#include "scroll.c"


int main(int argc, char**argv)
{
     SDL_Init(SDL_INIT_VIDEO);
     SDL_Surface *ecran = NULL;
     Background b;
   
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption ("DIVINE", NULL);

    Mix_Music* myMus;
    SDL_Init(SDL_INIT_AUDIO);

    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT, 2, 1024);

    Chargermap(&b);

    Mix_PlayMusic(myMus, -1);

    int continuer = 1;
    SDL_Event evenement;

    while(continuer)
    {

     afficherBackground(&b, ecran);


     SDL_PollEvent(&evenement);

        switch(evenement.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;

            case SDL_KEYDOWN:

            switch(evenement.key.keysym.sym)
            {
                 case SDLK_ESCAPE:
                 continuer = 0;
                 break;

                 default:
                 break;
            }
            
              Scrolling(B, sens_deplacement);
              SDL_BlitSurface(map,NULL,ecran,&b->scrolling);
              SDL_Flip(ecran);
              SDL_Delay(150);

            break;
        }

    }


          SDL_FreeSurface(map);
          SDL_FreeSurface(ecran);
          SDL_FreeSurface(ecran);

    SDL_Quit();

return 0;
}

