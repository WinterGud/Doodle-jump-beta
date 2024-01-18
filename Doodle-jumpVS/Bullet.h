#pragma once
#include "BaseEntity.h"
#include "Constans.h"

class Bullet : public BaseEntity
{
public:
    Bullet(const std::string path, int x, int y);
    void setDirectionAndCoof(int directionX, int directionY);
    void moveBullet();
    int getBulletDirectionX() { return m_bulletDirectionX; }
    int getBulletDirectionY() { return m_bulletDirectionY; }
    int getCoofX() { return m_coofX; }
    int getCoofY() { return m_coofY; }
private:
    int m_bulletDirectionX;
    int m_bulletDirectionY;
    int m_coofX;
    int m_coofY;
};