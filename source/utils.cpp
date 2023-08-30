#include "../headers/common.h"

vector<int> copy(vector<int> src) {
    vector<int> copy;
    copy.swap(src);

    return copy;
}

void swapInt(vector<int> &tab, int one, int two) {
    int tmp = tab.at(one);
    tab.at(one) = tab.at(two);
    tab.at(two) = tmp;
}

void initSizes(vector<int> &rectSizes) {
    srand(time(NULL));
    for(int i = 0; i < rectNum; i++) {
        rectSizes.push_back(rand() % height);
    }
}

void shuffle(vector<int> &rectSizes) {
    srand(time(NULL));

    int j;
    int tmp;

    for(int i = 0; i < rectSizes.size(); i++) {
        j = rand() % (i + 1);
        tmp = rectSizes.at(i);
        rectSizes.at(i) = rectSizes.at(j);
        rectSizes.at(j) = tmp;
    }
}

void verify(vector<int> tab) {
    int last = tab.at(0);
    for (int i = 0; i < tab.size(); i++) {
        if (tab.at(i) < last)
            return;
    }
    verifiedSorted = true;
    return;
}

void sleep() {
    sleepCount += waitTime;
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

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

int parser(int argc, char **argv) {
    if (argc == 1)
        return -1;

    if (argc >= 3) {
        rectNum = stoi(argv[2]);
        if (rectNum < 1)
            rectNum = 1;
    }

    if (argc == 4) {
        waitTime = atof(argv[3]);
    }

    switch(str2int(argv[1])) {
        case str2int("all"):
            return -42;

        case str2int("insertion"):
            return 0;

        case str2int("selection"):
            return 1;

        case str2int("quick"):
            return 2;

        case str2int("bubble"):
            return 3;

        case str2int("comb"):
            return 4;

        case str2int("merge"):
            return 5;

        default:
            return -1;
    }
}