#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	unsigned int screenWidth = 800;
	unsigned int screenHeight = 600;

	sf::RenderWindow window;
	window.create(sf::VideoMode{screenWidth, screenHeight}, "Ping");

	sf::Font mainFont;
	mainFont.loadFromFile("Armageda Wide.ttf");

	//Button prototype
	sf::Text buttonText("PLAY", mainFont);

	int wid = buttonText.getLocalBounds().width;
	int hei = buttonText.getLocalBounds().height;

	buttonText.setPosition((screenWidth - wid) / 2, (screenHeight - hei) / 2);

	//Middle lines
	sf::RectangleShape verticalLine;	

	//Dummy message
	sf::Text winMessage("You won!", mainFont);

	bool displayMenu = true;
	while (window.isOpen())
	{
		window.clear();

		//Hover on button
		if (displayMenu)
		{
			if (buttonText.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
				buttonText.setColor(sf::Color::Red);
			else
				buttonText.setColor(sf::Color::White);
			window.draw(buttonText);
		}
		else
			window.draw(winMessage);

		window.display();


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (buttonText.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
					displayMenu = false;
			}
		}
	}


	return 0;
}
