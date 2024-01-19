#include "BlackHole.h"
#include "Constans.h"

BlackHole::BlackHole(const std::string& path, int x, int y)
    : BaseEntity(path, x, y)
{
    setSize(BLACK_HOLE_WIDTH, BLACK_HOLE_HEIGHT);
}
