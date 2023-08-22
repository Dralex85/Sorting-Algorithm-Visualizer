#ifndef COMMON_HEADER
#define COMMON_HEADER

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>

using namespace std;

const int height = 600;
const int width = 600;
const int rectNum = 100;
const int rectWidth = width / rectNum - 5;
const float waitTime = 0.05;
extern bool sorted;
extern bool closable;
extern sf::RenderWindow window;

#endif