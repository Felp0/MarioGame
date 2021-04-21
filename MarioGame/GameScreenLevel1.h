#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H

#include "GameScreen.h"
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "LevelMap.h"

class Texture2D;
class Character;
class CharacterMario;
class CharacterLuigi;

class GameScreenLevel1 : GameScreen
{
private:
	//LevelMap* m_level_map;

	Texture2D* m_background_texture;

	CharacterMario* my_character;
	CharacterLuigi* my_Luigi;

	LevelMap* m_level_map;
	
	bool SetUpLevel();

	void SetLevelMap(); 
	

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;




};

#endif // !_GAMESCREENLEVEL1_H
