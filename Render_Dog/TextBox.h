#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <iostream>
#include <Windows.h>

class TextBox {


public:

	TextBox(int PosX, int PosY, int sizex, int sizey) {
	
		Tbox.setSize(sf::Vector2f(sizex, sizey));	Tbox.setOrigin(Tbox.getSize().x /2 , Tbox.getSize().y / 2);
		Tbox.setPosition(PosX, PosY);
		Tbox.setOutlineThickness(1);
		Tbox.setFillColor(sf::Color::Transparent);	Tbox.setOutlineColor(sf::Color::White);

	}

	void Write(int MouseX, int MouseY, sf::Event& event) {
		
		BebasNeue.loadFromFile("C:/Users/Felipe/source/repos/Render_Dog/Render_Dog/BebasNeue-Regular.otf");

		// Posicoes do objeto 
		unsigned short TPx = Tbox.getPosition().x;			unsigned short TSx = Tbox.getSize().x / 2 ;
		unsigned short TPy = Tbox.getPosition().y;			unsigned short TSy = Tbox.getSize().y / 2 ;
		
		// Texto a ser renderizado
		Ui_text.setFont(BebasNeue);


		// Y do texto = Y da posicao + || - 22x
		Ui_text.setPosition(160, 378);	Ui_text.setCharacterSize(35);
		Ui_text.setString(User_Input);

		Tbox.setOutlineColor(sf::Color::Red);

		std::string	String_User_Input = (std::string)User_Input;
		String_UserInput = (std::string)User_Input;

		// Detecta colisao da Textbox com o mouse
		if (MouseX >= TPx - TSx && MouseY >= TPy - TSy && MouseX <= TPx + TSx && MouseY <= TPy + TSy) {
			
			// Se detectar click do mouse durante a colisao com a Textbox 
			// Textbox_clicked = true, agora podemos escrever na textbox
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Textbox_clicked = true;
	

		}

		// Se o mouse nao estiver em colisao com a text box
		else {

			// E detectar click esquerdo, agora Textbox_click = falso, 
			// Nao podemos escrever mais na textbox
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Textbox_clicked = false;

			// Se a textbox estiver clicada, ela fica vermelha, se nao, fica branca
			if (Textbox_clicked == true) Tbox.setOutlineColor(sf::Color::Red);
			else Tbox.setOutlineColor(sf::Color::White);
		}

			
			// Se textbox_clicked == true
			if(Textbox_clicked == true) {

				// Se backspase for pressionado, removemos uma letra da nossa string
				// sem deixar o programa adicionar backspace para a string



				// FUNCAO CTRL + V
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
					sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
				
					// Abre o Clipboard para o programa
					OpenClipboard(0);

					// Handle é uma variavel de tipo indefinido sem função
					// Mas que pode ser acessada se for usada do modo certo
					HANDLE TextInClipboard = GetClipboardData(CF_TEXT);

					// Aqui usamos HANDLE covertido para referencia de char / char* 
					std::cout << (char*)TextInClipboard << std::endl;

					// E aqui inputamos que User_Input = (char*). Para podermos passar nosso vetor de caracteres
					// Para a nossa string
					User_Input = (char*)TextInClipboard;

					// Fechamos o Clipboard para podermos trazer novas informações quando precisarmos
					// E para evitar possiveis bugs
					CloseClipboard();
					
				
				
				}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && Textbox_clicked
				&& Text_Clock.getElapsedTime().asMilliseconds() > 30) {

				// Transformando SF::STRING em c++ string para usar .size() - 1 e retornar o tamanho da lista
				// Para pordermos excluir o index final da string
				

				

				// Se a string for = 0, nao faz nada, assim o programa nao crasha
				// por falta do que apagar
				if (String_User_Input.size() == 0) {}

				// Caso backspace nao tenha sido apertado, e nossa string > 0
				// a ultima letra e removida da nossa string
				else {
					User_Input.erase(String_User_Input.size() - 1, 1);
					Text_Clock.restart();
					
				}
			}
			

			// Trasnforma o input de texto do usuario em SF::STRING
			if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)
				&& !sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
				
				// Adiciona a tecla apertada para nossa string
				// obs : string do sf - "sf::string"
				User_Input += event.text.unicode;

				Text_Clock.restart();	}
			}
			
	}


	void Clear(bool Clicked){
	
		if (Clicked == true) { User_Input.clear(); }

	}

	void GetString(bool Clicked){

			if (Clicked == true) {
		
				// Abre o Clipboard para o programa
				OpenClipboard(0);

				// Handle é uma variavel de tipo indefinido sem função
				// Mas que pode ser acessada se for usada do modo certo
				HANDLE TextInClipboard = GetClipboardData(CF_TEXT);

				// Aqui usamos HANDLE covertido para referencia de char / char* 
				std::cout << (char*)TextInClipboard << std::endl;

				// E aqui inputamos que User_Input = (char*). Para podermos passar nosso vetor de caracteres
				// Para a nossa string
				User_Input = (char*)TextInClipboard;

				// Fechamos o Clipboard para podermos trazer novas informações quando precisarmos
				// E para evitar possiveis bugs
				CloseClipboard();

			}
	
	}


	void Render(sf::RenderWindow& window) {
	
		window.draw(Tbox);
		window.draw(Ui_text);
	}


private:

	bool Textbox_clicked = false;


	std::string String_UserInput; 
	sf::Clock Text_Clock;
	sf::RectangleShape Tbox; 
	sf::String User_Input;
	sf::Text Ui_text;	sf::Font BebasNeue;
};