#pragma once
#ifndef CHARACTERMARIO_H
#define CHARACTERMARIO_H
#include "Character.h"

class CharacterMario : public Character
{

public:
	CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D start_position,LevelMap* map);
	~CharacterMario();

	
	virtual void Update(float deltatime, SDL_Event e);

 };

#endif // !CHARACTERMARIO_H
