#pragma once
#include <memory>
#include "PlatformsManager.h"

class Doodle;
enum class FRKey;

class Game
{
public:
    Game();
    void init();
    void tick();
    void logic();
    void doodleMove(FRKey key);
    void moveScreen();
    void checkPlatformsAndOther();
private:
    std::shared_ptr<Doodle> m_doodle;
    PlatformsManager m_platformManager;
};
