#include "PCH.hpp"

enum btn_states
{
	BTN_IDLE = 0,
	BTN_HOVER = 1,
	BTN_ACTIVE = 2
};

// button(float x_pos, float y_pos, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
class button
{
public:
	button(float x_pos, float y_pos, float width, float height,
		sf::Font font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color outlineColor);
	~button();
	bool isPressed();
	std::string getInnerString();
	void render(sf::RenderTarget& target);
	void update(const sf::Vector2f mousePos);
	void setTextSize(int size);
	void setTextColor(sf::Color color);
	void setOutlineColor(sf::Color color);

private:
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;
	std::string innerString;
	int textSize = 40;						// 16 by default
	sf::Color textColor = sf::Color::Black; // white by default
	sf::Color idleColor, hoverColor, activeColor;
	sf::Color outlineColor;
	//button state
	short unsigned btnState;
	bool click_lock = false;
};