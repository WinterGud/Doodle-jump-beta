#include "Bullet.h"

namespace 
{
    const int BULLET_WIDTH = 10;
    const int BULLET_HEIGHT = 10;
}

Bullet::Bullet(const std::string path, int x, int y, int bulletDirectionX, int bulletDirectionY)
    : BaseEntity(path, x, y),
      m_bulletDirectionX(bulletDirectionX),
      m_bulletDirectionY(bulletDirectionY),
      COOF_X(m_x - m_bulletDirectionX / BULLET_SPEED),
      COOF_Y(m_y - m_bulletDirectionY / BULLET_SPEED)
{
    setSize(BULLET_WIDTH, BULLET_HEIGHT);
}

void Bullet::moveBullet()
{
    
}
