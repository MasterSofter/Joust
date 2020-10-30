#pragma once
#include "State.h"
#include "defs.h"
#include "Player.h"
namespace player
{
	class FlyRightState : public PlayerState
	{
	public:
		FlyRightState(Player* player);
		virtual ~FlyRightState();
		void Do(float deltaTime);
	};



}
