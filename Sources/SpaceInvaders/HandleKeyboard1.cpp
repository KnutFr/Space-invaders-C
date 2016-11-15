#include "stdafx.h"
#include "my.h"

void HandleKeyboardEventsHome(t_menu *m, t_game *g, Uint8 *keystate)
{
	m->home.itemFont[m->home.posItems-1] = TTF_RenderText_Blended(m->fontItems,
		m->home.items[m->home.posItems-1], m->fontColor);
	if (keystate[SDLK_UP])
		if (m->home.posItems == 1)
			m->home.posItems = m->home.nbItems;
		else
			m->home.posItems--;
	if (keystate[SDLK_DOWN])
		if (m->home.posItems == m->home.nbItems)
			m->home.posItems = 1;
		else
			m->home.posItems++;
	m->home.itemFont[m->home.posItems-1] = TTF_RenderText_Blended(m->fontItems,
		m->home.items[m->home.posItems-1], m->fontColorSelect);
	if (keystate[SDLK_RETURN])
		BrowserMenuHome(m, g);
}

void HandleKeyboardEventsShip(t_menu *m, t_game *g, Uint8 *keystate)
{
	m->ship.itemFont[m->ship.posItems-1] = TTF_RenderText_Blended(m->fontItems,
		m->ship.items[m->ship.posItems-1], m->fontColor);
	m->level.ValidLev = 0;
	LoadItemsLevel (m);
	if (keystate[SDLK_UP])
		if (m->ship.posItems == 1)
			m->ship.posItems = m->ship.nbItems;
		else
			m->ship.posItems--;
	if (keystate[SDLK_DOWN])
		if (m->ship.posItems == m->ship.nbItems)
			m->ship.posItems = 1;
		else
			m->ship.posItems++;
	m->ship.itemFont[m->ship.posItems-1] = TTF_RenderText_Blended(m->fontItems,
		m->ship.items[m->ship.posItems-1], m->fontColorSelect);
	if (keystate[SDLK_RETURN])
		BrowserMenuShip(m, g);
}

void HandleKeyboardEventsScore(t_menu *m, t_game *g, Uint8 *keystate)
{
	if (keystate[SDLK_RETURN])
		m->posMenu = 1;
}

void HandleKeyboardEventsLevel(t_menu *m, t_game *g, Uint8 *keystate)
{
	int key;

	m->time.now = SDL_GetTicks();
	key = g->event.resize.h;
	m->level.itemFont[m->level.posItems-1] = TTF_RenderText_Blended(
		m->fontItems, m->level.items[m->level.posItems-1], m->fontColor);
	if (m->level.ValidLev != 0)
	{
		m->posMenu = 2;
		LevelCodeinit(m);
		SDL_Delay(1000);
	}
	else if (keystate[SDLK_UP])
		if (m->level.posItems == 1)
			m->level.posItems = m->level.nbItems;
		else
			m->level.posItems--;
	else if (keystate[SDLK_DOWN])
		if (m->level.posItems == m->level.nbItems)
			m->level.posItems = 1;
		else
			m->level.posItems++;
	else if (key >= 97 && key <=122 && m->level.posItems == 1 
		&& m->level.nbkeycode < 5 && m->time.now > m->time.last + 250)
	{
		 Levelcode(m, g);
		 m->level.nbkeycode++;
	}
	else if (keystate[SDLK_BACKSPACE] && m->level.nbkeycode > 0)
	{
		m->level.nbkeycode--;
		Levelcode(m, g);
	}
	else if (keystate[SDLK_RETURN])
		BrowserMenuLevel(m,g);
	m->level.itemFont[m->level.posItems-1] = TTF_RenderText_Blended(
		m->fontItems, m->level.items[m->level.posItems-1], m->fontColorSelect);
}

void HandleKeyboardEventsOpt(t_menu *m, t_game *g, Uint8 *keystate)
{
	m->opt.itemFont[m->opt.posItems-1] = TTF_RenderText_Blended(m->fontItems,
		m->opt.items[m->opt.posItems-1], m->fontColor);
	if (keystate[SDLK_UP])
		if (m->opt.posItems == 1)
			m->opt.posItems = m->opt.nbItems;
		else
			m->opt.posItems--;
	else if (keystate[SDLK_DOWN])
		if (m->opt.posItems == m->opt.nbItems)
			m->opt.posItems = 1;
		else
			m->opt.posItems++;
	else if(keystate[SDLK_RETURN])
		BrowserMenuOpt(m, g);
	m->opt.itemFont[m->opt.posItems-1] = TTF_RenderText_Blended(m->fontItems,
		m->opt.items[m->opt.posItems-1], m->fontColorSelect);
}