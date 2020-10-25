#include "StateMachine.h"
namespace player
{
	StateMachine::StateMachine(Player* p)
		: player(p)
	{
		AddState(new IdleRightState(player));
		AddState(new IdleLeftState(player));
		AddState(new GoRightState(player));
		AddState(new GoLeftState(player));
		AddState(new FlyRightState(player));
		AddState(new FlyLeftState(player));
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
		this->player->animation.Working = false;
	}

	void StateMachine::Update(float deltaTime)
	{
		this->currentState->Do(deltaTime);
	}
}