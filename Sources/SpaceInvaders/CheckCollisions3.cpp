#include "stdafx.h"
#include "my.h"

void FireballCollision(t_game *g)
{
	if (g->boss.fb.stepX && g->boss.fb.stepY) {
			if (g->boss.fb.fbRect.y + 16 >= g->ship.rect.y
					&& ((g->ship.rect.x + 10 >= g->boss.fb.fbRect.x
					&& g->ship.rect.x + 10 <= g->boss.fb.fbRect.x + 30)
					|| (g->ship.rect.x + 20 >= g->boss.fb.fbRect.x
					&& g->ship.rect.x + 20 <= g->boss.fb.fbRect.x + 30)))
				g->ship.life--;
			else if (g->ship.rect.y >= g->boss.fb.fbRect.y -5
					&& g->ship.rect.y <= g->boss.fb.fbRect.y +5
					&& ((g->ship.rect.x + 2 >= g->boss.fb.fbRect.x
					&& g->ship.rect.x + 2 <= g->boss.fb.fbRect.x + 30)
					|| (g->ship.rect.x + 26 >= g->boss.fb.fbRect.x
					&& g->ship.rect.x + 26 <= g->boss.fb.fbRect.x + 30)))
				g->ship.life--;
	}
}

void LaserCollision(t_game *g)
{
	if (g->boss.atkNb == 1 && g->boss.leftArm == 2) {
		if ((g->boss.laser.laserRect[0].x >= g->ship.rect.x
				&& g->boss.laser.laserRect[0].x <= g->ship.rect.x + 28)
				|| (g->boss.laser.laserRect[0].x + 6 >= g->ship.rect.x
				&& g->boss.laser.laserRect[0].x + 6 <= g->ship.rect.x + 28)
				|| (g->boss.laser.laserRect[1].x >= g->ship.rect.x
				&& g->boss.laser.laserRect[1].x <= g->ship.rect.x + 28)
				|| (g->boss.laser.laserRect[1].x + 6 >= g->ship.rect.x
				&& g->boss.laser.laserRect[1].x + 6 <= g->ship.rect.x + 28))
			g->ship.life--;
	} else if (g->boss.atkNb == 3 && g->boss.leftArm == 2) {
		if ((g->boss.laser.laserRect[0].x >= g->ship.rect.x
				&& g->boss.laser.laserRect[0].x <= g->ship.rect.x + 28)
				|| (g->boss.laser.laserRect[0].x + 11 >= g->ship.rect.x
				&& g->boss.laser.laserRect[0].x + 11 <= g->ship.rect.x + 28)
				|| (g->boss.laser.laserRect[1].x >= g->ship.rect.x
				&& g->boss.laser.laserRect[1].x <= g->ship.rect.x + 28)
				|| (g->boss.laser.laserRect[1].x + 11 >= g->ship.rect.x
				&& g->boss.laser.laserRect[1].x + 11 <= g->ship.rect.x + 28))
			g->ship.life--;
	}
}

void ChargeCollision(t_game *g)
{
	if (g->boss.pos.y + 120 == g->ship.rect.y) {
		if (g->ship.rect.x + 10 >= g->boss.pos.x + 110
				&& g->ship.rect.x + 10 <= g->boss.pos.x + 110 + 10
				|| g->ship.rect.x + 10 + 8 >= g->boss.pos.x + 110
				&& g->ship.rect.x + 10 + 8 <= g->boss.pos.x + 110 + 10)
			g->ship.life--;
	}
}