#include "./headers/common.h"

sf::RenderWindow window(sf::VideoMode(width, height), "Sorting Visualization");

int rectNum = 50;
int rectWidth;
float waitTime = 0.05;
float sleepCount = 0;
bool sorted = false;
bool closable = false;
bool verifiedSorted = false;

void algorithmChoice(int algorithm, vector<int> &rectSizes) {
    switch(algorithm) {

        case 0:
            cout << "InsertionSort" << endl;
            insertionSort(rectSizes);
            break;

        case 1:
            cout << "SelectionSort" << endl;
            selectionSort(rectSizes);
            break;

        case 2:
            cout << "QuickSort" << endl;
            quickSort(rectSizes, 0, rectSizes.size() - 1, 0);
            break;
        
        case 3:
            cout << "BubbleSort" << endl;
            bubble(rectSizes);
            break;

        case 4:
            cout << "CombSort" << endl;
            combSort(rectSizes);
            break;

        default:
            cout << "Error : No algorithm choose" << endl;
            break;
    }
    return;
}

int main(int argc, char **argv) {

    vector<int> rectSizes;
    int algorithm = parser(argc, argv);
    rectWidth = (width / rectNum) - 5;
    int index = 0;
    initSizes(rectSizes);
    shuffle(rectSizes);
    display(rectSizes, -1);

    const clock_t clock_start = clock();
    bool clockIsUp = true;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (!sorted && !closable) {
            algorithmChoice(algorithm, rectSizes);
        }

        if(sorted && clockIsUp) {
            const clock_t clock_end = clock();
            clockIsUp = false;
            cout << "CPU time used : " << (1000.0 * (clock_end - clock_start) /CLOCKS_PER_SEC) - sleepCount * 1000 << "ms" << endl;
            cout << "Real time elapsed : " << (1000.0 * (clock_end - clock_start) /CLOCKS_PER_SEC) << "ms" << endl;
        }
        index = sortedDisplay(rectSizes, index);
    }

}