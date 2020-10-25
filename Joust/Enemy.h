#pragma once
#include "GameObject.h"

namespace AI
{
	class StateMachine;
	class Enemy : public GameObject
	{
	public:
		Enemy(sf::String texturePath);
	public:
		Animation						 animation;
		StateMachine* stateMachine;
		void							 Update(float deltaTime);
		virtual void					 setPosition(sf::Vector2f position);
	private:
		sf::IntRect						 rect;

	};
}


