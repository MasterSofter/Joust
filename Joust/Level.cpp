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

		GameObject* player = new player::Player("../data/textures/enemies.png", "../data/textures/spawn1.png");
			player->setPosition(sf::Vector2f(360, 472));
			player->Name = "Player";
			player->lifes = 5;
			player->Alive = true;
			_gameObjects.push_back(player);
			physics.addGameObject(player);

			GameObject* enemy = new AI::Enemy("../data/textures/enemies2.png", (player::Player*) player);
			enemy->setPosition(sf::Vector2f(157, 108));
			_gameObjects.push_back(enemy);
			physics.addGameObject(enemy);

	}

	void Level::processEvents()
	{

	}

	void Level::update(float deltaTime, sf::Vector2u windowSize)
	{
		if (_currentState == _stateGame)
		{
			physics.Update(deltaTime);
			for (auto it = _gameObjects.begin(); it != _gameObjects.end(); it++)
			{
				(*it)->Update(deltaTime, windowSize);
				if (!(*it)->Static)
				{
					if ((*it)->Name == "Player" && !(*it)->Alive)
						(*it)->Spawn(sf::Vector2f(360, 472));

					if ((*it)->getPosition().x > 800)
						(*it)->setPosition(sf::Vector2f(0, (*it)->getPosition().y));
					if ((*it)->getPosition().x < 0)
						(*it)->setPosition(sf::Vector2f(800, (*it)->getPosition().y));
				}
				
			}
			return;
		}

		if (_currentState == _statePause)
		{
			return;
		}
	}

	void Level::run(float deltaTime, sf::Vector2u windowSize)
	{
		processEvents();
		update(deltaTime, windowSize);
	}

}


