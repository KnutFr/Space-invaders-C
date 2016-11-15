#include "stdafx.h"
#include "my.h"

void SetAndInitAttack(t_boss *boss)
{
	srand((unsigned int)time(NULL));
	if (boss->health > 400)
		boss->atkNb = rand() % 3;
	else {
		boss->atkNb = rand() % 5;
		if (boss->atkNb == 4)
			boss->atkNb = 3;
	}
	if (boss->atkNb == 0) {
		boss->fb.spriteNb = 3;
		boss->fb.spriteTimer.last = SDL_GetTicks();
	} else if (boss->atkNb == 1 || boss->atkNb == 3) {
		if (boss->atkNb == 1)
			boss->laser.laserSpriteNb = 0;
		else {
			boss->pos.nextX = 50;
			boss->laser.laserSpriteNb = 2;
		}
		boss->laser.ballSpriteNb = 1;
		boss->laser.spriteTimer.last = SDL_GetTicks();
	} else if (boss->atkNb == 2)
		boss->attacking = 1;
	if (boss->atkNb != 3)
		(*boss).atkTimer.last = SDL_GetTicks();
	else
		(*boss).atkTimer.last = 1;
}

void SelectFireballSprite(struct s_fireball *fb)
{
	if (SDL_GetTicks() >= fb->spriteTimer.last + 50)
	{
		fb->spriteNb++;
		if (fb->spriteNb == 4)
			fb->spriteNb = 0;
		fb->spriteTimer.last = SDL_GetTicks();
	}
}

void SetFireballInitialPostion(t_boss *boss)
{
	if (boss->leftArm == 1)
	{
		boss->fb.fbRect.x = (int)boss->pos.x;
		boss->fb.fbRect.y = (int)boss->pos.y + 17;
	}
	else if (boss->rightArm == 1)
	{
		boss->fb.fbRect.x = (int)boss->pos.x + 200;
		boss->fb.fbRect.y = (int)boss->pos.y + 17;
	}
	else if (boss->leftArm == 2)
	{
		boss->fb.fbRect.x = (int)boss->pos.x + 28;
		boss->fb.fbRect.y = (int)boss->pos.y + 55;
	}
	else if (boss->rightArm == 2)
	{
		boss->fb.fbRect.x = (int)boss->pos.x + 172;
		boss->fb.fbRect.y = (int)boss->pos.y + 55;
	}
}

void MoveFireball(t_game *g)
{
	if (!g->boss.fb.stepX && !g->boss.fb.stepY) {
		if (g->boss.leftArm) {
			g->boss.fb.fbRect.x = (int)g->boss.pos.x + 28;
			g->boss.fb.fbRect.y = (int)g->boss.pos.y + 55;
		} else if (g->boss.rightArm) {
			g->boss.fb.fbRect.x = (int)g->boss.pos.x + 172;
			g->boss.fb.fbRect.y = (int)g->boss.pos.y + 55;
		}
		g->boss.fb.stepX = (float)(g->boss.fb.fbRect.x -
			g->ship.rect.x + 28 / 2) / 20;
		g->boss.fb.stepY = (float)(g->boss.fb.fbRect.y -
			(SCREEN_HEIGHT - SHIP_HEIGHT - BORDER)) / 20;
	} else {
		if (g->boss.fb.fbRect.x >= SCREEN_WIDTH || g->boss.fb.fbRect.x <= 0
				|| g->boss.fb.fbRect.y >= SCREEN_HEIGHT) {
			g->boss.fb.stepX = 0;
			g->boss.fb.stepY = 0;
			g->boss.attacking = 0;
			g->boss.atkTimer.last = 0;
		} else {
			g->boss.fb.fbRect.x -= (int)g->boss.fb.stepX;
			g->boss.fb.fbRect.y -= (int)g->boss.fb.stepY;
		}
	}
}

void SetLaserEltsPostions(t_boss *boss, short offset)
{
	if (boss->leftArm == 1) {
		boss->laser.ballRect[0].x = (int)boss->pos.x + 10;
		boss->laser.ballRect[0].y = (int)boss->pos.y + 26;
		boss->laser.ballRect[1].x = (int)boss->pos.x + 203;
		boss->laser.ballRect[1].y = (int)boss->pos.y + 26;
	}
	else if (boss->leftArm == 2) {
		boss->laser.ballRect[0].x = (int)boss->pos.x + 36;
		boss->laser.ballRect[0].y = (int)boss->pos.y + 64;
		boss->laser.ballRect[1].x = (int)boss->pos.x + 177;
		boss->laser.ballRect[1].y = (int)boss->pos.y + 64;
		boss->laser.laserRect[0].x = (int)boss->pos.x + 41 - offset;
		boss->laser.laserRect[0].y = (int)boss->pos.y + 72;
		boss->laser.laserRect[1].x = (int)boss->pos.x + 182 - offset;
		boss->laser.laserRect[1].y = (int)boss->pos.y + 72;
	}
}