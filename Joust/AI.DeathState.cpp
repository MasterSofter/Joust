#include "AI.DeathState.h"
namespace AI
{
	DeathState::DeathState(Enemy* enemy) : State(enemy, STATE_NAME_DEATHSTATE)
	{
	
	}
	DeathState::~DeathState()
	{
	
	}

	void DeathState::move()
	{

	}

	void DeathState::Do(float deltaTime)
	{
		_enemyPtr->checkedCollisions = false;
		if (!_enemyPtr->animationUnmounted.Working)
		{
			_enemyPtr->checkedCollisions = false;
			_enemyPtr->isDead = false;
			_enemyPtr->switchTexture("UnmountedEnemyTexture");

			if (_enemyPtr->getPosition().x < 400)
				_enemyPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
			else
				_enemyPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));
			_enemyPtr->animationUnmounted.setCurrentImagePos(sf::Vector2u(6, 1));
			_enemyPtr->animationUnmounted.setImageCountDrawable(sf::Vector2u(2, 1));
			_enemyPtr->animationUnmounted.setSwitchTime(0.4f);

			if (_enemyPtr->getVelocity().y < 0)
			{
				if (_enemyPtr->getPosition().x < 400)
					_enemyPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
				else
					_enemyPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));

				_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(5, 1));
				_enemyPtr->animationUnmounted.setImageCountDrawable(sf::Vector2u(2, 1));
				_enemyPtr->animationUnmounted.setSwitchTime(0.4f);
				_enemyPtr->animationUnmounted.Working = true;
			}
		}


		if (switchedY >= 0.4f)
		{
			switchedY = 0.f;
			if (_enemyPtr->getPosition().x < 400)
				_enemyPtr->setVelocity(sf::Vector2f(-80, -180));
			else
				_enemyPtr->setVelocity(sf::Vector2f(80, -180));

			_enemyPtr->animationUnmounted.setCurrentImagePos(sf::Vector2u(5, 1));
			_enemyPtr->animationUnmounted.setImageCountDrawable(sf::Vector2u(2, 1));
			_enemyPtr->animationUnmounted.setSwitchTime(0.2f);
			_enemyPtr->animationUnmounted.Working = true;
		}

		// —бросить жизнь 
		if (_enemyPtr->getPosition().x < 0 || _enemyPtr->getPosition().x > 800)
		{
			_enemyPtr->Alive = false;
			_enemyPtr->lifes -= 1;
		}

		_enemyPtr->animationUnmounted.Update(sf::Vector2u(6, 1), deltaTime);
		_enemyPtr->gameObject.setTextureRect(_enemyPtr->animationUnmounted.uvRect);
		switchedY += 0.006f;
	}



}
