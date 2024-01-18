#pragma once
#include "BaseEntity.h"
#include "Constans.h"

class Bullet : public BaseEntity
{
public:
    Bullet(const std::string path, int x, int y, int bulletDirectionX, int bulletDirectionY);
    void moveBullet();
private:
    int m_bulletDirectionX;
    int m_bulletDirectionY;
    const int COOF_X;
    const int COOF_Y;
};