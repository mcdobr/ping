#include "Button.hpp"

namespace ping
{
	namespace GameMenu
	{
		bool Button::isClicked(const sf::Event& event, const sf::RenderWindow& window) const
		{
			//If the left mouse button is pressed and is pressed in the bounding box of the button
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) 
			&& this->getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
				return true;
			return false;
		}

		bool Button::isHoveredOver(const sf::RenderWindow& window) const
		{
			if (this->getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
				return true;
			return false;
		}
	}
}
