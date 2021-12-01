#include "player.h"

const int startPositionX = 350/2;
const int startPositionY = 700;

//Constructor and destructor
Player::Player(std::string srcImg, int width, int height) {
	this->srcImg = srcImg;
	this->width = width;
	this->height = height;
	if (!playerTexture.loadFromFile(this->srcImg)) {
		std::cout << "Wrong File Location. File Location does's exist";
		throw(this->srcImg);
	}

	playerSprite.setTexture(playerTexture);
	playerTexture.setSmooth(true);
	auto tmp = playerSprite.getGlobalBounds();
	playerSprite.setScale(float(this->width) / tmp.width, float(this->height) / tmp.height);
	sf::FloatRect spriteSize = playerSprite.getLocalBounds();
	playerSprite.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
	Reset();
}

Player::~Player(){
	std::cout << "Finish";
}

void Player::Reset() { //Reset when the player is contruct again after losing
	SetDirection(Direction::None); 
	speed = 0;
	step = 5;
	mState = true;
	mX = startPositionX;
	mY = startPositionY - height/2.;
	listItem.clear();
}


//Set speed and move step (speed relate to fps rate, step depend on player it self)
float Player::GetSpeed() { return speed; }

void Player::SetMoveStep(int step) {
	this->step = step;
}


//Direction for movement
void Player::SetDirection(Direction l_dir) { m_dir = l_dir; }

Direction Player::GetDirection() { return m_dir; }


//Get position of Player
int Player::getX() { return mX; }

int Player::getY() { return mY; }


//Movement 
void Player::MoveControl(sf::Vector2u windowSize) {
	if (m_dir == Direction::None) { return; }
	Move(windowSize);
	CheckCollision();
}

void Player::Move(sf::Vector2u windowSize) {
	if (m_dir == Direction::None) { return; }
	if (speed == 0)
		speed = 5;
	if (m_dir == Direction::Left) {
		this->mX -= step;
	}
	else if (m_dir == Direction::Right) {
		this->mX += step;
	}
	else if (m_dir == Direction::Up) {
		this->mY -= step;
	}
	else if (m_dir == Direction::Down) {
		this->mY += step;
	}
	//Hanle boundary
	if (mX - width/2. < 0) mX = width/2.;
	if (mX + width/2 >= (int)windowSize.x) mX = windowSize.x - width/2;
	if (mY - height/2. < 0) mY = height/2.;
	if (mY + height/2 >= (int)windowSize.y) mY = windowSize.y - height/2;
}


//Special ability
void Player::Transparent() {
	auto spriteColor = playerSprite.getColor();
	playerSprite.setColor(sf::Color(spriteColor.r, spriteColor.g, spriteColor.b, 128));
}

void Player::unTransparent() {
	auto spriteColor = playerSprite.getColor();
	playerSprite.setColor(sf::Color(spriteColor.r, spriteColor.g, spriteColor.b, 255));
}

//Check the impact: Obstacle, Spawner of Item
bool Player::isImpact(const Spawner& spawner) {

}

bool Player::isImpact(const Obstacle& obstacle) {

}

bool Player::isImpact(const Item& item) {

}


//Check collision with Item or Obstacle/Spawner
void Player::CheckCollision() {
	std::cout << "OK";

}


//Render to the windows
void Player::Render(sf::RenderWindow& l_window) {
	playerSprite.setPosition(this->mX, this->mY);
	this->SetDirection(Direction::None);
	l_window.draw(playerSprite);
}


//Check if the player lost for the windows Lost and Try again
bool Player::hasLost() {
	return mState;
}
