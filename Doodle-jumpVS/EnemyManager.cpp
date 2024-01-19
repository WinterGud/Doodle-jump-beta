#include "EnemyManager.h"
#include "Constans.h"
#include "Enemy.h"

void EnemyManager::tick() const
{
    for (auto it : m_enemiesList)
    {
        it->draw();
    }
}

void EnemyManager::createEnemy(int x, int y)
{
    m_enemiesList.push_back(std::make_shared<Enemy>(ENEMY_PATH, x, y));
}

void EnemyManager::deleteEnemies()
{
    for (int i = 0; i < m_enemiesList.size(); i++)
    {
        if (m_enemiesList[i]->getY() > MAP_WIDTH)
        {
            m_enemiesList.erase(m_enemiesList.begin() + i, m_enemiesList.begin() + (i + 1));
        }
    }
}

void EnemyManager::moveEnemiesDown() const
{
    for (int i = 0; i < m_enemiesList.size(); i++)
    {
        m_enemiesList[i]->setY(m_enemiesList[i]->getY() + MOVE_MAP_DOWN);
    }
}
