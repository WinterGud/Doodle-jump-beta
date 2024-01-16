#pragma once
#include "Framework.h"
#include "Definitions.h"
#include "game.h"



class MyFramework : public Framework {
public:
	
	
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = mapWidth;
		height = mapHight;
		fullscreen = false;
	}

	virtual bool Init()
	{
		game.init();
		return true;
	}

	virtual void Close()
	{

	}

	virtual bool Tick()
	{
		drawTestBackground();
		game.draw();
		game.logic();
		
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
		game.doodleMoveLeftRight(k);
	}

	virtual void onKeyReleased(FRKey k)
	{
		game.doodleMoveLeftRight(k);
	}

	virtual const char* GetTitle() override
	{
		return "Doodle Jump";
	}
private:
	Game game;
};
