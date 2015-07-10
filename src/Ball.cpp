#include "Ball.hpp"

#include <SFML/Graphics.hpp>

namespace ping 
{
	//Create a random number generator to set the initial speed of the ball
	std::random_device rd;	
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> fdistrib(0.1, 0.4);

	Ball::Ball()
	{
		this->setTexture(getTextureFromColor(sf::Color::White));
		this->setTextureRect(sf::IntRect(0, 0, 8, 8));
		this->setPosition(396, 296);
	}

	sf::Vector2f& Ball::getSpeed()
	{
		return speed;
	}

	void Ball::setSpeed(const sf::Vector2f& _speed)
	{
		speed = _speed;
	}
}
