#include "AI.State.h"
namespace AI
{
	State::State(Enemy* enemy, sf::String name)
		: _enemyPtr(enemy), _name(name)
	{
	}
}