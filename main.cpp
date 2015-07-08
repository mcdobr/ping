#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Button.hpp"

int main()
{
	unsigned int screenWidth = 800;
	unsigned int screenHeight = 600;

	sf::RenderWindow window;
	window.create(sf::VideoMode{screenWidth, screenHeight}, "Ping");

	sf::Font mainFont;
	mainFont.loadFromFile("Armageda Wide.ttf");

	//Button prototype
	GameMenu::Button playButton("PLAY", mainFont);

	int wid = playButton.getLocalBounds().width;
	int hei = playButton.getLocalBounds().height;

	playButton.setPosition((screenWidth - wid) / 2, (screenHeight - hei) / 2);

	//Dummy message
	sf::Text winMessage("You won!", mainFont);

	bool displayMenu = true;
	while (window.isOpen())
	{
		window.clear();

		//Hover on button
		if (displayMenu)
		{
			if (playButton.isHoveredOver(window))	
				playButton.setColor(sf::Color::Red);
			else
				playButton.setColor(sf::Color::White);
			window.draw(playButton);
		}
		else
			window.draw(winMessage);

		window.display();


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (playButton.isClicked(event, window))	
					displayMenu = false;
		}
	}

	return 0;
}
