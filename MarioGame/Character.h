#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include "SDL.h"
#include "Commons.h"
#include <string>

using namespace std;


class Texture2D;

class Character
{
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position; 
	Texture2D* m_texture;

	bool m_moving_right;
	bool m_moving_left;
	
	float move_speed;
	

	virtual void MovingLeft(float deltaTime);
	virtual void MovingRight(float deltaTime);

private:
	FACING m_facing_direction;
	

public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
};

#endif // !_CHARACTER_H
