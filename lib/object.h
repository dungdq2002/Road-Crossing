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
#include "Collision.hpp"
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
	sf::Vector2u winSiz = sf::Vector2u(350, 700);
	string srcImg;
	string srcSound;
	int width;
	int height;
	float mX, mY;
	
	//image
	sf::Texture objTexture;
	//sf::Sprite objSprite;

	//sound
	sf::SoundBuffer objBuffer;
	sf::Sound objSound;
public:
	sf::Sprite objSprite;
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	/*virtual void moveHorizontal(int sX, int sY, bool toRight, sf::Vector2u windowSize) {

	}*/
	virtual void continueRun(){}
	virtual void move() { /* nothing */}
	virtual void stop() { /* nothing */ }
	virtual void place(int, int) { /* nothing */ }
	virtual void render(sf::RenderWindow& l_window) = 0;
};

//SPAWNER
class Spawner:public Object {
public:
	Spawner(string img, string sound, int width, int height, float speed, int sX, int sY, bool toRight);

	//sX,sY: coordinate of start point.
	void move();
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
	void onSound();
	void render(sf::RenderWindow& l_window);
	
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

	Obstacle(string img, string sound, int width, int height);
	void place(int coorX, int coorY);
	void collapse() {

	}

	void render(sf::RenderWindow& l_window) {		
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