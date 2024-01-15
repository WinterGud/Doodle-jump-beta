#pragma once
#include "BaseEntity.h"
#include "Definitions.h"

class Doodle : public  BaseEntity
{
public:
    Doodle() = default;
    Doodle(std::string path, int _x, int _y);
    Doodle& operator=(const Doodle&);
    void moveUp();
    void moveDown();
    void shoot();
    void moveLeft();
    void moveRight();
private:
    const int doodleWidth = mapWidth/7;
    const int doodleHeight = mapHeight/7;

};
