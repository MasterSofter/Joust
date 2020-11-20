#include "AI.IdleRightState.h"
#include "AI.StateMachine.h"
namespace AI
{
	IdleRightState::IdleRightState(Enemy* enemy)
		: State(enemy, STATE_NAME_IDLE_RIGHT)
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
		_enemyPtr->checkedCollisions = true;
		if (_enemyPtr != nullptr && !_enemyPtr->animation.Working)
		{
			_enemyPtr->Static = false;
			_enemyPtr->checkedCollisions = true;
			_enemyPtr->switchTexture("EnemyTexture");
			_enemyPtr->setVelocity(sf::Vector2f(0, _enemyPtr->getVelocity().y));
			_enemyPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));
			_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(2, 1));
			_enemyPtr->animation.setImageCountDrawable(sf::Vector2u(1, 1));
			_enemyPtr->animation.setSwitchTime(0.4f);
			_enemyPtr->animation.Working = true;
		}

		if (this->_enemyPtr != nullptr)
		{
			//Ќадо решить куда двигатьс€
			//Ќайти разность между мной и player по x
			float directX = _enemyPtr->playergetPosition().x - _enemyPtr->getPosition().x;

			if (directX > 0)
			{
				//«анчит двигаемс€ вправо со стабильной скоростью на стабильной высоте

				//Ќадо перейти в состо€ние ходьбы вправо
				this->_enemyPtr->stateMachine->moveToState(STATE_NAME_GORIGHT);
			}
			else
			{
				//«анчит двигаемс€ влево со стабильной скоростью на стабильной высоте
				this->_enemyPtr->stateMachine->moveToState(STATE_NAME_GOLEFT);
				//Ќадо перейти в состо€ние полета влево
			}
		}

		_enemyPtr->animation.Update(sf::Vector2u(2, 1), deltaTime);
		_enemyPtr->gameObject.setTextureRect(_enemyPtr->animation.uvRect);
	}
}