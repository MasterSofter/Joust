#include "mainMenu.State.h"
namespace mainMenu
{
	State::State(MainMenu* mainMenu, sf::String name)
		: _mainMenuPtr(mainMenu), _name(name)
	{
	}
}
