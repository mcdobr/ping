#ifndef BALL_HPP
#define BALL_HPP

#include <random>
#include <SFML/Graphics.hpp>

#include "AppState.hpp"

namespace ping
{
	class Ball : public sf::Sprite
	{
		static const sf::IntRect ballRect;
		static const sf::Vector2f originalPosition;

		sf::Vector2f speed;

	public:
		Ball();
	};
}


#endif
