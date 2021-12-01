#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int randomStartX = 100;
const int randomStartY = 100;

enum class Direction { None, Up, Down, Left, Right };
class object{
protected:
	string srcImg;
	string srcSound;
	int width;
	int height;
	int mX, mY;
	sf::Texture objTexture;
	sf::Sprite objSprite;
	
public:

};

class spawner:public object {
public:
	spawner(string img, string sound, int width, int height) {
		srcImg = img;
		srcSound = sound;
		this->width = width;
		this->height = height;
		if (!objTexture.loadFromFile(this->srcImg)) {
			std::cerr << "error while loading texture " << std::endl;;
			throw(this->srcImg);
		}
		mX = randomStartX;
		mY = randomStartY;
		
		objTexture.setSmooth(true);
		
		objSprite.setTexture(objTexture);
		objSprite.setOrigin(width / 2, height / 2);
		sf::Vector2u size = objTexture.getSize();
		objSprite.setScale((float) width /(float) size.x, (float)height / (float)size.y);
		
	}

	//sX,sY: coordinate of start point.
	void moveHorizontal(int sX, int sY, float speed, bool toRight) {

	}
	void stop() {

	}
	void render(sf::RenderWindow& l_window) {
		objSprite.setPosition(mX, mY);
		//
		l_window.draw(objSprite);
	}
private:
	float speed;
	bool toRight;
	bool sound;// true=on, false=off;
	Direction m_dir; // current direction

};

class obstacle :public object {
public:

	obstacle(string img, string sound, int width, int height) {
		srcImg = img;
		srcSound = sound;
		this->width = width;
		this->height = height;
	}
	void place(int coorX, int coorY) {
		mX = coorX;
		mY = coorY;
	}
	void collapse() {

	}

	void render(sf::RenderWindow& l_window) {
		
		objSprite.setPosition(mX,mY);
		//
		l_window.draw(objSprite);

	}

private:

};

#endif