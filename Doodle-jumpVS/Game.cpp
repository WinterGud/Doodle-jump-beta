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

    platformGenerator.createNewPlatforms();
    platformGenerator.deletePlatforms();
}

void Game::doodleMove(FRKey key)
{
    doodle.moveLeftRight(key);
}

void Game::moveScreen()
{
    if(doodle.getY()+doodle.getDoodleHeight() < 1);//dorobutu
}


