#include "../headers/common.h"
#include "../headers/utils.h"
#include "../headers/display.h"

void selectionSort(int (&rectSizes)[]) {
    for (int i = 0; i < rectNum; i++) {
        sleep();
        int minPos = i;

        for (int j = i + 1; j < rectNum; j++) {
            if (rectSizes[j] < rectSizes[minPos])
                minPos = j;
        }
        swapInt(rectSizes, i, minPos);
        displayTwoInteraction(rectSizes, i, minPos);
    }
    sorted = true;



}