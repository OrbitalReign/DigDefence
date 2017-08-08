#pragma once
#include "Graphics.h"

class GroundMesh
{
public:
      void Draw(Graphics& gfx);
	  void ZoomMesh(float z);
	  void MoveMesh(int Left, int Right, int Top, int Bottom);
private:
	int x = 10 ;
	int y = 10 ;
	int y_Step = 0;
    int Top_Mesh_Spacing = 50;
	int Side_Mesh_Spacing = 0;
	int Mesh_Angle = 2;

	float ZoomRateDiv;
	int ZoomRate;

	float LeftTop;
	float LeftSide;    // left side start diagonals
	
	float RightTop;
	float RightSide;   // right side start diagonals


};