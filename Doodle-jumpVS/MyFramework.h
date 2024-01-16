#pragma once
#include "Framework.h"
#include "Doodle.h"
#include "Definitions.h"
#include "Platform.h"
#include "PlatformGenerator.h"



class MyFramework : public Framework {
public:

	Doodle d1;
	PlatformGenerator pg1;

	
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = mapWidth;
		height = mapHight;
		fullscreen = false;
	}

	virtual bool Init()
	{
		d1 = Doodle(doodlePath, 0, 650);
		//pg1 = PlatformGenerator();
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
		//pg1.draw();

		
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
