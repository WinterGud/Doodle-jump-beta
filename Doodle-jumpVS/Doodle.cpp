#include "Doodle.h"

Doodle::Doodle(std::string path, int _x, int _y)
    : BaseEntity(path, _x, _y)
{
    
}

void Doodle::moveDown()
{
    m_y += 20;
}

void Doodle::moveUp()
{
    m_y -= 20;
}

void Doodle::moveLeft()
{
    m_x -= 20;
}

void Doodle::moveRight()
{
    m_x += 20;
}

Doodle& Doodle::operator=(const Doodle& other)
{
    if(this->m_entitySprite == other.m_entitySprite)
        return *this;
    this->m_entitySprite = other.m_entitySprite;
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    return *this;
}

void Doodle::jump(bool)
{
    if((getTickCount()/1000)%2)
    {
        this->moveUp();
    }
    else
    {
        this->moveDown();
    }
}

