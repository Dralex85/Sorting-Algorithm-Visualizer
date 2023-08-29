#include "../headers/common.h"
#include <math.h>

void combSort(vector<int> &rectSizes) {
    int gap = rectSizes.size();
    float shrink = 1.3;
    bool swapped = true;

    while(gap != 1 || swapped == true) {
        gap = floor(gap / shrink);
        if (gap <= 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i < rectSizes.size() - gap; i++) {
            displayTwoIndex(rectSizes, i, i + gap);
            sleep();
            if (rectSizes.at(i) > rectSizes.at(i + gap)) {
                swapInt(rectSizes, i, i + gap);
                swapped = true;
            }
        }
    }
    sorted = true;
}