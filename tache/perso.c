#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

void init(Personne *p, int numeroperso)
{
	p->personnage_marche[0]=IMG_Load("./media/marche/marche_poseidon1.png");
	p->personnage_marche[1]=IMG_Load("./media/marche/marche_poseidon2.png");
	p->personnage_marche[2]=IMG_Load("./media/marche/marche_poseidon3.png");
	p->personnage_marche[3]=IMG_Load("./media/marche/marche_poseidon4.png");
	p->personnage_marche[4]=IMG_Load("./media/marche/marche_poseidon5.png");
	p->personnage_marche[5]=IMG_Load("./media/marche/marche_poseidon6.png");
	p->personnage_marche[6]=IMG_Load("./media/marche/marche_poseidon7.png");
	p->personnage_marche[7]=IMG_Load("./media/marche/marche_poseidon8.png");
	p->personnage_marche[8]=IMG_Load("./media/marche/marche_poseidon9.png");
	p->personnage_marche[9]=IMG_Load("./media/marche/marche_poseidon10.png");
	p->personnage_marche[10]=IMG_Load("./media/marche/marche_poseidon11.png");
	p->personnage_marche[11]=IMG_Load("./media/marche/marche_poseidon12.png");
	p->personnage_marche[12]=IMG_Load("./media/marche/marche_poseidon13.png");
	
	p->position_marche.x=100;
	p->position_marche.y=100;

	p->personnage_marche_gauche[0]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon1.png");
	p->personnage_marche_gauche[1]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon2.png");
	p->personnage_marche_gauche[2]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon3.png");
	p->personnage_marche_gauche[3]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon4.png");
	p->personnage_marche_gauche[4]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon5.png");
	p->personnage_marche_gauche[5]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon6.png");
	p->personnage_marche_gauche[6]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon7.png");
	p->personnage_marche_gauche[7]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon8.png");
	p->personnage_marche_gauche[8]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon9.png");
	p->personnage_marche_gauche[9]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon10.png");
	p->personnage_marche_gauche[10]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon11.png");
	p->personnage_marche_gauche[11]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon12.png");
	p->personnage_marche_gauche[12]=IMG_Load("./media/marche_gauche/marche_gauche_poseidon13.png");

	p->position_marche_gauche.x=100;
	p->position_marche_gauche.y=100;

	p->personnage_saut[0]=IMG_Load("./media/saut/saut_poseidon1.png");
	p->personnage_saut[1]=IMG_Load("./media/saut/saut_poseidon2.png");
	p->personnage_saut[2]=IMG_Load("./media/saut/saut_poseidon3.png");
	p->personnage_saut[3]=IMG_Load("./media/saut/saut_poseidon4.png");
	p->personnage_saut[4]=IMG_Load("./media/saut/saut_poseidon5.png");
	p->personnage_saut[5]=IMG_Load("./media/saut/saut_poseidon6.png");
	p->personnage_saut[6]=IMG_Load("./media/saut/saut_poseidon7.png");
	p->personnage_saut[7]=IMG_Load("./media/saut/saut_poseidon8.png");
	p->personnage_saut[8]=IMG_Load("./media/saut/saut_poseidon9.png");
	p->personnage_saut[9]=IMG_Load("./media/saut/saut_poseidon10.png");
	p->personnage_saut[10]=IMG_Load("./media/saut/saut_poseidon11.png");
	p->personnage_saut[11]=IMG_Load("./media/saut/saut_poseidon12.png");
	p->personnage_saut[12]=IMG_Load("./media/saut/saut_poseidon13.png");
	p->personnage_saut[13]=IMG_Load("./media/saut/saut_poseidon14.png");

	p->position_saut.x=100;
	p->position_saut.y=100;

	p->vie1=IMG_Load("./media/vie.png");
	p->vie2=IMG_Load("./media/vie.png");
	p->vie3=IMG_Load("./media/vie.png");

	p->position_vie1.x=50;
	p->position_vie1.y=20;
	p->position_vie2.x=125;
	p->position_vie2.y=20;
	p->position_vie3.x=200;
	p->position_vie3.y=20;

	p->frame_droite=0;
	p->frame_gauche=0;
	p->direction=1;  //droite
	p->vitesse=5;
	p->acceleration=0;
	p->up=-1;
	p->seuil=300;
	p->position_initiale=0;
	p->frame_saut=0;

}
void afficherperso(Personne p , SDL_Surface *ecran)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 139, 241, 216));
	if(p.direction ==1 && p.up == -1)
	{
		SDL_BlitSurface(p.personnage_marche[p.frame_droite], NULL, ecran, &p.position_marche);
	}
	if(p.direction ==-1 && p.up == -1)   
	{
		SDL_BlitSurface(p.personnage_marche_gauche[p.frame_gauche], NULL, ecran, &p.position_marche_gauche);
	}
	if(p.up != -1 && p.direction ==1)
	{
		SDL_BlitSurface(p.personnage_saut[p.frame_saut], NULL, ecran, &p.position_saut);
	}
	SDL_BlitSurface(p.vie1, NULL, ecran, &p.position_vie1);
	SDL_BlitSurface(p.vie2, NULL, ecran, &p.position_vie2);
	SDL_BlitSurface(p.vie3, NULL, ecran, &p.position_vie3);
}

