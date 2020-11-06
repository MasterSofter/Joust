#include "AI.GoRightState.h"
#include "AI.StateMachine.h"
namespace AI
{
	GoRightState::GoRightState(Enemy* enemy)
		: State(enemy, STATE_NAME_GORIGHT)
	{

	}

	GoRightState::~GoRightState()
	{

	}


	void GoRightState::move()
	{
		_enemyPtr->setVelocity(sf::Vector2f(80, _enemyPtr->getVelocity().y));
	}

	void GoRightState::Do(float deltaTime)
	{
		if (_enemyPtr != nullptr && !_enemyPtr->animation.Working)
		{
			_enemyPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
			_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(4, 1));
			_enemyPtr->animation.setImageCountDrawable(sf::Vector2u(1, 1));
			_enemyPtr->animation.setSwitchTime(0.2f);
			_enemyPtr->setVelocity(_enemyPtr->getVelocity() + sf::Vector2f(2, 0));

			if (_enemyPtr->getVelocity().x >= 0)
			{
				_enemyPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));
				_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(0, 1));
				_enemyPtr->animation.setImageCountDrawable(sf::Vector2u(4, 1));
				_enemyPtr->animation.setSwitchTime(0.2f);
				_enemyPtr->animation.Working = true;
			}
		}

		if (_enemyPtr != nullptr)
		{
			bool Space = false;
			float deltaX = _enemyPtr->playergetPosition().x - _enemyPtr->getPosition().x;

			Space = true;
			if (Space && deltaX > 0)
			{
				this->_enemyPtr->stateMachine->moveToState(STATE_NAME_FLYRIGHT);
				return;
			}
			else
				if (Space)
				{
					this->_enemyPtr->stateMachine->moveToState(STATE_NAME_FLYLEFT);
					return;
				}

			_enemyPtr->animation.Update(sf::Vector2u(0, 1), deltaTime);
			_enemyPtr->gameObject.setTextureRect(_enemyPtr->animation.uvRect);
		}

	}
}
