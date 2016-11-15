#include "stdafx.h"
#include "my.h"

void SelectLaserBallSprite(struct s_laser *laser)
{
	if (SDL_GetTicks() >= laser->spriteTimer.last + 50)
	{
		if (laser->ballSpriteNb == 0)
			laser->ballSpriteNb = 1;
		else
			laser->ballSpriteNb = 0;
		laser->spriteTimer.last = SDL_GetTicks();
	}
}

void SelectLaserSprite(struct s_laser *laser)
{
	if (SDL_GetTicks() >= laser->spriteTimer.last + 50)
	{
		if (laser->laserSpriteNb == 1)
			laser->laserSpriteNb = 2;
		else
			laser->laserSpriteNb = 1;
	}
}

void GetChargeSteps(t_game *g, short flag)
{
	if (!flag)
	{
		if (g->boss.pos.x + 88 != g->ship.rect.x + 28 / 2
				&& fabs(g->boss.pos.x + 88 - g->ship.rect.x + 28 / 2) > 8)
			g->boss.pos.stepX = 8
				* (g->boss.pos.x + 88 - g->ship.rect.x + 28 / 2)
				/ (float)fabs(g->boss.pos.x + 88 - g->ship.rect.x + 28 / 2);
		else if (g->boss.pos.x + 88 != g->ship.rect.x + 28 / 2)
			g->boss.pos.stepX = g->boss.pos.x + 88 - g->ship.rect.x + 28 / 2;
	}
	else
	{
		if (g->boss.pos.stepY == 0 && g->boss.pos.y != g->ship.rect.y
				&& g->boss.attacking == 1)
		{
			g->boss.pos.stepX = 0;
			g->boss.pos.stepY = -18;
		}
		else if (g->boss.pos.y + 120 == g->ship.rect.y
				&& g->boss.attacking == 1)
			g->boss.pos.stepY = 18;
		else if (g->boss.pos.y + 120 + 18 > g->ship.rect.y
				&& g->boss.pos.stepY != 18 && g->boss.attacking == 1)
			g->boss.pos.stepY = g->boss.pos.y + 120 - g->ship.rect.y;
	}
}

void SpecialAttackMoves(t_game *g)
{
	if (g->boss.pos.nextX != g->boss.pos.x) {
		if (g->boss.pos.stepNb == g->boss.pos.speed) {
			prepareDynamicAttack(&g->boss);
			SetArmsAndHeart(&g->boss, 0, 0, 3);
			g->boss.pos.stepX = 12 * (g->boss.pos.x - g->boss.pos.nextX)
				/ (float)fabs(g->boss.pos.x - g->boss.pos.nextX);
		}
		if (fabs(g->boss.pos.x - g->boss.pos.nextX) < 12
				&& g->boss.pos.x - g->boss.pos.nextX != 0)
			g->boss.pos.stepX = fabs(g->boss.pos.x - g->boss.pos.nextX)
				* (g->boss.pos.x - g->boss.pos.nextX)
				/ (float)fabs(g->boss.pos.x - g->boss.pos.nextX);
		moveBoss(&g->boss);
	} else {
		if (g->boss.atkTimer.last == 1 || SDL_GetTicks() - g->boss.atkTimer.last <= 1600 || g->boss.pos.x != 430)
			SpecialAttack(&g->boss);
		else {
			if (g->boss.heart == 3)
				SetArmsAndHeart(&g->boss, 0, 0, 0);
			if (SDL_GetTicks() - g->boss.atkTimer.last <= 2100) {
				g->boss.atkTimer.last = 0;
				g->boss.moving = 1;
			}
		}
	}
}