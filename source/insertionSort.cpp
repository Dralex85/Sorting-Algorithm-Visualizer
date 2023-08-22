#include "../headers/main.h"
#include "../headers/common.h"
#include "../headers/display.h"

void insertionSort(int (&rectSizes)[]) {
    int i = 1;
    int j;

    while(i < rectNum && !sorted && !closable) {
        sleep();
        j = i;
        while(j > 0 && rectSizes[j - 1] > rectSizes[j]) {
            rectSizes[j] = rectSizes[j] + rectSizes[j - 1];
            rectSizes[j - 1] = rectSizes[j] - rectSizes[j - 1];
            rectSizes[j] = rectSizes[j] - rectSizes[j - 1];
            display(rectSizes, j);
            j--;
        }
        i++;
    }
    sorted = true;
}