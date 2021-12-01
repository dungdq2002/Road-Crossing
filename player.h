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

class Obstacle {

};

class Spawner {

};

enum class Direction { None, Up, Down, Left, Right };
class Player {
public:
	Player(std::string srcImg, int width, int height);

	float GetSpeed();
	void SetMoveStep(int step);
	void Reset();

	//Movement
	void Move(sf::Vector2u windowSize);
	void MoveControl(sf::Vector2u windowSize);
	void SetDirection(Direction l_dir);
	Direction GetDirection();

	//Special ability
	void Transparent();
	void unTransparent();
	
	//handle Lost
	bool hasLost();

	//handle impacted by the Ostacle
	bool isImpact(const Spawner& spawner);
	bool isImpact(const Obstacle& obstacle);
	bool isImpact(const Item& item);

	int getX();
	int getY();
	//void passPhase();
	void Render(sf::RenderWindow& l_window);
	~Player();
private:
	void CheckCollision();
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	int mX, mY;
	std::string srcImg; //path to the custom pixel spaceShip
	int width;
	int height;
	float speed;
	int step;
	bool mState; //Alive or not
	Direction m_dir;
	std::vector<Item> listItem; //Contain special item
};

#endif
