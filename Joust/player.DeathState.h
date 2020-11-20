#pragma once
#include "player.State.h"
#include "Player.h"
namespace player
{
	class DeathState : public State
	{
		float switchedY = 0.f;
	public:
		DeathState(Player* player);
		virtual ~DeathState();
		void Do(float deltaTime);
		void move();
	};

}

