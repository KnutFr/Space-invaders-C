#include "stdafx.h"
#include "my.h"

void WrScoreName(t_menu *m, t_game *g, Uint8 *keystate)
{
	int key = g->event.resize.h;
	int i;
	m->time.last = SDL_GetTicks();
	m->wrscore.entname[m->wrscore.nbkeycode] = (unsigned)(char)key;

	for (i = m->wrscore.nbkeycode + 1; i < 4 ; i++)
		m->wrscore.entname[i] = NULL;
	m->wrscore.entname[i] = '\0';
	m->wrscore.items[0] = m->wrscore.entname;
}

void WrScoreNameInit(t_menu *m)
{
	m->wrscore.items[0] = "_ _ _ _";
	m->wrscore.entname[0] = '\0';
	m->wrscore.nbkeycode = 0;
	m->posMenu = 1;
}