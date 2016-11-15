#include "stdafx.h"
#include "my.h"

void LoadInvader(t_game *g, t_index t, SDL_Surface **loader, SDL_Surface **loadfire)
{
	g->inv[t.X][t.Y].img1 = SDL_DisplayFormatAlpha(loader[0]);
	g->inv[t.X][t.Y].img2 = SDL_DisplayFormatAlpha(loader[1]);
	g->inv[t.X][t.Y].life = 1;
	g->inv[t.X][t.Y].score = LoadInvScore(t.X);
	g->inv[t.X][t.Y].rect.x = INV_LEFT + t.Y * INV_SHIFT;
	g->inv[t.X][t.Y].rect.y = INV_TOP + t.X * INV_SHIFT;
	g->inv[t.X][t.Y].shoot.img1 = loadfire[0];
	g->inv[t.X][t.Y].shoot.img2 = loadfire[1];
	g->inv[t.X][t.Y].shoot.exist = 0;
}

void LoadLine(t_game *g)
{
	g->line.img = MyIMG_Load(PATH_LINE, g->line.img);
	g->line.rect.x = 0;
	g->line.rect.y = LINE_Y;
}

void LoadBlocks(t_game *g)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		g->block[i].img1 = MyIMG_Load(PATH_BLOCK1, g->block[i].img1);
		g->block[i].img2 = MyIMG_Load(PATH_BLOCK2, g->block[i].img2);
		g->block[i].img3 = MyIMG_Load(PATH_BLOCK3, g->block[i].img3);
		g->block[i].rect.x = BLOCK_LEFT + (i * BLOCK_SHIFT);
		g->block[i].rect.y = BLOCK_TOP;
		g->block[i].life = 20;
	}
	g->blockDirection = 1;
}

void LoadBoss(t_game *g)
{
	SetArmsAndHeart(&g->boss, 0, 0, 0);
	g->boss.health = 800;
	g->boss.oldhealth = 800;
	g->boss.moving = 1;
	g->boss.attacking = 0;
	g->boss.atkTimer.last = 0;
	g->boss.pos.nextX = 0;
	g->boss.pos.nextY = 0;
	g->boss.pos.stepNb = 80;
	g->boss.pos.speed = 80;
	g->boss.pos.x = SCREEN_WIDTH / 2 - 115;
	g->boss.pos.y = 60;
	g->boss.fb.stepX = 0;
	g->boss.fb.stepY = 0;
}

void LoadBossSprites(t_game *g)
{
	short i;
	char *leftArm[3] = {PATH_LEFT_ARM1, PATH_LEFT_ARM2, PATH_LEFT_ARM3};
	char *rightArm[3] = {PATH_RIGHT_ARM1, PATH_RIGHT_ARM2, PATH_RIGHT_ARM3};
	char *heart[4] = {PATH_HEART1, PATH_HEART2, PATH_HEART3, PATH_HEART4};
	char *fireball[4] = {PATH_FIREBALL1, PATH_FIREBALL2,
						 PATH_FIREBALL3, PATH_FIREBALL4};
	char *ball[2] = {PATH_CHARGING_LASER1, PATH_CHARGING_LASER2};
	char *laser[3] = {PATH_LASER, PATH_SPECIAL_LASER1, PATH_SPECIAL_LASER2};

	for (i = 0; i < 3; i++)
		g->boss.elts[0][i] = MyIMG_Load(leftArm[i], g->boss.elts[0][i]);
	for (i = 0; i < 3; i++)
		g->boss.elts[1][i] = MyIMG_Load(rightArm[i], g->boss.elts[1][i]);
	g->boss.elts[2][0] = MyIMG_Load(PATH_BODY, g->boss.elts[2][0]);
	for (i = 0; i < 4; i++)
		g->boss.elts[3][i] = MyIMG_Load(heart[i], g->boss.elts[3][i]);
	for (i = 0; i < 4; i++)
		g->boss.fb.fb[i] = MyIMG_Load(fireball[i], g->boss.fb.fb[i]);
	for (i = 0; i < 2; i++)
		g->boss.laser.ball[i] = MyIMG_Load(ball[i], g->boss.laser.ball[i]);
	for (i = 0; i < 3; i++)
		g->boss.laser.laser[i] = MyIMG_Load(laser[i], g->boss.laser.laser[i]);
}