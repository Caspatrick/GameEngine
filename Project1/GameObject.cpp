#include "GameObject.h"

GameObject::GameObject(std::string texture_file, sf::Vector2f _size, sf::Vector2f _pos) {
	size = _size;
	shape = sf::RectangleShape(size);
	texture = sf::Texture();
	texture.loadFromFile(texture_file);
	shape.setTexture(&texture);
	shape.setPosition(_pos);
	shape.setOrigin(0.5f * size);
}

void GameObject::move(float x, float y) {
	shape.move(x, y);
}
void GameObject::move(sf::Vector2f dir) {
	shape.move(dir);
}
sf::Vector2f GameObject::getPos() {
	return shape.getPosition();
}