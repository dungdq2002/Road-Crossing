#ifndef PLAYER_H
#define PLAYER_H

//Duy do in here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

//Item test
class Item { //abstract class
public:
	virtual bool isInvisible() = 0;
private:

};

class Invisible : public Item {
public:
	bool isInvisible() {
		return true;
	}
};

class Heart : public Item {
public:
	bool isInvisible() {
		return false;
	}
};

enum class Direction { None, Up, Down, Left, Right };
class Player {
public:
	Player(std::string srcImg, int width, int height);

	void SetDirection(Direction l_dir);
	Direction GetDirection();
	int GetSpeed();
	void Reset();
	void Move();
	bool getAliveState();
	void useInvisible();
	
	int getX();
	int getY();
	void Render(sf::RenderWindow& l_window);
	~Player();
private:
	void CheckCollision();
	int mX, mY;
	std::string srcImg; //path to the custom pixel spaceShip
	int width;
	int height;
	float speed;
	bool mState; //Alive or not
	Direction m_dir;
	std::vector<Item> listItem; //Contain special item
};
#endif
