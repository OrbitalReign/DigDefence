#include "GroundMesh.h"
#include <math.h>

void GroundMesh::Draw(Graphics& gfx)
{ 
	Color c(5 + ZoomRate * 2, 5 + ZoomRate * 2, 5 + ZoomRate * 2);  // Darkens ground mesh as you zoom out so its not so washed out.
    																				   
    // lines from top of screen to bottom right

	for (int i = LeftTop; i < Graphics::ScreenWidth; i += ZoomRate)
	{
		for (x = i; x < Graphics::ScreenWidth; x++)   // loops line printing
		{
			if (y < Graphics::ScreenHeight && y > 0)   // only prints in screen boundries .	
			{
				gfx.PutPixel(x, y, c);     
			}
			y_Step++;
			if (y_Step >= Mesh_Angle)
			{
				y++;
				y_Step = 0;
			}
		}
		y = 0;
	}
	
	// lines from left of screen to bottom right

	for (int i = LeftSide;  i < Graphics::ScreenHeight; i += (ZoomRate / 2))
	{
		y += i;
		for (x = 0; x < Graphics::ScreenWidth; x++)  // loops line printing
		{
			if (y < Graphics::ScreenHeight && y > 0)  // only prints in screen boundries 	
			{
				gfx.PutPixel(x, y, c);     
			}
			y_Step++;
			if (y_Step >= Mesh_Angle)
			{
				y++;
				y_Step = 0;
			}
			
		}
		y = 0;
	}

    // lines from top of screen to bottom left

	for (int i = RightTop; i > 0 ; i -= ZoomRate)
	{
		for (x = i; x > 0 ; x--)   // loops line printing
		{
			if (y < Graphics::ScreenHeight && y > 0)  // only prints in screen boundries 				
			{
				gfx.PutPixel(x, y, c);     
			}
			y_Step++;
			if (y_Step >= Mesh_Angle)
			{
				y++;
				y_Step = 0;
			}
		}
		y = 0;
	}
	
	// lines form right of screen to bottom left

	for (int i = RightSide ; i < Graphics::ScreenHeight ; i += (ZoomRate / 2))
	{
		y += i;
		for (x = Graphics::ScreenWidth - 1; x > 0; x--)   // loops line printing
		{
			if ( y < Graphics::ScreenHeight && y > 0)                                             // only prints in screen boundries 				  
			{
				gfx.PutPixel(x, y, c);    
			}
			y_Step++;
			if (y_Step >= Mesh_Angle)
			{
				y++;
				y_Step = 0;
			}

		}
		y = 0;
	}
	
}

void GroundMesh::ZoomMesh(float z)
{
	ZoomRateDiv = 50 / z;
	ZoomRate = z;
	Top_Mesh_Spacing = 50;            // zoomes mesh in and out linked to a zoom key
	Side_Mesh_Spacing = Top_Mesh_Spacing / 2;
}

void GroundMesh::MoveMesh(int Left, int Right, int Top, int Bottom)
{

	
	float temp_xL = (Left % Top_Mesh_Spacing);
	float temp_xR = Top_Mesh_Spacing - (Right % Top_Mesh_Spacing);     // divides screen boundry by the mesh spacing 
	float temp_yLR = (Top % Side_Mesh_Spacing);                          //and finds the remainder that should show on screen.
	
// Left side Mesh 
	 LeftSide = ((temp_xL / 2) - temp_yLR);
	 if (LeftSide < 0)  // handles if left side aka  side mesh 'y' is above screen and sets it inside screen.
	 {
		 LeftSide = Side_Mesh_Spacing + LeftSide;
	 }
	 LeftTop = (Top_Mesh_Spacing - (LeftSide * 2)); // sets top mesh 'x' from left side of screen.

	 // Right side mesh
	 RightSide = ((temp_xR / 2) - temp_yLR);
	 if (RightSide < 0)  // handles if right side aka  side mesh 'y' is above screen and sets it inside screen.
	 {
		 RightSide = Side_Mesh_Spacing + RightSide;
	 }
	 RightTop = (Top_Mesh_Spacing - (RightSide * 2));  // sets top mesh 'x' from right side of screen.

	 RightTop = Graphics::ScreenWidth - (RightTop / ZoomRateDiv);
	 LeftTop /= ZoomRateDiv;
	 RightSide /= ZoomRateDiv;
	 LeftSide /= ZoomRateDiv;
}
