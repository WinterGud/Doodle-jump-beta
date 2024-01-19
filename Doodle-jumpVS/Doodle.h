#pragma once
#include "BaseEntity.h"
#include "Constans.h"

class Doodle : public  BaseEntity
{
public:
    Doodle() = default;
    Doodle(const std::string& path, int _x, int _y);
    Doodle& operator=(const Doodle& other);
    void moveUp();
    void moveLeft();
    void moveRight();
    void jump();
    double getDy(){ return m_dy; }
    void setDy(double _dy) { m_dy = _dy; }
    void goOutMapWidth();
    void moveDoodleDown();
private:
    bool checkMoveLeft = false;
    bool checkMoveRight = false;
    double m_dx = m_x, m_dy = m_y;
};

