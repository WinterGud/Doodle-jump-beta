#include "game.h"


void Game::init()
{
    doodle = Doodle(doodlePath, 0, 0);
    platformGenerator = PlatformGenerator();
    platformGenerator.init();
}

void Game::draw()
{
    doodle.draw();
    platformGenerator.draw();
}

void Game::logic()
{
    doodle.jump();
}

void Game::doodleMoveLeftRight(FRKey key)
{
    if(key == FRKey::LEFT)
        doodle.setCheckMoveLeft();
    if(key == FRKey::RIGHT)
        doodle.setCheckMoveRight();
}
