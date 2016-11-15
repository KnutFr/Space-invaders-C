#include "stdafx.h"
#include "my.h"

void FileScoreRead(t_menu *m)
{
	FILE* fichier = NULL;
	char chaine[11];
	int i;
	int y = 0;

	fichier = fopen(PATH_HSCORE, "r");
	if (fichier != NULL)
	{
		while ((fgets(chaine, 10, fichier) != NULL) && (y < 5))
		{
			for (i = 0; i < 4; i++ )
				m->highscore[y].name[i] = chaine[i];
			m->highscore[y].name[4] = '\0';
			for (i = 4; i < 8; i++)
				m->highscore[y].score[i - 4] = chaine[i];
			m->highscore[y].score[4] = '\0';
			y++;
		}
		fclose(fichier);
	}
}

void FileScore_cast(t_menu *m)
{
	char score[5];
	int i, y, j = 0;

	_itoa(m->save.i_score, score, 10);
	for (i = 0; score[i] != '\0'; i++);
	for (y = 0; y < 4 - i; y++)
		m->save.c_score[y] = '0';
	for (y = 4 - i; y < 5; y++, j++)
		m->save.c_score[y] = score[j];
}

void FileScore_write(t_menu *m)
{
	FILE* fichier = NULL;
	int i;
	
	fichier = fopen(PATH_HSCORE, "w");
	if (fichier != NULL)
    {
		for (i = 0; i < 5; i++)
		{
			fputs(m->highscore[i].name, fichier);
			fputs(m->highscore[i].score, fichier);
			fputc('\n', fichier);
		}
        fclose(fichier);
    }
	m->posMenu = 1;
}

void FileScore_sort(t_menu *m)
{
	int i, y, flag = 0, nb = 5;
	char tmp_name[5], tmp_score[5];

	if ((atoi(m->highscore[4].score)) < m->save.i_score) {
		for (y = 0; y < 4; y++)
			m->highscore[4].name[y] = m->wrscore.entname[y];
		strcpy(m->highscore[4].score, m->save.c_score);
	}
	else flag = 1;
    for (;flag == 0; nb--) {
		flag = 1;
        for (i = 0 ; i < (nb - 1) ; i++) {
			if ((atoi(m->highscore[i].score)) < (atoi(m->highscore[i + 1].score))) {
				for (y = 0; y < 5; y++) {
					tmp_name[y] = m->highscore[i].name[y];
					tmp_score[y] = m->highscore[i].score[y];
				}
				strcpy(m->highscore[i].name, m->highscore[i + 1].name);
				strcpy(m->highscore[i].score, m->highscore[i + 1].score);
				strcpy(m->highscore[i + 1].name, tmp_name);
				strcpy(m->highscore[i + 1].score, tmp_score);
                flag = 0;
            }
        }
    }
}

void FileScoreWrite(t_menu *m, t_game *g)
{
	FileScore_cast(m);
	FileScoreRead(m);
	FileScore_sort(m);
	FileScore_write(m);
	WrScoreNameInit(m);
	LoadItemsScore(m);
}

