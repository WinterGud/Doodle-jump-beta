#include "BaseEntity.h"

void BaseEntity::setSize()
{
	setSpriteSize(m_entitySprite, m_coordinates.first + 100, m_coordinates.second + 100);
}

void BaseEntity::draw()
{
	drawSprite(m_entitySprite, getX(), getY());
}