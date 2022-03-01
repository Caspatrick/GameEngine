#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Renderer.h"
#include <iostream>


int main() {

	//initialize window
	sf::RenderWindow window(sf::VideoMode(600, 600), "simple SFML game", sf::Style::Close|sf::Style::Titlebar);
	float framerate = 25.0f;
	Renderer renderer(&window, framerate);
	//initialize player
	GameObject player(sf::Vector2f(100, 100), sf::Vector2f(300, 300));
	player.addAnimation("run", "assets\\MainCharacters\\VirtualGuy\\Run(32x32).png", 12, 1);
	player.playAnimation("run");
	renderer.add(&player);

	sf::Clock clock;
	float deltaT = 0.0f;
	//Game Loop
	while (window.isOpen())	{
		deltaT += clock.restart().asSeconds();
		if (deltaT > 1 / framerate) {
			//Event rection
			sf::Event evt;
			while (window.pollEvent(evt)) {
				switch (evt.type) {
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
				player.move(-1, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
				player.move(0, 1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				player.move(1, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
				player.move(0, -1);
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

}