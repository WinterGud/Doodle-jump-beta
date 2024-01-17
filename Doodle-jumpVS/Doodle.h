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
    void setIsFall(bool);
    int getDoodleWidth() const;
    int getDoodleHight() const;
    static int getJumpHight();
    void moveLeftRight(FRKey key);
    double getDy(){return dy;}
    void setDy(double _dy) { dy = _dy; }
private:
    const int doodleWidth = mapWidth/7;
    const int doodleHight = mapHight/7;
    static const int jumpHight = 200;
    bool checkMoveLeft = false;
    bool checkMoveRight = false;
    double dx = m_x, dy = m_y;
    const int speedUpDown = 20;
    bool isFall = true;
    // if (y<h)
    // for (int i=0;i<10;i++)
    // {
    //     y=h;
    //     plat[i].y=plat[i].y-dy;
    //     if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
    // }
    // for (int i=0;i<10;i++)
    //     if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
    //      && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))  dy=-10;

};

