#include "stdafx.h"
#include "my.h"

void CheckShipShoot(t_game *g)
{
	int i;
	int j;
	char buffer[5] = {'0', '0', '0', '0','0'};

	for (i = 0; i < INV_ROW; i++)
		for (j = 0; j < INV_COL; j++)
			if (g->inv[i][j].life)
 				if (g->shoot.rect.y <= g->inv[i][j].rect.y + INV_HEIGHT && 
					g->shoot.rect.y >= g->inv[i][j].rect.y && g->shoot.rect.x
					<= g->inv[i][j].rect.x + INV_WIDTH - 1 && g->shoot.rect.x
					>= g->inv[i][j].rect.x)
				{
 					g->shoot.rect.x = g->inv[i][j].rect.x;
					g->shoot.rect.y = g->inv[i][j].rect.y;
					g->inv[i][j].life = g->shoot.exist = 0;
					SDL_BlitSurface(g->shoot.img2, NULL, g->screen, 
						&g->shoot.rect); 
					g->score.value += g->inv[i][j].score;
					g->score.score = TTF_RenderText_Solid(g->score.font, _itoa(
						g->score.value, buffer, 10), g->score.scoreColor);
					return;
				}
	SDL_BlitSurface(g->shoot.img1, NULL, g->screen, &g->shoot.rect);
}

void CheckInvShootsWithShipShoot(t_game *g, int i, int j)
{
	if (g->inv[i][j].shoot.rect.y + SHOOT_HEIGHT >= g->shoot.rect.y &&
		g->inv[i][j].shoot.rect.y + SHOOT_HEIGHT <= g->shoot.rect.y + 
		SHOOT_HEIGHT + 10 && g->inv[i][j].shoot.rect.x >= g->shoot.rect.x
		- 4 && g->inv[i][j].shoot.rect.x <= g->shoot.rect.x + SHOOT_WIDTH + 4)
	{
		g->inv[i][j].shoot.exist = g->shoot.exist = 0;
		g->inv[i][j].shoot.rect.x = g->shoot.rect.x - 5;
		g->inv[i][j].shoot.rect.y = g->shoot.rect.y;
		SDL_BlitSurface(g->inv[i][j].shoot.img2, NULL, g->screen, 
			&g->inv[i][j].shoot.rect);
	}
}

void CheckInvShootsWithShip(t_game *g)
{
	int i;
	int j;
	char buffer[4];

	for (i = 0; i < INV_ROW; i++)
		for (j = 0; j < INV_COL; j++)
			if (g->inv[i][j].shoot.exist) {
				if (g->inv[i][j].shoot.rect.y + SHOOT_HEIGHT >= g->ship.rect.y
				&& g->inv[i][j].shoot.rect.y + SHOOT_HEIGHT <= 
				g->ship.rect.y + SHIP_HEIGHT && g->inv[i][j].shoot.rect.x
				>= g->ship.rect.x - 2 && g->inv[i][j].shoot.rect.x <= 
				g->ship.rect.x + SHIP_WIDTH + 2) {
					g->ship.life -= 1;
					g->inv[i][j].shoot.exist = 0;
					g->inv[i][j].shoot.rect.x = g->ship.rect.x;
					g->inv[i][j].shoot.rect.y = g->ship.rect.y;
					SDL_BlitSurface(g->inv[i][j].shoot.img2, NULL, 
						g->screen, &g->inv[i][j].shoot.rect);
					g->life.life = TTF_RenderText_Solid(g->life.font, 
						_itoa(g->ship.life, buffer, 10), g->life.lifeColor);
				}
				if (g->shoot.exist)
					CheckInvShootsWithShipShoot(g, i, j);
				CheckInvShootsWithBlock(g, i, j);
			}
}

void CheckCollisions(t_game *g)
{
	if (g->shoot.exist)
	{
		g->shoot.rect.y -= MOVE_SHOOT;

		if (g->shoot.rect.y <= 0)
			g->shoot.exist = 0;

		CheckShipShoot(g);
		if (g->level > 1)
			CheckShipShootWithBlocks(g);
	}
	CheckInvShootsWithShip(g);
}

void CheckShipShootWithBlocks(t_game *g)
{
	int i;

	if (g->shoot.exist)
		for (i = 0; i < 4; i++)
			if (g->block[i].life > 0 && g->shoot.rect.y <= g->block[i].rect.y 
				+ BLOCK_HEIGHT && g->shoot.rect.y >= g->block[i].rect.y &&
				g->shoot.rect.x <= g->block[i].rect.x + BLOCK_WIDTH &&
				g->shoot.rect.x >= g->block[i].rect.x)
			{
					g->block[i].life--;
					g->shoot.rect.x -= (EXPLOSION_WIDTH / 2);
					SDL_BlitSurface(g->shoot.img2, NULL, g->screen, 
						&g->shoot.rect);
					g->shoot.exist = 0;
			}
}