#include "stdafx.h"
#include "my.h"

void LoadGameOver(t_game *g)
{
	g->gameover.title = MyIMG_Load(PATH_GAMEOVER, g->gameover.title);
	g->gameover.titleRect.x = SCREEN_WIDTH / 2 - 150;
	g->gameover.titleRect.y = SCREEN_HEIGHT / 2 - 150;
	g->gameover.font = TTF_OpenFont(PATH_VISITOR, 36);
	g->gameover.msgRect.x = SCREEN_WIDTH / 2 - 220;
	g->gameover.msgRect.y = 450; 
	g->gameover.scoreRect.x = SCREEN_WIDTH / 2 + 200;
	g->gameover.scoreRect.y = 450;
	g->gameover.value = 0;
}

int LoadInvScore(int i)
{
	if (i < 1)
		return (30);
	else if (i < 3 && i > 0)
		return (20);
	else
		return (10);
}

void LoadInvPaths(int i, char **p1, char **p2, SDL_Surface **l1, SDL_Surface **l2)
{
	if (i < 1)
	{
		*p1 = PATH_INV_1A;
		*p2 = PATH_INV_1B;
	}
	else if (i < 3 && i > 0)
	{
		*p1 = PATH_INV_2A;
		*p2 = PATH_INV_2B;
	}
	else
	{
		*p1 = PATH_INV_3A;
		*p2 = PATH_INV_3B;
	}
	*l1 = IMG_Load(*p1);
	*l2 = IMG_Load(*p2);
}

void LoadInvaders(t_game *g)
{
	int i;
	int j;
	SDL_Surface *loader[2];
	SDL_Surface *loadfire[2];
	char *path[2];
	t_index t;

	loadfire[0] = IMG_Load(PATH_INV_SHOOT);
	loadfire[1] = IMG_Load(PATH_EXPLOSION);
	for (i = 0; i < INV_ROW; i++)
	{
		LoadInvPaths(i, &path[0], &path[1], &loader[0], &loader[1]);
		for (j = 0; j < INV_COL; j++)
		{
			t.X = i;
			t.Y = j;
			LoadInvader(g, t, loader, loadfire);
		}
		SDL_FreeSurface(loader[0]);
		SDL_FreeSurface(loader[1]);
	}
	g->lastTime = SDL_GetTicks();
	g->switcher = 1;
	g->direction = 1;
}

SDL_Surface *MyIMG_Load(char *path, SDL_Surface *dst)
{
	if (path[strlen(path) - 3] == 'p' && path[strlen(path) - 2] == 'n' 
		&& path[strlen(path) - 1] == 'g')
		dst = SDL_DisplayFormatAlpha(IMG_Load(path));
	else
		dst = SDL_DisplayFormat(IMG_Load(path));

 return dst;
}