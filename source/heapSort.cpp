#include "../headers/common.h"

void heapify(vector<int> &rectSizes, int size, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && rectSizes.at(left) > rectSizes.at(largest)) {
        largest = left;
    }

    if (right < size && rectSizes.at(right) > rectSizes.at(largest)) {
        largest = right;
    }

    if (largest != i) {
        sleep();
        displayTwoIndex(rectSizes, i, largest);
        swapInt(rectSizes, i, largest);
        heapify(rectSizes, size, largest);
    }
}

void heapSort(vector<int> &rectSizes) {
    for(int i = rectSizes.size() / 2 - 1; i >= 0; i--) {
        heapify(rectSizes, rectSizes.size(), i);
    }

    for (int i = rectSizes.size() - 1; i >= 0; i--) {
        swapInt(rectSizes, 0, i);

        heapify(rectSizes, i, 0);
    }

    sorted = true;
}