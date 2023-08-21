#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>

int height = 600;
int width = 600;

sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

int rectNum = 50;
bool sorted = false;

void shuffle(sf::RectangleShape (&rect)[]) {
    srand(time(NULL));
    sf::Vector2f tmp;

    for (int i = rectNum - 1; i >= 0; i--) {
        int j = rand() % (i + 1);

        tmp = rect[i].getSize();
        rect[i].setSize(rect[j].getSize());
        rect[j].setSize(tmp);
    }
}

void display(sf::RectangleShape (&rect)[], int index) {
    int j = 0;

    window.clear();
    while (j != rectNum) {
        if (j == index || sorted) {
            rect[j].setFillColor(sf::Color::Green);
        }
        window.draw(rect[j]);
        rect[j].setFillColor(sf::Color::White);
        j++;
    }
}

int main()
{


    sf::RectangleShape rect[rectNum];

    int i = 0, j = height, l = 0;
    int rectWidth = width / rectNum - 5;

    while (l < rectNum) {
        rect[l].setSize(sf::Vector2f(rectWidth, - (20  + 10 * l)));

        rect[l].setPosition(i, j);

        i += rectWidth + 5;

        l++;
    }

    l = 0;
    
    shuffle(rect);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        display(rect, -1);

        // Reset variables.
        l = 0;
        i = 0;
        // Copy the buffer to the window.
        window.display();
    }

    return 0;
}

