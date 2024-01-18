#pragma once

enum class FRKey; 

enum class FRMouseButton; 

class InputManager
{
public:
    void getKeyPressed(FRKey);
    void getKeyReleased(FRKey);
    void getMouseButton(FRMouseButton button, bool isReleased);
    void setMouseCoordinates(int& x, int& y, int& relativeX, int& relativeY);
    bool getCheckRightKeyPressed() { return m_checkRightKeyPressed; }
    bool getCheckLeftKeyPressed() { return m_checkLeftKeyPressed; }
    bool getCheckUpKeyPressed() { return m_checkUpKeyPressed; }
    bool getCheckLeftMouseButtonPressed() { return m_checkLeftMouseButtonPressed; }
    bool getCheckRightKeyReleased() { return m_checkRightKeyReleased; }
    bool getCheckLeftKeyReleased() { return m_checkLeftKeyReleased; }
    bool getCheckUpKeyReleased() { return m_checkUpKeyReleased; }
    bool getCheckLeftMouseButtonReleased() { return m_checkLeftMouseButtonReleased; }
    int getMouseX() { return m_xMouse; }
    int getMouseY() { return m_yMouse; }
    int getRelativeMouseX() { return m_relativeXMouse; }
    int getRelativeMouseY() { return m_relativeYMouse; }
private:
    bool m_checkRightKeyPressed = false;
    bool m_checkRightKeyReleased = false;
    bool m_checkLeftKeyPressed = false;
    bool m_checkLeftKeyReleased = false;
    bool m_checkUpKeyPressed = false;
    bool m_checkUpKeyReleased = false;
    bool m_checkLeftMouseButtonPressed = false;
    bool m_checkLeftMouseButtonReleased = false;
    int m_xMouse = 0;
    int m_yMouse = 0;
    int m_relativeXMouse = 0;
    int m_relativeYMouse = 0;
};
