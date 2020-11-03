#pragma once
#include "mainMenu.State.h"
#include "MainMenu.h"
#include "mainMenu.ExitState.h"
#include "mainMenu.LoadLevelState.h"
#include "mainMenu.MenuState.h"


namespace mainMenu
{
	class StateMachine
	{
		void AddState(State* state);

	public:
		StateMachine(MainMenu* mainMenu);
		~StateMachine();
		void moveToState(sf::String stateName);
		void Update(float deltaTime);

	public:
		std::map<sf::String, State*> states;
		State* currentState = nullptr;
		MainMenu* mainMenu = nullptr;

	};
}

