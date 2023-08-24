#include "../headers/common.h"

void insertionSort(vector<int> &rectSizes) {
    int j;

    for (int i = 0; i < rectSizes.size(); i++) {
        sleep();
        j = i;
        while(j > 0 && rectSizes[j - 1] > rectSizes[j]) {

        swapInt(rectSizes, j, j - 1);
        display(rectSizes, j);
        j--;
        }
    }
    sorted = true;
}