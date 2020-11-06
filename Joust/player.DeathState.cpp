#include "player.DeathState.h"
namespace player
{
	DeathState::DeathState(Player* player)
		: State(player, STATE_NAME_DEATH)
	{

	}

	DeathState::~DeathState()
	{

	}

	void DeathState::move()
	{
	
	}


	void DeathState::Do(float deltaTime)
	{
		if (_playerPtr->Alive)
		{
			_playerPtr->Alive = false;
			_playerPtr->lifes -= 1;
		}
	}
}