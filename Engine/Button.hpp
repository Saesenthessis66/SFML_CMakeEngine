//
// Created by lucja on 19.06.2024.
//

#ifndef BUTTON_HPP
#define BUTTON_HPP


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <functional>

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE, BTN_PRESSED};

class Button
{
    //variables
    short unsigned buttonState;
    short unsigned lastState;

    int textFontSize;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

    float width, height,xPos,yPos;

public:

    //Construct Destruct
    Button(float x, float y, float width, float height, sf::Font* Font, std::string txt,int textFontSize ,sf::Color idle, sf::Color hover, sf::Color active);
    ~Button();

    //Accessors
    const bool isPressed() const;
    std::function<void()> onClick;

    //Functions
    void update(const sf::Vector2f);
    void render(sf::RenderTarget* target);

};



#endif //BUTTON_HPP
