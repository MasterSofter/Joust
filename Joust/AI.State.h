#pragma once
#include "defs.h"
#include "Enemy.h"
namespace AI
{
	class State
	{
	protected:
		State(Enemy* player, sf::String name);
		float _timeSwitchY = 0;
		float _timeSwitchX = 0;

	public:
		virtual ~State() PURE {}
		virtual void Do(float deltaTime) {}
		sf::String Name() { return _name; }

		bool keyRightPressed = false;
		bool keyLeftPressed = false;

	protected:
		Enemy* _enemyPtr;

	private:
		sf::String _name;
	};

	const sf::String STATE_NAME_IDLE_RIGHT = "IdleRight";
	const sf::String STATE_NAME_IDLE_LEFT = "IdleLeft";
	const sf::String STATE_NAME_GORIGHT = "GoRight";
	const sf::String STATE_NAME_GOLEFT = "GoLeft";
	const sf::String STATE_NAME_FLYRIGHT = "FlyRight";
	const sf::String STATE_NAME_FLYLEFT = "FlyLeft";
}


