#include "../lib/object.h"

Spawner::Spawner(string img, string sound, int width, int height, float speed, int sX, int sY, bool toRight) {
	mX = sX;
	mY = sY;
	this->toRight = toRight;
	this->speed = speed;
	srcImg = img;
	srcSound = sound;
	this->width = width;
	this->height = height;

	if (!Collision::CreateTextureAndBitmask(objTexture, this->srcImg)) {
		std::cerr << "error while loading texture " << std::endl;;
		throw(this->srcImg);
	}



	objTexture.setSmooth(true);

	objSprite.setTexture(objTexture);

	auto size = objSprite.getGlobalBounds();
	//objSprite.setOrigin(width / 2, height / 2);
	objSprite.setScale((float)width / (float)size.width, (float)height / (float)size.height);
	sf::FloatRect spriteSize = objSprite.getLocalBounds();
	objSprite.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
	//testOrigin=objSprite.getOrigin();

	/*if (!objBuffer.loadFromFile(this->srcSound)) {
		std::cerr << "error while loading sound " << std::endl;;
		throw(this->srcSound);
	}
	objSound.setBuffer(objBuffer);*/
	objSprite.setPosition(mX, mY);
}

void Spawner::move() {
	//isStop = false;
	if (!isStop) {
		if (toRight) {
			if (mX >= winSiz.x+width/2) {
				mX = -width / 2;
			}
			else
			{
				mX += speed;
			}
		}
		else {
			if (mX + width / 2 <= 0) {
				mX = winSiz.x;
			}
			else
			{
				mX -= speed;
			}
		}
	}
	objSprite.setPosition(mX, mY);

}
void Spawner::onSound() {
	objSound.setLoop(true);
	objSound.setVolume(100.f);
	objSound.play();
}
void Spawner::render(sf::RenderWindow& l_window) {
	//objSprite.setPosition(mX+width/2, mY+height/2);
	cout << "calling\n";
	//objSprite.setPosition(mX , mY );
	cout << "set\n";
	//
	l_window.draw(objSprite);
	cout << "oops\n";
}

Obstacle::Obstacle(string img, string sound, int width, int height) {
	srcImg = img;
	srcSound = sound;
	if (!Collision::CreateTextureAndBitmask(objTexture, this->srcImg)) {
		std::cerr << "error while loading texture " << std::endl;;
		throw(this->srcImg);
	}

	this->width = width;
	this->height = height;
	mX = randomStaticX;
	mY = randomStaticY;

	objTexture.setSmooth(true);

	objSprite.setTexture(objTexture);
	auto size = objSprite.getGlobalBounds();
	objSprite.setScale((float)width / (float)size.width, (float)height / (float)size.height);
	sf::FloatRect spriteSize = objSprite.getLocalBounds();
	objSprite.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
	/*if (!objBuffer.loadFromFile(this->srcSound)) {
		std::cerr << "error while loading sound " << std::endl;;
		throw(this->srcSound);
	}
	objSound.setBuffer(objBuffer);*/
	objSprite.setPosition(mX, mY);
}
void Obstacle::place(int coorX, int coorY) {
	mX = coorX;
	mY = coorY;
	objSprite.setPosition(mX, mY);
}

light::light(string img, int width, int height, int x, int y) {
	srcImg = img;
	if (!Collision::CreateTextureAndBitmask(objTexture, this->srcImg)) {
		std::cerr << "error while loading texture " << std::endl;;
		throw(this->srcImg);
	}

	this->width = width;
	this->height = height;
	mX = x;
	mY = y;
	objTexture.setSmooth(true);

	objSprite.setTexture(objTexture);
	auto size = objSprite.getGlobalBounds();
	objSprite.setScale((float)width / (float)size.width, (float)height / (float)size.height);
	sf::FloatRect spriteSize = objSprite.getLocalBounds();
	objSprite.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
	/*if (!objBuffer.loadFromFile(this->srcSound)) {
		std::cerr << "error while loading sound " << std::endl;;
		throw(this->srcSound);
	}
	objSound.setBuffer(objBuffer);*/
	objSprite.setPosition(mX, mY);
	
	state = 1;
}
