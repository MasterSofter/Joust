#pragma once
#include "player.State.h"
#include "defs.h"
#include "Player.h"
namespace player
{
	class FlyRightState : public State
	{
	public:
		FlyRightState(Player* player);
		virtual ~FlyRightState();
		void Do(float deltaTime);
		void move();
	};



}
