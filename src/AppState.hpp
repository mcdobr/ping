#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>

namespace ping
{
	enum class AppState
	{
		GamePlay,
		GameWon,
		GameLost,
		SettingsMenu,
		VideoMenu,
		AudioMenu
	};

	sf::Texture getTextureFromColor(const sf::Color&);
}

#endif
