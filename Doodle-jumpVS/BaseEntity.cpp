#include "BaseEntity.h"

BaseEntity::BaseEntity(const std::string& pathSprite, int _x, int _y)
	: m_entitySprite(createSprite(pathSprite.c_str())), m_x(_x), m_y(_y)
{
	std::cout << m_entitySprite;
}

BaseEntity::~BaseEntity()
{
	destroySprite(m_entitySprite);
}


void BaseEntity::setSize(int width, int height)
{
	setSpriteSize(m_entitySprite, width, height);
}

void BaseEntity::draw()
{
	drawSprite(m_entitySprite, getX(), getY());
}

