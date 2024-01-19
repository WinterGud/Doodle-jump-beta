#pragma once
#include "Framework.h"
#include "Constans.h"
#include "game.h"

//рухливі платформи
//автоатака дудла
//чорна діра
//вороги
//підрахунок очок
//гейм овер
//розмір вікна з консолі
//пофіксити рухання платформ

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
		m_game.logic();
		m_game.tick();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative)
	{
		m_game.getInputManager().setMouseCoordinates(x, y, xrelative, yrelative);
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased)
	{
		m_game.getInputManager().getMouseButton(button, isReleased);
	}

	virtual void onKeyPressed(FRKey k)
	{
		m_game.getInputManager().getKeyPressed(k);
	}

	virtual void onKeyReleased(FRKey k)
	{
		m_game.getInputManager().getKeyReleased(k);
	}

	virtual const char* GetTitle() override
	{
		return "Doodle Jump";
	}
private:
	Game m_game;
};
