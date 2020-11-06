#pragma once
#include "Scene.h"
namespace mainMenu
{
	class StateMachine;
	class MainMenu : public Scene
	{
	public:
		StateMachine*		stateMachine;
		GameObject*			menuPtr;
		GameObject*			kursormenuPtr;
		sf::Text*			textJoustPtr;
		sf::Text*			textPlayPtr;
		sf::Text*			textExitPtr;
							MainMenu(sf::String name);
		virtual				~MainMenu();
		virtual void		init();
		virtual void		render(sf::RenderWindow* wnd);
		virtual void	    update(float deltaTime, sf::Vector2u windowSize);
	};
}
