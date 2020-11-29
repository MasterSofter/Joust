#pragma once
#include "Scene.h"
#include "Physics.h"


namespace level
{
	class StateMachine;
	class Level : public Scene
	{
	public:
		GameObject*			player;
		GameObject*			menuPtr;
		GameObject*			kursormenuPtr;
		sf::Text*			waveNumberText;	//“екст который будет выводитс€: Wave (номер волны)
		sf::Text*			textResumePtr;
		sf::Text*			textExitPtr;
		Physics				physics;
		StateMachine*		stateMachine;

							Level(sf::String name);
		virtual				~Level();
		virtual void		init();
		virtual void		render(sf::RenderWindow* wnd);
		virtual void	    update(float deltaTime, sf::Vector2u windowSize);
	};

}


