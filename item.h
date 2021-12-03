#ifndef ITEM_H
#define ITEM_H
#include "object.h"
enum SpecialItem { HEART, FROZEN, INVISIBLE, GOAL };
class Item:public Object{
private:
	
	SpecialItem speItem;
public:
	void place(float x, float y) {
		mX = x;
		mY = y;
	}
	Item(string srcImg, int width, int height, SpecialItem s) {
		this->srcImg = srcImg;
		if (!objTexture.loadFromFile(this->srcImg)) {
			std::cerr << "error while loading texture " << std::endl;;
			throw(this->srcImg);
		}
		mX = randomItemX;
		mY = randomItemY;
		speItem = s;

		objTexture.setSmooth(true);

		objSprite.setTexture(objTexture);

		sf::Vector2u size = objTexture.getSize();
		objSprite.setOrigin(width / 2, height / 2);
		objSprite.setScale((float)width / (float)size.x, (float)height / (float)size.y);
		this->width = width;
		this->height = height;
	}
	float getX() {
		return mX;
	}
	float getY() {
		return mY;
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	void render(sf::RenderWindow& l_window) {
		objSprite.setPosition(mX, mY);
		//
		l_window.draw(objSprite);
	}
};

#endif
