#include "stdafx.h"
#include "my.h"

void InitAll(t_menu *m, t_game *g)
{
	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO);
	g->screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, 
		SDL_SWSURFACE);
	g->event.type = 0;
	SDL_WM_SetCaption(SCREEN_TITLE, NULL);
	SDL_WM_SetIcon(IMG_Load(PATH_ICON), NULL);
	g->music = g->effect = 1;
	m->posMenu = 1;
}

void FreeAll(t_menu *m, t_game *g)
{
	 TTF_Quit();
	 SDL_Quit();
}

int main (int argc, char **argv)
{
	t_menu menu;
	t_game game;

	InitAll(&menu, &game);
	game.ship.life = 5;
	game.ship.oldLife = 5;
	LoadComponents(&menu, &game);
	while (game.event.type != SDL_QUIT)
	{
		if (game.ship.life != 5 || game.ship.oldLife != 5)
		{
			game.ship.life = 5;
			game.ship.oldLife = 5;
		}
		SDL_WaitEvent(&game.event);
		HandleKeyboardEvents(&menu, &game);
		ShowComponents(&menu, &game);
		SDL_Flip(game.screen);
		SDL_Delay(30);
	}
	FreeAll(&menu, &game);
	return EXIT_SUCCESS;
}