#ifndef _SPACECREATURE_H_
#define _SPACECREATURE_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "constant.h"
#include <math.h>
using namespace std;


class SpaceCreature {
public:
	SpaceCreature();
	virtual ~SpaceCreature();
	virtual void Move() = 0;
	virtual void Tell() = 0;

	virtual void setPosition(int x, int y) = 0;
	virtual void setSpeed(float speed) = 0;
	virtual void Render(sf::RenderWindow& l_window) = 0;
};

class Alien : public SpaceCreature {
public:
	Alien(std::string srcImg, int width, int height, float speed, int x, int y);
	~Alien();
	void setPosition(int x, int y);
	void setSpeed(float speed);
	void Render(sf::RenderWindow& l_window);

	void Move();
	void Tell();
private:
	sf::Sprite alienSprite;
	sf::Texture alienTexture;
	float mX, mY;
	std::string srcImg; //path to the custom pixel spaceShip
	int width;
	int height;
	float speed;
};

class Astronaut : public SpaceCreature {
public:
	Astronaut(std::string srcImg, int width, int height, float speed, int x, int y);
	~Astronaut();
	void setPosition(int x, int y);
	void setSpeed(float speed);
	void Render(sf::RenderWindow& l_window);

	void Move();
	void Tell();
private:
	sf::Sprite astronautSprite;
	sf::Texture astronautTexture;
	float mX, mY;
	std::string srcImg; //path to the custom pixel spaceShip
	int width;
	int height;
	float speed;
};
#endif // !_SPACECREATURE_H_