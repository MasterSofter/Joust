#pragma once
#include "AI.State.h"
#include "Enemy.h"
namespace AI
{
	class GoRightState : public State
	{
	public:
		GoRightState(Enemy* enemy);
		virtual ~GoRightState();
		void Do(float deltaTime);
	};

}

