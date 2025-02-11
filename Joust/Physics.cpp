#include "Physics.h"
#include<iterator>
#include<math.h>
#include<iostream>

void Physics::Update(float deltaTime)
{
	setlocale(LC_ALL, "RUSSIAN");
	for (std::map<GameObject*, sf::Vector2f> ::iterator it = gameobjects.begin(); it != gameobjects.end(); it++)
	{
		if (!(it->first->Static) && checkCollisions(it->first) == nullptr)
		{
			it->first->Grounded = false;

			sf::Vector2f F = (it->first->getMass() * g) + it->second;
			sf::Vector2f a = F / it->first->getMass();
			sf::Vector2f v = it->first->getVelocity() + a * deltaTime * 100.f;
			sf::Vector2f r = it->first->getPosition() + v * deltaTime + a * (deltaTime * deltaTime) / 2.f;

			it->first->setPosition(r);
			it->first->setVelocity(v);
		}
		else if(!(it->first->Static))
		{
			char typeColision = checkCollisionsType(it->first, checkCollisions(it->first));

			

			if (typeColision == COLLISION_TYPE_TOP)
			{
				it->first->setVelocity(sf::Vector2f(it->first->getVelocity().x, abs(it->first->getVelocity().y)));
				it->first->Grounded = false;
			}
			else
			if (typeColision == COLLISION_TYPE_BOTTOM && it->first->getVelocity().y >= 0)
			{
				it->first->setVelocity(sf::Vector2f(it->first->getVelocity().x, 0));
				it->first->Grounded = true;			
			}

			sf::Vector2f v = it->first->getVelocity();
			sf::Vector2f r = it->first->getPosition() + v * deltaTime;

			it->first->setPosition(r);
			it->first->setVelocity(v);

		}


		if (!(it->first->Static))
		{
			if (it->first->getVelocity().x > 160)
				it->first->setVelocity(sf::Vector2f(160, it->first->getVelocity().y));

			if (it->first->getVelocity().x < -160)
				it->first->setVelocity(sf::Vector2f(-160, it->first->getVelocity().y));

			if (it->first->getPosition().y > 600)
				it->first->Kill();


			if (it->first->Name == "Enemy")
			{
				GameObject* obj;
				obj = checkCollisions(it->first);
				if (obj != nullptr && obj->Name == "Player" && it->first->checkedCollisions &&it->first->getPosition().y < obj->getPosition().y)
				{
					obj->Kill();
				}
			}

			if (it->first->Name == "Player")
			{
				GameObject* obj;
				obj = checkCollisions(it->first);
				if (obj != nullptr && obj->Name == "Enemy" && it->first->checkedCollisions &&it->first->getPosition().y < obj->getPosition().y)
				{
					obj->Kill();
				}
			}
		}
		
	}
}

void Physics::setForce(GameObject* gameObject, sf::Vector2f force)
{
	this->gameobjects[gameObject] = force;
}

void Physics::addGameObject(GameObject* gameObject)
{
	std::pair<GameObject*, sf::Vector2f> pair;
	pair.first = gameObject;
	pair.second = sf::Vector2f(0, 0);
	this->gameobjects.insert(pair);
}

char Physics::checkCollisionsType(GameObject* gameObj, GameObject* collisionObject)
{
	double deltaY = collisionObject->getPosition().y - gameObj->getPosition().y;
	double deltaX = collisionObject->getPosition().x - gameObj->getPosition().x;

	if (deltaY > 0 && (collisionObject->getPosition().x - collisionObject->rectBounds.getSize().x / 2 < gameObj->getPosition().x < collisionObject->getPosition().x + collisionObject->rectBounds.getSize().x / 2))
		return COLLISION_TYPE_BOTTOM;

	if (deltaY <= 0 && (collisionObject->getPosition().x - collisionObject->rectBounds.getSize().x / 2 < gameObj->getPosition().x < collisionObject->getPosition().x + collisionObject->rectBounds.getSize().x / 2))
		return	COLLISION_TYPE_TOP;


	if (gameObj->getVelocity().x > 0 && gameObj->getVelocity().y < 0)
		return COLLISION_TYPE_RIGHT;
	if (gameObj->getVelocity().x < 0 && gameObj->getVelocity().y < 0)
		return COLLISION_TYPE_LEFT;

	return -1;


}


GameObject* Physics::checkCollisions(GameObject* gameObj)
{
	for (auto it = gameobjects.begin(); it != gameobjects.end(); it++)
	{
		if (it->first != gameObj && it->first->checkedCollisions)
		{
			sf::FloatRect gameObjRect = gameObj->rectBounds.getGlobalBounds();
			sf::FloatRect rectBounds = (*it).first->rectBounds.getGlobalBounds();

			if (gameObjRect.intersects(rectBounds))
			{
				return it->first;
			}
		}
	}

	return nullptr;

}

