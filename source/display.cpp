#include "../headers/common.h"

void display(int rectSizes[], int index) {
    int i = 0;
    int j = rectWidth;

    window.clear();
    while (i < rectNum) {      
        sf::RectangleShape rect;

        rect.setSize(sf::Vector2f(rectWidth, rectSizes[i]));
        rect.setPosition(j, height);
        rect.rotate(180);

        j += rectWidth + 5;

        if (i == index || sorted) {
            rect.setFillColor(sf::Color::Green);
        }
        window.draw(rect);
        i++;
    }
    window.display();
}

int sortedDisplay(int rectSizes[], int index) {
    int i = 0;
    int j = rectWidth;

    window.clear();
    while (i < rectNum) {      
        sf::RectangleShape rect;

        rect.setSize(sf::Vector2f(rectWidth, rectSizes[i]));
        rect.setPosition(j, height);
        rect.rotate(180);

        j += rectWidth + 5;

        if (i * 75 <= index ) {
            rect.setFillColor(sf::Color::Green);
        }
        window.draw(rect);
        i++;
    }
    window.display();
    if (index < rectNum * 75)
        index++;
    return(index);
}