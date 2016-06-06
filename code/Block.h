#pragma once
#include "GL/glut.h"
#include "Common.h"

class Block
{
private:
	int pos_x,pos_y;
public:
	Block(){pos_x=0;pos_y=0;};
	Block(int x,int y){pos_x=x;pos_y=y;};
	void Set_pos(int x,int y) {pos_x=x;pos_y=y;};
	void Set_pos_x(int x){pos_x=x;};
	void Set_pos_y(int y){pos_y=y;};
	int Get_pos_x()const{return pos_x;};
	int Get_pos_y()const{return pos_y;};
	
	void Move_(int x,int y){pos_x+=x;pos_y+=y;};
	bool Can_move(int x,int y);
	void Draw_() const;

	bool Can_rotate(const int center_x,const int center_y);
	bool Rotate_(const int center_x,const int center_y);
};
