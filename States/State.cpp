//
// Created by lucja on 19.06.2024.
//

#include "State.hpp"

//Construct Destruct
State::State(sf::RenderWindow* window_, std::stack<State*>* states_)
{
    this->window = window_;
    this->states = states_;
    this->quit = false;
}

State::~State()
{
}

//Accessors
const bool& State::getQuit() const
{
    return this->quit;
}

//Functions
void State::endState()
{
    this->quit = true;
}

void State::updateMousePositions()
{
    this->MousePosScreen = sf::Mouse::getPosition();
    this->MousePosWindow = sf::Mouse::getPosition(*this->window);
    this->MousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}