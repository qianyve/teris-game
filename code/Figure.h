#pragma once
#include "GL/glut.h"
#include "Common.h"
#include "Block.h"

class Figure
{
private:
	int pos_x,pos_y;
	bool can_rotate;
public:
	Block data[NUM_FIGURE_BLOCK];
	
	Figure();
	void New_(int numFigure);
	void Draw_() const;
	bool Move_(int x,int y);
	int Get_pos_y() const {return pos_y;};
	bool Rotate_();
	//bool Translate(const int offset_x,const int offset_y);
};
