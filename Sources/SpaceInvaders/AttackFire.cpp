#include "stdafx.h"
#include "my.h"

void Fire(t_game *g)
{
	g->shoot.rect.x = g->ship.rect.x + (SHIP_WIDTH / 2) - FIRE_SHIFTX;
	g->shoot.rect.y = g->ship.rect.y - (SHIP_HEIGHT / 3);
	g->shoot.exist = 1;
}

void InvFire(t_invader *i)
{
	i->shoot.rect.x = i->rect.x + (INV_WIDTH/2);
	i->shoot.rect.y = i->rect.y + (INV_HEIGHT);
	i->shoot.exist = 1;
}

void CheckForemostInv(t_game *g, int i, int j)
{
	if (i < 4 && g->inv[i+1][j].life)
		CheckForemostInv(g, i+1, j);
	else if (g->inv[i][j].life)
		InvFire(&g->inv[i][j]);
	else
		return;
}

void GenerateFire(t_game *g, t_index *f)
{
	int nb;
	int i;
	int count;

	srand((unsigned int)time(NULL));
	if ((count = CountAliveInvaders(g)) == 0)
		return;

	nb = 0 + rand() % (count - 0);
	for (i = 0; i < 5; i++)
		if (g->inv[i][f[nb].Y].shoot.exist)
			return;

	CheckForemostInv(g, f[nb].X, f[nb].Y);
	free(f);
}