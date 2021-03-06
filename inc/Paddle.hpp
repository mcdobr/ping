#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace ping
{
	class Paddle : public sf::Sprite
	{
		static const sf::Vector2f paddleSpeed;

		sf::Vector2f speed;
		sf::Keyboard::Key upKey, downKey;
		bool isInMovement;

	public:
		Paddle();
		Paddle(const sf::Texture&, const sf::Vector2f&, const sf::Vector2i&, const sf::Keyboard::Key&, const sf::Keyboard::Key&);

		//Setters
		void setSpeed(const sf::Vector2f&);
		
		//Getters
		bool isMoving();	
		sf::Vector2f& getSpeed();
		sf::Keyboard::Key& getUpKey();
		sf::Keyboard::Key& getDownKey();

		//"REAL" functions
		bool canMove(const sf::Vector2f& speed);
	};
}
#endif
