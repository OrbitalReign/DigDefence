#include "Frame.h"

void Frame::Frame_Set(int x, int y, float z)
{
	float Zoom = (z);
	float Temp_Zoom =(50 / Zoom);


	 x_Left   = int(x - (Focal_Point_x * Temp_Zoom)); //screen boundry left 
	 x_Right  = int(x + (Focal_Point_x  * Temp_Zoom)); // screen boundry right
	 y_Top    = int(y - (Focal_Point_y * Temp_Zoom)); //screen boundry top
	 y_Bottom = int(y + (Focal_Point_y * 2 * Temp_Zoom)); // screen boundry bottom 
	        // bottom is by * 2 to give 2/3 because focal point is 1/3 down the screen
}

int Frame::Get_Left()
{
	return x_Left;
}
int Frame::Get_Right()
{
	return x_Right;
}

int Frame::Get_Top()
{
	return y_Top;
}

int Frame::Get_Bottom()
{
	return y_Bottom;
}




