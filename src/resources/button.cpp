#include "button.h"
button::button(float x_pos, float y_pos, float width, float height,
	sf::Font font, std::string text,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->shape.setPosition(sf::Vector2f(x_pos, y_pos));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	// set text to center
	this->text.setPosition(
		this->shape.getPosition().x / 2.f - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y / 2.f - this->text.getGlobalBounds().height / 2.f);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
}

void button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}