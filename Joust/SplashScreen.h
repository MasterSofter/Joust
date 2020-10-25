#pragma once
#include "Scene.h"
class SplashScreen : public Scene
{
public:
						SplashScreen(sf::String name);
	virtual void		init();
	virtual void	    processEvents();
	virtual void	    update(float deltaTime);
	virtual void		run(float deltaTime);
};

