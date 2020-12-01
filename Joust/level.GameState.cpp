#include "level.GameState.h"
#include "level.StateMachine.h"

namespace level
{
	ControlView::ControlView() {}
	ControlView::ControlView(Level* level)
	{
		this->levelPtr = level;
	}

	PlayerLifesView::PlayerLifesView() {}
	PlayerLifesView::PlayerLifesView(Level* level) : ControlView(level)
	{
		lastLifes = levelPtr->player->lifes;
		float delta = 0;
		for (int i = 0; i < levelPtr->player->lifes; i++)
		{
			GameObject* life = new GameObject("../data/textures/life.png");
			life->setPosition(sf::Vector2f(190 + delta, 530));
			life->gameObject.setScale(1 / 2.f, 1 / 2.5f);
			life->Name = "Life";
			life->DrawAble = true;
			levelPtr->_gameObjects.push_back(life);
			lifes[i] = life;

			delta += life->gameObject.getSize().x / 2 + 12;
		}
	}

	void PlayerLifesView::view()
	{
		if (levelPtr->player->lifes < lastLifes && levelPtr > 0)
		{
			for (auto it = levelPtr->_gameObjects.begin(); it != levelPtr->_gameObjects.end(); it++)
			{
				if (*it == lifes[lastLifes - 1])
				{
					levelPtr->destroedObjects.push_back(*it);
					break;
				}
			}
			lastLifes--;
		}
	}

	GameManager::GameManager(Level* levelPtr)
	{
		playerLifesView = PlayerLifesView(levelPtr);
		srand(time(NULL));
		this->levelPtr = levelPtr;
	}

	int GameManager::random(int A, int B)
	{
		return A + rand() % ((B + 1) - A);
	}

	//Возрождение врага в рандомном месте
	void GameManager::spawnEnemy()
	{
		//Логика рандомного выбора точки спавна
		int i = random(0, 3);
		GameObject* enemy = new AI::Enemy("../data/textures/Enemy.png", "../data/textures/spawn1.png",
			"../data/textures/EnemyUnmounted.png", (player::Player*) levelPtr->player);

		enemy->setPosition(this->positions[i]);
		enemy->Name = "Enemy";
		levelPtr->newObjects.push_back(enemy);

		countEnemies--;
	}
	//Возрождение игрока в рандомном месте
	void GameManager::spawnPlayer()
	{
		//Логика рандомного выбора точки спавна
		int i = random(0, 3);
		levelPtr->player->Spawn(this->positions[i]);
	}

	//Загружает следующий уровень
	/*Показывает текст Wave (номер волны)
	  Обновляет счетчик кол-ва монстров на экране
	*/
	bool GameManager::showTextWave()
	{
		std::string stringName = "Wave ";
		std::string stringNumb;


		sf::String str = stringName + std::to_string(currentWave);

		levelPtr->waveNumberText->setString(str);
		levelPtr->waveNumberText->setPosition(sf::Vector2f(320, 180));
		//Показать текст на экране
		if (timeLoadLevel > 10)
		{
			levelPtr->waveNumberText->setPosition(sf::Vector2f(-320, -180));
			return true;
		}
		timeLoadLevel += 0.1f;
		return false;


	}

	bool GameManager::findEnemy()
	{
		for (auto it = levelPtr->_gameObjects.begin(); it != levelPtr->_gameObjects.end(); it++)
		{
			if ((*it)->Name == "Enemy")
				return true;
		}
		return false;
	}

	void GameManager::updateEnemies()
	{
		if (countEnemies > 0 && spawnTimeEnemy > 10)
		{
			spawnEnemy();
			spawnTimeEnemy = 0;
		}
		spawnTimeEnemy += 0.04f;
	}

	//Обновляет игру
	void GameManager::update(float deltaTime)
	{
		//Проверить кол-во монстров 

		if (countEnemies <= 0 && !findEnemy())
		{
			currentWave++;
			countEnemies = 5 + currentWave;
			timeLoadLevel = 0;
		}

		playerLifesView.view();
		showTextWave();
		updateEnemies();
		levelPtr->physics.Update(deltaTime);
		for (auto it = levelPtr->_gameObjects.begin(); it != levelPtr->_gameObjects.end(); it++)
		{
			(*it)->Update(deltaTime, sf::Vector2u(800, 600));
			if (!(*it)->Static)
			{
				if ((*it)->Name == "Player" && !(*it)->Alive)
					spawnPlayer();
				if ((*it)->Name == "Enemy" && !(*it)->Alive)
				{
					levelPtr->destroedObjects.push_back(*it);
				}

				if ((*it)->getPosition().x > 800)
					(*it)->setPosition(sf::Vector2f(0, (*it)->getPosition().y));
				if ((*it)->getPosition().x < 0)
					(*it)->setPosition(sf::Vector2f(800, (*it)->getPosition().y));
			}

		}

		//Добавление эоементов которые подлежат созданию

		for (auto it = levelPtr->newObjects.begin(); it != levelPtr->newObjects.end(); it++)
		{
			levelPtr->_gameObjects.push_back(*it);
			levelPtr->physics.addGameObject(*it);
		}

		//Удаление обьектов из списка gameObjects, которые попали в список destroedObjects;
		for (auto it = levelPtr->destroedObjects.begin(); it != levelPtr->destroedObjects.end(); it++)
		{
			bool mayDelete = false;
			auto elem = it;
			for (auto jt = levelPtr->_gameObjects.begin(); jt != levelPtr->_gameObjects.end(); jt++)
			{
				if (*it == *jt)
				{
					mayDelete = true;
					elem = jt;
					break;
				}
			}
			if(mayDelete)
				levelPtr->_gameObjects.erase(elem);
		}
		//Очищаем список
		levelPtr->destroedObjects.clear();
		levelPtr->newObjects.clear();
	}		




	GameState::GameState(Level* level)
		: State(level, STATE_NAME_GAME)
	{

	}

	GameState::~GameState()
	{
		delete(this->_gameManager);
	}

	void GameState::Do(float deltaTime)
	{
		if (!Loaded)
		{
			_gameManager = new GameManager(_levelPtr);
			Loaded = true;
			_levelPtr->CurrentStateName = _levelPtr->stateMachine->currentState->Name();
		}

		if (Loaded)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				_levelPtr->stateMachine->moveToState(STATE_NAME_PAUSE);
				return;
			}

			_gameManager->update(deltaTime);

		}

	}
}