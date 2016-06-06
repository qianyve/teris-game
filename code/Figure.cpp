#include "GL/glut.h"
#include "Common.h"
#include "Figure.h"
#include "Block.h"
#include "Win.h"

extern Win window;

Figure::Figure()
{
	//int numFigure = rand() % NUM_FIGURE;
	New_(rand()%NUM_FIGURE);
}

void Figure::New_(int numFigure)
{
	if (window.Get_map(NUM_ROW/2,NUM_COL-1)==1 &&
		window.Get_status())
	{
		window.Set_status(false);
		return;
	}
	if (numFigure>=0 && numFigure<NUM_FIGURE)
	{
		if (numFigure==0) can_rotate=0;
		else can_rotate=1;
		pos_x=NUM_ROW/2;
		pos_y=NUM_COL-2;

		for (int i=0;i<NUM_FIGURE_BLOCK;++i)
		data[i].Set_pos(pos_x+image[numFigure][i][0],
				pos_y+image[numFigure][i][1]);
	}
}

void Figure::Draw_() const
{
	for (int i=0;i<NUM_FIGURE_BLOCK;i++)
		data[i].Draw_();
}

bool Figure::Move_(int x,int y)
{
	for (int i=0;i<NUM_FIGURE_BLOCK;i++)
		if (!data[i].Can_move(x,y)) return false;
	pos_x+=x;
	pos_y+=y;
	for (int i=0;i<NUM_FIGURE_BLOCK;i++)
		data[i].Move_(x,y);
	return true;
}

bool Figure::Rotate_()
{
	if (can_rotate==0)	return false;
	for (int i=0;i<NUM_FIGURE_BLOCK;i++)
	{
		if (!data[i].Can_rotate(pos_x,pos_y))
			return false;
	}
	for (int i=0;i<NUM_FIGURE_BLOCK;i++)
	data[i].Rotate_(pos_x,pos_y);
	return true;
}
