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


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
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
	if (wnd.kbd.KeyIsPressed('W'))
	{
		y2 += 2;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		y2 -= 2;
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		x2 += 2;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		x2 -= 2;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= 5;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += 5;

	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 3;

	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 3;

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
				z = 50;
			}
			else if (z < 10)
			{
				z = 10;
			}
				
	xlines0.Zoom(z);
	xlines0.MoveMesh(x , y);
	Peon0.CubeZoom(z);
	Peon0.Location(x2, y2);
	
}

void Game::ComposeFrame()
{
	xlines0.Draw(gfx);
	Peon0.Draw(gfx);
	gfx.PutPixel( (Graphics::ScreenWidth / 2), (Graphics::ScreenWidth / 4), Colors::Green ); // Zoom centre
}
