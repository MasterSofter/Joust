#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"

class GameObject
{
public:
	GameObject(const sf::String texturePath);
	~GameObject();

	virtual void		Update(float deltaTime, sf::Vector2u windowSize);
	virtual void		Spawn(sf::Vector2f spawnPos);
	virtual void		Kill();

	virtual void		setPosition(sf::Vector2f position);
	sf::Vector2f		getPosition();

	void				setAccelerate(sf::Vector2f accelerate);
	sf::Vector2f		getAccelerate();

	void				setVelocity(sf::Vector2f velocity);
	sf::Vector2f		getVelocity();
	
	void				setMass(float mass);
	float				getMass();

	bool				checkedCollisions = true;


public:

	bool				Static = false;
	bool				Grounded = false;
	bool				Alive = true;
	int					lifes = 1;
	sf::String			Name = "";
	sf::RectangleShape  gameObject;
	sf::RectangleShape  rectBounds;
	sf::Text			text;

protected:

	sf::Texture _texture;
	sf::Vector2f _position;
	float _mass;
	sf::Vector2f _accelerate = sf::Vector2f(0, 0);
	sf::Vector2f _velocity = sf::Vector2f(0,0);
};

