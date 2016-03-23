#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <SFML/Audio.hpp>
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
		AudioMenu,
		SelectWinScore
	};

	class Game
	{
		//static const std::string gameName = "Ping";
		unsigned int screenWidth, screenHeight, scoreToWin = 5;
		std::pair<unsigned int, unsigned int> score;
		
		GameState currentState;
		ping::GameMenu::Button playButton;

		Paddle leftPaddle, rightPaddle;
		Ball ball;

		sf::RenderWindow window;		
		sf::Font font;
		sf::Texture whiteTexture;

		sf::SoundBuffer soundBuffer;
		sf::Sound boopSound;

		//Private interface
		
		void drawAssets();
		void drawScore();

		
		void handleEvents();
		void handleCollisions();
		void handleScore();
		void handleSelectingWinScore();
		

		void display();
		
		
		void reset();
		void resetAssets();

	public:
		Game();
		int run();
	};
}
#endif
