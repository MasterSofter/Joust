#pragma once
#include "mainMenu.State.h"
namespace mainMenu
{
	class ExitState : public State
	{
	public:
		ExitState(MainMenu* mainMenu);
		virtual			~ExitState();
		void			Do(float deltaTime);
	};

}

