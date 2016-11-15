#include "stdafx.h"
#include "my.h"

void Levelcode (t_menu *m, t_game *g)
{
int i;
	int key = g->event.resize.h;

	m->time.last = SDL_GetTicks();
	m->level.entcode[m->level.nbkeycode] = (unsigned)(char)key;
	for (i = m->level.nbkeycode + 1; i < 6 ; i++)   
		m->level.entcode[i] = NULL;
	m->level.items[0] = m->level.entcode;
}

void Levelcodecmp(t_menu *m, t_game *g)
{
	int i;
	char *result[4] = {"Go Level 1 !","Go Level 2 !",
		"Go Level 3 !","Go Level 4 !"};
	char *numlevel[4] = {"Level 1","Level 2","Level 3","Level 4"};

	for (i = 0; i < 4; i++)
		if (!strcmp(m->level.items[0], m->level.code[i]))
		{
			g->level = i + 1;
			m->level.ValidLev = i + 1;
			m->chlevel.items[0]= numlevel[i]; 
			m->chlevel.items[1] = m->level.code[i];
			m->level.items[0] = result[i];
			m->level.ValidLev = i + 1;
			LoadItemsChangeLev(m);
			break;
		}
		if (m->level.ValidLev == 0)
		{
			m->level.items[0] = "Not valid!";
			m->level.flag = 0;
			LoadItemsLevel(m);
		}
		m->level.nbkeycode = 0;
}

void LevelCodeinit(t_menu *m)
{
	m->level.items[0] = "_ _ _ _";  
	m->level.posItems = 1;
	m->level.flag = 1;
}