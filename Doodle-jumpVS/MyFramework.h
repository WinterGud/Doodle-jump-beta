#pragma once
#include "Framework.h"
#include "Constans.h"
#include "game.h"



class MyFramework : public Framework {
public:
	
	MyFramework(): m_game(){}
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = MAP_WIDTH;
		height = MAP_HEIGHT;
		fullscreen = false;
	}

	virtual bool Init()
	{
		m_game.init();
		return true;
	}

	virtual void Close()
	{

	}

	virtual bool Tick()
	{
		drawTestBackground();
		m_game.tick();
		m_game.logic();
		
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
		m_game.doodleMove(k);
	}

	virtual void onKeyReleased(FRKey k)
	{
		m_game.doodleMove(k);
	}

	virtual const char* GetTitle() override
	{
		return "Doodle Jump";
	}
private:
	Game m_game;
};
