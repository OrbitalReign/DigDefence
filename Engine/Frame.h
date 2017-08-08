#pragma once
#include "Graphics.h"


class Frame
{
public:
     void Frame_Set(int x, int y , float z);
	 int Get_Left(); 
	 int Get_Right();
	 int Get_Top();
	 int Get_Bottom();

	static constexpr int Focal_Point_x = (Graphics::ScreenWidth / 2);
	static constexpr int Focal_Point_y = (Graphics::ScreenHeight / 3);	
private:
	
	int x_Left;
	int x_Right;
	int y_Top;
	int y_Bottom;
};