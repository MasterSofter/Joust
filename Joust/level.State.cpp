#include "level.State.h"
namespace level
{
	State::State(Level* level, sf::String name)
		: _levelPtr(level), _name(name)
	{
	}
}