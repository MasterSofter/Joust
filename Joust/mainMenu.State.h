#pragma once
#include "MainMenu.h"
namespace mainMenu
{
	class State
	{
	protected:
		State(MainMenu* player, sf::String name);


	public:
		virtual ~State() {}
		virtual void Do(float deltaTime) {}
		sf::String Name() { return _name; }

		int _selectedLine = 0;
		bool Loaded = false;

	protected:
		MainMenu* _mainMenuPtr;

	private:
		sf::String _name;
	};

	const sf::String STATE_NAME_LOADLEVEL = "LoadLevel";
	const sf::String STATE_NAME_MAINMENU = "MainMenu";
	const sf::String STATE_NAME_EXIT = "Exit";

}

