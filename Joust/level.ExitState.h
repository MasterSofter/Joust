#pragma once
#include "level.State.h"
namespace level
{
	class ExitState : public State
	{
	public:
						ExitState(Level* level);
		virtual			~ExitState();
		void			Do(float deltaTime);
	};
}



