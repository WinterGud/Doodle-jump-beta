#pragma once
#include "BaseEntity.h"
#include "Definitions.h"


class Platform : public BaseEntity
{
public:
    Platform() = default;
    Platform(const std::string& path, int _x, int _y);
    Platform& operator=(const Platform&);
    static int getPlatformWidth();
    static int getPlatformHeight();
private:
    static const int platformWidth = mapWidth/5;
    static const int platformHeight = mapHight/27;
    
    
};
