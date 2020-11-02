#include "Level.h"
#include"iterator"
#include "level.StateMachine.h"
namespace level
{
	Level::Level(sf::String name) :Scene(name)
	{
		stateMachine = new StateMachine(this);
		stateMachine->currentState = stateMachine->states[STATE_NAME_GAME];
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
			enemy->Name = "Enemy";
			_gameObjects.push_back(enemy);
			physics.addGameObject(enemy);

		GameObject* menu = new GameObject("../data/textures/menu.png");
			menu->Static = true;
			menu->Name = "Menu";
			menu->setPosition(sf::Vector2f(-800/2.f, -600 /2.f));
			menu->gameObject.setScale(sf::Vector2f(12, 12));
			_gameObjects.push_back(menu);
			menuPtr = menu;

		GameObject* kursorMenu = new GameObject("../data/textures/kursor.png");
			kursorMenu->Static = true;
			kursorMenu->Name = "Kursor";
			kursorMenu->setPosition(sf::Vector2f(-100, -100));
			kursorMenu->gameObject.setScale(sf::Vector2f(1.2f, 1.2f));
			_gameObjects.push_back(kursorMenu);
			kursormenuPtr = kursorMenu;
		
		_font.loadFromFile("../data/fonts/ARCADECLASSIC.ttf");
		sf::Text* textResume = new sf::Text("Resume", _font);
			textResume->setCharacterSize(34);
			textResume->setStyle(sf::Text::Bold);
			textResume->setFillColor(sf::Color(160, 160, 160));
			textResume->setPosition(sf::Vector2f(-100,-100));
			_texts.push_back(textResume);
			textResumePtr = textResume;

		sf::Text* textExit = new sf::Text("Exit", _font);
			textExit->setCharacterSize(34);
			textExit->setStyle(sf::Text::Bold);
			textExit->setFillColor(sf::Color(160, 160, 160));
			textExit->setPosition(sf::Vector2f(-100, -100));
			_texts.push_back(textExit);
			textExitPtr = textExit;
	}

	void Level::processEvents()
	{

	}


	void Level::render(sf::RenderWindow* wnd)
	{
		wnd->clear();
		for (auto it = _gameObjects.begin(); it != _gameObjects.end(); it++)
			wnd->draw((*it)->gameObject);

		wnd->draw(*textResumePtr);
		wnd->draw(*textExitPtr);

		wnd->display();

	}


	void Level::update(float deltaTime, sf::Vector2u windowSize)
	{
		this->stateMachine->Update(deltaTime);
	}

	void Level::run(float deltaTime, sf::Vector2u windowSize)
	{
		processEvents();
		update(deltaTime, windowSize);
	}

}


