#include "Platform.h"

Platform::Platform(const std::string& path, int _x, int _y)
    : BaseEntity(path, _x, _y)
{
    this->setSize(platformWidth, platformHeight);
}
