#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include "SDL.h"
#include "Texture2D.h"
#include "LevelMap.h"
#include <string>

using namespace std;


class Texture2D;
class LevelMap;

class Character
{
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position; 
	Texture2D* m_texture;

	bool m_moving_right;
	bool m_moving_left;
	bool m_jumping;
	bool m_can_jump;
	
	float m_jump_force;
	float m_collision_radius;
	
	virtual void MovingLeft(float deltaTime); 
	virtual void MovingRight(float deltaTime);
	virtual void AddGravity(float deltaTime);
	virtual void Jump();

private:
	FACING m_facing_direction;

	LevelMap* m_current_levelmap;
	

public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	void SetPosition(Vector2D new_position);

	Vector2D GetPosition();

	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight()); }

	float GetCollisionRadius();


};

#endif // !_CHARACTER_H
