#include "Game.h"
Game::Game()
{
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Joust");
	_event =  new sf::Event();
	_clock =  new sf::Clock();
	moveToScene(SCENE_NAME_MAINMENU);
}

Game::~Game()
{
	delete(_window);
	delete(_event);
	delete(_clock);
}

void Game::moveToScene(sf::String sceneName)
{
	delete(_currentScene);
	if (sceneName == SCENE_NAME_MAINMENU)
	{
		_currentScene = new mainMenu::MainMenu(SCENE_NAME_MAINMENU);
		_currentScene->init();
	}

	if (sceneName == SCENE_NAME_LEVEL)
	{
		_currentScene = new level::Level(SCENE_NAME_LEVEL);
		_currentScene->init();
	}

}

void Game::processEvents()
{
	sf::Event event;
	while (_window->pollEvent(*_event))
	{
		switch (_event->type)
		{
			case sf::Event::Closed: 
				_window->close();
				break;
		}
	}
}

void Game::update()
{
	_deltaTime = _clock->restart().asSeconds();
	_currentScene->update(_deltaTime, _window->getSize());

	if (_currentScene->Name() == SCENE_NAME_MAINMENU)
	{
		if (_currentScene->CurrentStateName == "LoadLevel")
		{
			moveToScene(SCENE_NAME_LEVEL);
		}
		if (_currentScene->CurrentStateName == "Exit")
			_window->close();
	}

	if (_currentScene->Name() == SCENE_NAME_LEVEL)
	{
		if (_currentScene->CurrentStateName == "Exit")
		{
			moveToScene(SCENE_NAME_MAINMENU);

			return;
		}	
	}
}


void Game::render()
{
	_currentScene->render(_window);
}

void Game::run()
{
	while (_window->isOpen())
	{
		processEvents();
		update();
		render();
	}
}