#pragma once
#include "Graphics.h"
#include "Frame.h"
#include "RotationTable.h"
#include <math.h>




class CubePeon
{
public:
 
	void Draw(Graphics& gfx);
	void CubeZoom(float z);
	void SpeedIn(int speed);
	void Screen_Size(int Left, int Right, int Top, int Bottom);
	void Rotate(int * TablePointerx, int * TablePointery , int Turn);
	
private:

	void Lines();

private:

	// world location
	float True_x = 10000; 
	float True_y = 10000;

	float On_Screen_x = 0.0f;
	float On_Screen_y = 0.0f;
	float Zoomed_x = 0.0f;
	float Zoomed_y = 0.0f;

    float Zoom = 0.0f;
	float ZoomRate = 0.0f;

	bool In_Frame_x = false;
	bool In_Frame_y = false;

	int Edge_Left;
	int Edge_Right;
	int Edge_Top;
	int Edge_Bottom;

	// virtical line rotation stuff
	int Deg;  // degrees 
	float CubeWidth = 12.5f; // sets cube size from its centre to corners
	float CubeHeight = 25.0f;  // sets height of cube
	int ZoomCubeHeight;

	float New_x;
	float New_y;
	int Deg2;
	float New_x2;
	float New_y2;
	int Deg3; 
	float turnx;
	float turny;

	// line rotation stuff
	int dirivedx;
	int dirivedy;
	int dirivedx2;
	int dirivedy2;
	int steps;
	int steps2;
	float xinc;
	float yinc;
	float xinc2;
	float yinc2;
	float linex;
	float liney;
	float linex2;
	float liney2;

};