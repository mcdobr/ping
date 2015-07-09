#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

#include "AppState.hpp"

namespace ping
{
	class Paddle : public sf::Sprite
	{
		static const sf::Vector2f paddleSpeed;

		sf::Vector2f speed;
		bool isInMovement;
	public:
		Paddle(const sf::Vector2f&, const sf::Vector2i&);

		//Setters
		void setSpeed(const sf::Vector2f&);
		
		//Getters
		bool isMoving();	
		sf::Vector2f& getSpeed();
		
		//"REAL" functions
		void moveUp();
		void moveDown();
	};
}
#endif
