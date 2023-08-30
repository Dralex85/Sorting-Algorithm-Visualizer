#ifndef COMMON_HEADER
#define COMMON_HEADER

//CPP include
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

//SFML include
#include <SFML/Graphics.hpp>

using namespace std;

//Created headers
#include "utils.h"
#include "display.h"
#include "sorter.h"

//Hard const global variable
const int height = 720; //Height of the window
const int width = 1080; //Width of the window, also max number of element
const int algorithmNumber = 6;

//Global variable
extern sf::RenderWindow window;
extern int rectNum;
extern int rectWidth;
extern bool sorted;
extern bool closable;
extern bool verifiedSorted;
extern float waitTime;
extern float sleepCount;

#endif