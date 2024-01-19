#pragma once
#include <memory>
#include <vector>


class Enemy;

class EnemyManager
{
public:
   void tick() const;
   void deleteEnemies();
   void createEnemy(int x, int y);
private:
   std::vector<std::shared_ptr<Enemy>> m_enemiesList;
};
