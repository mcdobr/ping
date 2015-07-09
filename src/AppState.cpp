#include "AppState.hpp"

namespace ping
{
	sf::Texture getTextureFromColor(const sf::Color& color)
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
