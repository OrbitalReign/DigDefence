#include "GroundMesh.h"
#include <math.h>

void GroundMesh::Draw(Graphics& gfx)
{ 
	Color c(50 + Mesh_Spacing, 50 + Mesh_Spacing, 50 + Mesh_Spacing);  // Darkens ground mesh as you zoom out so its not so washed out.

	for (int i = Mesh_Spacing - Scroll_x; i < Graphics::ScreenWidth; i += Mesh_Spacing)     // lines from top of screen to bottom right
	{
		for (x = i; x < Graphics::ScreenWidth; x++)   // loops line printing
		{
			if (x < Graphics::ScreenWidth &&    // only prints in screen boundries .
				x > 0 &&
				y < Graphics::ScreenHeight &&
				y > 0)
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
	for (int i = Scroll_x / 2; i < Graphics::ScreenHeight; i += (Mesh_Spacing / 2))    // lines from left of screen to bottom right
	{
		y += i;
		for (x = 0; x < Graphics::ScreenWidth; x++)  // loops line printing
		{
			if (x < Graphics::ScreenWidth &&    // only prints in screen boundries 
				x > 0 &&
				y < Graphics::ScreenHeight &&
				y > 0)
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



	for (int i = Graphics::ScreenWidth - Scroll_x; i > 0 ; i -= Mesh_Spacing)   // lines from top of screen to bottom left
	{
		for (x = i; x > 0 ; x--)   // loops line printing
		{
			if (x < Graphics::ScreenWidth &&    // only prints in screen boundries 
				x > 0 &&
				y < Graphics::ScreenHeight &&
				y > 0)
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
	for (int i = ( Mesh_Spacing / 2 ) - ( Scroll_x / 2 ) ; i < Graphics::ScreenHeight ; i += (Mesh_Spacing / 2))  // lines form right of screen to bottom left
	{
		y += i;
		for (x = Graphics::ScreenWidth; x > 0; x--)   // loops line printing
		{
			if (x < Graphics::ScreenWidth &&    // only prints in screen boundries 
				x > 0 &&
				y < Graphics::ScreenHeight &&
				y > 0)
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

void GroundMesh::Zoom(int z)
{
	Mesh_Spacing = z;            // zoomes mesh in and out linked to a zoom key
}

void GroundMesh::MoveMesh(int x)
{

	if ( x > temp_x)  // moving right
	{
		Scroll_x += 3;
	}
	
	if (x < temp_x)   // moving left
	{
		Scroll_x -= 3;
	}


	if (Scroll_x > Mesh_Spacing)  // handles looping the mesh to apear like its moving ( left  )
	{
		Scroll_x = 0;
	}
	if (Scroll_x < 0)
	{
		Scroll_x = Mesh_Spacing;  // handles looping the mesh to apear like its moving ( right )
	}
	temp_x = x;
}
