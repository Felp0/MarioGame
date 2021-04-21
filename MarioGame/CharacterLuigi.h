#pragma once
#ifndef CHARACTERLUIGI_H
#define CHARACTERLUIGI_H
#include "Character.h"

class CharacterLuigi : public Character
{

public:
	CharacterLuigi(SDL_Renderer* renderer, string imagePath, Vector2D start_position,LevelMap* map);
	~CharacterLuigi();


	virtual void Update(float deltatime, SDL_Event e);

};

#endif // !CHARACTERMARIO_H
