#pragma once
#include "BaseEntity.h"
#include "Definitions.h"


class Platform : public BaseEntity
{
public:
    Platform() = default;
    Platform(const std::string& path, int _x, int _y);
    Platform& operator=(const Platform&);
    int getPlatformWidth() const;
    int getPlatformHeight() const;
private:
    const int platformWidth = mapWidth/5;
    const int platformHeight = mapHeight/27;
    
    
};
