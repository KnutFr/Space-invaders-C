#include "stdafx.h"
#include "my.h"

void LoadGame(t_game *g)
{
	LoadBackground(g);
	LoadFire(g);
	LoadShip(g);
	LoadInvaders(g);
	LoadBossSprites(g);
	LoadBossHealth(g);
	LoadScore(g);
	LoadGameOver(g);
	LoadLives(g);
	LoadLine(g);
	LoadBlocks(g);
	LoadBoss(g);
}

void LoadProperties(t_menu *m)
{
	m->bgImg = IMG_Load(PATH_BG_MENU);
	m->bgRect.x=0;
	m->bgRect.y=0;
	m->fontColor.r = 255;    
	m->fontColor.g = 255;
	m->fontColor.b = 255;
	m->fontColorSelect.r = 255;
	m->fontColorSelect.g = 226;
	m->fontColorSelect.b = 19;
	m->fontItems = TTF_OpenFont(PATH_RENEGADE, 36);
	m->fontTitle = TTF_OpenFont(PATH_RENEGADE, 55);
	m->fontCredit = TTF_OpenFont(PATH_RENEGADE, 25);
	m->title = TTF_RenderText_Blended(m->fontTitle, SCREEN_TITLE, m->fontColorSelect);
	m->titleRect.x=50;
	m->titleRect.y=50;
}

void LoadMenu(t_menu *m)
{
	LoadProperties(m);
	LoadMenuHome(m);
	LoadMenuShip(m);
	LoadMenuLevel(m);
	LoadMenuScore(m);
	LoadMenuOpt(m);
	LoadMenuCredit(m);
	LoadMenuChangeLev(m, "Level 1", PWD_LVL1);
	LoadMenuWrScore(m);
}

void LoadMenuItems(t_menu *m)
{
	LoadItemsHome(m);
	LoadItemsShip(m);
	LoadItemsLevel(m);
	LoadItemsScore(m);
	LoadItemsOpt(m);
	LoadItemsCredit(m);
	LoadItemsChangeLev(m);
	LoadItemsWrScore(m);
}

void LoadComponents(t_menu *m, t_game *g)
{
	LoadMenu(m);
	LoadMenuItems(m);
	LoadGame(g);
}