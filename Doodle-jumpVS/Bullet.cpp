#include "Bullet.h"

namespace 
{
    const int BULLET_WIDTH = 10;
    const int BULLET_HEIGHT = 10;
}

Bullet::Bullet(const std::string path, int x, int y)
    : BaseEntity(path, x, y)
{
    setSize(BULLET_WIDTH, BULLET_HEIGHT);
}

void Bullet::setDirectionAndCoof(int directionX, int directionY)
{
    m_bulletDirectionX = directionX;
    m_bulletDirectionY = directionY;
    m_coofX = (m_x - m_bulletDirectionX) / BULLET_SPEED;
    m_coofY = (m_y - m_bulletDirectionY) / BULLET_SPEED;
}

void Bullet::moveBullet()
{
    m_x -= m_coofX * BULLET_SPEED;
    m_y -= m_coofY * BULLET_SPEED;
}
