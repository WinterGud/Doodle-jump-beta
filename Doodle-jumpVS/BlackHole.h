#pragma once
#include "BaseEntity.h"

class BlackHole : public BaseEntity
{
public:
    BlackHole(const std::string& path, int x, int y);
private:
    double m_sppedAttraction = 0;
};
