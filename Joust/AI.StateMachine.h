#pragma once

#include "Enemy.h"
#include "AI.State.h"
#include "AI.IdleLeftState.h"
#include "AI.IdleRightState.h"
#include "AI.GoRightState.h"
#include "AI.GoLeftState.h"
#include "AI.FlyRightState.h"
#include "AI.FlyLeftState.h"
#include "AI.DeathState.h"
#include "AI.SpawnState.h"

namespace AI
{
	class StateMachine
	{
		void			AddState(State* state);
	public:
						StateMachine(Enemy* enemy);
		virtual			~StateMachine();
		void			moveToState(sf::String stateName);

	public:
		std::map<sf::String, State*> states;
		State* currentState = nullptr;
		Enemy* enemy = nullptr;
	};

}

