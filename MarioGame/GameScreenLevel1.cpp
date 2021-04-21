#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include "Collisions.h"
#include <iostream>

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	//set up level
	SetUpLevel();

	//pointer
	m_level_map = nullptr;

}
GameScreenLevel1::~GameScreenLevel1()
{
	m_background_texture = nullptr;
	my_character = nullptr;
	my_Luigi = nullptr;
	delete my_character;
}

void GameScreenLevel1::Render() 
{
	//Draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	//Call the character
	my_character->Render();
	my_Luigi->Render();

}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e) 
{
	//update character
	my_character->Update(deltaTime , e); 
	my_Luigi->Update(deltaTime, e);

	//Collision

	if (Collisions::Instance()->Circle(my_character, my_Luigi))
	{
		cout << "Circle hit!" << endl;
	}

	if (Collisions::Instance()->Box(my_character->GetCollisionBox(), my_Luigi->GetCollisionBox()))
	{
		cout << "Box hit!" << endl;
	}
	
	
} 

bool GameScreenLevel1::SetUpLevel()
{
	SetLevelMap();
	
	//set up player character
	my_character = new CharacterMario(m_renderer, "SDL2/Images/Mario.png", Vector2D(32, 330), m_level_map);
	my_Luigi = new CharacterLuigi(m_renderer, "SDL2/Images/Luigi.png", Vector2D(32, 356), m_level_map);
	//load texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("SDL2/Images/image.bmp"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}

}
	
void GameScreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
									  { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
	
	//CLEAR ANY OLD MAPS
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}

	//set the new one
	m_level_map = new LevelMap(map);
}