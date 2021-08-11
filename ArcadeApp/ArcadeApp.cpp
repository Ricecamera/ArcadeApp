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
#include <algorithm>

#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
#include "Shapes/Triangle.h"
#include "Shapes/star.h";
#include "Utils.h"

const int MAGNIFICATION = 1;

using namespace std;

vector<Star> createGroupofStar(int n);

int main(int argc, const char* argv[])
{
	Screen theScreen;

	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);

	auto starArr = createGroupofStar(10);
	// sorting by size and set position from top-left to bottom-right
	std::sort(starArr.begin(), starArr.end(), [](const Star& lhs, const Star& rhs)-> bool {
		if (lhs.GetOuterDist() < rhs.GetOuterDist())
		{
			return true;
		}

		if (IsEqual(lhs.GetOuterDist(), rhs.GetOuterDist()))
		{
			if (lhs.GetInnerDist() < rhs.GetInnerDist())
			{
				return true;
			}
			return false;
		}
		return false;
		});

	for (int i = 0; i < 10; i++)
	{
		starArr[i].MoveTo(Vec2D(30 + 80 * i, 30 + 50 * i));
	}

	// Draw stars
	for (auto& star : starArr)
	{
		theScreen.Draw(star, Color::Yellow());
	}
	
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

vector<Star> createGroupofStar(int n) {
	vector<Star> starArr;

	for (int i = 0; i < n; i++)
	{
		Star createStar = Star::GenerateRandomStar();
		
		starArr.push_back(createStar);
	}

	return starArr;
}