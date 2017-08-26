#pragma once
#include "Graphics.h"
#include "Frame.h"
#include "RotationTable.h"



class EnemyCube
{
public:
	void Draw(Graphics& gfx);
	void CubeZoom(float z);
	void SpeedIn(int speed);
	void Screen_Size(int Left, int Right, int Top, int Bottom);
	void Rotate(int * TablePointerx, int * TablePointery, int * DirectionPointx, int * DirectionPointy, int Turn);
	void SpawnSet(int x, int y);
	void Killed(); // add health stuff to call this <<<<
	void Getloc( int& x, int& y)const ;
	void Target();
private:

	void Lines();

private:

	// world location
	int True_x = 10000;
	int True_y = 10000;
	bool Spawned = false;

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

	int New_x;
	int New_y;
	int Deg2;
	int New_x2;
	int New_y2;
	int Deg3;
	int turnx;
	int turny;
	int Degrees;

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
