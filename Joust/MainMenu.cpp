#include "MainMenu.h"

MainMenu::MainMenu(sf::String name) :Scene(name)
{

}

void MainMenu::init()
{
	GameObject* plat = new GameObject("../data/textures/plat1.png");
	plat->Static = true;
	plat->setPosition(sf::Vector2f(400, 600 - 98 / 2.f));
	_gameObjects.push_back(plat);
}

void MainMenu::processEvents()
{

}


void MainMenu::render(sf::RenderWindow* wnd)
{
	wnd->clear();
	for (auto it = _gameObjects.begin(); it != _gameObjects.end(); it++)
		wnd->draw((*it)->gameObject);

	wnd->display();
}


void MainMenu::update(float deltaTime, sf::Vector2u windowSize)
{

}

void MainMenu::run(float deltaTime, sf::Vector2u windowSize)
{
	processEvents();
	update(deltaTime, windowSize);
}