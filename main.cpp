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
    rectWidth = width / rectNum - 5;          //Visual representation of each element


    initSizes(rectSizes); 
    shuffle(rectSizes);

    display(rectSizes, -1);

    cout << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!sorted) {
            switch(algorithm) {
                case 0:
                    insertionSort(rectSizes);
                    break;

                case 1:
                    selectionSort(rectSizes);
                    break;

                default:
                    cout << "Error : No algorithm selected" << endl;
                    window.close();
            }
//            insertionSort(rectSizes);
//            selectionSort(rectSizes);
        }
        index = sortedDisplay(rectSizes, index);
    }
    return 0;
}