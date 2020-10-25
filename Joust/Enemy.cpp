#include "Enemy.h"
namespace AI
{
	Enemy::Enemy(sf::String texturePath) : GameObject(texturePath)
	{
	}

	void Enemy::Update(float deltaTime)
	{
	
	}
	void Enemy::setPosition(sf::Vector2f position)
	{
		_position = position;
		this->gameObject.setPosition(position);
		this->rectBounds.setPosition(position + sf::Vector2f(_texture.getSize().x / 2.f - 30, 0));
	}
}