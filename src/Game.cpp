#include "Game.hpp"

namespace ping
{
	Game::Game()
	{
		screenWidth = 800; screenHeight = 600;
	
		currentState = GameState::GamePlay;

		window.create(sf::VideoMode(screenWidth, screenHeight), "Ping");
		window.setVerticalSyncEnabled(true);
		
		font.loadFromFile("Armageda Wide.ttf");

		playButton.setString("PLAY");
		playButton.setFont(font);
		playButton.setCharacterSize(30);
	
		//Create the white texture
		sf::Image img;
		img.create(128, 128, sf::Color::White);
		//Create plain texture
		whiteTexture.loadFromImage(img, sf::IntRect(0, 0, 8, 64));

		//Create paddles and ball
		leftPaddle = Paddle(whiteTexture, sf::Vector2f(10, 268), sf::Vector2i(8, 64), sf::Keyboard::Key::A, sf::Keyboard::Key::D);
		rightPaddle = Paddle(whiteTexture, sf::Vector2f(782, 268), sf::Vector2i(8, 64), sf::Keyboard::Key::Right, sf::Keyboard::Key::Left);
		ball = Ball(whiteTexture);
	
		//Initialize sound handling part 
		soundBuffer.loadFromFile("boop_soundFX.wav");
		boopSound.setBuffer(soundBuffer);
	}

	void Game::handleCollisions()
	{
		//if the ball hits the top or the bottom of the screen
		//if (ball.getGlobalBounds().top < ball.getSpeed().y || ball.getGlobalBounds().top == screenWidth - ball.getGlobalBounds().height)
		if (ball.getPosition().y < fabs(ball.getSpeed().y) || fabs(ball.getPosition().y + ball.getGlobalBounds().height- screenHeight) < ball.getSpeed().y)
		{
			ball.getSpeed().y *= -1;
			return;
		}

		//if the ball hits a paddle
		Paddle* hitPaddle = nullptr;
		if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()))
			hitPaddle = &leftPaddle;

		if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))
			hitPaddle = &rightPaddle;

		if (hitPaddle)
		{
			ball.getSpeed().x *= -1;

			boopSound.play();
		}
	}

	void Game::display()
	{
		window.clear();

		//Draw stuff on screen
		switch (currentState)
		{
			case GameState::GamePlay:
			{
				if (ball.getSpeed() == sf::Vector2f(0.0, 0.0))
					ball.setSpeed(sf::Vector2f(2.0, -1.15));

				if (sf::Keyboard::isKeyPressed(leftPaddle.getUpKey()) && leftPaddle.canMove(sf::Vector2f(0, -2)))
					leftPaddle.move(0, -2);
				if (sf::Keyboard::isKeyPressed(leftPaddle.getDownKey()) && leftPaddle.canMove(sf::Vector2f(0, 2)))
					leftPaddle.move(0, 2);
				if (sf::Keyboard::isKeyPressed(rightPaddle.getUpKey()) && rightPaddle.canMove(sf::Vector2f(0, -2)))
					rightPaddle.move(0, -2);
				if (sf::Keyboard::isKeyPressed(rightPaddle.getDownKey()) && rightPaddle.canMove(sf::Vector2f(0, 2)))
					rightPaddle.move(0, 2);

				ball.move(ball.getSpeed());

				handleCollisions();
				
				window.draw(ball);
				window.draw(leftPaddle);
				window.draw(rightPaddle);
				break;
			}
			case GameState::GameOver:
			{
				break;
			}
			case GameState::MainMenu:
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
}
