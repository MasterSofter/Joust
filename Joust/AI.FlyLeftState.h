#pragma once
#include "AI.State.h"
#include "Enemy.h"
namespace AI
{
	class FlyLeftState : public State
	{
	public:
		FlyLeftState(Enemy* enemy);
		virtual ~FlyLeftState();
		void Do(float deltaTime);
		void move();
	};
}


