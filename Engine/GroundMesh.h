#pragma once
#include "Graphics.h"

class GroundMesh
{
public:
      void Draw(Graphics& gfx);
	  void ZoomMesh(int z);
	  void MoveMesh(int Left, int Right, int Top, int Bottom);
private:
	int x = 10 ;
	int y = 10 ;
	int y_Step = 0;
    int Top_Mesh_Spacing = 50;
	int Side_Mesh_Spacing = 0;
	int Mesh_Angle = 2;
	int Scroll_x = 0;
	int Scroll_y = 0;
	float ZoomRateDiv;
	float ZoomRate;

	float LeftTop;
	float LeftSide;    // left side start diagonals
	
	float RightTop;
	float RightSide;   // right side start diagonals


};