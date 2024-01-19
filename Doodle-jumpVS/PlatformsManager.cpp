#include "PlatformsManager.h"
#include "Platform.h"
#include "Constans.h"

PlatformsManager::PlatformsManager()
    :   m_gen(m_rd()),
        m_randMapWidth(0, MAP_WIDTH - PLATFORM_WIDTH)
{}

void PlatformsManager::tick() const
{
    for (auto it : m_platformList)
     {
         it->draw();
     }
}

void PlatformsManager::init()
{
     m_platformList.push_back(std::make_shared<Platform>(STANDART_PLATFORM_PATH, 0, MAP_HEIGHT-10));
     m_randHeightToNextPlatform = std::uniform_int_distribution<>
     (-m_platformList.back()->getY()-300,
     m_platformList.back()->getY());
     for (int i = 1; i < NUM_PLATFORMS; i++)
     {
         m_platformList.push_back(std::make_shared<Platform>(STANDART_PLATFORM_PATH,
             m_randMapWidth(m_gen),
             m_randHeightToNextPlatform(m_gen)));
     }
}

void PlatformsManager::createNewPlatforms()
{
    if (m_platformList.size() < NUM_PLATFORMS)
    {
        for (int i = m_platformList.size(); i < NUM_PLATFORMS; i++)
        {
            m_platformList.push_back(std::make_shared<Platform>(STANDART_PLATFORM_PATH,
             m_randMapWidth(m_gen),
             m_randHeightToNextPlatform(m_gen)));
        }
    }
}

void PlatformsManager::deletePlatforms()
{
    for (int i = 0; i < m_platformList.size(); i++)
    {
        if(m_platformList[i]->getY() > MAP_HEIGHT)
        {
            m_platformList.erase(m_platformList.begin()+i, m_platformList.begin()+i+1);
        }
    }
}

void PlatformsManager::movePlatformDown() const
{
    for (auto it : m_platformList)
    {
        it->setY(it->getY()+2);
    }
}
