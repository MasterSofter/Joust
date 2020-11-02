#pragma once
#include "Scene.h"
class MainMenu : public Scene
{
public:
	GameObject*			menuPtr;
	GameObject*			kursormenuPtr;
	sf::Text*			textPlayPtr;
	sf::Text*			textExitPtr;
						MainMenu(sf::String name);
	virtual void		init();
	virtual void	    processEvents();
	virtual void		render(sf::RenderWindow* wnd);
	virtual void	    update(float deltaTime, sf::Vector2u windowSize);
	virtual void		run(float deltaTime, sf::Vector2u windowSize);
};

