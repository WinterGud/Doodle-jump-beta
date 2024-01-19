#pragma once
#include <memory>
#include "BulletManager.h"
#include "PlatformsManager.h"
#include "InputManager.h"
#include "EnemyManager.h"
#include <random>

class Doodle;
enum class FRKey;
enum class FRMouseButton;

class Game
{
public:
    Game();
    Game& operator=(const Game&);
    void init();
    void tick();
    void logic();
    void doodleMove();
    void moveScreen();
    void checkPlatformsAndOther();
    bool checkGameOver();
    void bulletShoot();
    void spawnEnemy();
    void killEnemy();
    InputManager& getInputManager() { return m_inputManager; }

private:
    std::shared_ptr<Doodle> m_doodle;
    PlatformsManager m_platformManager;
    InputManager m_inputManager;
    BulletManager m_bulletManager;
    EnemyManager m_enemyManager;
    bool m_gameOver = false;
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_int_distribution<> m_randEnemies = std::uniform_int_distribution<>(0, 10);
    int m_rundNum;
    unsigned long long int m_score;
};
