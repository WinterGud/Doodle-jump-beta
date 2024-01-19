#include "Doodle.h"
#include "Constans.h"

namespace 
{
    const int SPEED_UP_DOWN = 50;
    const int SPEED_LEFT_RIGHT = 20;
}

Doodle::Doodle(const std::string& path, int _x, int _y)
    : BaseEntity(path, _x, _y)
{}

void Doodle::moveDown()
{
    m_y += SPEED_UP_DOWN;
}

void Doodle::moveUp()
{
    m_y -= SPEED_UP_DOWN;
}

void Doodle::moveLeft()
{
    if(checkMoveLeft)
        m_x -= SPEED_LEFT_RIGHT;
}

void Doodle::moveRight()
{
    if(checkMoveRight)
        m_x += SPEED_LEFT_RIGHT;
}

Doodle& Doodle::operator=(const Doodle& other)
{
    if (this->m_entitySprite == other.m_entitySprite)
        return *this;
    this->m_entitySprite = other.m_entitySprite;
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    return *this;
}

void Doodle::jump()
{
    m_dy += 0.2;
    m_y += m_dy;
    if(m_y > MAP_HEIGHT)
    {
        m_dy = -SPEED_UP_DOWN/2;
    }
}

void Doodle::goOutMapWidth()
{
    if(m_x + DOODLE_WIDTH < 0)
    {
        m_x = MAP_WIDTH;
    }
    if(m_x > MAP_WIDTH)
    {
        m_x = -DOODLE_WIDTH;
    }
}
