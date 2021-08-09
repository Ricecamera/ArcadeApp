//============================================================================
// Name        : ArcadeApp.cpp
// Author      : Serge Lanisquot
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#undef main

#include "Color.h"
#include "Screen.h"
#include "Line2D.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 2;

using namespace std;

int main(int argc, const char* argv[])
{
	Screen theScreen;

	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);

	Line2D line = { Vec2D(0, 0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT) };

	float rotateAngle = M_PI;
	line.RotateBy(rotateAngle);

	theScreen.Draw(line, Color::White());
	theScreen.SwapScreens();

	SDL_Event sdlEvent;
	bool running = true;

	
	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			

			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}
	}

	return 0;
}
