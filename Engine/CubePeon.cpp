#include "CubePeon.h"

void CubePeon::Draw(Graphics & gfx)
{
	if (In_Frame_x && In_Frame_y)   // Draws if in frame
	{
		Color c(0, 100 + int(Zoom), 0);  // add fading


		for (int i = 0; i < Top_Bottom_x; i++)
		{
			gfx.PutPixel(Draw_x, Draw_y - i, c); // left pillar

		}
		for (int i = 0; i < Top_Bottom_x; i++)
		{
			gfx.PutPixel(Draw_x + int(Zoom), Draw_y - i, c);  // right pillar

		}
		for (int i = 0; i < Top_Bottom_x; i++)
		{
			gfx.PutPixel(Draw_x + Top_Bottom_x, Draw_y - Top_Bottom_y - i, c);  // top pillar

		}
		for (int i = 0; i < Top_Bottom_x; i++)
		{
			gfx.PutPixel(Draw_x + Top_Bottom_x, Draw_y + Top_Bottom_y - i, c);  // bottom pillar

		}

		// top and bottom diagonals
		for (int i = 0; i < Zoom; i++)
		{
			y_Step++;


			gfx.PutPixel(Draw_x + i, Draw_y + y2, c); //bottom starting up
			gfx.PutPixel(Draw_x + i, Draw_y + y3, c); // bottom starting down

			gfx.PutPixel(Draw_x + i, Draw_y + y2 - Top_Bottom_x, c); // top starting down
			gfx.PutPixel(Draw_x + i, Draw_y + y3 - Top_Bottom_x, c);  // top starting up

			if (i >= Top_Bottom_x)
			{
				Change_Draw_Direction = true;
			}
			if (y_Step >= 2)
			{
				if (Change_Draw_Direction)
				{
					y2++;
					y3--;
					y_Step = 0;
				}
				else
				{
					y2--;
					y3++;
					y_Step = 0;
				}
			}
		}
		Change_Draw_Direction = false;
		y2 = 0;  // temp stuff
		y3 = 0;   // temp stuff
	}
}

void CubePeon::CubeZoom(float z)
{
	  Zoom = z;
	  temp_Zoom = ( 50 / Zoom);

	if (True_x < Frame::Focal_Point_x)            // zooms cube with mesh in x dim
	{
		On_Screen_x = float(True_x - Edge_Left);
		Draw_x =int((On_Screen_x / temp_Zoom)); 
	}
	else if (True_x > Frame::Focal_Point_x)
	{
		On_Screen_x = float(Edge_Right - True_x);
			Draw_x = int(Graphics::ScreenWidth - (On_Screen_x / temp_Zoom));
	}
	else 
	{
		Draw_x = 400;
	}

	if (True_y < Frame::Focal_Point_y)         // zooms cube with mesh in y dim
	{
		On_Screen_y = float(True_y - Edge_Top);
		Draw_y = int( (On_Screen_y / temp_Zoom));
	}
	else if (True_y > Frame::Focal_Point_y)
	{
		On_Screen_y = float(Edge_Bottom - True_y);
		Draw_y = int(Graphics::ScreenHeight - (On_Screen_y / temp_Zoom));
	}
	else 
	{
		Draw_y = 200;
	}
	
	Top_Bottom_x = int(Zoom / 2);
	Top_Bottom_y = int(Zoom / 4);
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
 