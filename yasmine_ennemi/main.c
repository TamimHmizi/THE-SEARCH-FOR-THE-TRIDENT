#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enemie.h"

int main() {

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface * screen;
  screen = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  SDL_WM_SetCaption("entite\t1", NULL); //titre de la fenetre
  SDL_Rect posperso;

  posperso.x = 150;
  posperso.y = 400;
  posperso.h = 100;
  posperso.w = 100;

  ennemi E ;

  SDL_Event event;
  SDL_Surface * background;
  SDL_Surface * persotest;

  initEnnemi(&E);
  int running = 1;
  background = IMG_Load("background.png");
  persotest = IMG_Load("persotest.png");

  while (running) {

    while (SDL_PollEvent( & event)) {

      switch (event.type) {
      case SDL_QUIT:

        running = 0;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {

        case SDLK_LEFT:
          posperso.x -= 100;

          break;
        case SDLK_RIGHT:
          posperso.x += 100;

          break;
          case SDLK_UP:
          posperso.y -= 100;
          break;
          case SDLK_DOWN:
          posperso.y += 30;
          break;


        }
        break;
      }
    }

    SDL_BlitSurface(background, NULL, screen, NULL);
    SDL_BlitSurface(persotest, NULL, screen, & posperso);

  //  deplacerIA(&E,posperso);
    animerEnnemi(&E);
    afficherEnnemi(E,screen);
    deplacer(&E);

    if (collisionBB(E.position,posperso)==1)
    {
    	printf("collision\n");
    }

    SDL_Flip(screen);
    SDL_Delay(100);
  }
  TTF_Quit();

}