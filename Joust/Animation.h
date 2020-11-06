#pragma once
#include<SFML/Graphics.hpp>
class Animation
{
public:
						Animation();
						Animation(const sf::Texture& texture, sf::Vector2u imageCount, sf::Vector2u imageCountDrawable, float switchTime);
	virtual				~Animation();

	void				 Update(sf::Vector2u startPositionImage, float deltaTime);

public:
	sf::IntRect			uvRect;
	bool				Working = false;
	sf::Vector2u		getCurrentImagePos();
	void				setCurrentImagePos(sf::Vector2u pos);
	void				setImageCountDrawable(sf::Vector2u count);
	void				setSwitchTime(float time);
	float				getSwitchTime();

private:
	sf::Vector2u		currentImage;
	sf::Vector2u		imageCount;
	sf::Vector2u		imageCountDrawable;
	float				totalTime;
	float				switchTime;
};

