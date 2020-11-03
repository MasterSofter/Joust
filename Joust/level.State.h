#pragma once
#include "Level.h"
namespace level
{
	class State
	{
	protected:
		State(Level* level, sf::String name);


	public:
		virtual ~State() {}
		virtual void Do(float deltaTime) {}
		sf::String Name() { return _name; }

		bool Loaded = false;

	protected:
		Level* _levelPtr;

	private:
		sf::String _name;
	};

	const sf::String STATE_NAME_GAME = "Game";
	const sf::String STATE_NAME_PAUSE = "Pause";
	const sf::String STATE_NAME_EXIT = "Exit";


}

