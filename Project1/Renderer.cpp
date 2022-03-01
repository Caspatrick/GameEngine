#include "Renderer.h"

/*Renderer::Renderer(int sizeX, int sizeY, std::string title) {
	window = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), title, sf::Style::Close | sf::Style::Titlebar);
}*/

Renderer::Renderer(sf::RenderWindow* _window, float _framerate){
	window = _window;
	framerate = _framerate;
}

void Renderer::add(GameObject* obj) {
	renderObjects.push_back(obj);
}

void Renderer::draw() {
	deltaT += clock.restart().asSeconds();
	if (deltaT > 1 / framerate) {
		deltaT = 0;
		window->clear();
		for (GameObject* obj : renderObjects) {
			obj->update();
			window->draw(obj->shape);
		}
		window->display();
	}
}