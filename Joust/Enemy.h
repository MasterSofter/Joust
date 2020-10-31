#pragma once
#include "GameObject.h"
#include "Player.h"

namespace AI
{
	class StateMachine;
	class Enemy : public GameObject
	{
	public:
		Enemy(sf::String texturePath, player::Player* ptr);
	public:
		Animation						 animation;
		StateMachine* stateMachine;
		void							 Update(float deltaTime, sf::Vector2u windowSize);
		virtual void					 setPosition(sf::Vector2f position);
		sf::Vector2f					 playergetPosition();
		sf::Vector2u _windowSize;
	private:
		sf::IntRect						 rect;
		player::Player*					 _player;

	};
}


