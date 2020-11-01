#pragma once
#include "player.State.h"
#include "Player.h"
namespace player
{
	class SpawnState : public State
	{
	public:
						SpawnState(Player* player);
		virtual			~SpawnState();
		void			Do(float deltaTime);
	};

}

