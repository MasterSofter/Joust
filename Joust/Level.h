#pragma once
#include "Scene.h"
#include "Physics.h"


namespace level
{
	class StateMachine;
	class Level : public Scene
	{
	private:
		

	public:
		Level(sf::String name);
		GameObject*			menuPtr;
		GameObject*			kursormenuPtr;
		sf::Text*			textResumePtr;
		sf::Text*			textExitPtr;
		Physics				physics;
		StateMachine*		stateMachine;
		virtual void		init();
		virtual void	    processEvents();
		virtual void		render(sf::RenderWindow* wnd);
		virtual void	    update(float deltaTime, sf::Vector2u windowSize);
		virtual void		run(float deltaTime, sf::Vector2u windowSize);
	};

}


