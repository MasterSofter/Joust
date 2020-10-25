#include "Player.h"
#include<iostream>
#include<string>
#include "StateMachine.h"
#include "InputManager.h"

namespace player
{
	Player::Player(sf::String texturePath) : GameObject(texturePath)
	{
		rectBounds.setSize(sf::Vector2f(60, 60));
		rectBounds.setPosition(getPosition());
;		animation = Animation(_texture, sf::Vector2u(7, 1), sf::Vector2u(4, 1), 0.1f);;

		stateMachine = new StateMachine(this);
		stateMachine->currentState = stateMachine->states[STATE_NAME_IDLE_RIGHT];
		
		_inputManagerPtr = new InputManager(this);
		_mass = 160;
		_accelerate = sf::Vector2f(0, 0);
	}

	void Player::Update(float deltaTime)
	{
		stateMachine->Update(deltaTime);
	}

	void Player::setPosition(sf::Vector2f position)
	{
		_position = position;
		this->gameObject.setPosition(position);
		this->rectBounds.setPosition(position + sf::Vector2f(_texture.getSize().x/2.f - 30,0));
	}
}
