#pragma once
#include "BaseEntity.h"
#include "Definitions.h"

class Doodle : public  BaseEntity
{
public:
    Doodle() = default;
    Doodle(const std::string& path, int _x, int _y);
    Doodle& operator=(const Doodle&);
    void moveDown();
    void moveUp();
    void moveLeft();
    void moveRight();
    void jump();
    void shoot();
    void setCheckMoveLeft();
    void setCheckMoveRight();
    int getDoodleWidth() const;
    int getDoodleHight() const;
    static int getJumpHight();
    void moveLeftRight(FRKey key);
    double getDy(){return dy;}
    void setDy(double _dy) { dy = _dy; }
    void goOutMapWidth();
private:
    const int doodleWidth = mapWidth/7;
    const int doodleHight = mapHight/7;
    static const int jumpHight = 200;
    bool checkMoveLeft = false;
    bool checkMoveRight = false;
    double dx = m_x, dy = m_y;
    const int speedUpDown = 20;
    const int speedLeftRight = 20;
    
};

