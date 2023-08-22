
#include "./headers/common.h"
#include "./headers/insertion.h"
#include "./headers/display.h"

sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
bool sorted;
bool closable = false;

void shuffle(int (&rectSizes)[]) {
    srand(time(NULL));

    int tmp;
    for (int i = rectNum - 1; i >= 0; i--) {

        int j = rand() % (i + 1);

        tmp = rectSizes[i];
        rectSizes[i] = rectSizes[j];
        rectSizes[j] = tmp;

    }
}

void initSizes(int (&rectSizes)[]) {
    int i = 0;
    srand(time(NULL));
    while (i < rectNum) {
        rectSizes[i] = rand() % height;
//        rectSizes[i] = (20 + 10 * i + i) % height;
        i++;
    }
}
void sleep() {
    const sf::Time freezeLength{sf::seconds(waitTime)};
    sf::Clock freezeClock;
    while(freezeClock.getElapsedTime() < freezeLength) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                closable = true;
            }
        }
    }
}

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
        if (!sorted)
            insertionSort(rectSizes);
        index = sortedDisplay(rectSizes, index);
    }
    for (int i = 0; i < rectNum; i++) {
        cout << rectSizes[i] << endl;
    }
    return 0;
}