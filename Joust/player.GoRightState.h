#pragma once
#include "player.State.h"
#include "defs.h"
#include "Player.h"
namespace player
{
	class GoRightState : public State
	{
	public:
		GoRightState(Player* player);
		virtual ~GoRightState();
		void Do(float deltaTime);
		void move();
	};
}
