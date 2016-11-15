#include "stdafx.h"
#include "my.h"

void SetArmsAndHeart(t_boss *boss, short leftArm, short rightArm, short heart)
{
	boss->leftArm = leftArm;
	boss->rightArm = rightArm;
	boss->heart = heart;
}

void SetEltsPositions(t_boss *boss)
{
	short i;
	short eltsPos[4][2] = {{0, 8}, {154, 8}, {50, 0}, {105, 82}};

	for (i = 0; i < 4; i++) {
		boss->eltsRects[i].x = (int)boss->pos.x + eltsPos[i][0];
		boss->eltsRects[i].y = (int)boss->pos.y + eltsPos[i][1];
	}
}

void prepareDynamicAttack(t_boss *boss)
{
	boss->attacking = 1;
	boss->pos.stepNb += 10;
	boss->pos.speedCoef = 1;
	boss->pos.stepX = 0;
	boss->pos.stepY = 0;
}

void finishDynamicAttack(t_boss *boss)
{
	boss->attacking = 0;
	boss->pos.stepNb = 80;
	boss->laser.ballRect[0].x = 0;
	boss->laser.laserRect[0].x = 0;
}

void setScoreAndBossHealth(t_game *g, short pointsWon, short bossHealthLost)
{
	g->shoot.exist = 0;
	g->score.value += pointsWon;
	if (g->boss.health - bossHealthLost >= 0)
		g->boss.health -= bossHealthLost;
	else
		g->boss.health = 0;
}