#include "stdafx.h"
#include "my.h"

void HandleKeyboardEventsCredit(t_menu *m, t_game *g, Uint8 *keystate)
{
	m->credit.itemFont[m->credit.PosItems-1] = TTF_RenderText_Blended(
		m->fontItems, m->opt.items[m->credit.PosItems-1], m->fontColorSelect);
	if (keystate[SDLK_RETURN])
		m->posMenu = 1;
}

void HandleKeyboardEventsChangeLvl(t_menu *m, t_game *g, Uint8 *keystate)
{
	if (keystate[SDLK_RETURN])
	{
		StartGame(m, g);
		LoadGame(g);
		m->posMenu = 8;
		m->home.posItems = 1;
	}
}

void HandleKeyboardEventsWrScore(t_menu *m, t_game *g, Uint8 *keystate)
{
	int key;

	m->time.now = SDL_GetTicks();
	key = g->event.resize.h;
	
	m->wrscore.itemFont[m->wrscore.posItems-1] = TTF_RenderText_Blended(
		m->fontItems, m->wrscore.items[m->wrscore.posItems-1], m->fontColor);
        
	if (keystate[SDLK_ESCAPE])
		WrScoreNameInit(m);                           
	else if (keystate[SDLK_BACKSPACE] && m->wrscore.nbkeycode > 0)
	{
		m->wrscore.nbkeycode --;
		WrScoreName (m, g, keystate);
	}
	else if (key >= 97 && key <=122 && m->wrscore.posItems == 1 &&
		m->wrscore.nbkeycode < 4 && m->time.now > m->time.last + 250)
	{
		WrScoreName (m, g, keystate);
		m->wrscore.nbkeycode++;              
	}
	else if (keystate[SDLK_RETURN] && m->wrscore.nbkeycode == 4)
		FileScoreWrite(m, g);

	
	LoadItemsHome(m);
	m->wrscore.itemFont[m->wrscore.posItems-1] = TTF_RenderText_Blended(
		m->fontItems, m->wrscore.items[m->wrscore.posItems-1], m->fontColorSelect);
}

void HandleKeyboardGame(t_game *g, Uint8 *keystate)
{
	if (keystate[SDLK_LEFT])
		if (g->ship.rect.x > BORDER)
			g->ship.rect.x -= MOVE_SHIP;

	if (keystate[SDLK_RIGHT])
		if (g->ship.rect.x < SCREEN_WIDTH - SHIP_WIDTH - BORDER)
			g->ship.rect.x += MOVE_SHIP;

	if (keystate[SDLK_ESCAPE])
		main(0,0);

	if (keystate[SDLK_SPACE])
		if (!g->shoot.exist)
			Fire(g);
}

void HandleKeyboardEvents(t_menu *m, t_game *g)
{
	Uint8 *keystate;

	keystate = SDL_GetKeyState(NULL);
	if (m->posMenu == 1)
		HandleKeyboardEventsHome(m, g, keystate);
	else if (m->posMenu == 2)
		HandleKeyboardEventsShip(m, g, keystate);
	else if(m->posMenu == 3)
		HandleKeyboardEventsLevel(m, g, keystate);
	else if(m->posMenu == 4)
		HandleKeyboardEventsScore(m, g, keystate);
	else if(m->posMenu == 5)
		HandleKeyboardEventsOpt(m, g, keystate);
	else if(m->posMenu == 6)
		HandleKeyboardEventsCredit(m, g, keystate);
	else if(m->posMenu == 7)
		HandleKeyboardEventsChangeLvl(m, g, keystate);
	else if(m->posMenu == 8)									
		HandleKeyboardEventsWrScore(m, g, keystate);
}