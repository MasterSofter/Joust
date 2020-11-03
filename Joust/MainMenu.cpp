#include "MainMenu.h"
#include "mainMenu.StateMachine.h"

namespace mainMenu
{

	MainMenu::MainMenu(sf::String name) : Scene(name)
	{
		stateMachine = new StateMachine(this);
		stateMachine->moveToState(STATE_NAME_MAINMENU);
	}

	void MainMenu::init()
	{
		GameObject* plat = new GameObject("../data/textures/plat1.png");
		plat->Static = true;
		plat->setPosition(sf::Vector2f(400, 600 - 98 / 2.f));
		_gameObjects.push_back(plat);

		GameObject* plat1 = new GameObject("../data/textures/plat8.png");
		plat1->Static = true;
		plat1->setPosition(sf::Vector2f(550, 370));
		_gameObjects.push_back(plat1);

		GameObject* plat2 = new GameObject("../data/textures/plat2.png");
		plat2->Static = true;
		plat2->setPosition(sf::Vector2f(220, 600 / 2));
		_gameObjects.push_back(plat2);

		GameObject* plat3 = new GameObject("../data/textures/plat3.png");
		plat3->Static = true;
		plat3->setPosition(sf::Vector2f(180, 600 / 4));
		_gameObjects.push_back(plat3);

		GameObject* plat4 = new GameObject("../data/textures/plat6.png");
		plat4->Static = true;
		plat4->setPosition(sf::Vector2f(700, 600 / 3.2f));
		_gameObjects.push_back(plat4);

		GameObject* playerImage = new GameObject("../data/textures/PlayerImage.png");
		playerImage->Static = true;
		playerImage->gameObject.setScale(sf::Vector2f(1, 1));
		playerImage->setPosition(sf::Vector2f(160, 472));
		_gameObjects.push_back(playerImage);

		GameObject* enemyImage = new GameObject("../data/textures/EnemyImage.png");
		enemyImage->Static = true;
		enemyImage->gameObject.setScale(sf::Vector2f(-1, 1));
		enemyImage->setPosition(sf::Vector2f(800 - 160, 472));
		_gameObjects.push_back(enemyImage);

		GameObject* menu = new GameObject("../data/textures/menu.png");
		menu->Static = true;
		menu->Name = "Menu";
		menu->setPosition(sf::Vector2f(800 / 2.f, 600 / 2.f));
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
		sf::Text* textPlay = new sf::Text("Play", _font);
		textPlay->setCharacterSize(34);
		textPlay->setStyle(sf::Text::Bold);
		textPlay->setFillColor(sf::Color(160, 160, 160));
		textPlay->setPosition(sf::Vector2f(-100, -100));
		_texts.push_back(textPlay);
		textPlayPtr = textPlay;

		sf::Text* textExit = new sf::Text("Exit", _font);
		textExit->setCharacterSize(34);
		textExit->setStyle(sf::Text::Bold);
		textExit->setFillColor(sf::Color(160, 160, 160));
		textExit->setPosition(sf::Vector2f(-100, -100));
		_texts.push_back(textExit);
		textExitPtr = textExit;

		sf::Text* textJoust = new sf::Text("Joust", _font);
		textJoust->setCharacterSize(150);
		textJoust->setStyle(sf::Text::Bold);
		textJoust->setFillColor(sf::Color(255,165,0));
		_texts.push_back(textJoust);
		textJoustPtr = textJoust;
	}

	void MainMenu::processEvents()
	{

	}


	void MainMenu::render(sf::RenderWindow* wnd)
	{
		wnd->clear();
		if (stateMachine->currentState->Loaded)
		{
			for (auto it = _gameObjects.begin(); it != _gameObjects.end(); it++)
				wnd->draw((*it)->gameObject);

			wnd->draw(*textPlayPtr);
			wnd->draw(*textExitPtr);
			wnd->draw(*textJoustPtr);
		}
		wnd->display();
	}


	void MainMenu::update(float deltaTime, sf::Vector2u windowSize)
	{
		stateMachine->currentState->Do(deltaTime);
	}

	void MainMenu::run(float deltaTime, sf::Vector2u windowSize)
	{
		processEvents();
		update(deltaTime, windowSize);
	}
}
