#pragma once
#include "level.State.h"
#include <ctime>
#include <cstdlib>
#include <string.h>
namespace level
{
	class GameManager
	{
		float spawnTimeEnemy = 0;
		float timeLoadLevel = 0;	//����� �������� ������
		int currentWave = 1;		//������� �����
		int countEnemies = 0;		//���-�� �������� � ������� �����
		int random(int A, int B);
		Level* levelPtr;

		sf::Vector2f positions[4] = { {360, 472}, {157, 108}, {690, 148}, {574, 328} };

		bool findEnemy();
		void updateEnemies();
	public:
		GameManager(Level* levelPtr);
		void spawnEnemy();		//����������� ����� � ��������� �����
		void spawnPlayer();		//����������� ������ � ��������� �����
		bool showTextWave();	//��������� ��������� �������
		/*���������� ����� Wave (����� �����)
		  ��������� ������� ���-�� �������� �� ������
		*/
		void update(float deltaTime);			//��������� ����

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
