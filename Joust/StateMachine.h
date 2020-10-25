#pragma once
#include "Player.h"
#include "State.h"
#include "IdleLeftState.h"
#include "IdleRightState.h"
#include "GoRightState.h"
#include "GoLeftState.h"
#include "FlyRightState.h"
#include "FlyLeftState.h"
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
