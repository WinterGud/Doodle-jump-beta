#pragma once
#include "BaseEntity.h"
#include "Constans.h"


class Platform : public BaseEntity
{
public:
    Platform(const std::string& path, int _x, int _y);
    Platform& operator=(const Platform&);
    void setPostion(int x, int y);
private:
};
