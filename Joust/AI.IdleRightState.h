#pragma once
#include "Enemy.h"
#include "AI.State.h"

namespace AI
{
	class IdleRightState : public State
	{
	public:
		IdleRightState(Enemy* enemy);
		virtual ~IdleRightState();
		void Do(float deltaTime);
		void move();
	};

}

