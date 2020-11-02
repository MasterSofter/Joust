#pragma once
#include<SFML/Graphics.hpp>
#include"GameObject.h"
#include<list>
#include "Player.h"
#include "Enemy.h"


class Scene
{
protected:
	sf::String _name;


public:
	std::list<GameObject*> _gameObjects;
	std::list<sf::Text*>	_texts;
	sf::Font			_font;

						Scene(sf::String name);
	sf::String			Name();
	virtual void		init() = 0;
	virtual void	    processEvents() = 0;
	virtual void	    update(float deltaTime, sf::Vector2u windowSize) = 0;
	virtual void		render(sf::RenderWindow* wnd);
	virtual void		run(float deltaTime, sf::Vector2u windowSize) = 0;
};

