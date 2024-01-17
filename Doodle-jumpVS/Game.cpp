#include "game.h"


void Game::init()
{
    doodle = Doodle(doodlePath, 0, 700);
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
    doodle.goOutMapWidth();
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
    if(doodle.getY() < 400)
        //if(doodle.getY() < mapHight - doodle.getJumpHight()) 
        for (auto it : platformGenerator.platformVector)
        {
            it->setY(it->getY()+2);
        }
}

void Game::checkPlatformsAndOther()
{
    for(auto it : platformGenerator.platformVector)
    {
        if((doodle.getX()+doodle.getDoodleWidth() > it->getX())
            && (doodle.getX()+doodle.getDoodleWidth() < it->getX()+it->getPlatformWidth())
            && (doodle.getY()+doodle.getDoodleHight()>it->getY())
            && (doodle.getY()+doodle.getDoodleHight()<it->getY()+it->getPlatformHeight())
            && (doodle.getDy()> 0)) doodle.setDy(-10);
            
    }
}


