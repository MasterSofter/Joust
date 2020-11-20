#include "player.DeathState.h"
namespace player
{
	DeathState::DeathState(Player* player)
		: State(player, STATE_NAME_DEATH)
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
		_playerPtr->checkedCollisions = false;
		if (!_playerPtr->animationUnmounted.Working)
		{
			_playerPtr->checkedCollisions = false;
			_playerPtr->isDead = true;
			_playerPtr->switchTexture("UnmountedPlayerTexture");

			if(_playerPtr->getPosition().x < 400)
				_playerPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
			else
				_playerPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));
			_playerPtr->animationUnmounted.setCurrentImagePos(sf::Vector2u(6, 1));
			_playerPtr->animationUnmounted.setImageCountDrawable(sf::Vector2u(2, 1));
			_playerPtr->animationUnmounted.setSwitchTime(0.4f);

			if (_playerPtr->getVelocity().y < 0)
			{
				if (_playerPtr->getPosition().x < 400)
					_playerPtr->gameObject.setScale(sf::Vector2f(-1 / 7.f, 1));
				else
					_playerPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));

				_playerPtr->animation.setCurrentImagePos(sf::Vector2u(5, 1));
				_playerPtr->animationUnmounted.setImageCountDrawable(sf::Vector2u(2, 1));
				_playerPtr->animationUnmounted.setSwitchTime(0.4f);
				_playerPtr->animationUnmounted.Working = true;
			}
		}


		if (switchedY >= 0.4f)
		{
			switchedY = 0.f;
			if (_playerPtr->getPosition().x < 400)
				_playerPtr->setVelocity(sf::Vector2f(-80, -180));
			else
				_playerPtr->setVelocity(sf::Vector2f(80, -180));

			_playerPtr->animationUnmounted.setCurrentImagePos(sf::Vector2u(5, 1));
			_playerPtr->animationUnmounted.setImageCountDrawable(sf::Vector2u(2, 1));
			_playerPtr->animationUnmounted.setSwitchTime(0.2f);
			_playerPtr->animationUnmounted.Working = true;
		}

		// —бросить жизнь 
		if (_playerPtr->getPosition().x < 0 || _playerPtr->getPosition().x > 800)
		{
			_playerPtr->Alive = false;
			_playerPtr->lifes -= 1;
		}

		_playerPtr->animationUnmounted.Update(sf::Vector2u(6, 1), deltaTime);
		_playerPtr->gameObject.setTextureRect(_playerPtr->animationUnmounted.uvRect);
		switchedY += 0.006f;
	}
}