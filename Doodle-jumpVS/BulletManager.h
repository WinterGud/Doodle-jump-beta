#pragma once
#include <future>
#include <vector>

class Bullet;

class BulletManager
{
public:
    void tick() const;
    void deleteBullets();
    void shootBulletVertical(int doodleX, int doodleY);
    void shootBulletToCoordinates(int doodleX, int doodleY, int directionX, int directionY);
private:
    std::vector<std::shared_ptr<Bullet>> m_bulletsList;
};
