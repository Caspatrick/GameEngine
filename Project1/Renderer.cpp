#include "Renderer.h"

Renderer::Renderer(int sizeX, int sizeY, std::string title) {
	window = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), title, sf::Style::Close | sf::Style::Titlebar);
}

Renderer::Renderer(sf::RenderWindow* _window) {
	window = _window;
}

void Renderer::add(GameObject* obj) {
	renderObjects.push_back(obj);
}

void Renderer::draw() {
	window->clear();
	for (GameObject* obj : renderObjects) {
		window->draw(obj->shape);
	}
	window->display();
}