#pragma once
#include "BaseEntity.h"

class BlackHole : public BaseEntity
{
public:
    BlackHole(const std::string& path, int x, int y);
    double getSpeedAttraction() { return m_sppedAttraction; }
    void setSpeedAttraction(double speedAttraction) { m_sppedAttraction = speedAttraction; }

private:
    double m_sppedAttraction = 0;
};
