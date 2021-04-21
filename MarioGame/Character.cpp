#include "Character.h"
#include "constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position,LevelMap* map)
{
    m_facing_direction = FACING_RIGHT;
	m_renderer = renderer;
	m_position = start_position; 
    m_current_levelmap = map;

    m_collision_radius = 15.0f;

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


void Character::Update(float deltaTime, SDL_Event e)
{
    //collision position variables
    int centralX_position = (int)(m_position.x + (m_texture->GetWidth() * 0.5)) / TILE_WIDHT;
    int foot_position = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;
    //deal with gravity
    if (m_current_levelmap->GetTileAt(foot_position, centralX_position) == 0)
    {
        AddGravity(deltaTime);
    }
    else
    {
        m_can_jump = true;
    }

    if (m_jumping)
    {
        //adjust position
        m_position.y -= m_jump_force * deltaTime;

        //reduce ump force
        m_jump_force -=  deltaTime * JUMP_FORCE_DECREMENT;

        //is jump force 0 ?
        if (m_jump_force <= 0.0f)
            m_jumping = false;

        Jump();
        
    }
    
    
    //movement
    if (m_moving_left)
    {
        MovingLeft(deltaTime);
    }
    else if (m_moving_right)
    {
        MovingRight(deltaTime);
    }

        


   
 } 
Vector2D Character::GetPosition()
{
	return m_position;
}

void Character::MovingLeft(float deltaTime)
{
    m_facing_direction = FACING_LEFT;
    m_position.x -= deltaTime * MOVEMENTSPEED;
}



void Character::MovingRight(float deltaTime)
{
    m_facing_direction = FACING_RIGHT;
    m_position.x += deltaTime * MOVEMENTSPEED;
}

void Character::AddGravity(float deltaTime)
{
    if (m_position.y + 64 <= SCREEN_HEIGHT)
    {
        m_position.y += deltaTime * GRAVITY;
    }
    else
    {
        m_can_jump = true;
    }
   
       
    
}

void Character::Jump()
{
    if (!m_jumping)
    {
        m_jump_force = INITIAL_JUMP_FORCE;
        m_jumping = true;
        m_can_jump = false;
    }
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

float Character::GetCollisionRadius()
{
    return m_collision_radius;
}