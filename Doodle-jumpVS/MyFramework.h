#pragma once
#include "Framework.h"
#include "Doodle.h"
#include "Platform.h"




class MyFramework : public Framework {
public:

	BaseEntity b1;
	bool jump = true;

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = mapWidth;
		height = mapHeight;
		fullscreen = false;
	}

	virtual bool Init() {
		b1 = BaseEntity(standardPlatformPath, 0, 0);
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {

		b1.draw();
		
		//b1.moveUp();
		// if ((getTickCount() / 1000) % 2)
		// {
		// 	b1.moveUp();
		// }
		// else
		// {
		// 	b1.moveDown();
		// }
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
	}

	virtual void onKeyReleased(FRKey k) {
	}

	virtual const char* GetTitle() override
	{
		return "Doodle Jump";
	}
};
