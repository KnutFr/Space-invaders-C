#include "stdafx.h"
#include "my.h"

void CheckInvShootsWithBlock(t_game *g, int i, int j)
{
	int k;

	if (g->inv[i][j].shoot.exist)
		for (k = 0; k < 4; k++)
			if (g->block[k].life > 0 && g->inv[i][j].shoot.rect.y + 
				SHOOT_HEIGHT >= g->block[k].rect.y && 
				g->inv[i][j].shoot.rect.y + SHOOT_HEIGHT <= g->block[k].rect.y
				+ BLOCK_HEIGHT && g->inv[i][j].shoot.rect.x >= 
				g->block[k].rect.x && g->inv[i][j].shoot.rect.x <= 
				g->block[k].rect.x + BLOCK_WIDTH)
			{
					g->block[k].life--;
					g->inv[i][j].shoot.rect.x -= (EXPLOSION_WIDTH / 2);
					SDL_BlitSurface(g->inv[i][j].shoot.img2, NULL, g->screen, 
						&g->inv[i][j].shoot.rect);
					g->inv[i][j].shoot.exist = 0;
			}
}

void CheckShipWithBoss(t_game *g)
{
	if (xPosShootChecker(g, 105, 125) && yPosShootChecker(g, 85, 98)) {
		if (g->boss.heart != 0)
			setScoreAndBossHealth(g, 100, 25);
		else 
			setScoreAndBossHealth(g, 30, 10);
	} else if (xPosShootChecker(g, 87, 143)) {
		if (yPosShootChecker(g, 3, 64))
			setScoreAndBossHealth(g, 20, 10);
	} else if (xPosShootChecker(g, 81, 149)) {
		if (yPosShootChecker(g, 3, 52))
			setScoreAndBossHealth(g, 20, 10);
	} else if (xPosShootChecker(g, 1, 80)) {
		if (CheckArm(g, g->boss.leftArm, -1))
			setScoreAndBossHealth(g, 10, 10);
	} else if (xPosShootChecker(g, 150, 229)) {
		if (CheckArm(g, g->boss.rightArm, 1))
			setScoreAndBossHealth(g, 10, 10);
	}
}

int CheckArm(t_game *g, short armIndicator, short coeff)
{
	if (armIndicator == 0
			&& xPosShootChecker(g, 115 + coeff * 35, 115 + coeff * 75)) {
		if (yPosShootChecker(g, 24, 48))
			return 1;
	} else if (armIndicator == 0
			&& xPosShootChecker(g, 115 + coeff * 76, 115 + coeff * 104)) {
		if (yPosShootChecker(g, 40, 62))
			return 1;
	} else if (armIndicator == 1
			&& xPosShootChecker(g, 115 + coeff * 35, 115 + coeff * 114)) {
		if (yPosShootChecker(g, 15, 40))
			return 1;
	} else if (armIndicator == 2
			&& xPosShootChecker(g, 115 + coeff * 35, 115 + coeff * 58)) {
		if (yPosShootChecker(g, 26, 52))
			return 1;
	} else if (armIndicator == 2
			&& xPosShootChecker(g, 115 + coeff * 59, 115 + coeff * 88)) {
		if (yPosShootChecker(g, 28, 75))
			return 1;
	}

	return 0;
}

int xPosShootChecker(t_game *g, short x1, short x2)
{
	short Xmin, Xmax;

	if (x1 < x2) {
		Xmin = x1;
		Xmax = x2;
	} else {
		Xmin = x2;
		Xmax = x1;
	}


	if ((g->shoot.rect.x >= g->boss.pos.x + Xmin
			&& g->shoot.rect.x <= g->boss.pos.x + Xmax)
			|| (g->shoot.rect.x + 3 >= g->boss.pos.x + Xmin
			&& g->shoot.rect.x + 3 <= g->boss.pos.x + Xmax))
		return 1;

	return 0;
}

int yPosShootChecker(t_game *g, short y1, short y2)
{
	short Ymin, Ymax;

	if (y1 < y2) {
		Ymin = y1;
		Ymax = y2;
	} else {
		Ymin = y2;
		Ymax = y1;
	}


	if ((g->shoot.rect.y >= g->boss.pos.y + Ymin
			&& g->shoot.rect.y <= g->boss.pos.y + Ymax)
			|| (g->shoot.rect.y + 8 >= g->boss.pos.y + Ymin
			&& g->shoot.rect.y + 8 <= g->boss.pos.y + Ymax))
		return 1;

	return 0;
}