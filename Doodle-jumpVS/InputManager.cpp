#include "InputManager.h"

enum class FRKey {
    RIGHT,
    LEFT,
    UP,
};

enum class FRMouseButton {
    LEFT,
};


void InputManager::getKeyPressed(FRKey key)
{
    if(key == FRKey::RIGHT)
    {
        m_checkRightKeyPressed = true;
        m_checkRightKeyReleased = false;
    }
    if(key == FRKey::LEFT)
    {
        m_checkLeftKeyPressed = true;
        m_checkLeftKeyReleased = false;
    }
    if(key == FRKey::UP)
    {
        m_checkUpKeyPressed = true;
        m_checkUpKeyReleased = false;
    }
}

void InputManager::getKeyReleased(FRKey key)
{
    if(key == FRKey::RIGHT)
    {
        m_checkRightKeyPressed = false;
        m_checkRightKeyReleased = true;
    }
    if(key == FRKey::LEFT)
    {
        m_checkLeftKeyPressed = false;
        m_checkLeftKeyReleased = true;
    }
    if(key == FRKey::UP)
    {
        m_checkUpKeyPressed = false;
        m_checkUpKeyReleased = true;
    }
}

void InputManager::getMouseButton(FRMouseButton button, bool isReleased)
{
    if( button == FRMouseButton::LEFT)
    {
        if (isReleased)
        {
            m_checkLeftMouseButtonPressed = false;
            m_checkLeftMouseButtonReleased = true;
        }
        else
        {
            m_checkLeftMouseButtonPressed = true;
            m_checkLeftMouseButtonReleased = false;
        }
    }
}

void InputManager::setMouseCoordinates(int& x, int& y, int& relativeX, int& relativeY)
{
    m_xMouse = x;
    m_yMouse = y;
    m_relativeXMouse = relativeX;
    m_relativeYMouse = relativeY;
}