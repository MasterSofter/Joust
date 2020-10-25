#pragma once
#include "Player.h"
#include "State.h"

namespace player
{
	class IdleRightState : public State
	{
	public:
						IdleRightState(Player* player);
		virtual			~IdleRightState();
		void			Do(float deltaTime);
	};


}
