#pragma once
#include "player.State.h"
#include "defs.h"
#include "Player.h"
namespace player
{
	class GoLeftState : public State
	{
	public:
		GoLeftState(Player* player);
		virtual ~GoLeftState();
		void Do(float deltaTime);
		void move();
	};



}
