#pragma once
#include <list>
#include <map>
#include "GameObject.h"
class Physics
{
	const char COLLISION_TYPE_BOTTOM = 1;
	const char COLLISION_TYPE_TOP = 2;
	const char COLLISION_TYPE_RIGHT = 3;
	const char COLLISION_TYPE_LEFT = 4;
	const char COLLISION_TYPE_INNERCOLLISION = 5;

	const sf::Vector2f g = sf::Vector2f(0,10.f);
private:
	GameObject*							checkCollisions(GameObject* gameObj);
	char								checkCollisionsType(GameObject* gameObj, GameObject* collisionObject);
public:
	std::map<GameObject*, sf::Vector2f> gameobjects;
public:
	void								Update(float deltaTime);
	void								addGameObject(GameObject* gameObject);
	void								setForce(GameObject* gameObject ,sf::Vector2f force);

};

