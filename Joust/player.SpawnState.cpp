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

	void SpawnState::Do(float deltaTime)
	{
		if (_playerPtr != nullptr && !_playerPtr->animationSpawn.Working)
		{
			_playerPtr->switchTexture("SpawnTexture");
			_playerPtr->setVelocity(sf::Vector2f(0, 0));
			_playerPtr->gameObject.setScale(sf::Vector2f(1 / 6.f, 1));
			_playerPtr->animationSpawn.setCurrentImagePos(sf::Vector2u(0, 1));
			_playerPtr->animationSpawn.setImageCountDrawable(sf::Vector2u(6, 1));
			_playerPtr->animationSpawn.setSwitchTime(0.24f);
			_playerPtr->animationSpawn.Working = true;
			/*
			_playerPtr->setVelocity(sf::Vector2f(0, _playerPtr->getVelocity().y));
			_playerPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));
			_playerPtr->animation.setCurrentImagePos(sf::Vector2u(2, 1));
			_playerPtr->animation.setImageCountDrawable(sf::Vector2u(1, 1));
			_playerPtr->animation.setSwitchTime(0.4f);
			_playerPtr->animation.Working = true;
			*/
		}

		if (this->_playerPtr != nullptr)
		{
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
}