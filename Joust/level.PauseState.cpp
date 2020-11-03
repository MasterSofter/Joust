#include "level.PauseState.h"
#include "level.StateMachine.h"
#include <math.h>
namespace level
{
	PauseState::PauseState(Level* level)
		: State(level, STATE_NAME_PAUSE)
	{

	}

	PauseState::~PauseState()
	{

	}

	void PauseState::Do(float deltaTime)
	{
		if (!Loaded)
		{
			_levelPtr->menuPtr->setPosition(sf::Vector2f(abs(_levelPtr->menuPtr->getPosition().x), abs(_levelPtr->menuPtr->getPosition().y)));
			_levelPtr->textResumePtr->setPosition(sf::Vector2f(abs(_levelPtr->menuPtr->getPosition().x), abs(_levelPtr->menuPtr->getPosition().y - 65)));
			_levelPtr->textExitPtr->setPosition(sf::Vector2f(abs(_levelPtr->menuPtr->getPosition().x), abs(_levelPtr->menuPtr->getPosition().y + 15)));

			Loaded = true;
			_levelPtr->CurrentStateName = _levelPtr->stateMachine->currentState->Name();
			_selectedLine = 0;
		}

		if (Loaded)
		{
			if (_selectedLine == 0)
			{
				_levelPtr->kursormenuPtr->setPosition(sf::Vector2f(abs(_levelPtr->menuPtr->getPosition().x - 50), abs(_levelPtr->menuPtr->getPosition().y - 42)));
			}

			if (_selectedLine == 1)
			{
				_levelPtr->kursormenuPtr->setPosition(sf::Vector2f(abs(_levelPtr->menuPtr->getPosition().x - 50), abs(_levelPtr->menuPtr->getPosition().y + 40)));
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
					_levelPtr->menuPtr->setPosition(sf::Vector2f(-abs(_levelPtr->menuPtr->getPosition().x), -abs(_levelPtr->menuPtr->getPosition().y)));
					_levelPtr->textResumePtr->setPosition(sf::Vector2f(-100, -100));
					_levelPtr->textExitPtr->setPosition(sf::Vector2f(-100, -100));
					_levelPtr->kursormenuPtr->setPosition(sf::Vector2f(-100, -100));


					_levelPtr->stateMachine->moveToState(STATE_NAME_GAME);
					Loaded = false;
					return;
				}

				if (_selectedLine == 1)
				{
					//Выход в главное меню игры
					_levelPtr->stateMachine->moveToState(STATE_NAME_EXIT);
					return;
				}
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				
			}
		}
	}
}