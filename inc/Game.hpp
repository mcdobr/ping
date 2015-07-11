#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Ball.hpp"
#include "Button.hpp"
#include "Paddle.hpp"

namespace ping
{
	enum class GameState
	{
		GamePlay,
		GameOver,
		SettingsMenu,
		VideoMenu,
		AudioMenu
	};

	class Game
	{
		//static const std::string gameName = "Ping";

		unsigned int screenWidth, screenHeight;
		GameState currentState;
		ping::GameMenu::Button playButton;
		sf::RenderWindow window;		
		sf::Font font;

	public:
		Game();
		
		void display();
		void handleEvents();		
		int run();
		
		static sf::Texture getTextureFromColor(const sf::Color&);
	};
}
#endif
