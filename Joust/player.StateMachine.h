#pragma once
#include "Player.h"
#include "player.State.h"
#include "player.IdleLeftState.h"
#include "player.IdleRightState.h"
#include "player.GoRightState.h"
#include "player.GoLeftState.h"
#include "player.FlyRightState.h"
#include "player.FlyLeftState.h"
#include "player.SpawnState.h"
#include "InputManager.h"

namespace player
{
	class StateMachine
	{
		void AddState(State* state);

	public:
		StateMachine(Player* player);
		~StateMachine();
		void moveToState(sf::String stateName);	
		void Update(float deltaTime);

	public:
		std::map<sf::String, State*> states;
		State* currentState = nullptr;
		Player* player = nullptr;

	};
}