void deplacerperso(Personne *p)
{
	if(p->update == 1)
	{
		p->position_marche.x += 7;
		p->direction =1;
	}		
	else if (p->update == -1)
	{
		p->position_marche.x -= 7;
		p->position_marche_gauche.x=p->position_marche.x;
		p->direction =-1;
	}
	if (p->update == 2)
	{
		if(p->direction ==1)
		{
			p->acceleration+=1;
			p->position_marche.x += (p->acceleration+ p->vitesse);
		}
		if(p->direction ==-1)
		{
			p->acceleration+=0.8;
			p->position_marche_gauche.x -= (p->acceleration+ p->vitesse);
		}
	}
}

void animerperso(Personne *p)
{
	if(p->update == 1)
	{
		if(p->frame_droite==12)
			p->frame_droite=0;
		else
		{
			(p->frame_droite)++;
		}

	}

	if(p->update == -1)
	{
		if(p->frame_gauche==12)
			p->frame_gauche=0;
		else
		{
			(p->frame_gauche)++;
		}

	}
	if (p->update == 2)
	{
		if(p->direction ==1)
		{
			if(p->frame_droite==12)
				p->frame_droite=0;
			else
			{
				(p->frame_droite)++;
			}
		}
		if(p->direction ==-1)
		{
			if(p->frame_gauche==12)
			p->frame_gauche=0;
			else
			{
				(p->frame_gauche)++;
			}
		}
	}
	if (p->update == 3)
	{
		if(p->direction ==1)
		{
			if(p->frame_saut==13)
			p->frame_saut=0;
			else
			{
				(p->frame_saut)++;
			}
		}
		/*if(p->ancienne_direction ==-1)
		{
			p->acceleration+=0.8;
			p->position_marche_gauche.x -= (p->acceleration+ p->vitesse);
		}*/
	}
}
void saut(Personne *p)
{
	int compteur =0;
	if(p->update == 3)
	{
		p->up = 1;
		compteur++;

		if(compteur ==14)
			compteur=0;
		if(p->direction ==1 && compteur==1)
		{
			p->position_saut=p->position_marche;
			p->position_initiale = p->position_saut.y;
			printf("balise %d pos init\n", p->position_saut.y);

		}
		if(p->direction ==-1 && compteur==1)
			p->position_initiale = p->position_marche_gauche.y;
		if(p->up == 1 && p->position_saut.y < p->seuil)
		{
			p->acceleration+=1;
			p->position_saut.y += (p->acceleration+ p->vitesse);
						
		}
		if(p->position_saut.y == p->seuil)
		{
			p->up=0;
			if(p->position_saut.y != p->position_initiale)
			{
				p->acceleration+=1;
				p->position_saut.y -= (p->acceleration+ p->vitesse);
			}
		}
		if(p->position_initiale == p->position_saut.y)
			p->up=-1;
		printf("balise %d up\n", p->up);

	}

	
}

void update(Personne *p, int input)
{
	if(input == 1)
	{
		p->update =1;
	}		
	else if (input == -1)
	{
		p->update =-1;
	}
	else if (input == 2)
	{
		p->update = 2;
	}
	else if (input == 3)
	{
		p->update = 3;
	}
}

void liberation(Personne *p)
{
	int i=0; 
	 //liberation marche droite
	for(i=0; i<13; i++)
	{
		SDL_FreeSurface( p->personnage_marche[i]);
	}

	//liberation marche gauche
	for(i=0; i<13; i++)
	{
		SDL_FreeSurface( p->personnage_marche_gauche[i]);
	}

	//liberation saut
	for(i=0; i<14; i++)
	{
		SDL_FreeSurface( p->personnage_saut[i]);
	}



}