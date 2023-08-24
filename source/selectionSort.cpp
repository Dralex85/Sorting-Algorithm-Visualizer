#include "../headers/common.h"

void selectionSort(vector<int> &rectSizes) {
    int minPos;
    for (int i = 0; i < rectSizes.size(); i++) {
        sleep();
        minPos = i;

        for (int j = i + 1; j < rectSizes.size(); j++) {
            if (rectSizes[j] < rectSizes[minPos])
                minPos = j;
        }
        swapInt(rectSizes, i, minPos);
        displayTwoIndex(rectSizes, i, minPos);
    }
    sorted = true;
}