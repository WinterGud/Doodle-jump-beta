#include "game.h"
#include "Constans.h"
#include "Doodle.h"
#include "PlatformsManager.h"
#include "Platform.h"

Game::Game()
{}

void Game::init()
{
    m_doodle = std::make_shared<Doodle>(DOODLE_PATH, 0, 100);
    m_platformManager.init();
}


void Game::tick()
{
    m_doodle->draw();
    m_platformManager.tick();
}

void Game::logic()
{
    m_doodle->jump();
    m_doodle->moveLeft();
    m_doodle->moveRight();
    m_doodle->goOutMapWidth();
    checkPlatformsAndOther();
    
    moveScreen();
    m_platformManager.createNewPlatforms();
    m_platformManager.deletePlatforms();
}

void Game::doodleMove(FRKey key)
{
    m_doodle->moveLeftRight(key);
}

void Game::moveScreen()
{
    if(m_doodle->getY() < 400)
        for (auto it : m_platformManager.getPlatformsList())
        {
            it->setY(it->getY()+2);
        }
}

void Game::checkPlatformsAndOther()
{
    for(auto it : m_platformManager.getPlatformsList())
    {
        if((m_doodle->getX() + DOODLE_WIDTH > it->getX())
            && (m_doodle->getX() + DOODLE_WIDTH < it->getX() + PLATFORM_WIDTH)
            && (m_doodle->getY() + DOODLE_HEIGHT > it->getY())
            && (m_doodle->getY() + DOODLE_HEIGHT < it->getY() + PLATFORM_HEIGHT)
            && (m_doodle->getDy() > 0)) m_doodle->setDy(-10);
            
    }
}


