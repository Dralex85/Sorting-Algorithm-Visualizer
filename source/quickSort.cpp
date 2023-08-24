#include "../headers/common.h"

int partition(vector<int> &rectSizes, int bot, int top) {
    int pivot = rectSizes.at(top);
    int i = bot - 1;

    for (int j = bot; j < top; j++) {
        if (rectSizes.at(j) <= pivot) {
            i++;
            sleep();
            swapInt(rectSizes, i, j);
            displayQuick(rectSizes, bot, top, i, j);
        }
    }
    i++;
    swapInt(rectSizes, i, top);
    displayQuick(rectSizes, bot, top, i, top);
    return i;
}

void quickSort(vector<int> &rectSizes, int bot, int top, int version) {
    int pivot = 0;

    if (bot >= top || bot < 0)
        return;

    pivot = partition(rectSizes, bot, top);

    quickSort(rectSizes, bot, pivot - 1, version + 1);
    quickSort(rectSizes, pivot + 1, top, version + 1);

    if (version == 0)
        sorted =true;

}