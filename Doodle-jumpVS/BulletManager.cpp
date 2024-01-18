#include "BulletManager.h"
#include "Bullet.h"

void BulletManager::tick() const
{
    for (auto it : m_bulletsList)
    {
        it->draw();
        it->moveBullet();
    }
}

void BulletManager::deleteBullets()
{
    for(size_t i = 0; i < m_bulletsList.size(); i++)
    {
        if(m_bulletsList[i]->getY() < 0)
        {
            m_bulletsList.erase(m_bulletsList.begin()+i, m_bulletsList.begin()+i+1);
        }
    }
}

void BulletManager::shootBulletVertical(int doodleX, int doodleY)
{
    m_bulletsList.push_back(std::make_shared<Bullet>(DOODLE_PATH, doodleX + DOODLE_WIDTH/ 2, doodleY));
    m_bulletsList.back()->setDirectionAndCoof(doodleX, 0);
}

void BulletManager::shootBulletToCoordinates(int doodleX, int doodleY, int directionX, int directionY)
{
    m_bulletsList.push_back(std::make_shared<Bullet>(DOODLE_PATH, doodleX + DOODLE_WIDTH/ 2, doodleY));
    m_bulletsList.back()->setDirectionAndCoof(directionX, directionY);
}

