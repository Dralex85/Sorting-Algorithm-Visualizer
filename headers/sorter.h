#ifndef SORTER_HEADER
#define SORTER_HEADER

#include "./common.h"

void insertionSort(vector<int> &rectSizes);
void selectionSort(vector<int> &rectSizes);
void selectionSortNoDisplay(vector<int> &rectSizes);
void quickSort(vector<int> &rectSizes, int bot, int top, int version);
void bubble(vector<int> &rectSizes);
void combSort(vector<int> &rectSizes);
void mergeSort(vector<int> &rectSizes, int min, int max);
void heapSort(vector<int> &rectSizes);

#endif