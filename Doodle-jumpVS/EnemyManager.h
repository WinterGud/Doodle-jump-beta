#pragma once
#include <memory>
#include <vector>


class Enemy;

class EnemyManager
{
public:
    using EnemiesList = std::vector<std::shared_ptr<Enemy>>;
    void tick() const;
    void deleteEnemies();
    void createEnemy(int x, int y);
    void moveEnemiesDown() const;
    EnemiesList& getEnemiesList() { return m_enemiesList; }

private:
    std::vector<std::shared_ptr<Enemy>> m_enemiesList;
};
