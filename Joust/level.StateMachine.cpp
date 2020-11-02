#include "level.StateMachine.h"
namespace level
{
	StateMachine::StateMachine(Level* p)
		: level(p)
	{
		AddState(new GameState(level));
		AddState(new PauseState(level));
		
	}

	void StateMachine::AddState(State* state)
	{
		states[state->Name()] = state;
	}

	StateMachine::~StateMachine()
	{
		for (std::map<sf::String, State*>::iterator it = states.begin(); it != states.end(); it++)
			delete(it->second);
	}

	void StateMachine::moveToState(sf::String stateName)
	{
		currentState = states[stateName];
		currentState->Loaded = false;
	}

	void StateMachine::Update(float deltaTime)
	{
		this->currentState->Do(deltaTime);
	}
}