#pragma once
#include "Framework.h"
#include <string>
#include <iostream>

class BaseEntity
{
public:
	BaseEntity() = default;
	BaseEntity(const std::string& pathSprite, int _x, int _y) ;
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	void setX(int _x) { m_x = _x; }
	void setY(int _y) { m_y = _y; }
	void setSize(int width, int height);
	void draw();

protected:
	Sprite* m_entitySprite = nullptr;
	int m_x, m_y;
	
};