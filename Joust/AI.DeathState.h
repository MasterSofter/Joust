#pragma once
#include "AI.State.h"
#include "Enemy.h"
namespace AI
{
	class DeathState : public State
	{
		float switchedY = 0.f;
	public:
		DeathState(Enemy* enemy);
		virtual ~DeathState();
		void Do(float deltaTime);
		void move();
	};
}
