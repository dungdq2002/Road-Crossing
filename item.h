#ifndef ITEM_H
#define ITEM_H
#include "object.h"
enum SpecialItem { HEART, FROZEN, INVISIBLE, GOAL };
class item{
private:
	float mX;
	float mY;
	string srcImg;
	int width;
	int height;
	SpecialItem speItem;
public:
	void place(float x, float y) {
		mX = x;
		mY = y;
	}
	item(string srcImg, int width, int height, SpecialItem s) {
		speItem = s;
		
		this->width = width;
		this->height = height;
	}
};

#endif
