#include "State.h"

namespace player
{
	PlayerState::PlayerState(Player* player, sf::String name)
		: _playerPtr(player), _name(name)
	{
	}
}
