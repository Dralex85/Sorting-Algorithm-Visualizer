#include "../headers/common.h"

void swapInt(int (&tab)[], int one, int two) {
    int tmp = tab[one];
    tab[one] = tab[two];
    tab[two] = tmp;
}

bool verify(int (&tab)[]) {
    int last = tab[0];
    for (int i = 0; i < rectNum; i++) {
        if (tab[i] < last)
            return false;
    }
    return true;
}

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