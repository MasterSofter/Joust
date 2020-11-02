#pragma once
#include "level.State.h"
namespace level
{
	class GameState : public State
	{
	public:
						GameState(Level* level);
		virtual			~GameState();
		void			Do(float deltaTime);
	};


}
