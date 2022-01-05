#ifndef _SPACECREATURE_H_
#define _SPACECREATURE_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "constant.h"
#include <math.h>
#include "Collision.hpp"
//#include "player.h"

using namespace std;


class SpaceCreature {
public:
	SpaceCreature();
	virtual ~SpaceCreature();
	virtual void Move() = 0;
	virtual void Tell() = 0;
	virtual void Mute() = 0;

	virtual void setPosition(int x, int y) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setSpeed(float speed) = 0;
	virtual void Render(sf::RenderWindow& l_window) = 0;
	virtual void stop() = 0;
private:
	friend class Player;
	virtual sf::Sprite getSprite() = 0;
};

class Alien : public SpaceCreature {
public:
	Alien(std::string srcImg, int width, int height, float speed, int x, int y);
	~Alien();
	void setPosition(int x, int y);
	sf::Vector2f getPosition();
	void setSpeed(float speed);
	void Render(sf::RenderWindow& l_window);
	sf::Sprite getSprite();

	void Move();
	void Tell();
	void Mute();
	void stop();
private:
	sf::Sprite alienSprite;
	sf::Texture alienTexture;
	float mX, mY;
	std::string srcImg; //path to the custom pixel spaceShip
	int width;
	int height;
	float speed;
	bool isStop = false;

	bool isSetSound = false;
	sf::SoundBuffer tellBuffer;
	sf::Sound tell;
};

class Astronaut : public SpaceCreature {
public:
	Astronaut(std::string srcImg, int width, int height, float speed, int x, int y);
	~Astronaut();
	void setPosition(int x, int y);
	sf::Vector2f getPosition();
	void setSpeed(float speed);
	void Render(sf::RenderWindow& l_window);
	sf::Sprite getSprite();

	void Move();
	void Tell();
	void Mute();
	void stop();
private:
	sf::Sprite astronautSprite;
	sf::Texture astronautTexture;
	sf::Vector2f incrementMove;
	float mX, mY;
	std::string srcImg; //path to the custom pixel spaceShip
	int width;
	int height;
	float speed;
	bool isStop = false;
	
	bool isSetSound = false;
	sf::SoundBuffer tellBuffer;
	sf::Sound tell;
};
#endif // !_SPACECREATURE_H_