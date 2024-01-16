#pragma once
#include "Framework.h"
#include "Doodle.h"
#include "Definitions.h"
#include "Platform.h"

class MyFramework : public Framework {
public:

	Doodle d1;
	Platform p1;
	
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = mapWidth;
		height = mapHeight;
		fullscreen = false;
	}

	virtual bool Init()
	{
		d1 = Doodle(doodlePath, 0, 0);
		p1 = Platform(standardPlatformPath, 0, 400);
		return true;
	}

	virtual void Close()
	{

	}

	virtual bool Tick()
	{
		drawTestBackground();
		d1.draw();
		d1.jump();
		d1.moveLeft();
		d1.moveRight();
		p1.draw();
		if((d1.getX() <= p1.getPlatformWidth() + p1.getX())
			&&
			(d1.getY() + d1.getDoodleHeight() > p1.getY()))
			d1.setIsFall(false);

		
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative)
	{

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased)
	{

	}

	virtual void onKeyPressed(FRKey k)
	{
		if(k == FRKey::LEFT)
			d1.setCheckMoveLeft();
		if(k == FRKey::RIGHT)
			d1.setCheckMoveRight();
			
	}

	virtual void onKeyReleased(FRKey k)
	{
		if(k == FRKey::LEFT)
			d1.setCheckMoveLeft();
		if(k == FRKey::RIGHT)
			d1.setCheckMoveRight();
	}

	virtual const char* GetTitle() override
	{
		return "Doodle Jump";
	}
};
