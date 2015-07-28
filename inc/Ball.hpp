#ifndef BALL_HPP
#define BALL_HPP

#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>

namespace ping
{
	class Ball : public sf::Sprite
	{
		static const sf::IntRect ballRect;
		static const sf::Vector2f originalPosition;

		sf::Vector2f speed;

	public:
		Ball();
		Ball(const sf::Texture&);

		//Getters
		sf::Vector2f& getSpeed();
		//Setters
		void setSpeed(const sf::Vector2f& _speed);

		bool isLeftOfScreen(const sf::RenderWindow&) const;
		bool isRightOfScreen(const sf::RenderWindow&) const;
	};
}


#endif
