#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "AppState.hpp"
#include "Button.hpp"

int main()
{
	unsigned int screenWidth = 800;
	unsigned int screenHeight = 600;

	const sf::Vector2f paddleSpeed = {0, 15};

	sf::RenderWindow window;
	window.create(sf::VideoMode{screenWidth, screenHeight}, "Ping");

	sf::Font mainFont;
	mainFont.loadFromFile("Armageda Wide.ttf");

	//Button prototype
	ping::GameMenu::Button playButton("PLAY", mainFont);

	int wid = playButton.getLocalBounds().width;
	int hei = playButton.getLocalBounds().height;

	playButton.setPosition((screenWidth - wid) / 2, (screenHeight - hei) / 2);

	//Dummy message
	sf::Text winMessage("You won!", mainFont);

	//Create a dummy image
	sf::Image whiteImg;
	whiteImg.create(128, 128, sf::Color::White);
	
	//Create the white plain texture
	sf::Texture whiteTexture;
	whiteTexture.loadFromImage(whiteImg, sf::IntRect(0, 0, 8, 64));

	sf::Sprite leftPaddle;
	leftPaddle.setTexture(whiteTexture);
	leftPaddle.setTextureRect(sf::IntRect(0, 0, 8, 64));
	leftPaddle.setPosition(10, (screenHeight - 64) / 2);

	sf::Sprite rightPaddle;
	rightPaddle.setTexture(whiteTexture);
	rightPaddle.setTextureRect(sf::IntRect(0, 0, 8, 64));
	rightPaddle.setPosition(screenWidth - 18, (screenHeight - 64) / 2);

	sf::Sprite ball;
	ball.setTexture(whiteTexture);
	ball.setTextureRect(sf::IntRect(0, 0, 8, 8));
	ball.setPosition((screenWidth - 8) / 2, (screenHeight - 8) / 2);

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
						currentState = AppState::GamePlay;
				}
				case sf::Event::KeyPressed:
				{
					if (currentState == AppState::GamePlay)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && leftPaddle.getPosition().y >= 0)
						{
							leftPaddle.move(-paddleSpeed);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && leftPaddle.getPosition().y <= 536)
						{
							leftPaddle.move(paddleSpeed);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && rightPaddle.getPosition().y <= 536)
						{
							rightPaddle.move(paddleSpeed);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && rightPaddle.getPosition().y >= 0)
						{
							rightPaddle.move(-paddleSpeed);
						}
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
