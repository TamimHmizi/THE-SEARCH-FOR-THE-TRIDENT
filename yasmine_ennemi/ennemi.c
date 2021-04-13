#include "ennemi.h"


void initEnnemi(ennemi*e){
    e->image=IMG_Load("enemie.png");

    e->direction=0;

    e->position.x=700;
    e->position.y=400;

    e->pos_sprite.x=0;
    e->pos_sprite.y=0;
    e->pos_sprite.w=150;
    e->pos_sprite.h=150;
}


void afficherEnnemi(ennemi e, SDL_Surface * screen){
    SDL_BlitSurface(e.image,&e.pos_sprite,screen,&e.position);
}

void animerEnnemi( ennemi * e){
    e->pos_sprite.x += e->pos_sprite.w ; // e->pos_sprite.x += 150
    if (e->pos_sprite.x>=2250)
    {
        e->pos_sprite.x=0;
    }
 //////   ////////////////////////

    e->pos_sprite.y = e->direction * e->pos_sprite.h ; //e->pos_sprite.y = e->direction * 150
}



void deplacer( ennemi * e){
    int xmin=500;
    int xmax=900;
    if (e->direction==0)
    {
        e->position.x -= 10;
    }
    else if (e->direction==1)
    {
        e->position.x += 10;
    }


    if (e->position.x >= xmax) e->direction =0;
    if (e->position.x <= xmin) e->direction =1;

}




int collisionBB(SDL_Rect E, SDL_Rect p) {
  int collision;
  if (((p.x + p.w) < E.x) || (p.x > (E.x + E.w)) || ((p.y + p.h) < E.y) || (p.y > (E.y + E.h))) {
    collision = 0;
  } else {
    collision = 1;
  }
  return collision;
}























