#pragma once
#include <vector>
#include <memory>
#include "Platform.h"
#include <random>
#include "Doodle.h"

class PlatformGenerator
{
public:
    std::vector<std::shared_ptr<Platform>> platformVector;
    
public:
    PlatformGenerator();
    PlatformGenerator& operator=(const PlatformGenerator&);
    void draw() const;
    void init();
    void createNewPlatforms();
    void deletePlatforms();
private:
    const int numPlatfoms = mapHight / 54 * 1.6;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> randMapWidth;
    std::uniform_int_distribution<> randHeightToNextPlatform;
    
};
