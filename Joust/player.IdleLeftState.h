#pragma once
#include"defs.h"
#include "Player.h"
#include "player.State.h"

namespace player
{
	class IdleLeftState : public State
	{
	public:
		IdleLeftState(Player* player);
		virtual ~IdleLeftState();
		void Do(float deltaTime);
	};
}
