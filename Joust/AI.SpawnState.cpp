#include "AI.SpawnState.h"
#include "AI.StateMachine.h"
namespace AI
{
	SpawnState::SpawnState(Enemy* enemy) : State(enemy, STATE_NAME_SPAWN)
	{
	
	}
	SpawnState::~SpawnState()
	{
	
	}

	void SpawnState::move()
	{

	}

	void SpawnState::Do(float deltaTime)
	{
		if (!_enemyPtr->animationSpawn.Working)
		{
			_enemyPtr->Static = true;
			_enemyPtr->checkedCollisions = false;
			_enemyPtr->isDead = false;
			_enemyPtr->Alive = true;
			_enemyPtr->switchTexture("SpawnTexture");
			_enemyPtr->setVelocity(sf::Vector2f(0, 0));
			_enemyPtr->gameObject.setScale(sf::Vector2f(1 / 6.f, 1));
			_enemyPtr->animationSpawn.setCurrentImagePos(sf::Vector2u(0, 1));
			_enemyPtr->animationSpawn.setImageCountDrawable(sf::Vector2u(6, 1));
			_enemyPtr->animationSpawn.setSwitchTime(0.24f);
			_enemyPtr->animationSpawn.Working = true;
		}

		if (_enemyPtr->animationSpawn.getCurrentImagePos().x == 5)
		{
			_enemyPtr->animationSpawn.Working = false;
			_enemyPtr->stateMachine->moveToState(STATE_NAME_IDLE_RIGHT);
			return;
		}
		_enemyPtr->animationSpawn.Update(sf::Vector2u(0, 1), deltaTime);
		_enemyPtr->gameObject.setTextureRect(_enemyPtr->animationSpawn.uvRect);
	}


}
