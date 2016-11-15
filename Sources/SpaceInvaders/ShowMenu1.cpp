#include "stdafx.h"
#include "my.h"

void ShowHome(t_menu *m, t_game *g)
{
	int count;

	for (count = 1; count <= m->home.nbItems; count++)
		SDL_BlitSurface(m->home.itemFont[count - 1], NULL, g->screen, 
		&m->home.itemRect[count - 1]);
}

void ShowShip(t_menu *m, t_game *g)
{
	int count;

	for (count = 1; count <= m->ship.nbItems; count++)
	{
		SDL_BlitSurface(m->ship.itemFont[count-1], NULL, g->screen, 
			&m->ship.itemRect[count - 1]);
		SDL_BlitSurface(m->ship.PictShip[count - 1], NULL, g->screen, 
			&m->ship.PictRect[count - 1]);
	}
}

void ShowLevel(t_menu *m, t_game *g)
{
	int count;

	for (count = 1; count <= m->level.nbItems; count++)
	{
		SDL_BlitSurface(m->level.itemFont[count - 1], NULL, g->screen, 
		&m->level.itemRect[count - 1]);
	}
	SDL_BlitSurface(m->level.labelcodeFont, NULL, g->screen, 
		&m->level.labelcodeRect);
}

void ShowScore(t_menu *m, t_game *g)
{
	int count;

	for (count = 1; count <= m->score.nbItems; count++)
	{
		SDL_BlitSurface(m->score.itemRkFont[count - 1], NULL, g->screen, 
		&m->score.itemRkRect[count - 1]);
		SDL_BlitSurface(m->score.itemFont[count - 1], NULL, g->screen, 
		&m->score.itemRect[count - 1]);
		SDL_BlitSurface(m->score.itemScFont[count - 1], NULL, g->screen, 
			&m->score.itemScRect[count - 1]);
	}
}

void ShowOpt(t_menu *m, t_game *g)
{
	int count;

	for (count = 1; count <= m->opt.nbItems; count++)
	{
		SDL_BlitSurface(m->opt.itemFont[count - 1], NULL, g->screen, 
			&m->opt.itemRect[count - 1]);
		SDL_BlitSurface(m->opt.valFont[count - 1], NULL, g->screen, 
			&m->opt.optValRect[count - 1]);
	}
}