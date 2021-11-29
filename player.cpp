#include "player.h"

const int startPositionX = 350/2;
const int startPositionY = 700;

Player::Player(std::string srcImg, int width, int height) {
	this->srcImg = srcImg;
	this->width = width;
	this->height = height;
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
	mY = startPositionY - height / 2;
	listItem.clear();
}

void Player::SetDirection(Direction l_dir) { m_dir = l_dir; }

Direction Player::GetDirection() { return m_dir; }

float Player::GetSpeed() { return speed; }

int Player::getX() { return mX; }

int Player::getY() { return mY; }

void Player::Tick() {
	if (m_dir == Direction::None) { return; }
	Move();
	CheckCollision();
}

void Player::Move() {
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
}

void Player::CheckCollision() {
	std::cout << "OK";
}

void Player::Render(sf::RenderWindow& l_window) {
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile(this->srcImg)) {
		std::cout << "Wrong File Location. File Location does's exist";
		throw(this->srcImg);
	}

	sf::Sprite player(playerTexture);
	sf::Vector2u size = playerTexture.getSize();
	//player.setScale(float(this->width / size.x), float(this->height / size.y));
	player.setOrigin(float(size.x / 2), float(size.y / 2));
	player.setPosition(this->mX, this->mY);
	this->SetDirection(Direction::None);
	l_window.draw(player);
}
