#include "stdafx.h"
#include "my.h"

void StartGame(t_menu *m, t_game *g)
{
	Uint8 *keystate;

	keystate = SDL_GetKeyState(NULL);
	while (g->event.key.keysym.sym != SDLK_ESCAPE && g->ship.life != 0 && 
		g->boss.health != 0)
	{
		SDL_PollEvent(&g->event);
		HandleKeyboardGame(g, keystate);
		if (g->level == 4)
			animateBoss(g);
		if (g->ship.destroyedTimer.last != 0)
			ShipReappearance(g);
		if (CountAliveInvaders(g) == 0 && g->level != 4)
		{
			g->level++;
			LoadLevel(m, g);
		}
		ShowGame(g);
		SDL_UpdateRect(g->screen, 0, 0, 0, 0);
		SDL_Flip(g->screen);
		SDL_Delay(30);
	}
	m->save.i_score = g->score.value;
	ShowGameOver(g);
}

void LoadTransitionScreen(t_menu *m, t_game *g)
{
	if (g->level == 1)
		LoadMenuChangeLev(m, "Level 1", PWD_LVL1);
	else if (g->level == 2)
		LoadMenuChangeLev(m, "Level 2", PWD_LVL2);
	else if (g->level == 3)
		LoadMenuChangeLev(m, "Level 3", PWD_LVL3);
	else if (g->level == 4)
		LoadMenuChangeLev(m, "Level BOSS", PWD_LVL4);
	LoadItemsChangeLev(m);

	while (g->event.key.keysym.sym != SDLK_RETURN &&
		g->event.key.keysym.sym != SDLK_ESCAPE) 
	{
		while(SDL_PollEvent(&g->event));
		SDL_BlitSurface(m->bgImg, NULL, g->screen, &m->bgRect);
		SDL_BlitSurface(m->title, NULL, g->screen, &m->titleRect);
		ShowChangeLevel(m, g);
		SDL_Flip(g->screen);
		SDL_Delay(30);
	}
}

void LoadLevel(t_menu *m, t_game *g)
{
	ReloadGame(g);
	LoadTransitionScreen(m, g);
	if (g->level == 4)
		LoadBoss(g);
}

void ReloadGame(t_game *g)
{
	LoadFire(g);
	LoadShip(g);
	if (g->level != 4)
	{
		LoadInvaders(g);
		LoadBlocks(g);
	}
}