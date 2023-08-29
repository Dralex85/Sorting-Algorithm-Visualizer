#include "../headers/common.h"

void display(vector<int> rectSizes, int index) {
    int offset = rectWidth;

    window.clear();
    for (int i = 0; i < rectSizes.size(); i++) {
        sf::RectangleShape rect;

        //Set height of object
        rect.setSize(sf::Vector2f(rectWidth, rectSizes.at(i)));
        //Set position of object at the bottom of the window
        rect.setPosition(offset, height);
        //Rotate object, normally rect will point to the bottom
        rect.rotate(180);

        //Set offset to have a space between object
        offset += rectWidth + 5;

        //If the rect is currently check, color it
        if (i == index)
            rect.setFillColor(sf::Color::Green);

        window.draw(rect);
    }
    window.display();
}

void displayTwoIndex(vector<int> rectSizes, int index1, int index2) {
    int offset = rectWidth;

    window.clear();
    for (int i = 0; i < rectSizes.size(); i++) {
        sf::RectangleShape rect;

        //Set height of object
        rect.setSize(sf::Vector2f(rectWidth, rectSizes.at(i)));
        //Set position of object at the bottom of the window
        rect.setPosition(offset, height);
        //Rotate object, normally rect while point to the bottom
        rect.rotate(180);

        //Set offset to have a space between object
        offset += rectWidth + 5;

        //If the rect is currently check, color it
        if (i == index1 || i == index2)
            rect.setFillColor(sf::Color::Green);

        window.draw(rect);
    }
    window.display();
}

void displayQuick(vector<int> rectSizes,int bot, int top, int index1, int index2) {
    int offset = rectWidth;

    window.clear();
    for (int i = 0; i < rectSizes.size(); i++) {
        sf::RectangleShape rect;

        //Set height of object
        rect.setSize(sf::Vector2f(rectWidth, rectSizes.at(i)));
        //Set position of object at the bottom of the window
        rect.setPosition(offset, height);
        //Rotate object, normally rect while point to the bottom
        rect.rotate(180);

        //Set offset to have a space between object
        offset += rectWidth + 5;

        //Color all the rect in the interval currently processed
        if((i >= bot && i <= top)) {
            rect.setFillColor(sf::Color {75, 75, 75});
        }

        //If the rect is currently check, color it
        if (i == index1 || i == index2)
            rect.setFillColor(sf::Color::Green);

        window.draw(rect);
    }
    window.display();
}

int sortedDisplay(vector<int> rectSizes, int index) {
    int offset = rectWidth;
    //Higher it is, slower it is
    int speedFactor = 20;

    window.clear();

    //If it is the first call, check if the sort algorithm was right
    if(!verifiedSorted)
        verify(rectSizes);
    
    for (int i = 0; i < rectSizes.size(); i++) {
        sf::RectangleShape rect;

        //Set height of object
        rect.setSize(sf::Vector2f(rectWidth, rectSizes[i]));
        //Set position of object at the bottom of the window
        rect.setPosition(offset, height);
        //Rotate object, normally rect while point to the bottom
        rect.rotate(180);

        //Set offset to have a space between object
        offset += rectWidth + 5;

        //If the rect is currently check, color it accordingly to the sorting state
        if (i * speedFactor <= index)
            rect.setFillColor(verifiedSorted ? sf::Color::Green : sf::Color::Red);

        window.draw(rect);
    }
    window.display();
    if (index < rectSizes.size() * speedFactor)
        index++;

    return index;
}