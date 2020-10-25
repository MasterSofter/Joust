#include "Level.h"
#include"iterator"
namespace level
{


	Level::Level(sf::String name) :Scene(name)
	{
		_currentState = _stateGame;
	}

	void Level::init()
	{
		GameObject* plat = new GameObject("../data/textures/plat1.png");
			plat->Static = true;
			plat->setPosition(sf::Vector2f(400, 600-98/2.f));
			_gameObjects.push_back(plat);
			physics.addGameObject(plat);

		GameObject* plat1 = new GameObject("../data/textures/plat8.png");
			plat1->Static = true;
			plat1->setPosition(sf::Vector2f(550, 370));
			_gameObjects.push_back(plat1);
			physics.addGameObject(plat1);

		GameObject* plat2 = new GameObject("../data/textures/plat2.png");
			plat2->Static = true;
			plat2->setPosition(sf::Vector2f(220, 600/2));
			_gameObjects.push_back(plat2);
			physics.addGameObject(plat2);

		GameObject* plat3 = new GameObject("../data/textures/plat3.png");
			plat3->Static = true;
			plat3->setPosition(sf::Vector2f(180, 600/4));
			_gameObjects.push_back(plat3);
			physics.addGameObject(plat3);

		GameObject* plat4 = new GameObject("../data/textures/plat6.png");
			plat4->Static = true;
			plat4->setPosition(sf::Vector2f(700, 600/3.2f));
			_gameObjects.push_back(plat4);
			physics.addGameObject(plat4);

		GameObject* player = new player::Player("../data/textures/enemies.png");
			player->setPosition(sf::Vector2f(400, 200));
			_gameObjects.push_back(player);
			physics.addGameObject(player);
	}

	void Level::processEvents()
	{

	}

	void Level::update(float deltaTime)
	{
		if (_currentState == _stateGame)
		{
			physics.Update(deltaTime);
			for (auto it = _gameObjects.begin(); it != _gameObjects.end(); it++)
			{
				(*it)->Update(deltaTime);
			}
			return;
		}

		if (_currentState == _statePause)
		{
			return;
		}
	}

	void Level::run(float deltaTime)
	{
		processEvents();
		update(deltaTime);
	}

}


