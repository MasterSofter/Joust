#include "Scene.h"

Scene::Scene(sf::String name)
{
	_name = name;
}

Scene::~Scene()
{
	std::list<GameObject*>  _gameObjects;
	std::list<sf::Text*>	_texts;
	sf::Font			    _font;
	sf::String			    CurrentStateName;

	for (auto it = _gameObjects.begin(); it != _gameObjects.end(); it++)
		delete(*it);
	_gameObjects.clear();
}

sf::String Scene::Name()
{
	return _name;
}
