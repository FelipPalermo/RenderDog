#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>


class Button_GetString {
	
public:

	Button_GetString(int PosX, int PosY, sf::Vector2f size) {

		BebasNeue.loadFromFile("C:/Users/Felipe/source/repos/Render_Dog/Render_Dog/BebasNeue-Regular.otf");

		Button_Created.setSize(size);	Button_Created.setOrigin(Button_Created.getSize().x / 2, Button_Created.getSize().y / 2);
		Button_Created.setPosition(PosX, PosY);
		Button_Created.setFillColor(sf::Color::White);
		
		GsText.setFont(BebasNeue);
		GsText.setCharacterSize(25);		GsText.setPosition(Button_Created.getPosition().x - 26, Button_Created.getPosition().y - 15);
		GsText.setString("Paste");		GsText.setFillColor(sf::Color::Black);

	}

	bool colision(int MouseX, int MouseY) {

		unsigned short BPx = Button_Created.getPosition().x;			unsigned short BSx = Button_Created.getSize().x / 2;
		unsigned short BPy = Button_Created.getPosition().y;			unsigned short BSy = Button_Created.getSize().y / 2;


		if (MouseX >= BPx - BSx && MouseY >= BPy - BSy && MouseX <= BPx + BSx && MouseY <= BPy + BSy) {
			Button_Created.setFillColor(sf::Color::Red);
			GsText.setFillColor(sf::Color::White);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				return true;
			}
		}
		else { Button_Created.setFillColor(sf::Color::White);	GsText.setFillColor(sf::Color::Black); } 

		return false;
	}



	void render(sf::RenderWindow& window) {

		window.draw(Button_Created);
		window.draw(GsText);
	}

private:

	sf::RectangleShape Button_Created;
	sf::Text GsText;	sf::Font BebasNeue;
};

