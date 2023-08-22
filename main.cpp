
#include "./headers/common.h"
#include "./headers/sorter.h"
#include "./headers/display.h"
#include "./headers/utils.h"

sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
bool sorted;
bool closable = false;

int main()
{
    int index = 0;
    sorted = false;
    int rectSizes[rectNum];
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
//            insertionSort(rectSizes);
            selectionSort(rectSizes);
        }
        index = sortedDisplay(rectSizes, index);
    }
    return 0;
}