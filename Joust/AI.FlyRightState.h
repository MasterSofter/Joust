#pragma once
#include "AI.State.h"
#include "Enemy.h"
namespace AI
{
	class FlyRightState : public State
	{
	public:
		FlyRightState(Enemy* enemy);
		virtual ~FlyRightState();
		void Do(float deltaTime);
	};
}



