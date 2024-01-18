#pragma once

enum class FRKey {
    RIGHT,
    LEFT,
    UP,
};

enum class FRMouseButton {
    LEFT,
};

class InputManager
{
public:
    void getKey(FRKey);
    void getMouseButton(FRMouseButton);
    bool getCheckRightKeyPressed() { return m_checkRightKeyPressed; }
    bool getcheckLeftKeyPressed() { return m_checkLeftKeyPressed; }
    bool getcheckUpKeyPressed() { return m_checkUpKeyPressed; }
    bool getcheckLeftMouseButtonPressed() { return m_checkLeftMouseButtonPressed; }
private:
    bool m_checkRightKeyPressed = false;
    bool m_checkLeftKeyPressed = false;
    bool m_checkUpKeyPressed = false;
    bool m_checkLeftMouseButtonPressed = false;
    
};
