#pragma once

	enum FACING
	{

		FACING_LEFT,
		FACING_RIGHT

	};
	enum SCREENS
	{
		SCREEN_INTRO,
		SCREEN_MENU,
		SCREEN_LEVEL1,
		SCREEN_LEVEL2,
		SCREEN_GAMEOVER,
		SCREEN_HIGHSCORES
	};
struct Vector2D
{
	float x;
	float y;
	
	Vector2D(float X = 0, float Y = 0)
	{
		x = X;
		y = Y;
	}


};