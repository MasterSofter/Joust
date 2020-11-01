#include "Animation.h"

Animation::Animation()
{

}

Animation::~Animation()
{

}

Animation::Animation(const sf::Texture& texture, sf::Vector2u imageCount, sf::Vector2u imageCountDrawable, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->totalTime = 0;
	this->currentImage.x = 0;
	this->currentImage.y = 1;
	this->imageCountDrawable = imageCountDrawable;

	this->uvRect.width = texture.getSize().x / float(imageCount.x);
	this->uvRect.height = texture.getSize().y / float(imageCount.y);

}


void Animation::Update(sf::Vector2u startPositionImage, float deltaTime)
{

	this->totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		this->currentImage.x++;

		if (this->currentImage.x >= this->imageCountDrawable.x)
			this->currentImage.x = startPositionImage.x;
	}

	this->uvRect.left = this->currentImage.x * this->uvRect.width;
	//this->uvRect.top = this->currentImage.y * this->uvRect.height;

}


sf::Vector2u Animation::getCurrentImagePos()
{
	return this->currentImage;
}

void Animation::setCurrentImagePos(sf::Vector2u pos)
{
	this->currentImage = pos;
}
void Animation::setImageCountDrawable(sf::Vector2u count)
{
	this->imageCountDrawable = count;
}

void Animation::setSwitchTime(float time)
{
	switchTime = time;
}

float Animation::getSwitchTime()
{
	return switchTime;
}