#include "CubePeon.h"

void CubePeon::Draw(Graphics & gfx)
{
	Color c(0, 255 , 0);



	gfx.PutPixel(x, y, c);  // left pillar
	gfx.PutPixel(x + Zoom, y, c);  // right pillar
	gfx.PutPixel(x + Top_Bottom_x, y - Top_Bottom_y , c);  // top pillar
	gfx.PutPixel(x + Top_Bottom_x, y + Top_Bottom_y , c);  // bottom pillar
}

void CubePeon::CubeZoom(int z)
{
	Zoom = z;

	if (Zoom > temp_Zoom  )
	{
		y += 5;
	}
	if (Zoom < temp_Zoom  )
	{
		y -= 5;
	}
	temp_Zoom = z ;
	Top_Bottom_x = Zoom /2;
	Top_Bottom_y = Zoom / 4;
}
