#pragma once
#include "SFML/Graphics.hpp"


class StateMachine;
class Player;

namespace player
{
	class InputManager
	{
	private:
		Player* _playerPtr;

	public:
		InputManager(Player* playerPtr);
		void Update();
	};
}

