#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>


class Button_Clear {

public:

	Button_Clear(int PosX, int PosY, sf::Vector2f size) {
		
		BebasNeue.loadFromFile("C:/Users/Felipe/source/repos/Render_Dog/Render_Dog/BebasNeue-Regular.otf");

		Button_Created.setSize(size);	Button_Created.setOrigin(Button_Created.getSize().x / 2, Button_Created.getSize().y / 2);
		Button_Created.setPosition(PosX, PosY);
		Button_Created.setFillColor(sf::Color::White);	
		
		ClearText.setFont(BebasNeue);
		ClearText.setCharacterSize(25);		ClearText.setPosition(Button_Created.getPosition().x - 24, Button_Created.getPosition().y - 15);
		ClearText.setString("Clear");		ClearText.setFillColor(sf::Color::Black);
	
	}

	bool colision(int MouseX, int MouseY) {

		unsigned short BPx = Button_Created.getPosition().x;			unsigned short BSx = Button_Created.getSize().x / 2;
		unsigned short BPy = Button_Created.getPosition().y;			unsigned short BSy = Button_Created.getSize().y / 2;


		if (MouseX >= BPx - BSx && MouseY >= BPy - BSy && MouseX <= BPx + BSx && MouseY <= BPy + BSy) {
			Button_Created.setFillColor(sf::Color::Red);
			ClearText.setFillColor(sf::Color::White);
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			
			return true;
			}
		}
		else { Button_Created.setFillColor(sf::Color::White); ClearText.setFillColor(sf::Color::Black); }

		return false;
	}
	


	void render(sf::RenderWindow& window) {
		
		window.draw(Button_Created);
		window.draw(ClearText);
	}

private:

	sf::RectangleShape Button_Created;
	sf::Text ClearText;		sf::Font BebasNeue;

};

