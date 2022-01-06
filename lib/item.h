#ifndef ITEM_H
#define ITEM_H
#include "object.h"

enum SpecialItem { HEART, FROZEN, INVISIBLE, GOAL };
class Item:public Object{
private:
	int baseX, baseY;
	SpecialItem speItem;
	bool isActivated;
public:
	void place(float x, float y) {
		mX = x;
		mY = y;
		objSprite.setPosition(mX, mY);
	}
	void reset() {
		place(baseX, baseY);
	}
	void falling(float step) {
		mY += step;
	}
	bool isFrozen() {
		return speItem == FROZEN;
	}
	bool isInvisible() {
		return speItem == INVISIBLE;
	}
	bool isGoal() {
		return speItem == GOAL;
	}
	Item(string srcImg, int width, int height, SpecialItem s, int baseX = -1, int baseY = -1);
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
	void changeState() {

	}
	bool getState() {
		return true;
	}
};

#endif
