#include "AI.FlyLeftState.h"
#include "AI.StateMachine.h"
namespace AI
{
	FlyLeftState::FlyLeftState(Enemy* enemy)
		: State(enemy, STATE_NAME_FLYLEFT)
	{

	}

	FlyLeftState::~FlyLeftState()
	{

	}

	void FlyLeftState::Do(float deltaTime)
	{

		if (_enemyPtr != nullptr && !_enemyPtr->animation.Working)
		{
			_timeSwitchY = 0.4f;
			_enemyPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
			_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(6, 1));
			_enemyPtr->animation.setImageCountDrawable(sf::Vector2u(2, 1));
			_enemyPtr->animation.setSwitchTime(0.4f);

			if (_enemyPtr->getVelocity().y < 0)
			{
				_enemyPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
				_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(5, 1));
				_enemyPtr->animation.setImageCountDrawable(sf::Vector2u(2, 1));
				_enemyPtr->animation.setSwitchTime(0.4f);
				_enemyPtr->animation.Working = true;
			}
		}
		if (_enemyPtr != nullptr)
		{

			_enemyPtr->setVelocity(_enemyPtr->getVelocity() + sf::Vector2f(-1.2f, 0));

			float deltaX = _enemyPtr->playergetPosition().x - _enemyPtr->getPosition().x;
			if (deltaX > 0 && _timeSwitchX >= 0.4f)
			{
				_timeSwitchX = 0.f;
				this->_enemyPtr->stateMachine->moveToState(STATE_NAME_FLYRIGHT);
				return;
			}


			float deltaY = _enemyPtr->playergetPosition().y - _enemyPtr->getPosition().y;
			if (_timeSwitchY >= 0.4f && deltaY > 0 )
			{
				_timeSwitchY = 0.f;
				_enemyPtr->setVelocity(sf::Vector2f(_enemyPtr->getVelocity().x, -180));

				_enemyPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
				_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(5, 1));
				_enemyPtr->animation.setImageCountDrawable(sf::Vector2u(2, 1));
				_enemyPtr->animation.setSwitchTime(0.2f);
				_enemyPtr->animation.Working = true;
			}
			else if (_timeSwitchY >= 0.4f && _enemyPtr->getPosition().y > 0)
			{
				_timeSwitchY = 0.f;
				_enemyPtr->setVelocity(sf::Vector2f(_enemyPtr->getVelocity().x, -330));

				_enemyPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
				_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(5, 1));
				_enemyPtr->animation.setImageCountDrawable(sf::Vector2u(2, 1));
				_enemyPtr->animation.setSwitchTime(0.2f);
				_enemyPtr->animation.Working = true;
			}

			_enemyPtr->animation.Update(sf::Vector2u(6, 1), deltaTime);
			_enemyPtr->gameObject.setTextureRect(_enemyPtr->animation.uvRect);

			_timeSwitchY += 0.002f;
			_timeSwitchX += 0.0005f;
		}

		}

}


