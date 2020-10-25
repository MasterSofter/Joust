#include "Scene.h"

Scene::Scene(sf::String name)
{
	_name = name;
}

sf::String Scene::Name()
{
	return _name;
}