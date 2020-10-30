#pragma once
#include "AI.State.h"
#include "Enemy.h"
namespace AI
{
	class IdleLeftState : public State
	{
	public:
		IdleLeftState(Enemy* enemy);
		virtual ~IdleLeftState();
		void Do(float deltaTime);
	};
}


