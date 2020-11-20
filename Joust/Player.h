#pragma once
#include "GameObject.h"
#include "player.IMoveble.h"
#include <map>


namespace player
{
	class StateMachine;
	class Player : public GameObject, public IMoveble 
	{
	public:
							Player(sf::String texturePath, sf::String textureSpawnPath, sf::String textureUnmountedPath);
		virtual				~Player();

	public:
		bool				isDead = false;
		Animation			animation;
		Animation			animationSpawn;
		Animation			animationUnmounted;
		StateMachine*		stateMachine;
		void				Update(float deltaTime, sf::Vector2u windowSize);
		virtual void		Spawn(sf::Vector2f spawnPos);
		virtual void		Kill();
		virtual void		move();
		virtual void		setPosition(sf::Vector2f position);
		void				switchTexture(sf::String textureName);
	private:
		sf::IntRect			rect;
		sf::Texture			_textureSpawn;
		sf::Texture			_textureUnmounted;
		sf::String			_currentTexturename = "";
	};
}









