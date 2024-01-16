#include "PlatformGenerator.h"

PlatformGenerator::PlatformGenerator()
    :   platformVector(numPlatfoms),
        gen(rd()),
        randMapWidth(0, mapWidth - Platform::getPlatformWidth()),
        randHeightToNextPlatform(platformVector.back()->getY(),
            platformVector.back()->getY()+Doodle::getJumpHight())
        
{
    platformVector.push_back(std::make_shared<Platform>(standardPlatformPath, randMapWidth(gen), mapHight));
    for (int i = 1; i < platformVector.size(); i++)
    {
        platformVector.push_back(std::make_shared<Platform>(standardPlatformPath,
            randMapWidth(gen),
            randHeightToNextPlatform(gen)));
    }
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
    for (int i = 0; i < platformVector.size(); i++)
        platformVector[i]->draw();
}
