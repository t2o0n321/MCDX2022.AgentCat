#include "PCH.hpp"
class displayBar
{
public:
	displayBar(sf::Vector2f pos, sf::Vector2f size, sf::Color Backgroundcolor, sf::Font font, sf::Color textColor, int textSize, std::string defaultText);
	void render(sf::RenderTarget& target);
	void update();

private:
	sf::RectangleShape shape;
	sf::Text text;
	sf::Color backgroundColor;
	sf::Color textColor;
	int textSize;
	std::string defaultText;
};