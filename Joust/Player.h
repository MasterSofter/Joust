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
		Player(sf::String texturePath, sf::String textureSpawnPath);

	public:

		Animation animation;
		Animation animationSpawn;
		StateMachine* stateMachine;
		void Update(float deltaTime, sf::Vector2u windowSize);
		virtual void setPosition(sf::Vector2f position);
		void switchTexture(sf::String textureName);
	private:
		sf::IntRect rect;
		sf::Texture _textureSpawn;
		sf::String _currentTexturename = "";

		InputManager* _inputManagerPtr;
	};
}









