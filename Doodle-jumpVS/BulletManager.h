#pragma once
#include <future>
#include <vector>

class Bullet;

class BulletManager
{
public:
    using bulletsList = std::vector<std::shared_ptr<Bullet>>;
    void tick() const;
    void deleteBullets();
    void shootBulletVertical(int doodleX, int doodleY);
    void shootBulletToCoordinates(int doodleX, int doodleY, int directionX, int directionY);
    bulletsList& getBulletsList() { return m_bulletsList; }

private:
    bulletsList m_bulletsList;
};
