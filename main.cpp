#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>

using namespace std;

int height = 600;
int width = 600;

int rectNum = 50;
int rectWidth = width / rectNum - 5;
bool sorted = false;

sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

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

void display(int rectSizes[], int index) {
    int i = 0;
    int j = 0;

    window.clear();
    sf::RectangleShape rect;
    while (i != rectNum) {      
        rect.setSize(sf::Vector2f(rectWidth, rectSizes[i]));

        rect.setPosition(j, height);

        j += rectWidth + 5;

        if (i == index || sorted) {
            rect.setFillColor(sf::Color::Green);
        }
        window.draw(rect);
        i++;
    }
    window.display();
}

void initSizes(int (&rectSizes)[]) {
    int i = 0;

    while (i != rectNum) {
        rectSizes[i] = - (20 + 10 * i);
        i++;
    }
}

int main()
{
    int rectSizes[rectNum];
    initSizes(rectSizes); 
    shuffle(rectSizes);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        display(rectSizes, -1);
    }

    return 0;
}