#pragma once
#include "mainMenu.State.h"
namespace mainMenu
{
	class LoadLevelState : public State
	{
	public:
		LoadLevelState(MainMenu* mainMenu);
		virtual			~LoadLevelState();
		void			Do(float deltaTime);
	};

}

