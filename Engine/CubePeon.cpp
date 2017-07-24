#include "CubePeon.h"

void CubePeon::Draw(Graphics & gfx)
{
	Color c(0 , 100 + (Zoom * 2), 0);


	for (int i = 0; i < Top_Bottom_x; i++)
	{
		gfx.PutPixel(Draw_x ,Draw_y - i , c); // left pillar

	}
	for (int i = 0; i < Top_Bottom_x; i++)
	{
		gfx.PutPixel(Draw_x + Zoom , Draw_y - i, c);  // right pillar
		
	}
	for (int i = 0; i < Top_Bottom_x; i++)
	{
		gfx.PutPixel(Draw_x + Top_Bottom_x , Draw_y - Top_Bottom_y - i, c);  // top pillar

	}
	for (int i = 0; i < Top_Bottom_x; i++)
	{
		gfx.PutPixel(Draw_x + Top_Bottom_x , Draw_y + Top_Bottom_y - i, c);  // bottom pillar

	}

	// top and bottom diagonals
	for (int i = 0; i < Zoom ; i++)
	{
		y_Step++;

		
			gfx.PutPixel(Draw_x + i , Draw_y + y2, c); //bottom starting up
			gfx.PutPixel(Draw_x + i , Draw_y + y3, c); // bottom starting down
						 		  
			gfx.PutPixel(Draw_x + i , Draw_y + y2 - Top_Bottom_x, c); // top starting down
			gfx.PutPixel(Draw_x + i , Draw_y + y3 - Top_Bottom_x, c);  // top starting up
		
		if ( i >= Top_Bottom_x)
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

void CubePeon::CubeZoom(int z)
{
	Zoom = z;
	temp_Zoom = 50 / Zoom;
	if ( True_x < 400 )                                               // zooms cube with mesh in x dim
	{
		Draw_x = static_cast<int>(400 - (True_x / temp_Zoom)); 
	}
	else if (True_x > 400)
	{
		Draw_x = static_cast<int>(400 + (True_x / temp_Zoom));
	}

	if (True_y < 200)                                                // zooms cube with mesh in y dim
	{
		Draw_y = static_cast<int> ( 200 - (True_y / temp_Zoom));
	}
	else if (True_y > 200)
	{
		Draw_y = static_cast<int> (200 + (True_y / temp_Zoom));
	}

	Top_Bottom_x = Zoom / 2;
	Top_Bottom_y = Zoom / 4;
} 

void CubePeon::Location(int x, int y)
{
	True_x = x;
	True_y = y;
}
