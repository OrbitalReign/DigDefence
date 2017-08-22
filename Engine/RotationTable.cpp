#include "RotationTable.h"
#include <math.h>
#define PI 3.1415926536

void RotationTable::ZoomIn(float In_z)
{
	ZoomRate = (50.0f / In_z);
	Hypot = CubeWidth / ZoomRate;
	if ( In_z != Zoom)
	{
		Zoom = (In_z);
		RotateCalc();  // updates table only if Zoom changes
	}
}

void RotationTable::RotateCalc()
{
	
	for (int i = 0; i < RotationAccuracy; i++)   // Array for cudes rotation with zoom 
	{
		int Calc_vx;
		int Calc_vy;
		Degrees = i * PI / 180;    // gets radians for trig function
		Calc_vx = int((cos(Degrees) * Hypot) * 2);  // x multiplied by 2 to give an elipse rotation to match view angle.
		Calc_vy = int(sin(Degrees) * Hypot);
		RotationArray_x[i] = Calc_vx;
		RotationArray_y[i] = Calc_vy;
	}
    for (int i = 0; i < RotationAccuracy; i++)   //Base array for Move Direction
	{
		int Calc_vx;
		int Calc_vy;
		Degrees = i * PI / 180;    // gets radians for trig function
		Calc_vx = int((cos(Degrees) * CubeWidth) * 2);  // x multiplied by 2 to give an elipse rotation to match view angle.
		Calc_vy = int(sin(Degrees) * CubeWidth);
		DirectionArray_x[i] = Calc_vx;
		DirectionArray_y[i] = Calc_vy;
	 }
	
}
