#pragma once
#include "BaseEntity.h"
#include "Constans.h"

class Doodle : public  BaseEntity
{
public:
    Doodle() = default;
    Doodle(const std::string& path, int _x, int _y);
    Doodle& operator=(const Doodle& other);
    void moveDown();
    void moveUp();
    void moveLeft();
    void moveRight();
    void jump();
    void shoot();
    double getDy(){ return m_dy; }
    void setDy(double _dy) { m_dy = _dy; }
    void goOutMapWidth();
private:
    bool checkMoveLeft = false;
    bool checkMoveRight = false;
    double m_dx = m_x, m_dy = MAP_HEIGHT;
};

