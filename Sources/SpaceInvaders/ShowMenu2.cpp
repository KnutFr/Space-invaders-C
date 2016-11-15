#include "stdafx.h"
#include "my.h"

void ShowCredit(t_menu *m, t_game *g)
{
	int count;

	for (count = 1; count <= m->ship.nbItems; count++)
	{
		SDL_BlitSurface(m->credit.itemFont[count - 1], NULL, g->screen, 
			&m->credit.itemRect[count - 1]);
		SDL_BlitSurface(m->credit.Pict[count - 1], NULL, g->screen, 
			&m->credit.PictRect[count - 1]);
	}
}

void ShowChangeLevel(t_menu *m, t_game *g)
{
	int count;

	for (count = 1; count <= m->chlevel.NbItems; count++)
		SDL_BlitSurface(m->chlevel.itemFont[count - 1], NULL, g->screen, 
		&m->chlevel.itemRect[count - 1]);
}

void ShowWrScore(t_menu *m, t_game *g)
{
	int count;
	
	for (count = 1; count <= m->wrscore.nbItems; count++)
	{
		SDL_BlitSurface(m->wrscore.itemFont[count - 1], NULL, g->screen, 
			&m->wrscore.itemRect[count - 1]);
	}
	SDL_BlitSurface(m->wrscore.labelnameFont, NULL, g->screen, 
		&m->wrscore.labelnameRect);
}

void ShowComponents(t_menu *m, t_game *g)
{
	SDL_BlitSurface(m->bgImg, NULL, g->screen, &m->bgRect);
	SDL_BlitSurface(m->title, NULL, g->screen, &m->titleRect);
	if (m->posMenu == 1)
		ShowHome(m, g);
	else if (m->posMenu == 2)
		ShowShip(m, g);
	else if (m->posMenu == 3)
		ShowLevel(m, g);
	else if (m->posMenu == 4)
		ShowScore(m, g);
	else if(m->posMenu == 5)
		ShowOpt(m, g);
	else if(m->posMenu == 6)
		ShowCredit(m, g);
	else if(m->posMenu == 7)
		ShowChangeLevel(m, g);
	else if(m->posMenu == 8)
		ShowWrScore(m,g);
}