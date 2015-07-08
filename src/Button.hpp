#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

namespace ping {
	
	namespace GameMenu 
	{
		class Button : public sf::Text
		{
			using Text::Text;
		public:
			bool isClicked(const sf::Event&, const sf::RenderWindow&) const;
			bool isHoveredOver(const sf::RenderWindow&) const;
		};
	}
}
#endif
