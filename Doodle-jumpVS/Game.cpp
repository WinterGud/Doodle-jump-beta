#include "game.h"


void Game::init()
{
    doodle = Doodle(doodlePath, 0, 600);
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
    doodle.moveLeft();
    doodle.moveRight();
    checkPlatformsAndOther();
    moveScreen();
    platformGenerator.createNewPlatforms();
    platformGenerator.deletePlatforms();
}

void Game::doodleMove(FRKey key)
{
    doodle.moveLeftRight(key);
}

void Game::moveScreen()
{
    if(doodle.getY() < doodle.getJumpHight())
        for (auto it : platformGenerator.platformVector)
        {
            doodle.setY(doodle.getJumpHight());
            it->setY(it->getY()+-doodle.getY());
            if(it->getY()>mapHight)
            {
                it->setY(0);
                it->setX(rand()%400);
            }
        }
}

void Game::checkPlatformsAndOther()
{
    for(auto it : platformGenerator.platformVector)
    {
        if((doodle.getX()+doodle.getDoodleWidth())
            && (doodle.getX()+doodle.getDoodleWidth() < it->getX()+it->getPlatformWidth())
            && (doodle.getY()+doodle.getDoodleHight()>it->getY())
            && (doodle.getY()+doodle.getDoodleHight()<it->getY()+it->getPlatformHeight())
            && doodle.getDy()> 0) doodle.setDy(-10);
            
    }
}


