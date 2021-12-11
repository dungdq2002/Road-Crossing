#ifndef PLAYER_H
#define PLAYER_H

//Duy do in here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "object.h"
#include "item.h"
#include "constant.h"

enum class DirectionPlayer { None, Up, Down, Left, Right };

class Player {
public:
	Player(std::string srcImg, int width, int height);

	float GetSpeed();
	void SetMoveStep(int step);
	void Reset();

	//Movement
	void Move();
	void MoveControl(Object* obj, float intersectPercent);
	void SetDirection(DirectionPlayer l_dir);
	DirectionPlayer GetDirection();

	//Special ability
	void Transparent();
	void unTransparent();
	
	//handle Lost
	bool hasLost();

	//handle impacted by the Object
	bool isImpact(Object* obj, float intersectPercent);

	//add Item
	void addItem(const Item& item);

	float getX();
	float getY();
	//void passPhase();
	void Render(sf::RenderWindow& l_window);
	~Player();
private:
	void CheckCollision(Object* obj, float intersectPercent);
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	float mX, mY;
	std::string srcImg; //path to the custom pixel spaceShip
	int width;
	int height;
	float speed;
	int step;
	bool mState; //Alive or not
	DirectionPlayer m_dir;
	std::vector<Item> listItem; //Contain special item
};

#endif
