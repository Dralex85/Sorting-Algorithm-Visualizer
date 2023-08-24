#ifndef DISPLAY_HEADER
#define DISPLAY_HEADER

#include "./common.h"

void display(vector<int> rectSizes, int index);
void displayTwoIndex(vector<int> rectSizes, int index1, int index2);
void displayQuick(vector<int> rectSizes,int bot, int top, int index1, int index2);
int sortedDisplay(vector<int> rectSizes, int index);

#endif