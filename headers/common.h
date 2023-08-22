#ifndef COMMON_HEADER
#define COMMON_HEADER

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>

using namespace std;

const int height = 600;                            //Height of the window
const int width = 600;                             //Width of the window
const int rectNum = 50;                           //Number of elements to sort,   Must be equal or inferior to width and height
const int rectWidth = width / rectNum - 5;          //Visual representation of each element
const float waitTime = 0.05;                        //Time between each frame

extern bool sorted;
extern bool closable;
extern sf::RenderWindow window;

#endif