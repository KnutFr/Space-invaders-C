#include "stdafx.h"
#include "my.h"  

void BrowserMenuHome(t_menu *m, t_game *g)
{
	g->level = 1;
	LoadLevel(m, g);
	if (m->home.posItems == 6)
		g->event.type = SDL_QUIT;
	else
		m->posMenu = m->home.posItems+1;
}

void BrowserMenuShip(t_menu *m, t_game *g)
{
	char *shipPath[4] = {PATH_SHIP1, PATH_SHIP2, PATH_SHIP3, PATH_SHIP4};
	
	if (m->ship.posItems == 5)
		m->posMenu = 1;
	else if(m->level.ValidLev > 0)
		m->level.ValidLev = 0;
	else
		m->posMenu = 7;

	if (m->ship.posItems < 5)
		g->ship.img = IMG_Load(shipPath[m->ship.posItems-1]);

}

void BrowserMenuLevel(t_menu *m, t_game *g)
{
	if (m->level.posItems == 2)
	{
		LevelCodeinit(m);
		m->posMenu = 1;
	}
	else if (m->level.flag == 0)
		LevelCodeinit(m);
	else
		Levelcodecmp(m,g);
}

void BrowserMenuOpt(t_menu *m, t_game *g)
{
	if (m->opt.posItems == 3)
		m->posMenu = 1;
	else
		ChangeOpt(m,g);
}