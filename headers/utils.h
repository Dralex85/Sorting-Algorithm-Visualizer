#ifndef UTILS_COMMON
#define UTILS_COMMON

#include "./common.h"

void initSizes(vector<int> &rectSizes);
int parser(int argc, char **argv);
void sleep();
void shuffle(vector<int> &rectSizes);
void swapInt(vector<int> &tab, int one, int two);
void verify(vector<int> tab);
void statData(vector<int> rectSizes, vector<int> original);

#endif