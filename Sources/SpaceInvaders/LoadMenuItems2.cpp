#include "stdafx.h"
#include "my.h"

void LoadItemsOpt(t_menu *m)
{
	int count;

	for (count = 1; count < m->opt.nbItems + 1; count++)
	{
		if (count == 1 && m->posMenu != 5)                                  
			m->opt.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->opt.items[count - 1], m->fontColorSelect);
		else
			m->opt.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->opt.items[count - 1], m->fontColor);
		m->opt.itemRect[count - 1].x = m->opt.itemsX[count - 1];
		m->opt.itemRect[count - 1].y = 200 + (count * 50);
		m->opt.valFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->opt.optval[count - 1], m->fontColor); 
		m->opt.optValRect[count - 1].x = m->opt.itemsX[count - 1] + 300;
		m->opt.optValRect[count - 1].y = 200 + (count * 50);
	}
}

void LoadItemsChangeLev(t_menu *m)
{
	int count;
	
	for (count = 1; count < m->chlevel.NbItems + 1; count++)
	{
		m->chlevel.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->chlevel.items[count - 1], m->fontColor);
		m->chlevel.itemRect[count - 1].x = m->chlevel.itemsX[count - 1];
		m->chlevel.itemRect[count - 1].y = 200 + (count * 50);
	}
}

void LoadItemsWrScore(t_menu *m)
{
		int count;
	
		for (count = 1; count < m->wrscore.nbItems + 1; count++)
	{
		m->wrscore.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->wrscore.items[count - 1], m->fontColor);
		m->wrscore.itemRect[count - 1].x = m->wrscore.itemsX[count - 1];
		m->wrscore.itemRect[count - 1].y = 200 + (count * 100);
	}
	m->wrscore.labelnameFont = TTF_RenderText_Blended(m->fontItems, 
	m->wrscore.labelname,  m->fontColor);
	m->wrscore.labelnameRect.x = m->wrscore.LabelnameX;
	m->wrscore.labelnameRect.y = 200 + 100;

}