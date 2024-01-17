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
    void shoot();
    void moveLeft();
    void moveRight();
    void jump();
    void setCheckMoveLeft();
    void setCheckMoveRight();
    void setIsFall(bool);
    int getDoodleWidth() const;
    int getDoodleHeight() const;
    static int getJumpHight();
    void moveLeftRight(FRKey key);
private:
    const int doodleWidth = mapWidth/7;
    const int doodleHeight = mapHight/7;
    static const int jumpHight = 200;
    bool checkMoveLeft = false;
    bool checkMoveRight = false;
    int count = 0;
    const int speedUpDown = 1;
    bool isFall = true;
};

