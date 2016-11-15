#include "stdafx.h"
#include "my.h"

void Fireball(t_game *g)
{
	if (SDL_GetTicks() - g->boss.atkTimer.last < 1500) {
		if (g->boss.heart != 1) {
			g->boss.attacking = 1;
			if (g->ship.rect.x + 14 <= g->boss.pos.x + 115)
				SetArmsAndHeart(&g->boss, 1, 0, 1);
			else
				SetArmsAndHeart(&g->boss, 0, 1, 1);
			SetFireballInitialPostion(&g->boss);
		}
		SelectFireballSprite(&g->boss.fb);
	} else {
		if (SDL_GetTicks() - g->boss.atkTimer.last < 2000
				&& g->boss.leftArm != 2 && g->boss.rightArm != 2) {
			if (g->boss.leftArm)
				g->boss.leftArm = 2;
			else
				g->boss.rightArm = 2;
		} else if (SDL_GetTicks() - g->boss.atkTimer.last >= 2000
				&& !g->boss.moving) {
			SetArmsAndHeart(&g->boss, 0, 0, 0);
			g->boss.moving = 1;
		}
		SelectFireballSprite(&g->boss.fb);
		MoveFireball(g);
	}
}

void Laser(t_game *g)
{
	if (SDL_GetTicks() - g->boss.atkTimer.last < 1500) {
		if (g->boss.heart != 2) {
			SetArmsAndHeart(&g->boss, 1, 1, 2);
			SetLaserEltsPostions(&g->boss, 0);
			prepareDynamicAttack(&g->boss);
			if (g->boss.pos.x + 85 == g->ship.rect.x + 28 / 2)
				g->boss.pos.stepX = 4;
			else
				g->boss.pos.stepX = 4 * (g->boss.pos.x + 85 - g->ship.rect.x + 28 / 2) / (float)fabs(g->boss.pos.x + 85 - g->ship.rect.x + 28 / 2);
		}
		SelectLaserBallSprite(&g->boss.laser);
	} else if (SDL_GetTicks() - g->boss.atkTimer.last < 3000 && ((g->boss.pos.x >= 50 && g->boss.pos.stepX == 4) || (g->boss.pos.x <= 445 && g->boss.pos.stepX == -4))) {
		if (g->boss.leftArm != 2)
			SetArmsAndHeart(&g->boss, 2, 2, 2);
		moveBoss(&g->boss);
		SelectLaserBallSprite(&g->boss.laser);
		SetLaserEltsPostions(&g->boss, 0);
	} else if (SDL_GetTicks() - g->boss.atkTimer.last < 3500) {
		if (g->boss.leftArm != 0) {
			SetArmsAndHeart(&g->boss, 0, 0, 0);
			finishDynamicAttack(&g->boss);
		}
	} else {
		g->boss.atkTimer.last = 0;
		g->boss.moving = 1;
	}
}

void Charge(t_game *g)
{
	if (SDL_GetTicks() - g->boss.atkTimer.last < 2500
			&& g->boss.attacking == 1) {
		if (g->boss.pos.stepNb == g->boss.pos.speed)
			prepareDynamicAttack(&g->boss);
		GetChargeSteps(g, 0);
		moveBoss(&g->boss);
	} else {
		GetChargeSteps(g, 1);
		if (g->boss.attacking == 1) {
			moveBoss(&g->boss);
			if (g->boss.pos.y <= 200 && g->boss.pos.stepY == 18) {
				g->boss.attacking = 0;
				g->boss.atkTimer.last = SDL_GetTicks();
			}
		} else if (g->boss.atkTimer.last >= 500) {
			finishDynamicAttack(&g->boss);
			g->boss.atkTimer.last = 0;
			g->boss.moving = 1;
		}
	}
}

void SpecialAttack(t_boss *boss)
{
	if (boss->atkTimer.last == 1) {
		SetArmsAndHeart(boss, 1, 1, 3);
		SetLaserEltsPostions(boss, 0);
		boss->atkTimer.last = SDL_GetTicks() - 500;
	}
	if (SDL_GetTicks() - boss->atkTimer.last <= 1100)
		SelectLaserBallSprite(&boss->laser);
	else if (SDL_GetTicks() - boss->atkTimer.last <= 1500) {
		if (boss->leftArm != 2) {
			SetArmsAndHeart(boss, 2, 2, 3);
			SetLaserEltsPostions(boss, 3);
		}
		SelectLaserSprite(&boss->laser);
		SelectLaserBallSprite(&boss->laser);
	} else if (SDL_GetTicks() - boss->atkTimer.last <= 1600) {
		if (boss->leftArm != 0) {
			SetArmsAndHeart(boss, 0, 0, 3);
			finishDynamicAttack(boss);
		}
	} else if (boss->pos.x != 430) {
		boss->pos.nextX += 190;
		boss->atkTimer.last = 1;
	} 
}