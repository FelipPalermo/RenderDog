#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>


class Button_Watch {

public:

	Button_Watch(int PosX, int PosY, sf::Vector2f size) {

		BwatchFont.loadFromFile("C:/Users/Felipe/source/repos/Render_Dog/Render_Dog/BebasNeue-Regular.otf");
		WatchText.setFont(BwatchFont);

		

		Button_Created.setSize(size);	Button_Created.setOrigin(Button_Created.getSize().x / 2, Button_Created.getSize().y / 2);
		Button_Created.setPosition(PosX, PosY);
		Button_Created.setFillColor(sf::Color::White);
		
		WatchText.setFillColor(sf::Color::Black);
		WatchText.setCharacterSize(55);
		WatchText.setPosition(350,695);
		WatchText.setString("Watch");

	}

	bool colision(int MouseX, int MouseY) {

		int BPx = Button_Created.getPosition().x;			int BSx = Button_Created.getSize().x / 2;
		int BPy = Button_Created.getPosition().y;			int BSy = Button_Created.getSize().y / 2;


		if (MouseX >= BPx - BSx && MouseY >= BPy - BSy && MouseX <= BPx + BSx && MouseY <= BPy + BSy) {
			WatchText.setFillColor(sf::Color::White);
			Button_Created.setFillColor(sf::Color::Red);
			

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				return true;
			}
		}
		else
		{
			WatchText.setFillColor(sf::Color::Black);
			Button_Created.setFillColor(sf::Color::White);
		}

		return false;
	}



	void render(sf::RenderWindow& window) {

		window.draw(Button_Created);
		window.draw(WatchText);
	}

private:

	sf::RectangleShape Button_Created;
	sf::Text WatchText;		sf::Font BwatchFont; 
};

