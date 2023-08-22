#include "../headers/common.h"
#include "../headers/utils.h"

void display(int rectSizes[], int index) {
    int i = 0;
    int j = rectWidth;
    int color;

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

void displayTwo(int rectSizes[], int indexOne, int indexTwo) {
    int i = 0;
    int j = rectWidth;

    window.clear();
    while (i < rectNum) {  
        sf::RectangleShape rect;

        rect.setSize(sf::Vector2f(rectWidth, rectSizes[i]));
        rect.setPosition(j, height);
        rect.rotate(180);

        j += rectWidth + 5;

        if (i == indexOne || i == indexTwo || sorted) {
            rect.setFillColor(sf::Color::Green);
        }
        window.draw(rect);
        i++;
    }
    window.display();
}

void displayQuick(int rectSizes[], int bot, int top, int indexOne, int indexTwo) {
    int i = 0;
    int j = rectWidth;
    int color;

    window.clear();
    while (i < rectNum) {  
        sf::RectangleShape rect;

        rect.setSize(sf::Vector2f(rectWidth, rectSizes[i]));
        rect.setPosition(j, height);
        rect.rotate(180);

        j += rectWidth + 5;

        if ((i >= bot && i <= top) && !sorted) {
            rect.setFillColor(sf::Color {75, 75, 75});
        }

        if (i == indexOne || i == indexTwo || sorted) {
            rect.setFillColor(sf::Color::Green);
        }

        window.draw(rect);
        i++;
    }
    window.display();
}

int sortedDisplay(int (&rectSizes)[], int index) {
    int i = 0;
    int j = rectWidth;

    window.clear();
    bool sortedForReal = verify(rectSizes);
    while (i < rectNum) {      
        sf::RectangleShape rect;

        rect.setSize(sf::Vector2f(rectWidth, rectSizes[i]));
        rect.setPosition(j, height);
        rect.rotate(180);

        j += rectWidth + 5;

        if (i * 75 <= index ) {
            rect.setFillColor(sortedForReal ? sf::Color::Green : sf::Color::Red);
        }
        window.draw(rect);
        i++;
    }
    window.display();
    if (index < rectNum * 75)
        index++;
    return(index);
}