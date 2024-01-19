#include "Bullet.h"
#include "game.h"
#include "Constans.h"
#include "Doodle.h"
#include "Enemy.h"
#include "PlatformsManager.h"
#include "Platform.h"

Game::Game()
{
}

void Game::init()
{
    m_doodle = std::make_shared<Doodle>(DOODLE_PATH, 0, 100);
    m_platformManager.init();
}

Game& Game::operator=(const Game& other)
{
    m_doodle = std::make_shared<Doodle>(DOODLE_PATH, 0, 100);
    m_platformManager = PlatformsManager();
    m_platformManager.getPlatformsList().push_back(std::make_shared<Platform>(STANDART_PLATFORM_PATH, 0, 700));
    m_inputManager = other.m_inputManager;
    m_bulletManager = other.m_bulletManager;
    m_enemyManager = other.m_enemyManager;
    m_gameOver = other.m_gameOver;
    return *this;
}


void Game::tick()
{
    m_doodle->draw();
    m_platformManager.tick();
    m_enemyManager.tick();
    m_bulletManager.tick();
}

void Game::logic()
{
    m_doodle->jump();
    doodleMove();
    m_doodle->goOutMapWidth();
    checkPlatformsAndOther();

    m_bulletManager.deleteBullets();
    bulletShoot();

    moveScreen();
    m_platformManager.createNewPlatforms();
    m_platformManager.deletePlatforms();

    spawnEnemy();
    m_enemyManager.deleteEnemies();
    killEnemy();
}

void Game::doodleMove()
{
    if (m_inputManager.getCheckRightKeyPressed())
    {
        m_doodle->setX(m_doodle->getX() + 10);
    }
    else if (m_inputManager.getCheckLeftKeyPressed())
    {
        m_doodle->setX(m_doodle->getX() - 10);
    }
}

void Game::moveScreen()
{
    if (m_doodle->getY() < 400)
    {
        m_platformManager.movePlatformDown();
        m_doodle->moveDoodleDown();
        m_enemyManager.moveEnemiesDown();
        m_score += MOVE_MAP_DOWN;
    }
}

void Game::checkPlatformsAndOther()
{
    for (auto it : m_platformManager.getPlatformsList())
    {
        if ((m_doodle->getX() + DOODLE_WIDTH > it->getX())
            && (m_doodle->getX() + DOODLE_WIDTH < it->getX() + PLATFORM_WIDTH)
            && (m_doodle->getY() + DOODLE_HEIGHT > it->getY())
            && (m_doodle->getY() + DOODLE_HEIGHT < it->getY() + PLATFORM_HEIGHT)
            && (m_doodle->getDy() > 0))
            m_doodle->setDy(-10);
    }
}

void Game::bulletShoot()
{
    if (m_inputManager.getCheckUpKeyPressed())
    {
        m_bulletManager.shootBulletVertical(m_doodle->getX(), m_doodle->getY());
    }
    else if (m_inputManager.getCheckLeftMouseButtonPressed())
    {
        m_bulletManager.shootBulletToCoordinates(m_doodle->getX(),
                                                 m_doodle->getY(),
                                                 m_inputManager.getMouseX(),
                                                 m_inputManager.getMouseY());
    }
}


bool Game::checkGameOver()
{
    if (m_doodle->getY() - DOODLE_HEIGHT > MAP_WIDTH)
    {
        std::cout << "YOUR SCORE: " << m_score << '\n';
        m_gameOver = true;
    }
    for (auto it : m_enemyManager.getEnemiesList())
    {
        if ((m_doodle->getX() + DOODLE_WIDTH > it->getX())
            && (m_doodle->getX() + DOODLE_WIDTH < it->getX() + ENEMY_WIDTH)
            && (m_doodle->getY() + DOODLE_HEIGHT > it->getY())
            && (m_doodle->getY() + DOODLE_HEIGHT < it->getY() + ENEMY_HEIGHT))
        {
            std::cout << "YOUR SCORE: " << m_score << '\n';
            m_gameOver = true;
        }
    }
    return m_gameOver;
}

void Game::spawnEnemy()
{
    m_rundNum = m_randEnemies(m_gen);
    if (m_rundNum > 9)
    {
        m_enemyManager.createEnemy(m_platformManager.getPlatformsList().back()->getX(),
                                   m_platformManager.getPlatformsList().back()->getY() - ENEMY_HEIGHT);
    }
}

void Game::killEnemy()
{
    for (int i = 0; i < m_bulletManager.getBulletsList().size(); ++i)
    {
        for (int j = 0; j < m_enemyManager.getEnemiesList().size(); ++j)
        {
            if ((m_bulletManager.getBulletsList()[i]->getX() + BULLET_WIDTH > m_enemyManager.getEnemiesList()[j]->
                    getX())
                && (m_bulletManager.getBulletsList()[i]->getX() + BULLET_WIDTH < m_enemyManager.getEnemiesList()[j]->
                    getX() + ENEMY_WIDTH)
                && (m_bulletManager.getBulletsList()[i]->getY() + BULLET_HEIGHT > m_enemyManager.getEnemiesList()[j]->
                    getY())
                && (m_bulletManager.getBulletsList()[i]->getY() + BULLET_HEIGHT < m_enemyManager.getEnemiesList()[j]->
                    getY() + ENEMY_HEIGHT))
            {
                m_enemyManager.getEnemiesList().erase(m_enemyManager.getEnemiesList().begin() + j,
                                                      m_enemyManager.getEnemiesList().begin() + j + 1);
            }
        }
    }
}
