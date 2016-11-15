#include "stdafx.h"
#include "my.h"

void LoadBossHealth(t_game *g)
{
	g->boss.life.font = TTF_OpenFont(PATH_VISITOR, 24);
	g->boss.life.msgColor.r = 255;
	g->boss.life.msgColor.g = 255;
	g->boss.life.msgColor.b = 255;
	g->boss.life.msgRect.x = 280;
	g->boss.life.msgRect.y = 14;
	g->boss.life.msg = TTF_RenderText_Blended(g->boss.life.font, "health : ", 
		g->boss.life.msgColor); 
	g->boss.life.lifeColor.r = 43;
	g->boss.life.lifeColor.g = 216;
	g->boss.life.lifeColor.b = 4;
	g->boss.life.lifeRect.x = 380;
	g->boss.life.lifeRect.y = 14;
}