#include "FlyLeftState.h"
#include"StateMachine.h"
namespace player
{

	FlyLeftState::FlyLeftState(Player* player)
		: State(player, STATE_NAME_FLYLEFT)
	{

	}

	FlyLeftState::~FlyLeftState()
	{

	}

	void FlyLeftState::Do(float deltaTime)
	{
		if (_playerPtr != nullptr && !_playerPtr->animation.Working)
		{
			_playerPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
			_playerPtr->animation.setCurrentImagePos(sf::Vector2u(6, 1));
			_playerPtr->animation.setImageCountDrawable(sf::Vector2u(2, 1));
			_playerPtr->animation.setSwitchTime(0.4f);

			if (_playerPtr->getVelocity().y < 0)
			{
				_playerPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
				_playerPtr->animation.setCurrentImagePos(sf::Vector2u(5, 1));
				_playerPtr->animation.setImageCountDrawable(sf::Vector2u(2, 1));
				_playerPtr->animation.setSwitchTime(0.4f);
				_playerPtr->animation.Working = true;
			}
		}

		if (_playerPtr != nullptr)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				_playerPtr->setVelocity(sf::Vector2f(_playerPtr->getVelocity().x, -200));

				_playerPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
				_playerPtr->animation.setCurrentImagePos(sf::Vector2u(5, 1));
				_playerPtr->animation.setImageCountDrawable(sf::Vector2u(2, 1));
				_playerPtr->animation.setSwitchTime(0.1f);
				_playerPtr->animation.Working = true;
			}

			_playerPtr->animation.Update(sf::Vector2u(6, 1), deltaTime);
			_playerPtr->gameObject.setTextureRect(_playerPtr->animation.uvRect);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			_playerPtr->setVelocity(_playerPtr->getVelocity() + sf::Vector2f(-2, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->_playerPtr->stateMachine->moveToState(STATE_NAME_FLYRIGHT);
			return;
		}

		if (_playerPtr->Grounded)
			this->_playerPtr->stateMachine->moveToState(STATE_NAME_GOLEFT);


	}


}