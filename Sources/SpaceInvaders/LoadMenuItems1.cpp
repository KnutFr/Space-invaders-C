#include "stdafx.h"
#include "my.h"

void LoadItemsHome(t_menu *m)
{
	int count;

	for (count = 1; count < m->home.nbItems + 1; count++)
	{
		if (count == 1)
			m->home.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems,
			m->home.items[count - 1], m->fontColorSelect);
		else
			m->home.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->home.items[count - 1], m->fontColor);
		m->home.itemRect[count - 1].x = m->home.itemsX[count - 1];
		m->home.itemRect[count - 1].y = 200 + (count * 50);
	}
}

void LoadItemsShip(t_menu *m)
{
	int count;

	for (count = 1; count < m->ship.nbItems + 1; count++)
	{
		if (count == 1)
			m->ship.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->ship.items[count - 1], m->fontColorSelect);
		else
			m->ship.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->ship.items[count - 1],  m->fontColor);
		m->ship.itemRect[count - 1].x = m->ship.itemsX[count - 1];
		m->ship.itemRect[count - 1].y = 200 + (count * 50);
		m->ship.PictRect[count - 1].x = m->ship.PictRectX[count - 1];
		m->ship.PictRect[count - 1].y = 210 + (count * 50);
	}
}

void LoadItemsCredit(t_menu *m)
{
	int count; 

	for (count = 1; count < m->ship.nbItems + 1; count++)
	{
		m->credit.itemFont[count - 1] = TTF_RenderText_Blended(m->fontCredit, 
			m->credit.Items[count - 1], m->fontColorSelect);
		m->credit.itemRect[count - 1].x = m->credit.itemsX[count - 1];
		m->credit.itemRect[count - 1].y = 70 + (count * 135);
		m->credit.PictRect[count - 1].x = m->credit.PictRectX[count - 1];
		m->credit.PictRect[count - 1].y = 30 + (count * 135);
	}
}

void LoadItemsLevel(t_menu *m)
{
	int count;

	for (count = 1; count < m->level.nbItems + 1; count++)
	{
		if (count == 1)
			m->level.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->level.items[count - 1], m->fontColorSelect);
		else
			m->level.itemFont[count - 1] = TTF_RenderText_Blended(m->fontItems, 
			m->level.items[count - 1],  m->fontColor);
		m->level.itemRect[count - 1].x = m->level.itemsX[count - 1];
		m->level.itemRect[count - 1].y = 200 + (count * 60);
	}
	m->level.labelcodeFont = TTF_RenderText_Blended(m->fontItems, 
		m->level.labelcode,  m->fontColor);
	m->level.labelcodeRect.x = m->level.LabelcodeX;
		m->level.labelcodeRect.y = 200 + 60;
}

void LoadItemsScore(t_menu *m)
{
	int count;

	for (count = 1; count < m->score.nbItems + 1; count++)
	{

		m->score.itemRkFont[count - 1] = TTF_RenderText_Blended(m->fontCredit, 
			m->score.itemsRank[count - 1], m->fontColor);
		m->score.itemRkRect[count - 1].x = m->score.itemsRkX[count - 1];
		m->score.itemRkRect[count - 1].y = 200 + (count * 50);
		m->score.itemFont[count - 1] = TTF_RenderText_Blended(m->fontCredit, 
			m->score.items[count - 1], m->fontColor);
		m->score.itemRect[count - 1].x = m->score.itemsX[count - 1] + 150;
		m->score.itemRect[count - 1].y = 200 + (count * 50);
		m->score.itemScFont[count - 1] = TTF_RenderText_Blended(m->fontCredit, 
			m->score.itemsSc[count - 1], m->fontColorSelect); 
		m->score.itemScRect[count - 1].x = m->score.itemsScX[count - 1] + 80;
		m->score.itemScRect[count - 1].y = 200 + (count * 50);
	}
}