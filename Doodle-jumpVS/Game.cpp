#include "game.h"
#include "Constans.h"
#include "Doodle.h"
#include "PlatformsManager.h"
#include "Platform.h"

Game::Game()
{}

void Game::init()
{
    m_doodle = std::make_shared<Doodle>(DOODLE_PATH, 200, 100);
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
    doodleMove();
    m_doodle->goOutMapWidth();
    checkPlatformsAndOther();
    
    checkGameOver();

    m_bulletManager.tick();
    m_bulletManager.deleteBullets();
    bulletShoot();
    
    moveScreen();
    m_platformManager.createNewPlatforms();
    m_platformManager.deletePlatforms();
}

void Game::doodleMove()
{
    if(m_inputManager.getCheckRightKeyPressed())
    {
        m_doodle->setX(m_doodle->getX() + 10);
    }
    else if(m_inputManager.getCheckLeftKeyPressed())
    {
        m_doodle->setX(m_doodle->getX() - 10);
    }
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

void Game::bulletShoot()
{
    if (m_inputManager.getCheckUpKeyPressed())
    {
        m_bulletManager.shootBulletVertical(m_doodle->getX(), m_doodle->getY());
    }
    else if(m_inputManager.getCheckLeftMouseButtonPressed())
    {
        m_bulletManager.shootBulletToCoordinates(m_doodle->getX(),
            m_doodle->getY(),
            m_inputManager.getMouseX(),
            m_inputManager.getMouseY());
    }
}


void Game::checkGameOver()
{
    if(m_doodle->getY() + DOODLE_HEIGHT > MAP_WIDTH)
    {
        m_gameOver = true;
    }
} 

