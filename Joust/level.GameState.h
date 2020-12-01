#pragma once
#include "level.State.h"
#include <ctime>
#include <cstdlib>
#include <string.h>
namespace level
{
	class ControlView
	{
	protected:
		float updateTime = 16;
		float currentTime = 0;
		Level* levelPtr;
	public:
		ControlView();
		ControlView(Level* level);
		virtual void view() = 0;
	};

	class PlayerScoreView : public ControlView
	{
	public:
		virtual void view();
	};

	class PlayerLifesView : public ControlView
	{
		int lastLifes;
		GameObject* lifes[5];
	public:
		PlayerLifesView();
		PlayerLifesView(Level* level);
		virtual void view();
	};

	class GameManager
	{
		PlayerLifesView playerLifesView;
		float spawnTimeEnemy = 0;
		float timeLoadLevel = 0;	//Время загрузки уровня
		int currentWave = 1;		//Текущая волна
		int countEnemies = 0;		//Кол-во монстров в текущей волне
		int random(int A, int B);
		Level* levelPtr;

		sf::Vector2f positions[4] = { {360, 472}, {157, 108}, {690, 148}, {574, 328} };

		bool findEnemy();
		void updateEnemies();
	public:
		GameManager(Level* levelPtr);
		void spawnEnemy();		//Возрождение врага в рандомном месте
		void spawnPlayer();		//Возрождение игрока в рандомном месте
		bool showTextWave();	//Загружает следующий уровень
		/*Показывает текст Wave (номер волны)
		  Обновляет счетчик кол-ва монстров на экране
		*/
		void update(float deltaTime);			//Обновляет игру

	};

	class GameState : public State
	{
		GameManager* _gameManager;
	public:
						GameState(Level* level);
		virtual			~GameState();
		void			Do(float deltaTime);
	};


}
