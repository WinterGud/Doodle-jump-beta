#pragma once
#include "Framework.h"
#include <string>
#include <iostream>

class BaseEntity
{
public:
	BaseEntity() = default;
	BaseEntity(const std::string& pathSprite, int x, int y) ;
	~BaseEntity();
	double getX() const { return m_x; }
	double getY() const { return m_y; }
	void setX(double _x) { m_x = _x; }
	void setY(double _y) { m_y = _y; }
	void setSize(int width, int height);
	void draw();

protected:
	Sprite* m_entitySprite = nullptr;
	double m_x, m_y;
};