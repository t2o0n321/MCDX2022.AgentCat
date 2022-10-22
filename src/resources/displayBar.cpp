#include "displayBar.h"
displayBar::displayBar(sf::Vector2f pos, sf::Vector2f size, sf::Color Backgroundcolor, sf::Font font, sf::Color textColor, int textSize, std::string defaultText)
{
	this->backgroundColor = Backgroundcolor;
	this->defaultText = defaultText;
	this->textColor = textColor;
	this->textSize = textSize;

	this->shape.setPosition(pos);
	this->shape.setSize(size);
	this->shape.setFillColor(this->backgroundColor);

	this->text.setFont(font);
	this->text.setFillColor(this->textColor);
	this->text.setCharacterSize(this->textSize);
	this->text.setString(this->defaultText);
}