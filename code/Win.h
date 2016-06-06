#pragma once 
#include "Common.h"

class Win
{
private:
	int num_row,num_col;
	bool status;
	bool map[100][100];
public:
	Win(){New_();};
	void New_(){num_row=NUM_ROW;num_col=NUM_COL;status=1;Init_map();};
	void Init_map(){for (int i=0;i<num_row;i++)
			for (int j=0;j<num_col;j++)
				map[i][j]=0;};
	void Reset_map(int i,int j,int t){map[i][j]=t;};
	bool Get_map(int i,int j){if (map[i][j]) return 1;else return 0;};
	void Draw_() const;
	bool Get_status(){return status;};
	void Set_status(bool new_status){status=new_status;};
	void Update_();
	bool Row_is_full(int col);
	void Clear_row(int col);
};
