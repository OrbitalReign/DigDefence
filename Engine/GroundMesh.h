#pragma once
#include "Graphics.h"

class GroundMesh
{
public:
      void Draw(Graphics& gfx);
	  void Zoom(int z);
	  void MoveMesh(int x);
private:
	int x = 10 ;
	int y = 10 ;
	int y_Step = 0;
	int Mesh_Spacing = 10;
	int Mesh_Angle = 2;
	int Scroll_x = 0;
	int temp_x = 0;
};