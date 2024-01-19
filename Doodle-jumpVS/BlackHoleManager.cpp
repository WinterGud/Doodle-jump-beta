#include "BlackHoleManager.h"
#include "Constans.h"
#include "BlackHole.h"

void BlackHoleManager::tick() const
{
    for (auto it : m_blackHolesList)
    {
        it->draw();
    }
}

void BlackHoleManager::createEnemy(int x, int y)
{
    m_blackHolesList.push_back(std::make_shared<BlackHole>(ENEMY_PATH, x, y));
}

void BlackHoleManager::deleteEnemies()
{
    for (int i = 0; i < m_blackHolesList.size(); i++)
    {
        if (m_blackHolesList[i]->getY() > MAP_WIDTH)
        {
            m_blackHolesList.erase(m_blackHolesList.begin() + i, m_blackHolesList.begin() + (i + 1));
        }
    }
}

void BlackHoleManager::moveEnemiesDown() const
{
    for (int i = 0; i < m_blackHolesList.size(); i++)
    {
        m_blackHolesList[i]->setY(m_blackHolesList[i]->getY() + MOVE_MAP_DOWN);
    }
}


