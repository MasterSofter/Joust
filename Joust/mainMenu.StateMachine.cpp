#include "mainMenu.StateMachine.h"
namespace mainMenu
{
	StateMachine::StateMachine(MainMenu* p)
		: mainMenu(p)
	{
		AddState(new MenuState(mainMenu));
		AddState(new LoadLevelState(mainMenu));
		AddState(new ExitState(mainMenu));
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
		currentState->Loaded = false;
	}

	void StateMachine::Update(float deltaTime)
	{
		this->currentState->Do(deltaTime);
	}
}