#include "EnemyCube.h"
#include <math.h>
#define PI 3.1415926536



void EnemyCube::Draw(Graphics & gfx)
{
	if (In_Frame_x && In_Frame_y)   // Draws if in frame
	{
		Color c(100 + int(Zoom), 0 , 0);  // add fading

		for (int i = 0; i < ZoomCubeHeight; i++)
		{
			gfx.PutPixel(int(New_x + Zoomed_x), int(New_y + Zoomed_y) - i, c); // right pillar
			gfx.PutPixel(int(-New_x + Zoomed_x), int(-New_y + Zoomed_y) - i, c);  // left pillar
			gfx.PutPixel(int(New_x2 + Zoomed_x), int(New_y2 + Zoomed_y) - i, c);  // bottom pillar
			gfx.PutPixel(int(-New_x2 + Zoomed_x), int(-New_y2 + Zoomed_y) - i, c);  // top pillar

			gfx.PutPixel(int(New_x + Zoomed_x + 1), int(New_y + Zoomed_y + 1) - i, Colors::Yellow);
			gfx.PutPixel(int(New_x2 + Zoomed_x + 1), int(New_y2 + Zoomed_y + 1) - i, Colors::Yellow);
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

void EnemyCube::CubeZoom(float z)
{
	Zoom = z;
	ZoomRate = (50 / Zoom);
	ZoomCubeHeight = int(CubeHeight / ZoomRate);

	if (True_x < Frame::Focal_Point_x)            // zooms cube with mesh in x dim
	{
		On_Screen_x = float(True_x - Edge_Left);
		Zoomed_x = On_Screen_x / ZoomRate;
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

void EnemyCube::SpeedIn(int speed)
{
// turnx = turnx * Speed;
//	turny = turny * Speed;
	True_x += turnx / 2;
	True_y += turny / 2;
}

void EnemyCube::Screen_Size(int Left, int Right, int Top, int Bottom)
{
	//  gets the zoomed screen boundary
	In_Frame_x = (True_x - 30 > Left && True_x + 30  < Right);   // checks true x is in frame
	In_Frame_y = (True_y - 50  > Top && True_y + 30  < Bottom);   // checks true y is in frame
	Edge_Left = Left;
	Edge_Right = Right;
	Edge_Top = Top;
	Edge_Bottom = Bottom;

}

void EnemyCube::Rotate(int * TablePointerx, int * TablePointery, int * DirectionPointx, int * DirectionPointy, int Turn)
{
	Deg = (-Degrees)+225;
	Deg2 = (-Degrees)+315;
	Deg3 = (-Degrees)+200;   // working? <<<<<<
	if (Deg > 359)
	{
		Deg = 0 + (Deg - 359); // Loops Deg around 360 degrees
	}
	else if (Deg < 0)
	{
		Deg = 359 - (Deg + 359 );
	}
	if (Deg2 > 359)
	{
		Deg2 = 0 + (Deg2 - 359); // Loops Deg2 around 360 degrees
	}
	else if (Deg2 < 0)
	{
		Deg2 = 359 - (Deg2 + 359);
	}
	if (Deg3 > 359)
	{
		Deg3 = 0 + (Deg3 - 359);        // Loops Deg3 around 360 degrees
	}
	else if (Deg3 < 0)
	{
		Deg3 = 359 - (Deg3 + 359);
	}
	const int * Xpoint = TablePointerx + Deg;
	const int * Ypoint = TablePointery + Deg;  // Rotates corner of cube
	New_x = *Xpoint;
	New_y = *Ypoint;

	const int * Xpoint1 = TablePointerx + Deg2;
	const int * Ypoint1 = TablePointery + Deg2;  // Rotates adjacent corner of cube at 90 from first.
	New_x2 = *Xpoint1;
	New_y2 = *Ypoint1;

	const int * Xpoint2 = DirectionPointx + Deg3;
	const int * Ypoint2 = DirectionPointy + Deg3;   // orientates front face of cube for movenment direction 
	turnx = *Xpoint2;
	turny = *Ypoint2;

}

void EnemyCube::SpawnSet(int x, int y)
{
	if (!Spawned)
	{
		True_x = x;
		True_y = y;
		Spawned = true;   // Cube has spawned and cant be reset till death.
	}
}

void EnemyCube::Killed() // add health stuff to call this <<<<
{
	Spawned = false;   // Cube is dead and can be respawned.
}

void EnemyCube::Getloc( int& x, int& y)const 
{
	x = True_x;
	y = True_y;
}

void EnemyCube::Target()
{
	// test stuff
	double x, y;
	x = True_x - 10000;
	y = True_y - 10000;

	Degrees = int(atan2(x, y) * 180 / PI);
}

void EnemyCube::Lines()
{
	// gets the right angle triangle 
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