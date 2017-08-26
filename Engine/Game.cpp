/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(1000, 15000),
	yDist(1000, 15000)

{
	for (int i = 0; i < Ncubes; i++)
	{		

		Enemy[i].SpawnSet(xDist(rng), yDist(rng));
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	speed = 0;
	if (wnd.kbd.KeyIsPressed('W'))
	{
		speed = 1; 
	}
	else if (wnd.kbd.KeyIsPressed('S'))
	{
		speed = -1;
	}

	if (wnd.kbd.KeyIsPressed('A'))
	{
		Turn -= 3;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		Turn += 3;
	}
	if (wnd.kbd.KeyIsPressed('H'))   // centers screen back at home.
	{
		x = 10000;
		y = 10000;
	}

		if (Turn > 359)  // keeps degrees at 0 - 360 
		{
			Turn = 0;
		}
		else if (Turn < 0)
		{
			Turn = 359;
		}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= 10;	
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += 10;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 10;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 10;
	}
		if (wnd.kbd.KeyIsPressed('Z'))
		{
			z += 1;
		}
		if (wnd.kbd.KeyIsPressed('X'))
		{
			z -= 1;
		}
	    if (z > 50)
		{
			z = 50;   // stops zooming in too far
		}
		else if (z < 10)
		{
			z = 10;    // stops zooming out too far
		}
	

    Table1.ZoomIn(z);  // Modifies table to adjust for zoom
    Zoom_Frame.Frame_Set(x, y, z);
	xlines0.ZoomMesh(z);
	xlines0.MoveMesh(Zoom_Frame.Get_Left(), Zoom_Frame.Get_Right(), Zoom_Frame.Get_Top(), Zoom_Frame.Get_Bottom());


	for (int i = 0; i < Ncubes2; i++)
	{
		
		Peon[i].Screen_Size(Zoom_Frame.Get_Left(), Zoom_Frame.Get_Right(), Zoom_Frame.Get_Top(), Zoom_Frame.Get_Bottom());
		Peon[i].CubeZoom(z);
		// Gives address of Table1 array to Peons
		Peon[i].Rotate(Table1.Array_xPoint, Table1.Array_yPoint, Table1.DirectionArray_x, Table1.DirectionArray_y, Turn); 
		Peon[i].SpeedIn(speed);
	}
	for (int i = 0; i < Ncubes; i++)
	{
		Enemy[i].Target();
		
		Enemy[i].Screen_Size(Zoom_Frame.Get_Left(), Zoom_Frame.Get_Right(), Zoom_Frame.Get_Top(), Zoom_Frame.Get_Bottom());
		Enemy[i].CubeZoom(z);
		// Gives address of Table1 array to Enemys
		Enemy[i].Rotate(Table1.Array_xPoint, Table1.Array_yPoint, Table1.DirectionArray_x, Table1.DirectionArray_y, Turn);
		Enemy[i].SpeedIn(speed);
	}
	
	for (int i = 0; i < Ncubes; i++)    // Enemy kill loop
	{
		int Enemylocx = 0;
	    int Enemylocy = 0;
		Enemy[i].Getloc(Enemylocx, Enemylocy);
		if (Enemylocx > 10000 - 100 &&
			Enemylocx < 10000 + 100 &&
			Enemylocy > 10000 - 100 &&
			Enemylocy < 10000 + 100)
		{
			Enemy[i].Killed();
			Enemy[i].SpawnSet( xDist(rng), yDist(rng)) ; 
		}
	}

}

void Game::ComposeFrame()
{
	//xlines0.Draw(gfx);  // <<<<  Laggy in debug, comment out for testing if need be

	for (int i = 0; i < Ncubes; i++)
	{
		Enemy[i].Draw(gfx);
	}
	for (int i = 0; i < Ncubes2; i++)
	{
		Peon[i].Draw(gfx);
	}

	gfx.PutPixel( (Graphics::ScreenWidth / 2), (Graphics::ScreenWidth / 4), Colors::Green ); // Zoom centre
	gfx.PutPixel((Graphics::ScreenWidth / 2) + 3, (Graphics::ScreenWidth / 4), Colors::Green);
	gfx.PutPixel((Graphics::ScreenWidth / 2) -3, (Graphics::ScreenWidth / 4), Colors::Green);
	gfx.PutPixel((Graphics::ScreenWidth / 2), (Graphics::ScreenWidth / 4) +3, Colors::Green);
	gfx.PutPixel((Graphics::ScreenWidth / 2), (Graphics::ScreenWidth / 4) -3, Colors::Green);
}
