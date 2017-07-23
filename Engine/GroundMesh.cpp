#include "GroundMesh.h"
#include <math.h>

void GroundMesh::Draw(Graphics& gfx)
{ 
	Color c(50 + Top_Mesh_Spacing, 50 + Top_Mesh_Spacing, 50 + Top_Mesh_Spacing);  // Darkens ground mesh as you zoom out so its not so washed out.
    																				   
    // lines from top of screen to bottom right

	for (int i = Top_Mesh_Spacing - Scroll_x - Scroll_y ; i < Graphics::ScreenWidth; i += Top_Mesh_Spacing)     
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
	
	// lines from left of screen to bottom right

	for (int i = (Scroll_x / 2) + ( Scroll_y / 2 );  i < Graphics::ScreenHeight; i += Side_Mesh_Spacing)    
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

    // lines from top of screen to bottom left

	for (int i = Graphics::ScreenWidth - Scroll_x + Scroll_y; i > 0 ; i -= Top_Mesh_Spacing)   
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
	
	// lines form right of screen to bottom left

	for (int i = Side_Mesh_Spacing - ( Scroll_x / 2 ) + ( Scroll_y / 2 ) ; i < Graphics::ScreenHeight ; i += Side_Mesh_Spacing)  
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
	Top_Mesh_Spacing = z;            // zoomes mesh in and out linked to a zoom key
}

void GroundMesh::MoveMesh(int x, int y)
{

	if ( x > temp_x)  // moving right
	{
		Scroll_x += 3;
	}	
	else if (x < temp_x)   // moving left
	{
		Scroll_x -= 3;
	}

	if (y > temp_y)  // moving Up
	{
		Scroll_y -= 5;
	}
	else if (y < temp_y)   // moving Down
	{
		Scroll_y += 5;
	}
	

	// stops Scroll x and y form going to 50 quadzilion though works without it  .
	if (Scroll_x > Top_Mesh_Spacing)  // handles looping the mesh to apear like its moving ( left  )
	{
		Scroll_x = 0;
	}
	else if (Scroll_x < 0)
	{
		Scroll_x = Top_Mesh_Spacing;  // handles looping the mesh to apear like its moving ( right )
	}

	if (Scroll_y > Top_Mesh_Spacing)  // handles looping the mesh to apear like its moving ( up  )
	{
		Scroll_y = 0;
	}
	else if (Scroll_y < 0)
	{
		Scroll_y = Top_Mesh_Spacing;  // handles looping the mesh to apear like its moving ( down )
	}  

	Side_Mesh_Spacing = Top_Mesh_Spacing / 2;
	temp_x = x;
	temp_y = y;
}
