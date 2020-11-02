#pragma once
#include "level.State.h"
namespace level
{
	class PauseState : public State
	{
		int _selectedLine = 0;
		sf::Texture _textureMenu;
		sf::RectangleShape menu;

	public:
		PauseState(Level* level);
		virtual			~PauseState();
		void			Do(float deltaTime);
	};

}

