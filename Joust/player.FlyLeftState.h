#pragma once
#include "player.State.h"
#include "Player.h"
namespace player
{
	class FlyLeftState : public State
	{
	public:
		FlyLeftState(Player* player);
		virtual ~FlyLeftState();
		void Do(float deltaTime);
		void move();
	};

}



