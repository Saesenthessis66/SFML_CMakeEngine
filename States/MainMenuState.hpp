//
// Created by lucja on 19.06.2024.
//

#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "State.hpp"

class MainMenuState : public State
{
    sf::Font font;

    std::vector<Button> buttons;

    void initFonts();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow*, std::stack<State*>*);
    virtual ~MainMenuState();

    void updateInput(const float&);
    void update(const float&);
    void updateButtons();
    void render(sf::RenderTarget* = NULL);
    void renderButtons(sf::RenderTarget* = NULL);

    void exitButtonFunction();
};



#endif //MAINMENUSTATE_HPP
