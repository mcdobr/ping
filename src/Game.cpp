#include "Game.hpp"

namespace ping
{
	Game::Game()
	{
		screenWidth = 800; screenHeight = 600;
		score = std::make_pair(0, 0);

		currentState = GameState::MainMenu;

		window.create(sf::VideoMode(screenWidth, screenHeight), "Ping");
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(60);

		font.loadFromFile("Armageda Wide.ttf");

		//Create the white texture
		sf::Image img;
		img.create(128, 128, sf::Color::White);
		whiteTexture.loadFromImage(img, sf::IntRect(0, 0, 8, 64));

		resetAssets();

		//Initialize sound handling part 
		soundBuffer.loadFromFile("boop_soundFX.wav");
		boopSound.setBuffer(soundBuffer);
	}

	void Game::resetAssets()
	{
		//Create paddles and ball
		leftPaddle = Paddle(whiteTexture, sf::Vector2f(10, 268), sf::Vector2i(8, 64),
							sf::Keyboard::A, sf::Keyboard::D);
		rightPaddle = Paddle(whiteTexture, sf::Vector2f(782, 268), sf::Vector2i(8, 64),
							sf::Keyboard::Right, sf::Keyboard::Left);
		ball = Ball(whiteTexture);
	}

	void Game::reset()
	{
		score = std::make_pair(0, 0);
		resetAssets();
		currentState = GameState::GamePlay;
	}

	void Game::drawScore()
	{
		sf::Text lScore(std::to_string(score.first), font);
		lScore.setPosition(100, 50);

		sf::Text rScore(std::to_string(score.second), font);
		rScore.setPosition(700, 50);
		
		window.draw(lScore);
		window.draw(rScore);
	}

	void Game::drawAssets()
	{
		window.draw(ball);
		window.draw(leftPaddle);
		window.draw(rightPaddle);
	}

	void Game::handleScore()
	{
		//if Ball is outside screen
		if (ball.isLeftOfScreen(window) || ball.isRightOfScreen(window))
		{
			if (ball.isLeftOfScreen(window))
				++score.second;		
			else
				++score.first;
		
			//if game is over
			if (score.first < scoreToWin && score.second < scoreToWin)
				resetAssets();
			else
				currentState = GameState::GameOver;
		}
	}
	

	void Game::handleCollisions()
	{
		//if the ball hits the top or the bottom of the screen
		if (ball.getPosition().y < fabs(ball.getSpeed().y) || 
				fabs(ball.getPosition().y + ball.getGlobalBounds().height- screenHeight) < ball.getSpeed().y)
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
			ball.getSpeed().x *= -1.1;
			while (ball.getGlobalBounds().intersects(hitPaddle -> getGlobalBounds()))
				ball.move(ball.getSpeed());
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
					ball.setSpeed(sf::Vector2f(3.0, -2.75));

				if (sf::Keyboard::isKeyPressed(leftPaddle.getUpKey()) && leftPaddle.canMove(sf::Vector2f(0, -3)))
					leftPaddle.move(0, -3);
				if (sf::Keyboard::isKeyPressed(leftPaddle.getDownKey()) && leftPaddle.canMove(sf::Vector2f(0, 3)))
					leftPaddle.move(0, 3);
				if (sf::Keyboard::isKeyPressed(rightPaddle.getUpKey()) && rightPaddle.canMove(sf::Vector2f(0, -3)))
					rightPaddle.move(0, -3);
				if (sf::Keyboard::isKeyPressed(rightPaddle.getDownKey()) && rightPaddle.canMove(sf::Vector2f(0, 3)))
					rightPaddle.move(0, 3);

				ball.move(ball.getSpeed());
				
				drawScore();
				drawAssets();

				handleScore();
				handleCollisions();
				break;
			}
			case GameState::GameOver:
			{
				sf::Text gameOverMsg("GAME OVER!", font);
				gameOverMsg.setPosition(350, 375);
				
				sf::Text winner("", font);
				winner.setPosition(350, 410);
				if (score.first == scoreToWin)
					winner.setString("PLAYER 1 WON!\nPRESS SPACE TO PLAY AGAIN!\n");
				else if (score.second == scoreToWin)
					winner.setString("PLAYER 2 WON!\nPRESS SPACE TO PLAY AGAIN!\n");
				
				window.draw(gameOverMsg);
				window.draw(winner);
				break;
			}
			case GameState::MainMenu:
			{
				int wid = playButton.getLocalBounds().width;
				int hei = playButton.getLocalBounds().height;
				playButton.setString("PLAY");
				playButton.setFont(font);
				playButton.setCharacterSize(30);
				playButton.setPosition((screenWidth - wid) / 2, (screenHeight - hei) / 2);
				
				
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
				case sf::Event::KeyPressed:
				{
					if (currentState == GameState::GameOver && event.key.code == sf::Keyboard::Space)
						reset();
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}

	//Main Game loop
	int Game::run()
	{
		while (window.isOpen())
		{
			display();
			handleEvents();
		}
		return 0;
	}
}
