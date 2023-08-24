#include "./headers/common.h"

sf::RenderWindow window(sf::VideoMode(width, height), "Sorting Visualization");

int rectNum = 50;
int rectWidth;
float waitTime = 0.05;
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
        
        default:
            cout << "Error : No algorithm choose";
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

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (!sorted && !closable) {
            algorithmChoice(algorithm, rectSizes);
        }

        index = sortedDisplay(rectSizes, index);
    }

}