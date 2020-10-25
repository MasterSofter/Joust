#pragma once
#include<SFML/Graphics.hpp>
#include"Scene.h"
#include"SplashScreen.h"
#include"MainMenu.h"
#include"Level.h"
#include"map"


const sf::String SCENE_NAME_LEVEL = "LevelScene";
const sf::String SCENE_NAME_MAINMENU = "MainMenuScene";
const sf::String SCENE_NAME_SPLASHSCREEN = "SplashScreenScene";

class Game
{
private:
    sf::RenderWindow*  _window;
    sf::Event*         _event;
    sf::Clock*         _clock;
	std::map<sf::String, Scene*>  _scenes;

    Scene*             _currentScene;
    float              _deltaTime;

public:
                     Game();
                     ~Game();
    void             addScene(Scene* scenePtr);
    void             moveToScene(sf::String sceneName);
    void             run();

private:
    void             handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void             processEvents();
    void             update();
    void             render();
};

