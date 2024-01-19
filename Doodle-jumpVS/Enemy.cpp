#include "Enemy.h"
#include "Constans.h"

Enemy::Enemy(const std::string& path, int x, int y)
    : BaseEntity(path, x, y)
{
    setSize(ENEMY_WIDTH, ENEMY_HEIGHT);
}
