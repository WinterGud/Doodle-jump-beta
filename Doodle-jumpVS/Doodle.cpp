#include "Doodle.h"

Doodle::Doodle(std::string path, int _x, int _y)
    : BaseEntity(path, _x, _y)
{
    
}

void Doodle::moveUp()
{
    m_y += 1;
}

void Doodle::moveDown()
{
    m_y -= 5;
}

void Doodle::moveLeft()
{
    m_x -= 5;
}

void Doodle::moveRight()
{
    m_x += 5;
}

Doodle& Doodle::operator=(const Doodle& other)
{
    if(this->m_entitySprite == other.m_entitySprite)
        return *this;
    this->m_entitySprite = other.m_entitySprite;
    this->m_x = other.m_x;
    this->m_y = other.m_y;
}
