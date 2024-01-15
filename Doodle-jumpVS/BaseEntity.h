#pragma once
#include "Framework.h"
#include <string>

class BaseEntity
{
public:
	BaseEntity() = default;
	BaseEntity(std::string pathSprite, int _x, int _y) : m_entitySprite(createSprite(pathSprite.c_str()))
	{}
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