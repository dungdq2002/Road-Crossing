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
	this->Move();
	l_window.draw(alienSprite);
	cout << "Alien move";
}

void Alien::Move() {
	//Move with the function of sin
	this->mX += speed;
	this->mY = sin(this->mX);
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
}

void Astronaut::Move() {

}

void Astronaut::Tell() {

}