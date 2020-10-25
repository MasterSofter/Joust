#include "State.h"

namespace player
{
	State::State(Player* player, sf::String name)
		: _playerPtr(player), _name(name)
	{
	}
}
