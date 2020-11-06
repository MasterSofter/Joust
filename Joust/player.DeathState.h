#pragma once
#include "player.State.h"
#include "Player.h"
namespace player
{
	class DeathState : public State
	{
	public:
		DeathState(Player* player);
		virtual ~DeathState();
		void Do(float deltaTime);
		void move();
	};

}

