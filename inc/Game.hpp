#ifndef GAME_HPP
#define GAME_HPP

#include <cmath>
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
		MainMenu,
		VideoMenu,
		AudioMenu
	};

	class Game
	{
		//static const std::string gameName = "Ping";

		unsigned int screenWidth, screenHeight;
		
		GameMenu::Button playButton;
		GameState currentState;

		Paddle leftPaddle, rightPaddle;
		Ball ball;

		sf::RenderWindow window;		
		sf::Font font;
		sf::Texture whiteTexture;

	public:
		Game();

		void handleCollisions();
		void display();
		void handleEvents();		
		int run();
		
		static sf::Texture getTextureFromColor(const sf::Color&);
	};
}
#endif
