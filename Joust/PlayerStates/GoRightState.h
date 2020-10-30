#pragma once
#include "State.h"
#include "defs.h"
#include "Player.h"
namespace player
{
	class GoRightState : public PlayerState
	{
	public:
		GoRightState(Player* player);
		virtual ~GoRightState();
		void Do(float deltaTime);
	};
}
