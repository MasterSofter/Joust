#include "AI.StateMachine.h"
namespace AI
{
	StateMachine::StateMachine(Enemy* e)
		: enemy(e)
	{
		AddState(new IdleRightState(enemy));
		AddState(new IdleLeftState(enemy));
		AddState(new GoRightState(enemy));
		AddState(new GoLeftState(enemy));
		AddState(new FlyRightState(enemy));
		AddState(new FlyLeftState(enemy));
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
		this->enemy->animation.Working = false;

	}

	void StateMachine::Update(float deltaTime)
	{
		this->currentState->Do(deltaTime);
	}
}