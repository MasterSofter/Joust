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
	std::list<GameObject*>  _gameObjects;		//Список игровых объектов на сцене
	sf::Font			    _font;				//Шрифт текста на сцене
	sf::String			    CurrentStateName;	//Текущее состояние внутри сцены

						Scene(sf::String name);
	virtual				~Scene();
	sf::String			Name();
	virtual void		init() = 0;
	virtual void	    update(float deltaTime, sf::Vector2u windowSize) = 0;
	virtual void		render(sf::RenderWindow* wnd) = 0;
};

