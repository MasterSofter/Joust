#pragma once
#include "level.State.h"
#include "Level.h"
#include "level.GameState.h"
#include "level.PauseState.h"
#include "level.ExitState.h"
namespace level
{
	class StateMachine
	{
		void AddState(State* state);

	public:
		StateMachine(Level* level);
		~StateMachine();
		void moveToState(sf::String stateName);
		void Update(float deltaTime);

	public:
		std::map<sf::String, State*> states;
		State* currentState = nullptr;
		Level* level = nullptr;

	};

}

