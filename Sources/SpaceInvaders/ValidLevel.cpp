#include "stdafx.h"
#include "my.h"

void ValidLevel1(t_menu *m, t_game *g)
{
	m->level.items[0] = "Go to the Level 1 !";
	g->level = 1;
	m->level.ValidLev = 1;
	m->chlevel.items[0]= "Level 1"; 
	m->chlevel.items[1] = PWD_LVL1;
}

void ValidLevel2(t_menu *m, t_game *g)
{
	m->level.items[0] = "Go to the Level 2 !";
	g->level = 2;
	m->level.ValidLev = 2;
	m->chlevel.items[0]= "Level 2"; 
	m->chlevel.items[1] = PWD_LVL2;
}

void ValidLevel3(t_menu *m, t_game *g)
{
	m->level.items[0] = "Go to the Level 3 !";
	g->level = 3;
	m->level.ValidLev = 3;
	m->chlevel.items[0]= "Level 3"; 
	m->chlevel.items[1] = PWD_LVL3;
}

void ValidLevel4(t_menu *m, t_game *g)
{
	m->level.items[0] = "Go to the Level 4 !";
	g->level = 4;
	m->level.ValidLev = 4;
	m->chlevel.items[0]= "Level 4"; 
	m->chlevel.items[1] = PWD_LVL4;
}

void ValidLevel5(t_menu *m, t_game *g)
{
	m->level.items[0] = "Go to the Level 5 !";
	g->level = 5;
	m->level.ValidLev = 5;
	m->chlevel.items[0]= "Level 5"; 
	m->chlevel.items[1] = PWD_LVL5;
}