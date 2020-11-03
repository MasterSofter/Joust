#include "mainMenu.LoadLevelState.h"
#include "mainMenu.StateMachine.h"
namespace mainMenu
{
	LoadLevelState::LoadLevelState(MainMenu* mainMenu)
		: State(mainMenu, STATE_NAME_LOADLEVEL)
	{

	}

	LoadLevelState::~LoadLevelState()
	{

	}

	void LoadLevelState::Do(float deltaTime)
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