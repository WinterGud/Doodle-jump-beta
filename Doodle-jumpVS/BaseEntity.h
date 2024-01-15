#pragma once
#include "Framework.h"
#include <tuple>
#include <string>

class BaseEntity
{
public:
	BaseEntity() = default;
	BaseEntity(std::string pathSprite, int _x, int _y) : m_entitySprite(createSprite(pathSprite.c_str()))
	{}
	int getX() const { return m_coordinates.first; }
	int getY() const { return m_coordinates.second; }
	void setX(int _x) { m_coordinates.first = _x; }
	void setY(int _y) { m_coordinates.second = _y; }
	void setSize();
	void draw();

protected:
	Sprite* m_entitySprite = nullptr;
	std::pair<int, int> m_coordinates;
	
};