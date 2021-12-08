#ifndef OBJECT_H
#define OBJECT_H
//#include "SFML-2.5.1/lib/sfml-audio-s.lib"
//#include "SFML-2.5.1/lib/openal32.lib"
//#include "SFML-2.5.1/lib/flac.lib"
//#include "SFML-2.5.1/lib/ogg.lib"
//#include "SFML-2.5.1/lib/vorbis.lib"
//#include "SFML-2.5.1/lib/vorbisenc.lib"
//#include "SFML-2.5.1/lib/vorbisfile.lib"
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
const int randomStaticX = 200;
const int randomStaticY = 200;
const int randomItemX = 250;
const int randomItemY = 150;
enum class Direction { None, Up, Down, Left, Right };
class Object{
protected:
	string srcImg;
	string srcSound;
	int width;
	int height;
	float mX, mY;
	
	//image
	sf::Texture objTexture;
	sf::Sprite objSprite;

	//sound
	//sf::SoundBuffer objBuffer;
	//sf::Sound objSound;
public:
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual void moveHorizontal(int sX, int sY, bool toRight, sf::Vector2u windowSize) {

	}
	virtual void render(sf::RenderWindow& l_window) = 0;
};

//SPAWNER
class Spawner:public Object {
public:
	Spawner(string img, string sound, int width, int height,float speed, int sX, int sY, bool toRight) {
		mX = sX;
		mY = sY;
		this->toRight = toRight;
		this->speed = speed;
		srcImg = img;
		srcSound = sound;
		this->width = width;
		this->height = height;
		if (!objTexture.loadFromFile(this->srcImg)) {
			std::cerr << "error while loading texture " << std::endl;;
			throw(this->srcImg);
		}
		
		

		objTexture.setSmooth(true);
		
		objSprite.setTexture(objTexture);
		
		auto size = objSprite.getGlobalBounds();
		//objSprite.setOrigin(width / 2, height / 2);
		objSprite.setScale((float) width /(float) size.width, (float)height / (float)size.height);
		sf::FloatRect spriteSize = objSprite.getLocalBounds();
		objSprite.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
		//testOrigin=objSprite.getOrigin();

		/*if (!objBuffer.loadFromFile(this->srcSound)) {
			std::cerr << "error while loading sound " << std::endl;;
			throw(this->srcSound);
		}
		objSound.setBuffer(objBuffer);*/
	}

	//sX,sY: coordinate of start point.
	void moveHorizontal(sf::Vector2u windowSize) {
		if (!isStop) {
			if (toRight) {
				if (mX >= windowSize.x) {
					mX = -width / 2;
				}
				else
				{
					mX += speed;
				}
			}
			else {
				if (mX + width / 2 <= 0) {
					mX = windowSize.x;
				}
				else
				{
						mX -= speed;
				}
			}
		}
		
				
	}
	/*float getOrigin() {
		return testOrigin.x;
	}*/
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
	void stop() {
		//speed = 0;
		isStop = true;
	}
	void continueRun() {
		isStop = false;
	}
	void onSound() {
		/*objSound.setLoop(true);
		objSound.setVolume(100.f);
		objSound.play();*/
	}
	void render(sf::RenderWindow& l_window) {
		//objSprite.setPosition(mX+width/2, mY+height/2);
		objSprite.setPosition(mX , mY );

		//
		l_window.draw(objSprite);
	}
private:
	float speed;
	bool toRight;
	bool sound;// true=on, false=off;
	Direction m_dir; // current direction
	bool first = true;
	bool isStop = false;

	//sf::Vector2f testOrigin;
};


//OBSTACLE
class Obstacle :public Object {
public:

	Obstacle(string img, string sound, int width, int height) {
		srcImg = img;
		srcSound = sound;
		if (!objTexture.loadFromFile(this->srcImg)) {
			std::cerr << "error while loading texture " << std::endl;;
			throw(this->srcImg);
		}

		this->width = width;
		this->height = height;
		mX = randomStaticX;
		mY = randomStaticY;

		objTexture.setSmooth(true);

		objSprite.setTexture(objTexture);
		auto size = objSprite.getGlobalBounds();
		objSprite.setScale((float)width / (float)size.width, (float)height / (float)size.height);
		sf::FloatRect spriteSize = objSprite.getLocalBounds();
		objSprite.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
		/*if (!objBuffer.loadFromFile(this->srcSound)) {
			std::cerr << "error while loading sound " << std::endl;;
			throw(this->srcSound);
		}
		objSound.setBuffer(objBuffer);*/
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
private:

};

#endif