#pragma once
#include"defs.h"
#include "Player.h"
#include "State.h"

namespace player
{
	class IdleLeftState : public PlayerState
	{
	public:
		IdleLeftState(Player* player);
		virtual ~IdleLeftState();
		void Do(float deltaTime);
	};
}
