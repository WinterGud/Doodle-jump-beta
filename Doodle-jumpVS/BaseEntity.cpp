#include "BaseEntity.h"

void BaseEntity::setSize(int width, int height)
{
	setSpriteSize(m_entitySprite, width, height);
}

void BaseEntity::draw()
{
	drawSprite(m_entitySprite, getX(), getY());
}

