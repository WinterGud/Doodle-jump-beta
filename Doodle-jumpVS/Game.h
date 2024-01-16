#pragma once
#include "Doodle.h"
#include "PlatformGenerator.h"


class Game
{
public:
    Game() = default;
    void init();
    void draw();
    void logic();
    void doodleMoveLeftRight(FRKey key);
private:
    Doodle doodle;
    PlatformGenerator platformGenerator;
};
