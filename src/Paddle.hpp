#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

#include "AppState.hpp"

namespace ping
{
	class Paddle : public sf::Sprite
	{
	public:
		Paddle(const sf::Vector2f&, const sf::Vector2i&);
	};
}
#endif
