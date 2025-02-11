#include "player.IdleRightState.h"
#include "player.StateMachine.h"
namespace player
{
	IdleRightState::IdleRightState(Player* player) : State(player, STATE_NAME_IDLE_RIGHT)
	{

	}

	IdleRightState::~IdleRightState()
	{

	}


	void IdleRightState::move()
	{
		
	}

	void IdleRightState::Do(float deltaTime)
	{
		_playerPtr->checkedCollisions = true;
		if (!_playerPtr->animation.Working)
		{
			_playerPtr->checkedCollisions = true;
			_playerPtr->Static = false;
			_playerPtr->switchTexture("PlayerTexture");
			_playerPtr->setVelocity(sf::Vector2f(0, _playerPtr->getVelocity().y));
			_playerPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));
			_playerPtr->animation.setCurrentImagePos(sf::Vector2u(2, 1));
			_playerPtr->animation.setImageCountDrawable(sf::Vector2u(1, 1));
			_playerPtr->animation.setSwitchTime(0.4f);
			_playerPtr->animation.Working = true;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			this->_playerPtr->stateMachine->moveToState(STATE_NAME_FLYRIGHT);
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			_playerPtr->stateMachine->moveToState(STATE_NAME_GOLEFT);
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			_playerPtr->stateMachine->moveToState(STATE_NAME_GORIGHT);
			return;
		}

		_playerPtr->animation.Update(sf::Vector2u(2, 1), deltaTime);
		_playerPtr->gameObject.setTextureRect(_playerPtr->animation.uvRect);
	}
}