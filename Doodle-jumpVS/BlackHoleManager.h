#pragma once
#include <vector>
#include <memory>

class BlackHole;

class BlackHoleManager
{
public:
    using blackHolesList = std::vector<std::shared_ptr<BlackHole>>;
    
    void tick() const;
    void deleteEnemies();
    void createEnemy(int x, int y);
    void moveEnemiesDown() const;
    void killEnemy(blackHolesList::iterator it);
    blackHolesList& getEnemiesList() { return m_blackHolesList; }

private:
    blackHolesList<BlackHole> m_blackHolesList;
};
