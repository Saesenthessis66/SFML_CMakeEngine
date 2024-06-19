//
// Created by lucja on 19.06.2024.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "../States/MainMenuState.hpp"

class Engine {

    //Variables
    sf::RenderWindow* window;
    sf::Event e;

    float dt;
    sf::Clock dtClock;

    std::stack<State*> states;

    //Init
    void initWindow();
    void initStates();

public:
    //Construct Destruct
    Engine();
    ~Engine();

    //Functions
    void updateDt();
    void updateSFMLEvents();

    void update();
    void render();

    void run();

};



#endif //ENGINE_HPP
