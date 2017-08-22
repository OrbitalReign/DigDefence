#include "RotationTable.h"
#include <math.h>
#define PI 3.1415926536

void RotationTable::ZoomIn(int In_z)
{
	ZoomRate = float(50.0f / In_z);
	Hypot = CubeWidth / ZoomRate;
	if ( In_z != Zoom)
	{
		Zoom = (In_z);
		RotateCalc();  // updates table only if Zoom changes
	}
}

void RotationTable::RotateCalc()
{
	
	for (int i = 0; i < RotationAccuracy; i++)
	{
		int Calc_vx;
	    int Calc_vy;
		Degrees = i * PI / 180;    // gets radians for trig function
		Calc_vx = int((cos(Degrees) * Hypot) * 2);  // x multiplied by 2 to give an elipse rotation to match view angle.
		Calc_vy = int(sin(Degrees) * Hypot);
		RotationArray_x[i] = Calc_vx;
		RotationArray_y[i] = Calc_vy;
	}
	
}
