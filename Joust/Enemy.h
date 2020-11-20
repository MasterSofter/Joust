#pragma once
#include "GameObject.h"
#include "Player.h"
#include "AI.IMoveble.h"

namespace AI
{
	class StateMachine;
	class Enemy : public GameObject, public IMoveble
	{
	public:
										Enemy(sf::String texturePath, sf::String spawnTexturePath ,sf::String textureUnmountedPath , player::Player* ptr);
		virtual							~Enemy();
	public:
		Animation						 animation;
		Animation					     animationSpawn;
		Animation						 animationUnmounted;
		sf::Texture						 _textureSpawn;
		sf::Texture						 _textureUnmounted;
		StateMachine* stateMachine;
		void							 Update(float deltaTime, sf::Vector2u windowSize);
		bool						     isDead = false;
		virtual void					 setPosition(sf::Vector2f position);
		virtual void					 Spawn(sf::Vector2f spawnPos);
		virtual void					 move();
		virtual void					 Kill();
		sf::Vector2f					 playergetPosition();
		void							 switchTexture(sf::String textureName);
		sf::Vector2u _windowSize;
	private:
		sf::IntRect						 rect;
		player::Player*					 _player;
		sf::String						_currentTexturename;

	};
}


