#pragma once
#include "Scene.h"
class MainMenu : public Scene
{
public:
						MainMenu(sf::String name);
	virtual void		init();
	virtual void	    processEvents();
	virtual void	    update(float deltaTime);
	virtual void		run(float deltaTime);
};

