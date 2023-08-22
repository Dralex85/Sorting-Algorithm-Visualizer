#include "./headers/common.h"
#include "./headers/sorter.h"
#include "./headers/display.h"
#include "./headers/utils.h"

sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
bool sorted;
bool closable = false;
int rectNum = 50;
int rectWidth = width / rectNum - 5;
float waitTime = 0.05;



int main(int argc, char **argv)
{
    int algorithm = parser(argc, argv);
    int index = 0;
    sorted = false;
    int rectSizes[rectNum];
    rectWidth = width / rectNum - 5;


    initSizes(rectSizes); 
    shuffle(rectSizes);

    display(rectSizes, -1);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!sorted) {
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
                    quickSort(rectSizes, 0, rectNum - 1, 0);
                    break;

                default:
                    cout << "Error : No algorithm selected" << endl;
                    window.close();
            }
        }
        index = sortedDisplay(rectSizes, index);
    }
    return 0;
}