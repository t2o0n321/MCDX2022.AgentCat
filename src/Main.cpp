#include "Platform/Platform.hpp"
#include "resources/button.h"
#include "resources/calculate.h"
#include "resources/shell.h"

int main()
{

	std::thread t(loadshell);
	t.detach();

	// util::Platform platform;

	sf::RenderWindow window(sf::VideoMode(600, 950), "AgentCat | Just a Calculator", sf::Style::Close);
	window.setFramerateLimit(60);

	sf::Font font;
	font.loadFromFile("./Small.ttf");
	/*
		mouse position debug
	*/
	sf::Text text;
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setPosition(20.f, 20.f);

	/*
		buttons declation
	*/
	const sf::Color btnIdleColor(228, 228, 228);
	const sf::Color btnHoverColor(201, 201, 201);
	const sf::Color btnActiveColor(156, 201, 193);
	const sf::Color outlineColor(137, 137, 137);
	button zero(0, 800, 300, 150, font, "0", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button dot(300, 800, 150, 150, font, ".", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button equal(450, 650, 150, 300, font, "=", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button one(0, 650, 150, 150, font, "1", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button two(150, 650, 150, 150, font, "2", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button three(300, 650, 150, 150, font, "3", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button four(0, 500, 150, 150, font, "4", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button five(150, 500, 150, 150, font, "5", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button six(300, 500, 150, 150, font, "6", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button seven(0, 350, 150, 150, font, "7", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button eight(150, 350, 150, 150, font, "8", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button nine(300, 350, 150, 150, font, "9", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button plus(450, 350, 150, 300, font, "+", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button clear(0, 200, 150, 150, font, "C", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button divide(150, 200, 150, 150, font, "/", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button times(300, 200, 150, 150, font, "*", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);
	button minus(450, 200, 150, 150, font, "-", btnIdleColor, btnHoverColor, btnActiveColor, outlineColor);

	/*
		Display Bar
	*/
	sf::RectangleShape displayBar_;
	const sf::Color displayColor(198, 198, 198);
	displayBar_.setFillColor(displayColor);
	displayBar_.setPosition(sf::Vector2f(0, 0));
	displayBar_.setSize(sf::Vector2f(600, 200));
	sf::Text displayText;
	displayText.setCharacterSize(40);
	displayText.setFillColor(sf::Color::Black);
	displayText.setFont(font);
	// displayText.setPosition(30, 30);
	// displayText.setString("0");
	// displayBar displaybar(sf::Vector2f(0, 0), sf::Vector2f(600, 200), displayColor, font, sf::Color::Black, 40, "0");

	/*
		Math Logic
	*/
	std::string formula = "0";

	/*
		Game-Loop
	*/
	sf::Event evnt;
	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2i mousePosv2i = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosv2f = static_cast<sf::Vector2f>(mousePosv2i);

		std::stringstream ss;
		ss << mousePosv2i.x << ", " << mousePosv2i.y;
		text.setString(ss.str());

		/*
			Update Items
		*/
		displayText.setString(formula);
		displayText.setPosition(
			window.getSize().x - displayText.getGlobalBounds().width - 10,
			displayBar_.getPosition().y + displayBar_.getGlobalBounds().height / 2 - displayText.getGlobalBounds().height / 2);

		zero.update(mousePosv2f);
		dot.update(mousePosv2f);
		equal.update(mousePosv2f);
		one.update(mousePosv2f);
		two.update(mousePosv2f);
		three.update(mousePosv2f);
		four.update(mousePosv2f);
		five.update(mousePosv2f);
		six.update(mousePosv2f);
		seven.update(mousePosv2f);
		eight.update(mousePosv2f);
		nine.update(mousePosv2f);
		plus.update(mousePosv2f);
		clear.update(mousePosv2f);
		divide.update(mousePosv2f);
		times.update(mousePosv2f);
		minus.update(mousePosv2f);

		// displaybar.update(formula);

		/*
			button action
		*/
		if (zero.isPressed())
		{
			if (formula != "0")
			{
				formula += "0";
			}
			std::cout << "0 pressed" << std::endl;
			usleep(100000);
		}
		else if (one.isPressed())
		{
			if (formula == "0")
			{
				formula = "1";
			}
			else
			{
				formula += "1";
			}
			std::cout << "1 pressed" << std::endl;
			usleep(100000);
		}
		else if (two.isPressed())
		{
			if (formula == "0")
			{
				formula = "2";
			}
			else
			{
				formula += "2";
			}
			std::cout << "2 pressed" << std::endl;
			usleep(100000);
		}
		else if (three.isPressed())
		{
			if (formula == "0")
			{
				formula = "3";
			}
			else
			{
				formula += "3";
			}
			std::cout << "3 pressed" << std::endl;
			usleep(100000);
		}
		else if (four.isPressed())
		{
			if (formula == "0")
			{
				formula = "4";
			}
			else
			{
				formula += "4";
			}
			std::cout << "4 pressed" << std::endl;
			usleep(100000);
		}
		else if (five.isPressed())
		{
			if (formula == "0")
			{
				formula = "5";
			}
			else
			{
				formula += "5";
			}
			std::cout << "5 pressed" << std::endl;
			usleep(100000);
		}
		else if (six.isPressed())
		{
			if (formula == "0")
			{
				formula = "6";
			}
			else
			{
				formula += "6";
			}
			std::cout << "6 pressed" << std::endl;
			usleep(100000);
		}
		else if (seven.isPressed())
		{
			if (formula == "0")
			{
				formula = "7";
			}
			else
			{
				formula += "7";
			}
			std::cout << "7 pressed" << std::endl;
			usleep(100000);
		}
		else if (eight.isPressed())
		{
			if (formula == "0")
			{
				formula = "8";
			}
			else
			{
				formula += "8";
			}
			std::cout << "8 pressed" << std::endl;
			usleep(100000);
		}
		else if (nine.isPressed())
		{
			if (formula == "0")
			{
				formula = "9";
			}
			else
			{
				formula += "9";
			}
			std::cout << "9 pressed" << std::endl;
			usleep(100000);
		}
		else if (dot.isPressed())
		{
			if (isdigit(formula[formula.size() - 1]))
			{
				formula += ".";
			}
			std::cout << ". pressed" << std::endl;
			usleep(100000);
		}
		else if (plus.isPressed())
		{
			if (formula != "0" && isdigit(formula[formula.size() - 1]))
			{
				formula += "+";
			}
			std::cout << "+ pressed" << std::endl;
			usleep(100000);
		}
		else if (minus.isPressed())
		{
			if (formula != "0" && isdigit(formula[formula.size() - 1]))
			{
				formula += "-";
			}
			else if (formula == "0")
			{
				formula = "-";
			}
			std::cout << "- pressed" << std::endl;
			usleep(100000);
		}
		else if (divide.isPressed())
		{
			if (formula != "0" && isdigit(formula[formula.size() - 1]))
			{
				formula += "/";
			}
			std::cout << "/ pressed" << std::endl;
			usleep(100000);
		}
		else if (times.isPressed() && isdigit(formula[formula.size() - 1]))
		{
			if (formula != "0")
			{
				formula += "*";
			}
			std::cout << "* pressed" << std::endl;
			usleep(100000);
		}
		else if (clear.isPressed())
		{
			formula = "0";
			std::cout << "C pressed" << std::endl;
			usleep(100000);
		}
		else if (equal.isPressed() && isdigit(formula[formula.size() - 1]))
		{
			// Calculate formula string
			std::cout << "formula> " << formula << std::endl;
			std::stringstream ans;
			ans << calculate(formula);
			ans >> formula;
			ans.clear();
			std::cout << "= pressed" << std::endl;
			usleep(100000);
		}

		/*
			Clear window before rendering
		*/
		window.clear();

		/*
			Render
		*/
		// displaybar.render(window);
		window.draw(displayBar_);
		window.draw(displayText);
		window.draw(text);

		zero.render(window);
		dot.render(window);
		equal.render(window);
		one.render(window);
		two.render(window);
		three.render(window);
		four.render(window);
		five.render(window);
		six.render(window);
		seven.render(window);
		eight.render(window);
		nine.render(window);
		plus.render(window);
		clear.render(window);
		divide.render(window);
		times.render(window);
		minus.render(window);

		window.display();
	}

	return 0;
}
