//
// Created by lucja on 19.06.2024.
//

#include "Button.hpp"

//Construct Destruct
Button::Button(float x, float y, float width, float height, sf::Font* Font, std::string txt,int fontSize, sf::Color idle, sf::Color hover, sf::Color active)
{
    this->width = width;
    this->height = height;
    xPos = x-width/2;
    yPos = y-height/2;
    this->textFontSize = fontSize;

    this->buttonState = BTN_IDLE;

    this->shape.setPosition(x, y);
    this->shape.setSize(sf::Vector2f(width, height));

    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);

    this->font = Font;
    this->text.setFont(*this->font);
    this->text.setString(txt);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(this->textFontSize);

    float offsetX =  (float)this->text.getCharacterSize()/20;
    float offsetY = (float)this->text.getCharacterSize()/4;

    this->text.setPosition(xPos+width/2-text.getGlobalBounds().width/2-offsetX, yPos + height/2 - text.getGlobalBounds().height / 2- offsetY);

    this->idleColor = idle;
    this->hoverColor = hover;
    this->activeColor = active;

    this->shape.setFillColor(this->idleColor);

    this->onClick = 0;
}

Button::~Button()
{

}

//Accessors
const bool Button::isPressed() const
{
    if (this->buttonState == BTN_ACTIVE)
    {
        return true;
    }

    return false;
}

//Functions
void Button::update(const sf::Vector2f mousePos)
{
    this->buttonState = BTN_IDLE;

    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_ACTIVE;
        }

        if(this->lastState == BTN_ACTIVE && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_PRESSED;
        }

    }

    switch (this->buttonState)
    {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            this->shape.setPosition(sf::Vector2f(xPos, yPos));
            this->shape.setSize(sf::Vector2f(width, height));
            lastState = BTN_IDLE;
            break;

        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            this->shape.setPosition(sf::Vector2f(xPos-5,yPos-5));
            this->shape.setSize(sf::Vector2f(width+10,height+10));
            lastState = BTN_HOVER;
            break;

        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            lastState = BTN_ACTIVE;
            break;

        case BTN_PRESSED:
            this->onClick();
            break;

        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
    }
}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->text);
}