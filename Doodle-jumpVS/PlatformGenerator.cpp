#include "PlatformGenerator.h"

PlatformGenerator::PlatformGenerator()
    :   gen(rd()),
        randMapWidth(0, mapWidth - Platform::getPlatformWidth())
{
}

PlatformGenerator& PlatformGenerator::operator=(const PlatformGenerator& other)
{
    if(this->platformVector == other.platformVector)
        return *this;
    this->platformVector = other.platformVector;
    return *this;
}

void PlatformGenerator::draw() const
{
    for (auto it : platformVector)
     {
         it->draw();
     }
}

void PlatformGenerator::init()
{
     platformVector.push_back(std::make_shared<Platform>(doodlePath, randMapWidth(gen), mapHight));
     randHeightToNextPlatform = std::uniform_int_distribution<>
     (-platformVector.back()->getY()-300,
     platformVector.back()->getY());
     for (int i = 1; i < numPlatfoms; i++)
     {
         platformVector.push_back(std::make_shared<Platform>(standardPlatformPath,
             randMapWidth(gen),
             randHeightToNextPlatform(gen)));
     }
}

void PlatformGenerator::createNewPlatforms()
{
    if (platformVector.size() < numPlatfoms)
    {
        for (int i = platformVector.size(); i < numPlatfoms; i++)
        {
            platformVector.push_back(std::make_shared<Platform>(standardPlatformPath,
             randMapWidth(gen),
             randHeightToNextPlatform(gen)));
        }
    }
}

void PlatformGenerator::deletePlatforms()
{
    for (int i = 0; i < platformVector.size(); i++)
    {
        if(platformVector[i]->getY() > mapHight)
        {
            platformVector.erase(platformVector.begin()+i, platformVector.begin()+i+1);
        }
    }
}
