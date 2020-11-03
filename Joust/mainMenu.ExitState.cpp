#include "mainMenu.ExitState.h"
#include "mainMenu.StateMachine.h"
namespace mainMenu
{
	ExitState::ExitState(MainMenu* mainMenu)
		: State(mainMenu, STATE_NAME_EXIT)
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
			_mainMenuPtr->CurrentStateName = _mainMenuPtr->stateMachine->currentState->Name();
		}

		if (Loaded)
		{

		}
	}
}
