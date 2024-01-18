#pragma once
#include <memory>
#include "BulletManager.h"
#include "PlatformsManager.h"
#include "InputManager.h"

class Doodle;
enum class FRKey;
enum class FRMouseButton;

class Game
{
public:
    Game();
    void init();
    void tick();
    void logic();
    void doodleMove();
    void moveScreen();
    void checkPlatformsAndOther();
    void checkGameOver();
    void bulletShoot();
    InputManager& getInputManager() { return m_inputManager; }

private:
    std::shared_ptr<Doodle> m_doodle;
    PlatformsManager m_platformManager;
    InputManager m_inputManager;
    BulletManager m_bulletManager;
    bool m_gameOver = false;
};
