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

	eatItemBuffer.loadFromFile("./asset/sound/getItem.wav");
	eatItem.setBuffer(eatItemBuffer);
	eatItem.setVolume(5.f);

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
	SetDirection(DirectionPlayer::None); 
	speed = 0;
	step = PLAYER_STEP;
	mState = true;
	mX = startPositionX;
	mY = startPositionY - height/2.;
	this->unTransparent();
	listItem.clear();
}


//Set speed and move step (speed relate to fps rate, step depend on player it self)
float Player::GetSpeed() { return speed; }

void Player::SetMoveStep(int step) {
	this->step = step;
}


//Direction for movement
void Player::SetDirection(DirectionPlayer l_dir) { m_dir = l_dir; }

DirectionPlayer Player::GetDirection() { return m_dir; }


//Get position of Player
float Player::getX() { return mX; }

float Player::getY() { return mY; }


//Movement 
void Player::MoveControl(Object* obj, float intersectPercent) {
	CheckCollision(obj, intersectPercent);
	if (m_dir == DirectionPlayer::None) { return; }
	Move();
}

void Player::Move() {
	if (m_dir == DirectionPlayer::None) { return; }
	if (speed == 0)
		speed = 5;
	if (m_dir == DirectionPlayer::Left) {
		this->mX -= step;
	}
	else if (m_dir == DirectionPlayer::Right) {
		this->mX += step;
	}
	else if (m_dir == DirectionPlayer::Up) {
		this->mY -= step;
	}
	else if (m_dir == DirectionPlayer::Down) {
		this->mY += step;
	}
	//Hanle boundary
	if (mX - width/2. < 0) mX = width/2.;
	if (mX + width/2 >= (int)SCREEN_WIDTH) mX = SCREEN_WIDTH - width/2;
	if (mY - height/2. < 0) mY = height/2.;
	if (mY + height/2 >= (int)SCREEN_HEIGHT) mY = SCREEN_HEIGHT - height/2;
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
bool Player::isImpact(Object* obj, float intersectPercent) {
	if (intersectPercent > 1)
		throw "Intersection has to less than 1.";
	if (obj == nullptr)
		return false;
	/*
	float conditionalDistanceX = (obj->getWidth() / 2.) + (this->width / 2.) * (1. - intersectPercent);
	float conditionalDistanceY = (obj->getHeight() / 2.) + (this->height / 2.) * (1. - intersectPercent);

	if (abs(this->mX - obj->getX()) <= conditionalDistanceX && abs(this->mY - obj->getY()) <= conditionalDistanceY) {
		return true;
	}
	return false;*/

	if (Collision::PixelPerfectTest(obj->objSprite, playerSprite)) {
		return true;
	}
	return false;

}

//Check collision with Item or Obstacle/Spawner
void Player::CheckCollision(Object* obj, float intersectPercent) {
	//Test 
	//If have condition for item and object you can put in here
	if (this->isImpact(obj, intersectPercent)) {
		cout << "IS IMPACT: " << this->mX << " " << this->mY << endl;
		cout << obj->getX() << " " << obj->getY() << endl;
	}
}

//Add item
void Player::addItem(const Item& item) {
	this->listItem.push_back(item);
}

//Special item controller
bool Player::isAbleFrozen() {
	for (auto it = listItem.begin(); it != listItem.end(); it++) {
		if (it->isFrozen()) {
			return true;
		}
	}
	return false;
}

bool Player::isAbleInvisible() {
	for (auto it = listItem.begin(); it != listItem.end(); it++) {
		if (it->isInvisible()) {
			return true;
		}
	}
	return false;
}

void Player::eraseItemFrozen() {
	for (auto it = listItem.begin(); it != listItem.end(); it++) {
		if (it->isFrozen()) {
			listItem.erase(it);
			return;
		}
	}
}

void Player::eraseItemInvisible() {
	for (auto it = listItem.begin(); it != listItem.end(); it++) {
		if (it->isInvisible()) {
			listItem.erase(it);
		}
	}
}
//Render to the windows
void Player::Render(sf::RenderWindow& l_window) {
	playerSprite.setPosition(this->mX, this->mY);
	this->SetDirection(DirectionPlayer::None);
	l_window.draw(playerSprite);
}


//Check if the player lost for the windows Lost and Try again
bool Player::hasLost() {
	return mState;
}
