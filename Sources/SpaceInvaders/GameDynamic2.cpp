#include "stdafx.h"
#include "my.h"

void MoveBlock(t_game *g)
{
	int i;

	if (g->block[3].rect.x + BLOCK_WIDTH > SCREEN_WIDTH - BORDER ||
		g->block[0].rect.x < BORDER)
		g->blockDirection *= (-1);

	for (i = 0; i < 4; i++)
		g->block[i].rect.x += (g->blockDirection * MOVE_BLOCK);
}

void animateBoss (t_game *g)
{
	char buffer[5];

	void (*attacksPtr[4])(t_game *) = {Fireball, Laser, Charge,
									   SpecialAttackMoves};
	void (*collisionsPtr[4])(t_game *) = {FireballCollision, LaserCollision,
										  ChargeCollision, LaserCollision};

	if (g->boss.moving)
	{
		moveBoss(&g->boss);
		if(!g->boss.moving)
			SetAndInitAttack(&g->boss);
	}
	if (g->boss.atkTimer.last && SDL_GetTicks() - g->boss.atkTimer.last >= 500)
	{
		(*attacksPtr[g->boss.atkNb])(g);
		if (g->ship.destroyedTimer.last == 0)
			(*collisionsPtr[g->boss.atkNb])(g);
	}
	if (g->shoot.exist && g->shoot.rect.y < g->boss.pos.y + 110)
		CheckShipWithBoss(g);
}

void moveBoss(t_boss *boss)
{
	if (boss->pos.stepNb == boss->pos.speed) {
		boss->pos.nextX = (float)(50 + rand() % (420 - 50));
		boss->pos.nextY = (float)(60 + rand() % (300 - 60));
		if (fabs(boss->pos.x - boss->pos.nextX) < 150
				&& fabs(boss->pos.y - boss->pos.nextY) < 150)
			boss->pos.speedCoef = (float)0.5;
		else
			boss->pos.speedCoef = 1;
		boss->pos.stepX = (boss->pos.x - boss->pos.nextX)
						  / ((float)boss->pos.speed * boss->pos.speedCoef);
		boss->pos.stepY = (boss->pos.y - boss->pos.nextY)
						  / ((float)boss->pos.speed * boss->pos.speedCoef);
		boss->pos.stepNb = 0;
	} else {
		boss->pos.stepNb += (short)(1 / boss->pos.speedCoef);
		if (boss->pos.stepNb == boss->pos.speed) {
			boss->pos.x = boss->pos.nextX;
			boss->pos.y = boss->pos.nextY;
			if (boss->attacking == 0)
				boss->moving = 0;
		} else {
			boss->pos.x -= boss->pos.stepX;
			boss->pos.y -= boss->pos.stepY;
		}
	}
}