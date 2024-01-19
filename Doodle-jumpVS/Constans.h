#pragma once
#include <string>

//W 35
//H 54
using std::string;
const int MAP_WIDTH = 600;
const int MAP_HEIGHT = 800;
//const int MOVE_MAP_DOWN = MAP_HEIGHT / 8;
const int DOODLE_WIDTH = MAP_WIDTH/7;
const int DOODLE_HEIGHT = MAP_HEIGHT/7;
const int DOODLE_JUMP_HEIGHT = 200;
const int PLATFORM_WIDTH = MAP_WIDTH/5;
const int PLATFORM_HEIGHT = MAP_HEIGHT/27;
const int NUM_PLATFORMS = MAP_HEIGHT / 54 * 1.6;
const double BULLET_SPEED = 0.1;
const int ENEMY_WIDTH = MAP_WIDTH/7;
const int ENEMY_HEIGHT = MAP_HEIGHT/6;
const int BLACK_HOLE_WIDTH = MAP_WIDTH/7;
const int BLACK_HOLE_HEIGHT = MAP_HEIGHT/4;
const int MOVE_MAP_DOWN = 6;
const int BULLET_WIDTH = 10;
const int BULLET_HEIGHT = 10;

const std::string DOODLE_PATH = "..\\Data\\ghost-right-odskok@2x.png";
const std::string HOLE_PATH = "..\\Data\\ghost-darkness@2x.png";
const std::string STANDART_PLATFORM_PATH = "..\\Data\\bck@2x.png";
const std::string BACKGROUND_PATH = "..\\Data\\bck@2x.png";
const std::string BULLET_PATH = "..\\Data\\achievement-name-tiles.png";
const std::string ENEMY_PATH = "..\\Data\\hop-head@2x.png";