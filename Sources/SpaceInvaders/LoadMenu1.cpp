#include "stdafx.h"
#include "my.h"

void LoadMenuHome(t_menu *m)
{
	int i;
	int tab[6] = {300, 290, 230, 270, 273, 310};
	char *items[6] = {"Play", "Level", "High Scores", 
		"Options", "Credits", "Exit"};

	for (i = 0; i < 6; i++)
	{
		m->home.itemsX[i] = tab[i];
		m->home.itemFont[i] = NULL;
		m->home.items[i] = items[i];
	}
	m->home.nbItems = 6;
	m->home.posItems = 1;
	m->time.last = SDL_GetTicks();
}

void LoadMenuLevel(t_menu *m)
{
	int i;
	int tab[3] = {250, 300};
	char *tcode[4] = {PWD_LVL1, PWD_LVL2, PWD_LVL3, PWD_LVL4};
	char *items[2] = {"_ _ _ _ _", "Back"};

	for (i = 0; i < 3; i++)
	{
		m->level.itemsX[i] = tab[i];
		m->level.itemFont[i] = NULL;
		m->level.items[i] = items[i];
		m->level.code[i] = tcode[i];
		m->level.code[i + 2] = tcode[i + 2];
	}
	m->level.LabelcodeX = 100;
	m->level.labelcode = "Code :";
	m->level.labelcodeFont = NULL;
	m->level.nbItems = 2;
	m->level.nbkeycode = 0;
	m->level.posItems = 1;
	m->level.flag = 1;
	m->level.ValidLev = 0;
}

void LoadMenuScore(t_menu *m)
{
	int i;
	int tab[5] = {200, 200, 200, 200, 200};
	char *Rank[5] = {"1ST","2ND","3RD","4TH","5TH"};

	FileScoreRead(m);
	for (i = 0; i < 5; i++)
	{
		m->score.itemsRkX[i] = tab[i];
		m->score.itemRkFont[i] = NULL;
		m->score.itemsRank[i] = Rank[i];
		m->score.itemsScX[i] = tab[i] + 20;
		m->score.itemScFont[i] = NULL;
		m->score.itemsSc[i] = m->highscore[i].name;
		m->score.itemsX[i] = tab[i] + 100;
		m->score.itemFont[i] = NULL;
		m->score.items[i] =  m->highscore[i].score;
	}
	m->score.nbItems = 5;
	m->score.posItems = 5;
}

void LoadMenuOpt(t_menu *m)
{
	int i;
	int tab[3] = {200, 200, 200};
	char *items[3] = { "Music", "Sound effect", "Back"};
	char *Optval[3] = {"ON", "ON", ""};

	for (i = 0; i < 3; i++)
	{
		m->opt.itemsX[i] = tab[i];
		m->opt.itemFont[i] = NULL;
		m->opt.items[i] = items[i];
		m->opt.optval[i] = Optval[i];
	}
	m->opt.nbItems = 3;
	m->opt.posItems = 1;
}

void LoadMenuShip(t_menu *m)
{
	int i;
	int tab[5] = {240, 240, 240, 240, 240};
	char *items[5] = {"Serenity", "X-Wing", "Arc 170", "Globemaster", "Back"};
	char *shipPict[5] ={PATH_SHIP1, PATH_SHIP2, PATH_SHIP3, PATH_SHIP4, PATH_NONE};
	
	for (i = 0; i < 5; i++)
	{
		m->ship.itemsX[i] = tab[i];
		m->ship.itemFont[i] = NULL;
		m->ship.items[i] = items[i];
		m->ship.PictShip[i] = IMG_Load(shipPict[i]);
		m->ship.PictRectX[i] = tab[i] - 70;
	}
	m->ship.nbItems = 5 ;
	m->ship.posItems = 1;
}