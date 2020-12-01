#include "level.StateMachine.h"
namespace level
{
	StateMachine::StateMachine(Level* p)
		: level(p)
	{
		AddState(new GameState(level));
		AddState(new PauseState(level));
		AddState(new ExitState(level));
	}

	StateMachine::~StateMachine()
	{
		for (auto it = states.begin(); it != states.end(); it++)
			delete((*it).second);
		states.clear();
	}

	void StateMachine::AddState(State* state)
	{
		states[state->Name()] = state;
	}

	void StateMachine::moveToState(sf::String stateName)
	{
		currentState = states[stateName];
	}

	void StateMachine::Update(float deltaTime)
	{
		this->currentState->Do(deltaTime);
	}
}