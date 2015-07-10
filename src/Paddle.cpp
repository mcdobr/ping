#include "Paddle.hpp"

namespace ping
{
	const sf::Vector2f Paddle::paddleSpeed = sf::Vector2f(0, 15);

	Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2i& size, const sf::Keyboard::Key& _upKey, const sf::Keyboard::Key& _downKey)
	{
		this -> setTexture(getTextureFromColor(sf::Color::White));
		this -> setTextureRect(sf::IntRect(sf::Vector2i(0, 0), size));
		this -> setPosition(position);
		this -> setSpeed(sf::Vector2f(0, 0));
		this -> upKey = _upKey;
		this -> downKey = _downKey;
		this -> isInMovement = false;
	}

	//setters
	void Paddle::setSpeed(const sf::Vector2f& _speed)
	{
		speed = _speed;
		if (speed != sf::Vector2f(0.0, 0.0))
			isInMovement = true;
		else
			isInMovement = false;
	}

	//Getters
	bool Paddle::isMoving()
	{
		return isInMovement;
	}

	sf::Vector2f& Paddle::getSpeed()
	{
		return speed;
	}
	sf::Keyboard::Key& Paddle::getUpKey()
	{
		return upKey;
	}
	sf::Keyboard::Key& Paddle::getDownKey()
	{
		return downKey;
	}

	//"REAL" functions
	void Paddle::moveUp()
	{
		if (this -> getPosition().y >= 0)
			this -> move(-paddleSpeed);
	}

	void Paddle::moveDown()
	{
		if (this -> getPosition().y <= 536)
			this -> move(paddleSpeed);
	}
}
