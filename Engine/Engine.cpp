//
// Created by lucja on 19.06.2024.
//

#include "Engine.hpp"
#include <fstream>

//Init
void Engine::initWindow()
{
    std::ifstream ifs("../../window.ini");

    std::string title = "Empty";
    sf::VideoMode window_bounds(800, 600);
    unsigned int framerate_limit = 30;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width;
        ifs >> window_bounds.height;
        ifs >> framerate_limit;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds,title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setKeyRepeatEnabled(false);
}

void Engine::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->states));
}

//Construct Destruct
Engine::Engine()
{
    this->initWindow();
    this->initStates();
}

Engine::~Engine()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();   //data
        this->states.pop();   //pointer
    }
}

//Functions
void Engine::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Engine::updateSFMLEvents()
{
    while (this->window->pollEvent(this->e))
    {
        if (this->e.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Engine::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->window->close();
    }

}

void Engine::render()
{
    this->window->clear();

    if (!this->states.empty())
    {
        this->states.top()->render(this->window);
    }

    this->window->display();
}

void Engine::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}