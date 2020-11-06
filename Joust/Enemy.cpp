#include "Enemy.h"
#include "AI.StateMachine.h"

namespace AI
{
	Enemy::Enemy(sf::String texturePath, player::Player* ptr) : GameObject(texturePath)
	{
		_player = ptr;
		rectBounds.setSize(sf::Vector2f(60, 60));
		rectBounds.setPosition(getPosition());
		animation = Animation(_texture, sf::Vector2u(7, 1), sf::Vector2u(4, 1), 0.1f);

		stateMachine = new StateMachine(this);
		stateMachine->currentState = stateMachine->states[STATE_NAME_IDLE_RIGHT];

		_mass = 160;
		_accelerate = sf::Vector2f(0, 0);
	}

	Enemy::~Enemy()
	{
		delete(stateMachine);
	}

	sf::Vector2f Enemy::playergetPosition()
	{
		return _player->getPosition();
	}

	void Enemy::move()
	{
		
	}


	void Enemy::Update(float deltaTime, sf::Vector2u windowSize)
	{
		stateMachine->currentState->move();
		stateMachine->currentState->Do(deltaTime);
	}
	void Enemy::setPosition(sf::Vector2f position)
	{
		_position = position;
		this->gameObject.setPosition(position);
		this->rectBounds.setPosition(position + sf::Vector2f(_texture.getSize().x / 2.f - 30, 0));
	}
}