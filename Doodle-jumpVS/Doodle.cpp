#include "Doodle.h"

#include "Platform.h"

Doodle::Doodle(std::string path, int _x, int _y)
    : BaseEntity(path, _x, _y)
{}

void Doodle::moveDown()
{
    m_y += speedUpDown;
}

void Doodle::moveUp()
{
    m_y -= speedUpDown;
}

void Doodle::moveLeft()
{
    if(checkMoveLeft)
        m_x -= 15;
}

void Doodle::moveRight()
{
    if(checkMoveRight)
        m_x += 15;
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
    if (isFall)
    {
        moveDown();
    }
    else
    {
        if (count >= jumpHight)
        {
            count = 0;
            isFall = true;
        }
        else
        {
            count += speedUpDown;
            moveUp();
        }
        
    }
}

void Doodle::setCheckMoveLeft()
{
    if (checkMoveLeft)
    {
        checkMoveLeft = false;
        return;
    }
    checkMoveLeft = true;
}

void Doodle::setCheckMoveRight()
{
    if (checkMoveRight)
    {
        checkMoveRight = false;
        return;
    }
    checkMoveRight = true;
}

void Doodle::setIsFall(bool _isFall)
{
    isFall = _isFall;
}

int Doodle::getDoodleHeight() const
{
    return doodleHeight;
}

int Doodle::getDoodleWidth() const
{
    return doodleWidth;
}

int Doodle::getJumpHight()
{
    return jumpHight;
}
