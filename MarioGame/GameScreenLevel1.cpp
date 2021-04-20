#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include <iostream>

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	
	SetUpLevel();

}
GameScreenLevel1::~GameScreenLevel1()
{
	m_background_texture = nullptr;
	my_character = nullptr;
	delete my_character;
}

void GameScreenLevel1::Render() 
{
	//Draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	//Call the character
	my_character->Render();

}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e) 
{
	//update character
	my_character->Update(deltaTime , e); 
	
} 

bool GameScreenLevel1::SetUpLevel()
{
	//set up player character
	my_character = new Character(m_renderer, "SDL2/Images/Mario.png", Vector2D(32, 330));
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
			