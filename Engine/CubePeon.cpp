#include "CubePeon.h"

void CubePeon::Draw(Graphics & gfx)
{

	


	if (In_Frame_x && In_Frame_y)   // Draws if in frame
	{
		Color c(0, 100 + int(Zoom), 0);  // add fading


		for (int i = 0; i < ZoomCubeHeight; i++)
		{
			gfx.PutPixel( int(New_x + Draw_x), int(New_y + Draw_y) - i, c); // right pillar

		}
		for (int i = 0; i < ZoomCubeHeight; i++)
		{
			gfx.PutPixel(int(-New_x + Draw_x), int(-New_y + Draw_y) - i, c);  // left pillar

		}
		for (int i = 0; i < ZoomCubeHeight; i++)
		{
			gfx.PutPixel(int(New_x2 + Draw_x), int(New_y2 + Draw_y) - i, c);  // bottom pillar

		}
		for (int i = 0; i < ZoomCubeHeight; i++)
		{
			gfx.PutPixel(int(-New_x2 + Draw_x), int(-New_y2 + Draw_y) - i, c);  // top pillar

		}

		
	}
}

void CubePeon::CubeZoom(float z)
{
	  Zoom = z;
	  ZoomRate = ( 50 / Zoom);
	  Hypot = CubeWidth / ZoomRate;
	  ZoomCubeHeight = int(CubeHeight / ZoomRate);

	if (True_x < Frame::Focal_Point_x)            // zooms cube with mesh in x dim
	{
		On_Screen_x = float(True_x - Edge_Left);
		Draw_x =On_Screen_x / ZoomRate; 
	}
	else if (True_x > Frame::Focal_Point_x)
	{
		On_Screen_x = float(Edge_Right - True_x);
			Draw_x = Graphics::ScreenWidth - (On_Screen_x / ZoomRate);
	}
	else 
	{
		Draw_x = 400;
	}

	if (True_y < Frame::Focal_Point_y)         // zooms cube with mesh in y dim
	{
		On_Screen_y = float(True_y - Edge_Top);
		Draw_y = On_Screen_y / ZoomRate;
	}
	else if (True_y > Frame::Focal_Point_y)
	{
		On_Screen_y = float(Edge_Bottom - True_y);
		Draw_y = Graphics::ScreenHeight - On_Screen_y / ZoomRate;
	}
	else 
	{
		Draw_y = 200;
	}

} 

void CubePeon::Location(int x2 , int y2)
{

	True_x = x2;  // gets cubes actual location
	True_y = y2;
}

void CubePeon::Screen_Size(int Left, int Right, int Top, int Bottom)
{
	//  gets the zoomed screen boundary
	In_Frame_x = (True_x - 10 > Left && True_x + 60  < Right);   // checks true x is in frame
	In_Frame_y = (True_y - 40  > Top && True_y + 20  < Bottom);   // checks true y is in frame

	Edge_Left  = Left;
	Edge_Right = Right;
	Edge_Top = Top;
	Edge_Bottom = Bottom;

}

void CubePeon::Rotate(int Turn)
{
	Deg = double(Turn);
	Deg = Deg * PI / 180;    // gets radians for trig function
	New_x = float((cos(Deg) * Hypot) * 2);
	New_y = float(sin(Deg) * Hypot);

	Deg2 = double(Turn) + 90 ;  // offsets by 90 degrees  
	if (Deg2 > 360)
	{
		Deg2 = 0 + ( Deg2 - 360);
	}

	Deg2 = Deg2 * PI / 180;    // gets radians for trig function
	New_x2 = float((cos(Deg2) * Hypot) * 2);
	New_y2 = float(sin(Deg2) * Hypot);
	
}

 