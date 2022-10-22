#include "button.h"
button::button(float x_pos, float y_pos, float width, float height,
	sf::Font font, std::string text,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color outlineColor)
{
	this->btnState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x_pos, y_pos));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(this->font);
	this->innerString = text;
	this->text.setString(this->innerString);
	this->text.setFillColor(this->textColor);
	this->text.setCharacterSize(this->textSize);
	// set text to center
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->outlineColor = outlineColor;

	this->shape.setFillColor(this->idleColor);
	this->shape.setOutlineColor(this->outlineColor);
	this->shape.setOutlineThickness(3.f);
	// this->shape.setOutlineColor()
}

bool button::isPressed()
{
	return this->btnState == BTN_ACTIVE;
}

void button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

void button::update(const sf::Vector2f mousePos)
{
	// idle
	this->btnState = BTN_IDLE;
	// hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->btnState = BTN_HOVER;
		// pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->btnState = BTN_ACTIVE;
		}
	}
	switch (this->btnState)
	{
		case BTN_IDLE:
			this->shape.setFillColor(this->idleColor);
			break;
		case BTN_HOVER:
			this->shape.setFillColor(this->hoverColor);
			break;
		case BTN_ACTIVE:
			this->shape.setFillColor(this->activeColor);
			break;
		default:
			this->shape.setFillColor(sf::Color::Red);
			break;
	}
}

void button::setTextColor(sf::Color color)
{
	this->textColor = color;
	this->text.setFillColor(this->textColor);
}

void button::setTextSize(int size)
{
	this->textSize = size;
	this->text.setCharacterSize(this->textSize);
}

void button::setOutlineColor(sf::Color color)
{
	this->outlineColor = color;
	this->shape.setOutlineColor(this->outlineColor);
}

std::string button::getInnerString()
{
	return this->innerString;
}

button::~button()
{
}