#pragma once
#include "Graphics.h"
#include "Frame.h"
#include <math.h>
#define PI 3.1415926536


class CubePeon
{
public:
	void Draw(Graphics& gfx);
	void CubeZoom(float z);
	void Location(int x2, int y2);
	void Screen_Size(int Left, int Right, int Top, int Bottom);
	void Rotate(int Turn);
private:
	int True_x = 50; //makes sure its set in screen
	int True_y = 50;
	float On_Screen_x = 0;
	float On_Screen_y = 0;
	float Draw_x = 0;
	float Draw_y = 0;

	double Deg;  // degrees 
	float CubeWidth = 25; // sets cube size from its centre to corners
	float CubeHeight = 50;  // sets height of cube
	int ZoomCubeHeight;
	float Hypot; // hypotenuse 
	float New_x;
	float New_y;
	double Deg2;
	float New_x2;
	float New_y2;

	float Zoom = 0;
	float ZoomRate = 0;

	bool In_Frame_x = false;
	bool In_Frame_y = false;

	int Edge_Left;
	int Edge_Right;
	int Edge_Top;
	int Edge_Bottom;
};