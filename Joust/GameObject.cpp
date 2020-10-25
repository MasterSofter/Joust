#include "GameObject.h"


GameObject::GameObject(const sf::String texturePath)
{
	_texture.loadFromFile(texturePath);
	gameObject.setSize(sf::Vector2f(_texture.getSize().x, _texture.getSize().y));
	gameObject.setOrigin(sf::Vector2f(_texture.getSize().x / 2, _texture.getSize().y / 2));
	gameObject.setTexture(&(_texture));

	rectBounds.setSize(gameObject.getSize());
	rectBounds.setOrigin(sf::Vector2f(_texture.getSize().x / 2, _texture.getSize().y / 2));
}

GameObject::~GameObject() {};

void GameObject::Update(float deltaTime)
{

}

void GameObject::setAccelerate(sf::Vector2f accelrate)
{
	_accelerate = accelrate;
}
sf::Vector2f GameObject::getAccelerate()
{
	return _accelerate;
}

void GameObject::setVelocity(sf::Vector2f velocity)
{
	_velocity = velocity;
}
sf::Vector2f GameObject::getVelocity()
{
	return _velocity;
}

void GameObject::setMass(float mass)
{
	_mass = mass;
}
float GameObject::getMass()
{
	return _mass;
}

void GameObject::setPosition(sf::Vector2f position)
{
	_position = position;
	this->gameObject.setPosition(position);
	this->rectBounds.setPosition(position);
}
sf::Vector2f GameObject::getPosition()
{
	return _position;
}
