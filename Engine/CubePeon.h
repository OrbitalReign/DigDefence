#pragma once
#include "Graphics.h"
#include "Frame.h"


class CubePeon
{
public:
	void Draw(Graphics& gfx);
	void CubeZoom(float z);
	void Location(int x2, int y2);
	void Screen_Size(int Left, int Right, int Top, int Bottom);
	
private:
	int True_x = 50; //makes sure its set in screen
	int True_y = 50;
	float On_Screen_x = 0;
	float On_Screen_y = 0;
	int Draw_x = 0;
	int Draw_y = 0;

	int y2 = 0;  //temp name
	int y3 = 0;  //temp name
	int Top_Bottom_x = 0;
	int Top_Bottom_y = 0;
	int y_Step = 0;

	float Zoom = 0;
	float temp_Zoom = 0;

	bool Change_Draw_Direction = false;
	bool In_Frame_x = false;
	bool In_Frame_y = false;

	int Edge_Left;
	int Edge_Right;
	int Edge_Top;
	int Edge_Bottom;
};