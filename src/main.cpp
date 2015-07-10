#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "AppState.hpp"
#include "Button.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

int main()
{
	unsigned int screenWidth = 800;
	unsigned int screenHeight = 600;

	sf::RenderWindow window;
	window.create(sf::VideoMode{screenWidth, screenHeight}, "Ping");

	sf::Font mainFont;
	mainFont.loadFromFile("Armageda Wide.ttf");

	//Button prototype
	ping::GameMenu::Button playButton("PLAY", mainFont);

	int wid = playButton.getLocalBounds().width;
	int hei = playButton.getLocalBounds().height;

	playButton.setPosition((screenWidth - wid) / 2, (screenHeight - hei) / 2);

	//Create paddles and ball
	ping::Paddle leftPaddle(sf::Vector2f(10, 268), sf::Vector2i(8, 64), sf::Keyboard::Key::A, sf::Keyboard::Key::D);
	ping::Paddle rightPaddle(sf::Vector2f(782, 268), sf::Vector2i(8, 64), sf::Keyboard::Key::Right, sf::Keyboard::Key::Left);
	ping::Ball ball;

	using ping::AppState;
	ping::AppState currentState = ping::AppState::SettingsMenu;

	//Main application loop
	while (window.isOpen())
	{
		window.clear();

		//Draw stuff on screen
		switch (currentState)
		{
			case AppState::GamePlay:
			{

				if (sf::Keyboard::isKeyPressed(leftPaddle.getUpKey()) && leftPaddle.canMove(sf::Vector2f(0, -0.3)))
					leftPaddle.move(0, -0.3);
				if (sf::Keyboard::isKeyPressed(leftPaddle.getDownKey()) && leftPaddle.canMove(sf::Vector2f(0, 0.3)))
					leftPaddle.move(0, 0.3);
				if (sf::Keyboard::isKeyPressed(rightPaddle.getUpKey()) && rightPaddle.canMove(sf::Vector2f(0, -0.3)))
					rightPaddle.move(0, -0.3);
				if (sf::Keyboard::isKeyPressed(rightPaddle.getDownKey()) && rightPaddle.canMove(sf::Vector2f(0, 0.3)))
					rightPaddle.move(0, 0.3);

					
				ball.move(ball.getSpeed());

				if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()) || ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))
					ball.getSpeed().x *= -1.0;

			
				window.draw(ball);	
				window.draw(leftPaddle);
				window.draw(rightPaddle);
				break;
			}
			case AppState::GameWon:
			{
				break;
			}
			case AppState::GameLost:
			{
				break;
			}
			case AppState::SettingsMenu:
			{
				if (playButton.isHoveredOver(window))	
					playButton.setColor(sf::Color::Red);
				else
					playButton.setColor(sf::Color::White);
				window.draw(playButton);
				break;
			}
			case AppState::VideoMenu:
			{
				break;
			}
			case AppState::AudioMenu:
			{
				break;
			}
		}
		window.display();

		//Handle events
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
					{
						currentState = AppState::GamePlay;
						ball.setSpeed(sf::Vector2f(0.1, 0.0));
					}
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}
	return 0;
}
