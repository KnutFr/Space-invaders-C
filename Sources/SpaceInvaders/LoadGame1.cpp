#include "stdafx.h"
#include "my.h"

void LoadBackground(t_game *g)
{
	g->bg.img1 = MyIMG_Load(PATH_BG_GAME, g->bg.img1);
	g->bg.img2 = MyIMG_Load(PATH_BG_GAME2, g->bg.img2);
	g->bg.rect.x = 0;
	g->bg.rect.y = 0;
}

void LoadFire(t_game *g)
{
	g->shoot.img1 = MyIMG_Load(PATH_SHIP_SHOOT, g->shoot.img1);
	g->shoot.img2 = MyIMG_Load(PATH_EXPLOSION, g->shoot.img2);
}

void LoadShip(t_game *g)
{
	g->ship.rect.x = (SCREEN_WIDTH / 2) - (SHIP_WIDTH /2);
	g->ship.rect.y = SCREEN_HEIGHT - SHIP_HEIGHT - BORDER;
	g->ship.destroyedTimer.last = 0;
	g->ship.blinkingTimer.last = 0;
}

void LoadScore(t_game *g)
{
	char buffer[5];

	g->score.font = TTF_OpenFont(PATH_VISITOR, 24);
	g->score.msgColor.r = 255;
	g->score.msgColor.g = 255;
	g->score.msgColor.b = 255;
	g->score.msgRect.x = 20;
	g->score.msgRect.y = 14;
	g->score.msg = TTF_RenderText_Blended(g->score.font, "score : ", 
		g->score.msgColor); 
	g->score.scoreColor.r = 43;
	g->score.scoreColor.g = 216;
	g->score.scoreColor.b = 4;
	g->score.scoreRect.x = 130;
	g->score.scoreRect.y = 14;
	g->score.value = 0;
	g->score.score = TTF_RenderText_Solid(g->score.font,_itoa(g->score.value,
		buffer, 10), g->score.scoreColor); 
}

void LoadLives(t_game *g)
{
	char buffer[5];

	g->life.font = TTF_OpenFont(PATH_VISITOR, 24);
	g->life.msgColor.r = 255;
	g->life.msgColor.g = 255;
	g->life.msgColor.b = 255;
	g->life.msgRect.x = 560;
	g->life.msgRect.y = 14;
	g->life.msg = TTF_RenderText_Blended(g->life.font, "lives : ", 
		g->life.msgColor); 
	g->life.lifeColor.r = 43;
	g->life.lifeColor.g = 216;
	g->life.lifeColor.b = 4;
	g->life.lifeRect.x = 660;
	g->life.lifeRect.y = 14;
	g->life.life = TTF_RenderText_Solid(g->life.font, _itoa(g->ship.life, 
		buffer, 10), g->life.lifeColor);
}