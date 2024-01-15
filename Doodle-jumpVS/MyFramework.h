#pragma once
#include "Framework.h"
#include "Doodle.h"
#include "Definitions.h"

class MyFramework : public Framework {
public:

	Doodle d1;
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = mapWidth;
		height = mapHeight;
		fullscreen = false;
	}

	virtual bool Init() {
		d1 = Doodle(doodlePath, 0, 0);
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		drawTestBackground();
		d1.draw();
		d1.jump(false);
		
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k)
	{
		if(k == FRKey::LEFT)
		{
			d1.moveLeft();

		}
		if(k == FRKey::RIGHT)
			d1.moveRight();
	}

	virtual void onKeyReleased(FRKey k)
	{
		
	}

	virtual const char* GetTitle() override
	{
		return "Doodle Jump";
	}
};
