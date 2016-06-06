#include "GL/glut.h"
#include "Common.h"
#include "Win.h"
#include "Block.h"
#include "Figure.h"
#include "string.h"

extern Figure figure;

void Win::Draw_() const
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0,0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0,0,0);
	glVertex3f(WIN_WIDTH,0,0);
	glVertex3f(WIN_WIDTH,WIN_HEIGHT,0);
	glVertex3f(0,WIN_HEIGHT,0);
	glEnd();
	glFlush();

	if (status)
	{
		Block block;
		for (int i=0;i<num_row;i++)
			for (int j=0;j<num_col;j++)
				if (map[i][j])
				{
					block.Set_pos(i,j);
					block.Draw_();
				}
	}else{
		char string[]="GAME OVER";
		int len;
		
		glRasterPos2f(WIN_WIDTH/2-50,WIN_HEIGHT/2);

		len = (int) strlen(string);
		for (int i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	}
}

void Win::Update_()
{
	int i,j;
	for (int k=0;k<NUM_FIGURE_BLOCK;k++)
	{
		i=figure.data[k].Get_pos_x();
		j=figure.data[k].Get_pos_y();
		map[i][j]=1;
	}
	
	int num=figure.Get_pos_y();
	for (i=num-2;i<=num+2;i++)
		if (Row_is_full(i))	Clear_row(i--);
}

bool Win::Row_is_full(int col)
{
	for (int i=0;i<NUM_ROW;i++)
		if (!map[i][col])
			return false;
	return true;
}

void Win::Clear_row(int col)
{
	for (int j=col;j<NUM_COL;j++)
		for (int i=0;i<NUM_ROW;i++)
			map[i][j]=map[i][j+1];	
}
