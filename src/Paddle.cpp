#include "Paddle.hpp"

namespace ping
{
	const sf::Vector2f Paddle::paddleSpeed = sf::Vector2f(0, 15);

	Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2i& size)
	{
		this -> setTexture(getTextureFromColor(sf::Color::White));
		this -> setTextureRect(sf::IntRect(sf::Vector2i(0, 0), size));
		this -> setPosition(position);
	}

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
