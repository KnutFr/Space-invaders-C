#include "stdafx.h"
#include "my.h"

void ChangeOpt(t_menu *m, t_game *g)
{
	if (m->opt.posItems == 1)
		if (g->music == 1)
		{
			m->opt.optval[m->opt.posItems-1] = "OFF";
			g->music = 0;
		}
		else
		{
			m->opt.optval[m->opt.posItems-1] = "ON";
			g->music = 1;
		}
	else
		if (g->effect == 1)
		{
			m->opt.optval[m->opt.posItems-1] = "OFF";
			g->effect = 0;
		}
		else
		{
			m->opt.optval[m->opt.posItems-1] = "ON";
			g->effect = 1;
		}
	LoadItemsOpt(m);
}