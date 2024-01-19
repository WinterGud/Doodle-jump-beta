#pragma once
#include <vector>
#include <memory>
#include <random>

class Platform;

class PlatformsManager
{
public:
    using platformsList = std::vector<std::shared_ptr<Platform>>;
    PlatformsManager();
    void tick() const;
    void init();
    void createNewPlatforms();
    void deletePlatforms();
    void movePlatformDown() const;
    platformsList& getPlatformsList(){ return m_platformList; }
private:
    std::vector<std::shared_ptr<Platform>> m_platformList;
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_int_distribution<> m_randMapWidth;
    std::uniform_int_distribution<> m_randHeightToNextPlatform;
    
};
