#include "Ball.hpp"

#include <SFML/Graphics.hpp>

namespace ping 
{
	//Create a random number generator to set the initial speed of the ball
	std::random_device rd;	
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> fDistrib(2.1, 3.4);
	std::uniform_int_distribution<int> sgnDistrib(0, 1);

	Ball::Ball()
	{
	}

	Ball::Ball(const sf::Texture& texture)
	{
		this->setTexture(texture);
		this->setTextureRect(sf::IntRect(0, 0, 8, 8));
		this->setPosition(396, 296);
		this->setSpeed(sf::Vector2f(fDistrib(mt) * std::pow(-1, sgnDistrib(mt)), 
									fDistrib(rd) * std::pow(-1, sgnDistrib(mt))));
	}

	sf::Vector2f& Ball::getSpeed()
	{
		return speed;
	}

	void Ball::setSpeed(const sf::Vector2f& _speed)
	{
		speed = _speed;
	}

	bool Ball::isLeftOfScreen(const sf::RenderWindow& window) const
	{
		if (this -> getPosition().x + this -> getGlobalBounds().width < 0)
			return true;
		return false;
	}

	bool Ball::isRightOfScreen(const sf::RenderWindow& window) const
	{
		if (this -> getPosition().x > window.getSize().x)
			return true;
		return false;
	}
}
