#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class GameObject {
	friend class Renderer;
	sf::Texture texture;
	sf::Vector2f size;
	sf::RectangleShape shape;
	
public:
	GameObject(std::string texture_file, sf::Vector2f _size, sf::Vector2f _pos);
	void move(float x, float y);
	void move(sf::Vector2f dir);
	sf::Vector2f getPos();

};