#include "stdafx.h"
#include "my.h"

void MoveDownInvaders(t_game *g)
{
	int i;
	int j;
	t_index *t;

	for (i = 0; i < INV_ROW; i++)
		for (j = 0; j < INV_COL; j++)
			g->inv[i][j].rect.y += MOVE_INVY;

	t = GetAliveInvIndex(g);
	for (i = 0; i < CountAliveInvaders(g); i++)
		if (g->inv[t[i].X][t[i].Y].rect.y + INV_HEIGHT > LINE_Y)
			g->ship.life = 0;
}

void MoveInvader(t_game *g)
{
	int i;
	int j;

	if (g->inv[0][INV_COL-1].rect.x + INV_WIDTH > SCREEN_WIDTH - BORDER ||
		g->inv[0][0].rect.x < BORDER)
	{
		g->direction *= (-1);
		MoveDownInvaders(g);
	}

	for (i = 0; i < INV_ROW; i++)
		for (j = 0; j < INV_COL; j++)
			g->inv[i][j].rect.x += (g->direction * MOVE_INVX);
}

int ShipReappearance(t_game *g)
{
	if (SDL_GetTicks() - g->ship.destroyedTimer.last >= 1000
			&& SDL_GetTicks() - g->ship.destroyedTimer.last < 3000)
	{
		if (g->ship.blinkingTimer.last == 0)
			g->ship.blinkingTimer.last = SDL_GetTicks();
	} else if (SDL_GetTicks() - g->ship.destroyedTimer.last >= 3000)
	{
		g->ship.blinkingTimer.last = 0;
		g->ship.destroyedTimer.last = 0;
	}

	return 0;
}

int CountAliveInvaders(t_game *g)
{
	int i;
	int j;
	int count;

	for (i = 0, count =0; i < INV_ROW; i++)
		for (j = 0; j < INV_COL; j++)
			if (g->inv[i][j].life)
				count++;
	return count;
}

t_index *GetAliveInvIndex(t_game *g)
{
	int nbInv;
	t_index *f;
	int i;
	int j;
	int offset;

	nbInv = CountAliveInvaders(g);
	f = (t_index*) malloc(nbInv * sizeof(t_index));

	for (i = 0, offset = 0; i < INV_ROW; i++)
		for (j = 0; j < INV_COL; j++)
			if (g->inv[i][j].life)
			{
				f[offset].X = i;
				f[offset].Y = j;
				offset++;
			}

	return f;
}