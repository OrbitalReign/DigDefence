#include "CubePeon.h"

void CubePeon::Draw(Graphics & gfx)
{
	if (In_Frame_x && In_Frame_y)   // Draws if in frame
	{
		Color c(0, 100 + int(Zoom), 0);  // add fading

		for (int i = 0; i < ZoomCubeHeight; i++)
		{
			gfx.PutPixel( int(New_x + Zoomed_x), int(New_y + Zoomed_y) - i, c); // right pillar
            gfx.PutPixel(int(-New_x + Zoomed_x), int(-New_y + Zoomed_y) - i, c);  // left pillar
            gfx.PutPixel(int(New_x2 + Zoomed_x), int(New_y2 + Zoomed_y) - i, c);  // bottom pillar
            gfx.PutPixel(int(-New_x2 + Zoomed_x), int(-New_y2 + Zoomed_y) - i, c);  // top pillar
		}
		
		Lines(); // calls lines function

		for (int i = 0; i <= steps; i++)      // draws 2 sides top and bottom
		{
			gfx.PutPixel(int(linex + Zoomed_x), int(liney + Zoomed_y), c);
			gfx.PutPixel(int(-linex + Zoomed_x), int(-liney + Zoomed_y), c);
			gfx.PutPixel(int(linex + Zoomed_x), int(liney + Zoomed_y - ZoomCubeHeight), c);
			gfx.PutPixel(int(-linex + Zoomed_x), int(-liney + Zoomed_y - ZoomCubeHeight), c);

			linex += xinc;
			liney += yinc;			
		}
		for (int i = 0; i <= steps2; i++)  // draws other 2 sides top and bottom
		{
			gfx.PutPixel(int(linex2 + Zoomed_x), int(liney2 + Zoomed_y), c);
			gfx.PutPixel(int(-linex2 + Zoomed_x), int(-liney2 + Zoomed_y), c);
			gfx.PutPixel(int(linex2 + Zoomed_x), int(liney2 + Zoomed_y - ZoomCubeHeight), c);
			gfx.PutPixel(int(-linex2 + Zoomed_x), int(-liney2 + Zoomed_y - ZoomCubeHeight), c);
			
			linex2 += xinc2;
			liney2 += yinc2;
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
		Zoomed_x =On_Screen_x / ZoomRate; 
	}
	else if (True_x > Frame::Focal_Point_x)
	{
		On_Screen_x = float(Edge_Right - True_x);
			Zoomed_x = Graphics::ScreenWidth - (On_Screen_x / ZoomRate);
	}
	else 
	{
		Zoomed_x = 400;
	}

	if (True_y < Frame::Focal_Point_y)         // zooms cube with mesh in y dim
	{
		On_Screen_y = float(True_y - Edge_Top);
		Zoomed_y = On_Screen_y / ZoomRate;
	}
	else if (True_y > Frame::Focal_Point_y)
	{
		On_Screen_y = float(Edge_Bottom - True_y);
		Zoomed_y = Graphics::ScreenHeight - On_Screen_y / ZoomRate;
	}
	else 
	{
		Zoomed_y = 200;
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
	In_Frame_x = (True_x - 30 > Left && True_x + 30  < Right);   // checks true x is in frame
	In_Frame_y = (True_y - 50  > Top && True_y + 30  < Bottom);   // checks true y is in frame

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

void CubePeon::Lines()
{
	// gets the right triangle 
	dirivedx = int(New_x2 - New_x);
	dirivedy = int(New_y2 - New_y);            
	dirivedx2 = int(-New_x2 - New_x);
	dirivedy2 = int(-New_y2 - New_y);

	// gets the longest side of triangle in absolute for both sides 
	steps = abs(dirivedx) > abs(dirivedy) ? abs(dirivedx) : abs(dirivedy);
	steps2 = abs(dirivedx2) > abs(dirivedy2) ? abs(dirivedx2) : abs(dirivedy2);

	// sets x and y increments per loop by dividing by the steps for first set of lines;
	xinc = dirivedx / float(steps);
	yinc = dirivedy / float(steps);
	linex = float(New_x);
	liney = float(New_y);

	// sets x and y increments per loop by dividing by the steps for second set of lines;
	xinc2 = dirivedx2 / float(steps2);
	yinc2 = dirivedy2 / float(steps2);
	linex2 = float(New_x2);
	liney2 = float(New_y2);
		
}

 