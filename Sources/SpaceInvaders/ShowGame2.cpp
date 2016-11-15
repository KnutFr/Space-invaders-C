#include "stdafx.h"
#include "my.h"

void ShowBlocks(t_game *g)
{
	int i;

	if (g->level > 2)
		MoveBlock(g);
	for (i = 0; i < 4; i++)
		if (g->block[i].life == 20)
			SDL_BlitSurface(g->block[i].img1, NULL, g->screen, &g->block[i].rect);
		else if (g->block[i].life > 9)
			SDL_BlitSurface(g->block[i].img2, NULL, g->screen, &g->block[i].rect);
		else if (g->block[i].life > 0)
			SDL_BlitSurface(g->block[i].img3, NULL, g->screen, &g->block[i].rect);
}

void ShowBoss(t_game *g)
{
	SDL_BlitSurface(g->boss.elts[0][g->boss.leftArm],
					NULL, g->screen, &g->boss.eltsRects[0]);
	SDL_BlitSurface(g->boss.elts[1][g->boss.rightArm],
					NULL, g->screen, &g->boss.eltsRects[1]);
	SDL_BlitSurface(g->boss.elts[2][0],
					NULL, g->screen, &g->boss.eltsRects[2]);
	SDL_BlitSurface(g->boss.elts[3][g->boss.heart],
					NULL, g->screen, &g->boss.eltsRects[3]);
	
	if (g->shoot.exist) {
		SDL_BlitSurface(g->shoot.img1, NULL, g->screen, &g->shoot.rect);
		g->shoot.rect.y -= MOVE_SHOOT;
		if (g->shoot.rect.y <= 0)
			g->shoot.exist = 0;
	}
	else if (g->boss.oldhealth != g->boss.health)
	{
		g->boss.oldhealth = g->boss.health;
		g->shoot.rect.x -= 12;
		SDL_BlitSurface(g->shoot.img2, NULL, g->screen, &g->shoot.rect);
	}
}

void ShowBossLevelTxt(t_game *g)
{
	char buffer[5];

	SetEltsPositions(&g->boss);
	g->score.score = TTF_RenderText_Blended(g->score.font,
		_itoa(g->score.value, buffer, 10), g->score.scoreColor);
	g->boss.life.life = TTF_RenderText_Blended(g->boss.life.font,
		_itoa(g->boss.health, buffer, 10), g->boss.life.lifeColor);
	g->life.life = TTF_RenderText_Blended(g->life.font,
		_itoa(g->ship.life, buffer, 10), g->life.lifeColor);

	SDL_BlitSurface(g->boss.life.msg,
					NULL, g->screen, &g->boss.life.msgRect);
	SDL_BlitSurface(g->boss.life.life,
					NULL, g->screen, &g->boss.life.lifeRect);
	SDL_BlitSurface(g->score.msg, NULL, g->screen, &g->score.msgRect);
	SDL_BlitSurface(g->score.score, NULL, g->screen, &g->score.scoreRect);
	SDL_BlitSurface(g->life.msg, NULL, g->screen, &g->life.msgRect);
	SDL_BlitSurface(g->life.life, NULL, g->screen, &g->life.lifeRect);
}

void ShowBossAtk(t_game *g)
{
	if (g->boss.atkNb == 0)
		SDL_BlitSurface(g->boss.fb.fb[g->boss.fb.spriteNb],
						NULL, g->screen, &g->boss.fb.fbRect);
	else if (g->boss.atkNb == 1 || g->boss.atkNb == 3) {
		if (g->boss.laser.laserRect[0].x != 0) {
			SDL_BlitSurface(g->boss.laser.laser[g->boss.laser.laserSpriteNb],
							NULL, g->screen, &g->boss.laser.laserRect[0]);
			SDL_BlitSurface(g->boss.laser.laser[g->boss.laser.laserSpriteNb],
							NULL, g->screen, &g->boss.laser.laserRect[1]);
		}
		if (g->boss.laser.ballRect[0].x != 0) {
			SDL_BlitSurface(g->boss.laser.ball[g->boss.laser.ballSpriteNb],
							NULL, g->screen, &g->boss.laser.ballRect[0]);
			SDL_BlitSurface(g->boss.laser.ball[g->boss.laser.ballSpriteNb],
							NULL, g->screen, &g->boss.laser.ballRect[1]);
		}
	}
}

void ShowBackground(t_game *g)
{
	g->nowTime = SDL_GetTicks();
	if (g->nowTime > g->lastTime + INV_DELAY)
	{
		g->switcher = g->switcher % 2 + 1;
		g->lastTime = g->nowTime;
	}
	if (g->switcher == 1)
		SDL_BlitSurface(g->bg.img1, NULL, g->screen, &g->bg.rect);
	else
		SDL_BlitSurface(g->bg.img2, NULL, g->screen, &g->bg.rect);
}