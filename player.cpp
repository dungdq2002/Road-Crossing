#include "player.h"

const int startPositionX = 350/2;
const int startPositionY = 700;

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
	Reset();
}

Player::~Player(){
	std::cout << "Finish";
}

void Player::Reset() {
	SetDirection(Direction::None); 
	speed = 0;
	step = 5;
	mState = true;
	mX = startPositionX;
	mY = startPositionY - height;
	listItem.clear();
}

void Player::SetDirection(Direction l_dir) { m_dir = l_dir; }

Direction Player::GetDirection() { return m_dir; }

float Player::GetSpeed() { return speed; }

int Player::getX() { return mX; }

int Player::getY() { return mY; }

void Player::Tick(sf::RenderWindow& l_window) {
	if (m_dir == Direction::None) { return; }
	Move(l_window);
	CheckCollision();
}

void Player::Move(sf::RenderWindow& l_window) {
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
	if (mX < 0) mX = 0;
	if (mX + width > (int)l_window.getSize().x) mX = l_window.getSize().x - width;
	if (mY < 0) mY = 0;
	if (mY + height > (int)l_window.getSize().y) mY = l_window.getSize().y - height;
}

void Player::CheckCollision() {
	std::cout << "OK";
}

void Player::Render(sf::RenderWindow& l_window) {
	sf::Vector2u size = playerTexture.getSize();
	//std::cout << size.x << " " << size.y << std::endl;
	playerSprite.setScale(float(this->width) / size.x, float(this->height) / size.y);
	//std::cout << size.x << " " << size.y << std::endl;
	playerSprite.setOrigin(width/2, height/2);
	playerSprite.setPosition(this->mX, this->mY);
	this->SetDirection(Direction::None);
	l_window.draw(playerSprite);
}

void Player::update(float dt) {

}