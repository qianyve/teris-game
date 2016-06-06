#include "GL/glut.h"
#include "Common.h"
#include "Block.h"
#include "Win.h"

extern Win window;

void Block::Draw_() const
{
	glColor4f(1.0,1.0,1.0,1.0);
	glBegin(GL_QUADS);
	glVertex3f(pos_x*UNIT,pos_y*UNIT,0);
	glVertex3f((pos_x+1)*UNIT-BLOCK_SPACE,pos_y*UNIT,0);
	glVertex3f((pos_x+1)*UNIT-BLOCK_SPACE,(pos_y+1)*UNIT-BLOCK_SPACE,0);
	glVertex3f(pos_x*UNIT,(pos_y+1)*UNIT-BLOCK_SPACE,0);
	glEnd();
	glFlush();
}

bool Block::Can_move(int x,int y)
{
	if (pos_x+x<NUM_ROW && pos_x+x>=0)
		if (pos_y+y>=0)
			if (!window.Get_map(pos_x+x,pos_y+y))
				return 1;
	return 0;
}

bool Block::Can_rotate(const int center_x,const int center_y)
{
	int a=pos_x-center_x;
	int b=pos_y-center_y;

	if (a==0 && b==0) return true;

	int nextpos_x=pos_x-b;
	int nextpos_y=pos_y+a;

	if (window.Get_map(nextpos_x,nextpos_y)!=0) return false;

	if (abs(a)>1 || abs(b)>1)
	{
		if (window.Get_map(center_x+(2*a-b)/2,center_y+(a+2*b)/2)||
		window.Get_map(center_x+(a-2*b)/2,center_y+(2*a+b)/2))
		return false;
	}else if (abs(a)==1 && abs(b)==1){
		if (window.Get_map(center_x+(a-b)/2,center_y+(a+b)/2))
		return false;	
	}else if (a*b==0){
		if (window.Get_map(center_x+(a-b),center_y+(a+b)))
		return false;
	}

	return true;

}

bool Block::Rotate_(const int center_x,const int center_y)
{
	int offset_x=pos_x-center_x;
	int offset_y=pos_y-center_y;

	if (!Can_rotate(center_x,center_y))
		return false;

	int nextpos_x,nextpos_y;
	nextpos_x=center_x-offset_y;
	nextpos_y=center_y+offset_x;
	Set_pos(nextpos_x,nextpos_y);
	return true;

}
