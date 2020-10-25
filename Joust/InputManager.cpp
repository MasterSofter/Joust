#include "StateMachine.h"
#include "Player.h"
#include "InputManager.h"

namespace player
{

	InputManager::InputManager(Player* playerPtr)
		: _playerPtr(playerPtr)
	{
	
	}


	void InputManager::Update()
	{
		

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{

		}

	}
}
