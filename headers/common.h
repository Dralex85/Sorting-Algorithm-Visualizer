#ifndef COMMON_HEADER
#define COMMON_HEADER

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>

using namespace std;

const int height = 600;                     //Height of the window
const int width = 600;                      //Width of the window
extern int rectNum;                         //Number of elements to sort,   Must be equal or inferior to width and height
extern int rectWidth;                       //Visual representation of each element
extern float waitTime;                      //Time between each frame

extern bool sorted;
extern bool closable;
extern sf::RenderWindow window;

#endif