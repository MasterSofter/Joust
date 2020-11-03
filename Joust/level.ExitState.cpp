#include "level.ExitState.h"
#include "level.StateMachine.h"
namespace level
{
	ExitState::ExitState(Level* level)
		: State(level, STATE_NAME_EXIT)
	{

	}

	ExitState::~ExitState()
	{

	}

	void ExitState::Do(float deltaTime)
	{
		if (!Loaded)
		{
			Loaded = true;
			_levelPtr->CurrentStateName = _levelPtr->stateMachine->currentState->Name();
			sf::Time time = sf::seconds(0.1f);
			sf::sleep(time);
		}

		if (Loaded)
		{

		}
	}
}
