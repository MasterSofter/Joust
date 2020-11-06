#pragma once
#include "AI.State.h"
#include "Enemy.h"
namespace AI
{
	class GoLeftState : public State
	{
	public:
		GoLeftState(Enemy* enemy);
		virtual ~GoLeftState();
		void Do(float deltaTime);
		void move();
	};

}


