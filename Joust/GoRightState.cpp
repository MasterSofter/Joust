#include "GoRightState.h"
#include "StateMachine.h"
namespace player
{
	GoRightState::GoRightState(Player* player)
		: State(player, STATE_NAME_GORIGHT)
	{
	}

	GoRightState::~GoRightState()
	{
	
	}

	void GoRightState::Do(float deltaTime)
	{
		if (_playerPtr != nullptr && !_playerPtr->animation.Working)
		{
			_playerPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
			_playerPtr->animation.setCurrentImagePos(sf::Vector2u(4, 1));
			_playerPtr->animation.setImageCountDrawable(sf::Vector2u(1, 1));
			_playerPtr->animation.setSwitchTime(0.4f);
			_playerPtr->setVelocity(_playerPtr->getVelocity() + sf::Vector2f(2, 0));

			if (_playerPtr->getVelocity().x >= 0)
			{
				_playerPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));
				_playerPtr->animation.setCurrentImagePos(sf::Vector2u(0, 1));
				_playerPtr->animation.setImageCountDrawable(sf::Vector2u(4, 1));
				_playerPtr->animation.setSwitchTime(0.4f);
				_playerPtr->animation.Working = true;
			}
		}

		if (_playerPtr != nullptr)
		{
			if (abs(_playerPtr->getVelocity().x) < 2)
			{
				this->_playerPtr->stateMachine->moveToState(STATE_NAME_IDLE_RIGHT);
				return;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _playerPtr->animation.getSwitchTime() > 0.05)
			{
				_playerPtr->animation.setSwitchTime(_playerPtr->animation.getSwitchTime() - 0.001f);
				_playerPtr->setVelocity(_playerPtr->getVelocity() + sf::Vector2f(2, 0));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				this->_playerPtr->stateMachine->moveToState(STATE_NAME_FLYRIGHT);
				return;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				this->_playerPtr->stateMachine->moveToState(STATE_NAME_GOLEFT);
				return;
			}

			_playerPtr->animation.Update(sf::Vector2u(0, 1), deltaTime);
			_playerPtr->gameObject.setTextureRect(_playerPtr->animation.uvRect);
		}

	}
}