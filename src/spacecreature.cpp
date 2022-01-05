#include "../lib/spacecreature.h"

SpaceCreature::SpaceCreature() = default;

SpaceCreature::~SpaceCreature() {}

Alien::Alien(std::string srcImg, int width, int height, float speed, int x, int y) {
	this->srcImg = srcImg;
	this->width = width;
	this->height = height;
	this->speed = speed;
	this->mX = x;
	this->mY = y;
	if (!alienTexture.loadFromFile(this->srcImg)) {
		std::cout << "Wrong File Location. File Location does's exist";
		throw(this->srcImg);
	}

	alienSprite.setTexture(alienTexture);
	alienTexture.setSmooth(true);
	auto tmp = alienSprite.getGlobalBounds();
	alienSprite.setScale(float(this->width) / tmp.width, float(this->height) / tmp.height);
	sf::FloatRect spriteSize = alienSprite.getLocalBounds();
	alienSprite.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
	
	//Reset();
}

Alien::~Alien() {
	cout << " ";
}

void Alien::setSpeed(float speed) {
	this->speed = speed;
}

void Alien::setPosition(int x, int y) {
	this->mX = x;
	this->mY = y;
}

void Alien::Render(sf::RenderWindow& l_window) {
	alienSprite.setPosition(this->mX, this->mY);
	l_window.draw(alienSprite);
	this->Move();
}

sf::Sprite Alien::getSprite() {
	return alienSprite;
}

void Alien::Move() {
	//Move with the function of sin
	this->mX += SIN_SPEED;
	this->mY += SIN_RATIO*sin((1.0/this->speed) * this->mX);
	if (this->mX > SCREEN_WIDTH) {
		this->mX = 0;
	}
}

void Alien::Tell() {

}

Astronaut::Astronaut(std::string srcImg, int width, int height, float speed, int x, int y) {
	this->srcImg = srcImg;
	this->width = width;
	this->height = height;
	this->speed = speed;
	this->mX = x;
	this->mY = y;
	this->incrementMove.x = this->speed;
	this->incrementMove.y = this->speed;
	if (!astronautTexture.loadFromFile(this->srcImg)) {
		std::cout << "Wrong File Location. File Location does's exist";
		throw(this->srcImg);
	}

	astronautSprite.setTexture(astronautTexture);
	astronautTexture.setSmooth(true);
	auto tmp = astronautSprite.getGlobalBounds();
	astronautSprite.setScale(float(this->width) / tmp.width, float(this->height) / tmp.height);
	sf::FloatRect spriteSize = astronautSprite.getLocalBounds();
	astronautSprite.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
}

Astronaut::~Astronaut() {
	cout << " ";
}

void Astronaut::setSpeed(float speed) {
	this->speed = speed;
}

void Astronaut::setPosition(int x, int y) {
	this->mX = x;
	this->mY = y;
}

void Astronaut::Render(sf::RenderWindow& l_window) {
	astronautSprite.setPosition(this->mX, this->mY);
	l_window.draw(astronautSprite);
	this->Move();
}

sf::Sprite Astronaut::getSprite() {
	return astronautSprite;
}

void Astronaut::Move() {
	if ((astronautSprite.getPosition().x + (width/2) > SCREEN_WIDTH && incrementMove.x > 0)
		|| (astronautSprite.getPosition().x - (width / 2) < 0 && incrementMove.x < 0)) {
		incrementMove.x = -incrementMove.x;
	}
	if ((astronautSprite.getPosition().y + (height / 2) > SCREEN_HEIGHT && incrementMove.y > 0)
		|| (astronautSprite.getPosition().y - (height / 2) < 0 && incrementMove.y < 0)) {
		incrementMove.y = -incrementMove.y;
	}
	this->mX += incrementMove.x;
	this->mY += incrementMove.y;
}

void Astronaut::Tell() {

}