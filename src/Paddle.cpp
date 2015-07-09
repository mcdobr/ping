#include "Paddle.hpp"

namespace ping
{
	Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2i& size)
	{
		this->setTexture(getTextureFromColor(sf::Color::White));
		this->setTextureRect(sf::IntRect(sf::Vector2i(0, 0), size));
		this->setPosition(position);
	}
}
