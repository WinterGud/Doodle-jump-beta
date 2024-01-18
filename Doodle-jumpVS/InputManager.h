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
    bool getcheckLeftKeyPressed() { return m_checkLeftKeyPressed; }
    bool getcheckUpKeyPressed() { return m_checkUpKeyPressed; }
    bool getcheckLeftMouseButtonPressed() { return m_checkLeftMouseButtonPressed; }
    bool getCheckRightKeyReleased() { return m_checkRightKeyReleased; }
    bool getcheckLeftKeyReleased() { return m_checkLeftKeyReleased; }
    bool getcheckUpKeyReleased() { return m_checkUpKeyReleased; }
    bool getcheckLeftMouseButtonReleased() { return m_checkLeftMouseButtonReleased; }
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
