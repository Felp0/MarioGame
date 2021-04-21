#include "CharacterLuigi.h"

CharacterLuigi::CharacterLuigi(SDL_Renderer* renderer, string imagePath, Vector2D start_position,LevelMap* map) : Character(renderer, imagePath, start_position, map)
{
    m_moving_left = false;
    m_moving_right = false;

}
CharacterLuigi::~CharacterLuigi()
{

}

void CharacterLuigi::Update(float deltatime, SDL_Event e)
{
    //switch for movement
    switch (e.type)
    {
    case SDL_KEYUP:
        switch (e.key.keysym.sym)
        {
        case SDLK_RIGHT:
            m_moving_right = false;
            break;



        case SDLK_LEFT:
            m_moving_left = false;

            break;

        case SDLK_UP:
            m_jumping = false;


        default:
            break;
        }
        break;




    case SDL_KEYDOWN:
        switch (e.key.keysym.sym)
        {

        case SDLK_RIGHT:
            // m_facing_direction = FACING_RIGHT;
            cout << " luigi moving right:  " << m_position.x << endl;
            // m_position.x += move_speed;
            m_moving_right = true;
            // m_moving_left = false;

            break;

        case SDLK_LEFT:
            //m_facing_direction = FACING_LEFT;
            cout << " luigi moving left:  " << m_position.x << endl;
            // m_position.x -= move_speed;
            m_moving_left = true;
            // m_moving_right = false;

            break;

        case SDLK_UP:
            cout << "  luigi Jumping" << endl;
            m_jumping = true;

        default:

            break;

        }

        Character::Update(deltatime, e);
        break;

    }
}
