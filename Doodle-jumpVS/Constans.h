#pragma once
#include <string>

//W 35
//H 54
using std::string;
const int MAP_WIDTH = 600;
const int MAP_HEIGHT = 800;
const int MOVE_MAP_DOWN = MAP_HEIGHT / 8;
const int DOODLE_WIDTH = MAP_WIDTH/7;
const int DOODLE_HEIGHT = MAP_HEIGHT/7;
const int DOODLE_JUMP_HEIGHT = 200;
const int PLATFORM_WIDTH = MAP_WIDTH/5;
const int PLATFORM_HEIGHT = MAP_HEIGHT/27;
const int NUM_PLATFORMS = MAP_HEIGHT / 54 * 1.6;

const std::string DOODLE_PATH = "..\\Data\\ghost-right-odskok@2x.png";
const std::string HOLE_PATH = "..\\Data\\ghost-darkness@2x.png";
const std::string STANDART_PLATFORM_PATH = "..\\Data\\bck@2x.png";
const std::string BACKGROUND_PATH = "..\\Data\\bck@2x.png";
