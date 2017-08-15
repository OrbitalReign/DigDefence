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
	void SpeedIn(int speed);
	void Screen_Size(int Left, int Right, int Top, int Bottom);
	void Rotate(int Turn);
	void Lines();
private:
	float True_x = 10000; //makes sure its set in screen
	float True_y = 10000;
	float On_Screen_x = 0.0f;
	float On_Screen_y = 0.0f;
	float Zoomed_x = 0.0f;
	float Zoomed_y = 0.0f;

	double Deg;  // degrees 
	float CubeWidth = 12.5f; // sets cube size from its centre to corners
	float CubeHeight = 25.0f;  // sets height of cube
	int ZoomCubeHeight;
	float Hypot; // hypotenuse 
	float New_x;
	float New_y;
	double Deg2;
	float New_x2;
	float New_y2;
	//test
	double Deg3;
	float Hypot2; 
	float turnx;
	float turny;


	float Zoom = 0.0f;
	float ZoomRate = 0.0f;

	bool In_Frame_x = false;
	bool In_Frame_y = false;

	int Edge_Left;
	int Edge_Right;
	int Edge_Top;
	int Edge_Bottom;

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