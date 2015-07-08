#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace ping {
	
	namespace GameMenu 
	{
		class Button : public sf::Text
		{
			using Text::Text;
		public:
			//Constructor needed because of VS 2013 compiler being slow to implement c++11 features
			Button(const sf::String&, const sf::Font&);

			bool isClicked(const sf::Event&, const sf::RenderWindow&) const;
			bool isHoveredOver(const sf::RenderWindow&) const;
		};
	}
}
#endif
