#pragma once
#include "Scene.h"
class SplashScreen : public Scene
{
public:
						SplashScreen(sf::String name);
	virtual void		init();
	virtual void	    processEvents();
	virtual void	    update(float deltaTime, sf::Vector2u windowSize);
	virtual void		run(float deltaTime, sf::Vector2u windowSize);
};

