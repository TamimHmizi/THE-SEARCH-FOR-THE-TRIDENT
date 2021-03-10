#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *imageBoutonQuitter = NULL, *imageBoutonJouer = NULL, *imageBoutonOptions = NULL, *imageDeFondJouer = NULL, *imageDeFondOptions = NULL, *imageBoutonRetourMenu= NULL;
    SDL_Rect positionFond, positionQuitter, positionJouer, positionOptions, positionFondJouer, positionFondOptions, positionBoutonRetourMenu;
    SDL_Event event;
    int continuer =1; 
    
    positionFond.x = 0;
    positionFond.y = 0;
    positionQuitter.x = (800/2)-(100/2);
    positionQuitter.y = (600/2)-(75/2);  //(600/2)-(75/2);
    positionJouer.x= (800/2)-(100/2);
    positionJouer.y = 400;//600-((600/2)-(75/2))+5;
    positionOptions.x= (800/2)-(100/2);
    positionOptions.y= 500;
    positionFondJouer.x = 0;
    positionFondJouer.y = 0;
    positionFondOptions.x = 0;
    positionFondOptions.y = 0;
    positionBoutonRetourMenu.x = 20;
    positionBoutonRetourMenu.y = 20;
    
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    /* Chargement d'une image Bitmap dans une surface */
    imageDeFond = SDL_LoadBMP("./mediajeux/bg1.bmp");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    
    imageBoutonQuitter=SDL_LoadBMP("./mediajeux/bouton_quitter_1.bmp");
    SDL_BlitSurface(imageBoutonQuitter, NULL, ecran, &positionQuitter);

    imageBoutonJouer=SDL_LoadBMP("./mediajeux/bouton_jouer_1.bmp");
    SDL_BlitSurface(imageBoutonJouer, NULL, ecran, &positionJouer);
    
    imageBoutonOptions=SDL_LoadBMP("./mediajeux/bouton_options_1.bmp");
    SDL_BlitSurface(imageBoutonOptions, NULL, ecran, &positionOptions);

    SDL_Flip(ecran);
    
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024 );
    Mix_Music* music = Mix_LoadMUS("./mediajeux/boucle.mp3"); // Charge notre musique


    Mix_PlayMusic(music, -1); // Joue notre musique

    //getchar(); faire pause, attendre evenement
    while (continuer) 
    {
        SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
        switch(event.type) /* On teste le type d'événement */
        {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
                
            case SDL_MOUSEBUTTONUP:
            // clique bouton quitter
            	if(event.button.x >= 350 && event.button.x <= 450 && event.button.y >= 262.5 && event.button.y <= 337.5)
            		continuer = 0;
            //clique bouton jouer
		else if(event.button.x >= 350 && event.button.x <= 450 && event.button.y >= 400 && event.button.y <= 475)
            		{
            		 imageDeFondJouer = SDL_LoadBMP("./mediajeux/bg2.bmp");
                        SDL_BlitSurface(imageDeFondJouer, NULL, ecran, &positionFondJouer);
                        
                        imageBoutonRetourMenu = SDL_LoadBMP("./mediajeux/Son_off.png");
                        SDL_BlitSurface(imageBoutonRetourMenu, NULL, ecran, &positionBoutonRetourMenu);
                        SDL_Flip(ecran);
                       }
            //clique bouton options
		else if(event.button.x >= 350 && event.button.x <= 450 && event.button.y >= 500 && event.button.y <= 575)
            		{
            		 imageDeFondOptions = SDL_LoadBMP("./mediajeux/bg3.bmp");
                        SDL_BlitSurface(imageDeFondOptions, NULL, ecran, &positionFondOptions);
                        SDL_Flip(ecran);
                       }
            	break;

        }
    }
        Mix_FreeMusic(music); // Libére en mémoire notre musique
    Mix_CloseAudio(); // Quitter correctement SDL_Mixer
    
    SDL_FreeSurface(imageDeFond); /* On libère la surface */
    SDL_FreeSurface(imageBoutonQuitter);
    SDL_Quit();

    return EXIT_SUCCESS;
}
