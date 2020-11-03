#pragma once
#include "mainMenu.State.h"
namespace mainMenu
{
	class MenuState : public State
	{
	public:
						MenuState(MainMenu* mainMenu);
		virtual			~MenuState();
		void			Do(float deltaTime);
	};

}

