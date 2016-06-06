#pragma once
#include "GL/glut.h"

#define NUM_ROW 17
#define NUM_COL 25

#define WIN_WIDTH NUM_ROW*UNIT
#define WIN_HEIGHT NUM_COL*UNIT

#define BLOCK_SIZE 19
#define BLOCK_SPACE 1
#define UNIT (BLOCK_SIZE+BLOCK_SPACE)

#define NUM_FIGURE 7
#define NUM_FIGURE_BLOCK 4

//7 figures
const int image[NUM_FIGURE][NUM_FIGURE_BLOCK][2]=
{
	{
		//0
		{0,0},	{0,1},	{1,1},	{1,0}
	},
	{
		//I
		{0,-1},	{0,0},	{0,1},	{0,2}
	},
	{
		//J
		{0,1},	{-1,1},	{-1,0},	{-1,-1}
	},
	{
		//L
		{0,1},	{1,1},	{1,0},	{1,-1}
	},
	{
		//s
		{0,1},	{0,0},	{-1,0},	{-1,-1}
	},
	{
		//z
		{0,1},	{0,0},	{-1,0},	{-1,-1}
	},
	{
		//T
		{-1,0},	{0,0},	{1,0},	{0,1}
	}
};
