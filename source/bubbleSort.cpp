#include "../headers/common.h"

void bubble(vector<int> &rectSizes) {
    waitTime /= 100;
    while(!sorted) {
        sorted = true;
        for (int i = 0; i < rectSizes.size() - 1; i++) {
            if (rectSizes.at(i) > rectSizes.at(i + 1)) {
                swapInt(rectSizes, i, i + 1);
                sorted = false;
            }
            sleep();
            displayTwoIndex(rectSizes, i, i + 1);
        }
    }
    waitTime *= 100;
}