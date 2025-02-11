#include "Player.h"
#include<iostream>
#include<string>
#include "player.StateMachine.h"

namespace player
{
	Player::Player(sf::String texturePath, sf::String textureSpawnPath, sf::String textureUnmountedPath) : GameObject(texturePath)
	{
		rectBounds.setSize(sf::Vector2f(60, 60));
		rectBounds.setPosition(getPosition());

		animation = Animation(_texture, sf::Vector2u(7, 1), sf::Vector2u(4, 1), 0.1f);

		_textureSpawn.loadFromFile(textureSpawnPath);
		animationSpawn = Animation(_textureSpawn, sf::Vector2u(6, 1), sf::Vector2u(6, 1), 0.2f);

		_textureUnmounted.loadFromFile(textureUnmountedPath);
		animationUnmounted = Animation(_textureUnmounted, sf::Vector2u(7, 1), sf::Vector2u(2, 1), 0.1f);

		stateMachine = new StateMachine(this);
		stateMachine->currentState = stateMachine->states[STATE_NAME_SPAWN];
		
		_mass = 160;
		_accelerate = sf::Vector2f(0, 0);
	}

	Player::~Player()
	{
		delete(stateMachine);
	}


	void Player::switchTexture(sf::String textureName)
	{
		if (_currentTexturename != textureName && textureName == "SpawnTexture")
		{
			_currentTexturename = textureName;
			gameObject.setSize(sf::Vector2f(_textureSpawn.getSize().x, _textureSpawn.getSize().y));
			gameObject.setOrigin(sf::Vector2f(_textureSpawn.getSize().x / 2, _textureSpawn.getSize().y / 2));
			gameObject.setTexture(&(_textureSpawn));

			rectBounds.setSize(sf::Vector2f(gameObject.getSize().x / 6, gameObject.getSize().y));
			rectBounds.setOrigin(sf::Vector2f(_textureSpawn.getSize().x / 2, _textureSpawn.getSize().y / 2));
		}

		if (_currentTexturename != textureName && textureName == "PlayerTexture")
		{
			_currentTexturename = textureName;
			gameObject.setSize(sf::Vector2f(_texture.getSize().x, _texture.getSize().y));
			gameObject.setOrigin(sf::Vector2f(_texture.getSize().x / 2, _texture.getSize().y / 2));
			gameObject.setTexture(&(_texture));

			rectBounds.setSize(sf::Vector2f(gameObject.getSize().x/7, gameObject.getSize().y));
			rectBounds.setOrigin(sf::Vector2f(_texture.getSize().x / 2, _texture.getSize().y / 2));
		}

		if (_currentTexturename != textureName && textureName == "UnmountedPlayerTexture")
		{
			_currentTexturename = textureName;
			gameObject.setSize(sf::Vector2f(_textureUnmounted.getSize().x, _textureUnmounted.getSize().y));
			gameObject.setOrigin(sf::Vector2f(_textureUnmounted.getSize().x / 2, _textureUnmounted.getSize().y / 2));
			gameObject.setTexture(&(_textureUnmounted));

			rectBounds.setSize(sf::Vector2f(gameObject.getSize().x / 7, gameObject.getSize().y));
			rectBounds.setOrigin(sf::Vector2f(_textureUnmounted.getSize().x / 2, _textureUnmounted.getSize().y / 2));
		}
	}


	void Player::Spawn(sf::Vector2f spawnPos)
	{
		setPosition(spawnPos);
		this->stateMachine->moveToState(STATE_NAME_SPAWN);
	}

	void Player::Kill()
	{
		this->stateMachine->moveToState(STATE_NAME_DEATH);
	}

	void Player::move()
	{
		stateMachine->currentState->move();
	}

	void Player::Update(float deltaTime, sf::Vector2u windowSize)
	{
		stateMachine->currentState->Do(deltaTime);
		move();
	}

	void Player::setPosition(sf::Vector2f position)
	{
		_position = position;
		this->gameObject.setPosition(position);
		this->rectBounds.setPosition(position + sf::Vector2f(_texture.getSize().x/2.f - 30,0));
	}
}
