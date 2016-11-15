#include "stdafx.h"
#include "my.h"

void LoadMenuCredit(t_menu *m)
{
	int i;
	int tab[5] = {350, 350, 350, 350, 350};
	char *Items[5] = {MPA, AST, RTO, "Pour l'ETNA", "Back"};
	char *Pict[5] = {PATH_PIC_MPA,PATH_PIC_AST, PATH_PIC_RTO,PATH_NONE, PATH_NONE};

	for (i = 0; i < 5; i++)
	{
		m->credit.itemsX[i] = tab[i];
		m->credit.itemFont[i] = NULL;
		m->credit.Items[i] = Items[i];
		m->credit.Pict[i] = IMG_Load(Pict[i]);
		m->credit.PictRectX[i] = tab[i] - 150;
	}
	m->credit.NbItems = 5;
	m->credit.PosItems = 5;
}

void LoadMenuChangeLev(t_menu *m, char *level, char *pass)
{
	int i;
	int tab[2] = {280, 300};
	char *Items[2] = {level, pass};

	for (i = 0; i < 2; i++)
	{
		m->chlevel.itemsX[i] = tab[i];
		m->chlevel.items[i] = Items[i];
		m->chlevel.itemFont[i] = NULL;
	}
	m->chlevel.items[1]= Items[1];
	m->chlevel.NbItems = 2;
}

void LoadMenuWrScore(t_menu *m)
{
	m->wrscore.itemsX[0] = 400;
	m->wrscore.itemFont[0] = NULL;
	m->wrscore.items[0] = "_ _ _ _";
	m->wrscore.LabelnameX = 150;
	m->wrscore.labelname = "Your Name :";
	m->wrscore.labelnameFont = NULL;
	m->wrscore.nbItems = 1;
	m->wrscore.nbkeycode = 0;
	m->wrscore.posItems = 1;
	m->wrscore.flag = 1;
}