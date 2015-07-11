#include "Game.hpp"

namespace ping
{
	Game::Game()
	{
		screenWidth = 800; screenHeight = 600;
		
		window.create(sf::VideoMode(screenWidth, screenHeight), /*gameName*/"Ping");
		window.setVerticalSyncEnabled(true);
		
		font.loadFromFile("Armageda Wide.ttf");
	}
	
	void Game::display()
	{
		//Create paddles and ball
		ping::Paddle leftPaddle(getTextureFromColor(sf::Color::White), sf::Vector2f(10, 268), sf::Vector2i(8, 64), sf::Keyboard::Key::A, sf::Keyboard::Key::D);
		ping::Paddle rightPaddle(getTextureFromColor(sf::Color::White), sf::Vector2f(782, 268), sf::Vector2i(8, 64), sf::Keyboard::Key::Right, sf::Keyboard::Key::Left);
		ping::Ball ball(getTextureFromColor(sf::Color::White));


		window.clear();

		//Draw stuff on screen
		switch (currentState)
		{
			case GameState::GamePlay:
			{
				if (ball.getSpeed() == sf::Vector2f(0.0, 0.0))
					ball.setSpeed(sf::Vector2f(0.1, 0.0));

				if (sf::Keyboard::isKeyPressed(leftPaddle.getUpKey()) && leftPaddle.canMove(sf::Vector2f(0, -1)))
					leftPaddle.move(0, -1);
				if (sf::Keyboard::isKeyPressed(leftPaddle.getDownKey()) && leftPaddle.canMove(sf::Vector2f(0, 1)))
					leftPaddle.move(0, 1);
				if (sf::Keyboard::isKeyPressed(rightPaddle.getUpKey()) && rightPaddle.canMove(sf::Vector2f(0, -1)))
					rightPaddle.move(0, -1);
				if (sf::Keyboard::isKeyPressed(rightPaddle.getDownKey()) && rightPaddle.canMove(sf::Vector2f(0, 1)))
					rightPaddle.move(0, 1);

				
				ball.move(ball.getSpeed());

				if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()) || ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))
					ball.getSpeed().x *= -1.0;

		
				window.draw(ball);	
				window.draw(leftPaddle);
				window.draw(rightPaddle);
				break;
			}
			case GameState::GameOver:
			{
				break;
			}
			case GameState::SettingsMenu:
			{
				if (playButton.isHoveredOver(window))	
					playButton.setColor(sf::Color::Red);
				else
					playButton.setColor(sf::Color::White);
				window.draw(playButton);
				break;
			}
			case GameState::VideoMenu:
			{
				break;
			}
			case GameState::AudioMenu:
			{
				break;
			}
		}
		window.display();
	}

	void Game::handleEvents()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					window.close();
					break;
				}
				case sf::Event::MouseButtonPressed:
				{
					if (playButton.isClicked(event, window))
						currentState = GameState::GamePlay;
					break;
				}
				default:
				{
				break;
				}
			}
		}
	}

	//Need to refactor this as well
	int Game::run()
	{
		//Button prototype
		ping::GameMenu::Button playButton("PLAY", font);

		int wid = playButton.getLocalBounds().width;
		int hei = playButton.getLocalBounds().height;

		playButton.setPosition((screenWidth - wid) / 2, (screenHeight - hei) / 2);

		//Main application loop
		while (window.isOpen())
		{
			display();
			handleEvents();
		}
		return 0;
	}
	
	sf::Texture Game::getTextureFromColor(const sf::Color& color)
	{
		//create a dummy image
		sf::Image img;
		img.create(128, 128, color);
		
		//Create plain texture
		sf::Texture texture;
		texture.loadFromImage(img, sf::IntRect(0, 0, 8, 64));
		return texture;
	}
}
