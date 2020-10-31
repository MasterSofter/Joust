#pragma once
#include "Scene.h"
#include "Physics.h"

namespace level
{
	class Level : public Scene
	{
	private:
		Physics physics;
		int					_stateGame = 0;
		int					_statePause = 1;
		int					_currentState;

	public:
		Level(sf::String name);
		virtual void		init();
		virtual void	    processEvents();
		virtual void	    update(float deltaTime, sf::Vector2u windowSize);
		virtual void		run(float deltaTime, sf::Vector2u windowSize);
	};

}


