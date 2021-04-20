#include "Character.h"
#include "Texture2D.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
    m_facing_direction = FACING_RIGHT;

	m_moving_left = false;
	m_moving_right = false;

	move_speed = 1.0f;


	m_renderer = renderer;
	m_position = start_position; 

	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load character texture!" << std::endl;
		
	}

}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position; 
}
Character::~Character()
{
	m_renderer = nullptr;
}

void Character::Render()
{
    if (m_facing_direction == FACING_RIGHT)
    {

        m_texture->Render(m_position, SDL_FLIP_NONE); 

    }

    else
    {

        m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);

    }
}
void Character::Update(float deltaTime, SDL_Event e)
{
    if (m_moving_left)
    {

        MovingLeft(deltaTime);

    }

    else if (m_moving_right)
    {

        MovingRight(deltaTime);

    }

   

    switch (e.type)
    {
    case SDL_KEYUP:
        switch (e.key.keysym.sym)
        {
        case SDLK_d:
            //m_moving_right = false;
            break;



        case SDLK_a:
           // m_moving_left = false;
         
            break;


        default:
            break;
        }
        break;

          


    case SDL_KEYDOWN:
        switch (e.key.keysym.sym)
        {

        case SDLK_d:
            m_facing_direction = FACING_RIGHT;
            cout << " " << m_position.x << endl;
           // m_position.x += move_speed;
            m_moving_right = true;
            m_moving_left = false;

            break;

        case SDLK_a:
            m_facing_direction = FACING_LEFT;
            cout << " " << m_position.x << endl;
           // m_position.x -= move_speed;
            m_moving_left = true; 
            m_moving_right = false;

            break;

        default:

            break;

        }

        break;

    }
   
 } 
Vector2D Character::GetPosition()
{
	return m_position;
}

void Character::MovingLeft(float deltaTime)
{
    m_position.x -= move_speed;
}



void Character::MovingRight(float deltaTime)
{
    m_position.x += move_speed;
}