#include "level.GameState.h"
#include "level.StateMachine.h"

namespace level
{
	GameState::GameState(Level* level)
		: State(level, STATE_NAME_GAME)
	{

	}

	GameState::~GameState()
	{

	}

	void GameState::Do(float deltaTime)
	{
		if (!Loaded)
		{
			Loaded = true;
			_levelPtr->CurrentStateName = _levelPtr->stateMachine->currentState->Name();
		}

		if (Loaded)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				_levelPtr->stateMachine->moveToState(STATE_NAME_PAUSE);
				return;
			}

			_levelPtr->physics.Update(deltaTime);
			for (auto it = _levelPtr->_gameObjects.begin(); it != _levelPtr->_gameObjects.end(); it++)
			{
				(*it)->Update(deltaTime, sf::Vector2u(800, 600));
				if (!(*it)->Static)
				{
					if ((*it)->Name == "Player" && !(*it)->Alive)
						(*it)->Spawn(sf::Vector2f(360, 472));
					if ((*it)->Name == "Enemy" && !(*it)->Alive)
						(*it)->Spawn(sf::Vector2f(157, 108));

					if ((*it)->getPosition().x > 800)
						(*it)->setPosition(sf::Vector2f(0, (*it)->getPosition().y));
					if ((*it)->getPosition().x < 0)
						(*it)->setPosition(sf::Vector2f(800, (*it)->getPosition().y));
				}

			}
		}

	}
}