#pragma once
#include "Graphics.h"

class CubePeon
{
public:
	void Draw(Graphics& gfx);
	void CubeZoom(int z);
	void Location(int x, int y);
private:
	int True_x = 50;
	int True_y = 50;
	int Draw_x = 0;
	int Draw_y = 0;
	int y2 = 0;  //temp name
	int y3 = 0;  //temp name
	int Top_Bottom_x = 0;
	int Top_Bottom_y = 0;
	int y_Step = 0;
	int Loc_Zoom_x = 0;
	int Loc_Zoom_y = 0;
	float Zoom = 0;
	float temp_Zoom = 0;
	bool Change_Draw_Direction = false;
};