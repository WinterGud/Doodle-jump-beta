#include "Platform.h"

Platform::Platform(const std::string& path, int _x, int _y)
    : BaseEntity(path, _x, _y)
{
    this->setSize(PLATFORM_WIDTH, PLATFORM_HEIGHT);
}

Platform& Platform::operator=(const Platform& other)
{
    if (this->m_entitySprite == other.m_entitySprite)
        return *this;
    this->m_entitySprite = other.m_entitySprite;
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    return *this;
}

void Platform::setPostion(int x, int y)
{
    setX(x);
    setY(y);
}
