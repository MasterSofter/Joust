#pragma once
#include "defs.h"
#include "Player.h"

namespace player
{
	class State
	{
	protected:
		State(Player* player, sf::String name);

	public:
		virtual ~State() PURE {}
		virtual void Do(float deltaTime){}
		sf::String Name() { return _name; }

		bool keyRightPressed = false;
		bool keyLeftPressed = false;

	protected:
		Player* _playerPtr;

	private:
		sf::String _name;
	};

	const sf::String STATE_NAME_IDLE_RIGHT = "IdleRight";
	const sf::String STATE_NAME_IDLE_LEFT = "IdleLeft";
	const sf::String STATE_NAME_GORIGHT = "GoRight";
	const sf::String STATE_NAME_GOLEFT = "GoLeft";
	const sf::String STATE_NAME_FLYRIGHT = "FlyRight";
	const sf::String STATE_NAME_FLYLEFT = "FlyLeft";
	const sf::String STATE_NAME_SPAWN = "Spawn";

}
