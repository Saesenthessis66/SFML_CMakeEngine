//
// Created by lucja on 19.06.2024.
//

#include "MainMenuState.hpp"

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("../../Fonts/OpenSans-Bold.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD	FONT");
	}
}

void MainMenuState::initButtons()
{
	Button exitButton = Button(800,450,200,80,&this->font,"QUIT",30,
							sf::Color(100,100,100,200),
							sf::Color(150, 150, 150, 255),
							sf::Color(20, 20, 20, 200));

	buttons.push_back(exitButton);

	buttons[0].onClick = std::bind(&MainMenuState::exitButtonFunction, this);

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states) : State(window,states)
{
	this->initFonts();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::updateInput(const float&)
{

}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::updateButtons()
{

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].update(this->MousePosView);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	this->renderButtons(target);
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for(int i =0; i < buttons.size();i++)
	{
		buttons[i].render(target);
	}

}

void MainMenuState::exitButtonFunction()
{
	this->endState();
}