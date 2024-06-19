//
// Created by lucja on 19.06.2024.
//

#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <stack>
#include<vector>

#include "../Engine/Button.hpp"

class State
{

protected:

    //Variables
    std::stack<State*>* states;


    sf::RenderWindow* window;
    bool quit;

    sf::Vector2i MousePosScreen;
    sf::Vector2i MousePosWindow;
    sf::Vector2f MousePosView;

public:

    // Consruct Destruct
    State(sf::RenderWindow*, std::stack<State*>* states);
    virtual ~State();

    //Accessors
    const bool& getQuit() const;

    //Functions
    virtual void endState();
    virtual void updateMousePositions();
    virtual void updateInput(const float&)=0;
    virtual void update(const float&) = 0;
    virtual void render(sf::RenderTarget* = nullptr) = 0;

};

#endif //STATE_HPP
