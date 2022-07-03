#include <SFML/Graphics.hpp>
#include "Button_Clear.h"
#include "Button_GetString.h"
#include "TextBox.h"
#include "Button_Watch.h"


int main() {


	// Render window
	sf::RenderWindow window(sf::VideoMode(800, 800), "Render Dog");		window.setFramerateLimit(60.f);
	
	window.setKeyRepeatEnabled(false);



	// Ui
	Button_Clear B1(617, 450, sf::Vector2f(70, 35));
	Button_GetString B2(184, 450, sf::Vector2f(70, 35));
	Button_Watch BWatch(400,730, sf::Vector2f(720, 80));
	TextBox TB1(400, 400, 500, 50);


	// BG gradient
	sf::Vertex BG[4] = {
		sf::Vertex(sf::Vector2f(0,-300), sf::Color::Black),
		sf::Vertex(sf::Vector2f(800,-300), sf::Color::Black),
		sf::Vertex(sf::Vector2f(800,9900), sf::Color::White),
		sf::Vertex(sf::Vector2f(0,9900), sf::Color::White),
	};


	// Main loop
	while (window.isOpen()) {
		
		// Variaveis em Loop
		sf::Event event;
		unsigned short MouseX = sf::Mouse::getPosition(window).x;
		unsigned short MouseY = sf::Mouse::getPosition(window).y;


		// Loop de eventos
		while (window.pollEvent(event)) {
		
			if (event.type == sf::Event::Closed)	window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

			BWatch.colision(MouseX, MouseY);
			TB1.Write(MouseX, MouseY, event);
			TB1.Clear(B1.colision(MouseX, MouseY));
			TB1.GetString(B2.colision(MouseX, MouseY));

		
		}

		// Renderizacao		
		window.draw(BG, 4 ,sf::Quads);
		B1.render(window);
		B2.render(window);
		BWatch.render(window);
		TB1.Render(window);
		window.display();
		window.clear();


	}
	
	return 0;

}