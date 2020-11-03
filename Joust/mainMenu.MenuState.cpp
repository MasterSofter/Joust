#include "mainMenu.MenuState.h"
#include "mainMenu.StateMachine.h"
namespace mainMenu
{
	MenuState::MenuState(MainMenu* mainMenu)
		: State(mainMenu, STATE_NAME_MAINMENU)
	{

	}

	MenuState::~MenuState()
	{

	}

	void MenuState::Do(float deltaTime)
	{

		if (!Loaded)
		{
			_mainMenuPtr->textPlayPtr->setPosition(sf::Vector2f(abs(_mainMenuPtr->menuPtr->getPosition().x), abs(_mainMenuPtr->menuPtr->getPosition().y - 65)));
			_mainMenuPtr->textExitPtr->setPosition(sf::Vector2f(abs(_mainMenuPtr->menuPtr->getPosition().x), abs(_mainMenuPtr->menuPtr->getPosition().y + 15)));
			_mainMenuPtr->textJoustPtr->setPosition(sf::Vector2f(200, 12));


			Loaded = true;
			_mainMenuPtr->CurrentStateName = _mainMenuPtr->stateMachine->currentState->Name();
			_selectedLine = 0;
		}

		if (Loaded)
		{

			if (_selectedLine == 0)
			{
				_mainMenuPtr->kursormenuPtr->setPosition(sf::Vector2f(abs(_mainMenuPtr->menuPtr->getPosition().x - 50), abs(_mainMenuPtr->menuPtr->getPosition().y - 42)));
			}

			if (_selectedLine == 1)
			{
				_mainMenuPtr->kursormenuPtr->setPosition(sf::Vector2f(abs(_mainMenuPtr->menuPtr->getPosition().x - 50), abs(_mainMenuPtr->menuPtr->getPosition().y + 40)));
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				_selectedLine = 0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				_selectedLine = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				if (_selectedLine == 0)
				{
					_mainMenuPtr->stateMachine->moveToState(STATE_NAME_LOADLEVEL);
					return;
				}

				if (_selectedLine == 1)
				{
					_mainMenuPtr->stateMachine->moveToState(STATE_NAME_EXIT);
					return;
				}
			}
		}

	}
}
