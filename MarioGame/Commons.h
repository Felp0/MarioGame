#pragma once

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
	
	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D(float initial_x, float initial_y)
	{
		x = initial_x;
		x = initial_y;
	}


};