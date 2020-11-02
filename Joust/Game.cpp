#include "Game.h"


Game::Game()
{
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Joust");
	_event =  new sf::Event();
	_clock =  new sf::Clock();

	addScene(new SplashScreen(SCENE_NAME_SPLASHSCREEN));
	addScene(new level::Level(SCENE_NAME_LEVEL));
	addScene(new MainMenu(SCENE_NAME_MAINMENU));

	for (auto it = _scenes.begin(); it != _scenes.end(); it++)
		it->second->init();

	moveToScene(SCENE_NAME_LEVEL);
}

Game::~Game()
{
	delete(_window);
	delete(_event);
	delete(_clock);
}


void Game::addScene(Scene* scenePtr)
{
	_scenes[scenePtr->Name()] = scenePtr;
}
void Game::moveToScene(sf::String sceneName)
{
	_currentScene = _scenes[sceneName];
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

}

void Game::processEvents()
{
	sf::Event event;
	while (_window->pollEvent(*_event))
	{
		switch (_event->type)
		{
			case sf::Event::KeyPressed: 
				handlePlayerInput(_event->key.code, true);
				break;
			case sf::Event::KeyReleased: 
				handlePlayerInput(_event->key.code, false);
				break;
			case sf::Event::Closed: 
				_window->close();
				break;
		}
	}
}

void Game::update()
{
	_deltaTime = _clock->restart().asSeconds();

	_currentScene->run(_deltaTime, _window->getSize());
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