#pragma once
#include "Graphics.h"

class CubePeon
{
public:
	void Draw(Graphics& gfx);
	void CubeZoom(int z);
private:
	int x = 400;
	int y = 300;
	int Top_Bottom_x = 0;
	int Top_Bottom_y = 0;
	int Zoom = 0;
	int temp_Zoom = 0;
};