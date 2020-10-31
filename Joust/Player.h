#pragma once
#include "GameObject.h"
#include <map>


namespace player
{
	class StateMachine;
	class InputManager;

	class Player :public GameObject
	{
	public:
		Player(sf::String texturePath);

	public:

		Animation animation;
		StateMachine* stateMachine;
		void Update(float deltaTime, sf::Vector2u windowSize);
		virtual void setPosition(sf::Vector2f position);
	private:
		sf::IntRect rect;

		InputManager* _inputManagerPtr;
	};
}









