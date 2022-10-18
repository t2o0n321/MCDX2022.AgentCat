#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class button
{
public:
	button(float x_pos, float y_pos, float width, float height,
		sf::Font font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~button();
	void render(sf::RenderTarget* target);

private:
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;
	sf::Color idleColor, hoverColor, activeColor;
};