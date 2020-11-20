#include "player.SpawnState.h"
#include "player.StateMachine.h"
namespace player
{
	SpawnState::SpawnState(Player* player) : State(player, STATE_NAME_SPAWN)
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
		if (!_playerPtr->animationSpawn.Working)
		{
			_playerPtr->isDead = false;
			_playerPtr->Alive = true;
			_playerPtr->switchTexture("SpawnTexture");
			_playerPtr->setVelocity(sf::Vector2f(0, 0));
			_playerPtr->gameObject.setScale(sf::Vector2f(1 / 6.f, 1));
			_playerPtr->animationSpawn.setCurrentImagePos(sf::Vector2u(0, 1));
			_playerPtr->animationSpawn.setImageCountDrawable(sf::Vector2u(6, 1));
			_playerPtr->animationSpawn.setSwitchTime(0.24f);
			_playerPtr->animationSpawn.Working = true;
		}

		if (_playerPtr->animationSpawn.getCurrentImagePos().x == 5)
		{
			_playerPtr->animationSpawn.Working = false;
			_playerPtr->stateMachine->moveToState(STATE_NAME_IDLE_RIGHT);
			return;
		}
		_playerPtr->animationSpawn.Update(sf::Vector2u(0, 1), deltaTime);
		_playerPtr->gameObject.setTextureRect(_playerPtr->animationSpawn.uvRect);
	}
}