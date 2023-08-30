#include "../headers/common.h"

void merge(vector<int> &rectSizes, int min, int mid, int max) {
    int i, j, k;
    int size1 = mid - min + 1;
    int size2 = max - mid;

    vector<int> tab1, tab2;

    for (i = 0; i < size1; i++) {
        tab1.push_back(rectSizes.at(min + i));
    }

    for (j = 0; j < size2; j++) {
        tab2.push_back(rectSizes.at(mid + 1 + j));
    }

    i = 0;
    j = 0;
    k = min;

    while (i < size1 && j < size2) {
        if (tab1.at(i) <= tab2.at(j)) {
            displayTwoIndex(rectSizes, k, min + i);
            rectSizes.at(k) = tab1.at(i);
            i++;
        } else {
            displayTwoIndex(rectSizes, k, mid + 1 + i);
            rectSizes.at(k) = tab2.at(j);
            j++;
        }
        k++;
    }

    while (i < size1) {
        displayTwoIndex(rectSizes, k, min + i);
        rectSizes.at(k) = tab1.at(i);
        i++;
        k++;
    }

    while (j < size2) {
        displayTwoIndex(rectSizes, k, mid + 1 + i);
        rectSizes.at(k) = tab2.at(j);
        j++;
        k++;
    }
}

void mergeSort(vector<int> &rectSizes, int min, int max) {
    if (min < max) {
        int mid = min + (max - min) / 2;

        sleep();
        displayTwoIndex(rectSizes, min, mid);
        mergeSort(rectSizes, min, mid);

        sleep();
        displayTwoIndex(rectSizes, mid + 1, max);
        mergeSort(rectSizes, mid + 1, max);

        sleep();
        displayTwoIndex(rectSizes, min, max);
        merge(rectSizes, min, mid, max);
    }
    sorted = true;
}