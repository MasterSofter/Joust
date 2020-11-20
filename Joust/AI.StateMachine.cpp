#include "AI.StateMachine.h"
namespace AI
{
	StateMachine::StateMachine(Enemy* e)
		: enemy(e)
	{
		AddState(new SpawnState(enemy));
		AddState(new IdleRightState(enemy));
		AddState(new IdleLeftState(enemy));
		AddState(new GoRightState(enemy));
		AddState(new GoLeftState(enemy));
		AddState(new FlyRightState(enemy));
		AddState(new FlyLeftState(enemy));
		AddState(new DeathState(enemy));
	}

	void StateMachine::AddState(State* state)
	{
		states[state->Name()] = state;
	}

	StateMachine::~StateMachine()
	{
		for (std::map<sf::String, State*>::iterator it = states.begin(); it != states.end(); it++)
			delete(it->second);
		states.clear();
	}

	void StateMachine::moveToState(sf::String stateName)
	{
		currentState = states[stateName];
		this->enemy->animation.Working = false;
		this->enemy->animationSpawn.Working = false;
		this->enemy->animationUnmounted.Working = false;

	}
}