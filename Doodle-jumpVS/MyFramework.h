#pragma once
#include "Framework.h"





class MyFramework : public Framework {
public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		
		fullscreen = false;
	}

	virtual bool Init() {
		
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		drawTestBackground();
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
