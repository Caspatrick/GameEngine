#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Renderer.h"
#include <iostream>


int main() {

	//initialize window
	sf::RenderWindow window(sf::VideoMode(600, 600), "simple SFML game", sf::Style::Close|sf::Style::Titlebar);
	Renderer renderer(&window);
	//initialize player
	GameObject player("Box.png", sf::Vector2f(100, 100), sf::Vector2f(300, 300));
	renderer.add(&player);
	//Game Loop
	while (window.isOpen())	{
		//Event rection
		sf::Event evt;
		while (window.pollEvent(evt)){
			switch(evt.type){
			case sf::Event::Closed:
				window.close();
				break;
			//case sf::Event::Resized: //Resize option disabled 
			//	std::cout << "New Window size: (" << evt.size.width << "," << evt.size.height << ")" << std::endl;
			//case sf::Event::TextEntered:
			//	std::cout << evt.text.unicode << std::endl;
			}
		}

		//Keyboard input handling
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0f, 0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
			window.close();
		}

		//Mouse input handling
		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//get position relative to window
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		}*/
		renderer.draw();

	}

}