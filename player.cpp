#include "player.h"

const int startPositionX = 350/2;
const int startPositionY = 700;

Player::Player(std::string srcImg, int width, int height) {
	this->srcImg = srcImg;
	this->width = width;
	this->height = height;
	Reset();
}

void Player::Reset() {
	SetDirection(Direction::None); 
	speed = 0;
	mState = true;
	mX = startPositionX;
	mY = startPositionY - height / 2;
	listItem.clear();
}

void Player::SetDirection(Direction l_dir) { m_dir = l_dir; }
Direction Player::GetDirection() { return m_dir; }
int Player::GetSpeed() { return speed; }