#pragma once
#include<SFML/Graphics.hpp>
#include"GameObject.h"
#include<list>

class Scene
{
protected:
	sf::String _name;


public:
	std::list<GameObject*> _gameObjects;

						Scene(sf::String name);
	sf::String			Name();
	virtual void		init() = 0;
	virtual void	    processEvents() = 0;
	virtual void	    update(float deltaTime) = 0;
	virtual void		run(float deltaTime) = 0;
};

