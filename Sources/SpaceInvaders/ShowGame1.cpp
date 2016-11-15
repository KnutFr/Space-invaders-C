#include "stdafx.h"
#include "my.h"

void ShowGame(t_game *g)
{
	ShowBackground(g);
	ShowGameShip(g);
	if (g->level != 4)
	{
		SDL_BlitSurface(g->score.msg, NULL, g->screen, &g->score.msgRect);
		SDL_BlitSurface(g->score.score, NULL, g->screen, &g->score.scoreRect);
		SDL_BlitSurface(g->life.msg, NULL, g->screen, &g->life.msgRect);
		SDL_BlitSurface(g->life.life, NULL, g->screen, &g->life.lifeRect);
		SDL_BlitSurface(g->line.img, NULL, g->screen, &g->line.rect);
		ShowAnimatedInvaders(g);
		if (g->level > 1)
		{
			ShowBlocks(g);
			ShowInvShots(g);
		}
		CheckCollisions(g);
	}
	else
	{
		ShowBoss(g);
		ShowBossLevelTxt(g);
		if (g->boss.attacking)
			ShowBossAtk(g);
	}
}

void ShowAnimatedInvaders(t_game *g)
{
	int i;
	int j;

	for (i = 0; i < INV_ROW; i++)
		for (j = 0; j < INV_COL; j++)
			if (g->inv[i][j].life)
				if (g->switcher == 1)
					SDL_BlitSurface(g->inv[i][j].img1, NULL, g->screen, 
					&g->inv[i][j].rect);
				else
					SDL_BlitSurface(g->inv[i][j].img2, NULL, g->screen,
					&g->inv[i][j].rect);
	MoveInvader(g);
}

void ShowInvShots(t_game *g)
{
	int i;
	int j;

	GenerateFire(g, GetAliveInvIndex(g));
	for (i = 0; i < INV_ROW; i++)
		for (j = 0; j < INV_COL; j++)
			if (g->inv[i][j].shoot.exist)
			{
				SDL_BlitSurface(g->inv[i][j].shoot.img1, NULL, g->screen, 
					&g->inv[i][j].shoot.rect);
				g->inv[i][j].shoot.rect.y += 4;
				if (g->inv[i][j].shoot.rect.y > SCREEN_HEIGHT + 10)
				{
					g->inv[i][j].shoot.exist = 0;
					g->inv[i][j].shoot.rect.x = 0;
					g->inv[i][j].shoot.rect.y = 0;
				}
			}
}

void ShowGameOver(t_game *g)
{
	char buffer[5];
	
	g->gameover.msg = TTF_RenderText_Blended(g->gameover.font, 
		"final score : ", g->score.msgColor);
	g->gameover.score = TTF_RenderText_Solid(g->gameover.font,_itoa(
	g->score.value, buffer, 10), g->score.scoreColor);
	while (g->event.key.keysym.sym != SDLK_RETURN) 
	{
		ShowBackground(g);
		SDL_BlitSurface(g->gameover.title, NULL, g->screen,
			&g->gameover.titleRect);
		SDL_BlitSurface(g->gameover.msg, NULL, g->screen, 
			&g->gameover.msgRect);
		SDL_BlitSurface(g->gameover.score, NULL, g->screen, 
			&g->gameover.scoreRect);
		SDL_Flip(g->screen);
		SDL_Delay(30);
		SDL_WaitEvent(&g->event);
	}
	g->level =1;
}

void ShowGameShip(t_game *g)
{
	if (g->ship.oldLife != g->ship.life) 
	{
		g->ship.oldLife = g->ship.life;
		g->ship.destroyedTimer.last = SDL_GetTicks();
		SDL_BlitSurface(g->shoot.img2, NULL, g->screen, &g->ship.rect);
	} else if (g->ship.destroyedTimer.last == 0
			|| (g->ship.blinkingTimer.last != 0 
			&& SDL_GetTicks() - g->ship.blinkingTimer.last > 100)) 
	{
		SDL_BlitSurface(g->ship.img, NULL, g->screen, &g->ship.rect);
		if (g->ship.blinkingTimer.last != 0 
				&& SDL_GetTicks() - g->ship.blinkingTimer.last > 200)
			g->ship.blinkingTimer.last = SDL_GetTicks();
	}
}
