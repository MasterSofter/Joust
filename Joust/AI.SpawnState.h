#pragma once
#include "AI.State.h"
#include "Enemy.h"
namespace AI
{
	class SpawnState : public State
	{
	public:
		SpawnState(Enemy* enemy);
		virtual ~SpawnState();
		void Do(float deltaTime);
		void move();
	};
}
