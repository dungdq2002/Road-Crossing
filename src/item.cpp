#include "../lib/item.h"

Item::Item(string srcImg, int width, int height, SpecialItem s) {
	this->srcImg = srcImg;
	if (!Collision::CreateTextureAndBitmask(objTexture, this->srcImg)) {
		std::cerr << "error while loading texture " << std::endl;;
		throw(this->srcImg);
	}
	mX = randomItemX;
	mY = randomItemY;
	speItem = s;

	objTexture.setSmooth(true);

	objSprite.setTexture(objTexture);

	auto size = objSprite.getGlobalBounds();
	objSprite.setScale((float)width / (float)size.width, (float)height / (float)size.height);
	sf::FloatRect spriteSize = objSprite.getLocalBounds();
	objSprite.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
	this->width = width;
	this->height = height;
	objSprite.setPosition(mX, mY);
}