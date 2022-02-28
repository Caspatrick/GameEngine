#pragma once
#include <SFML/Graphics.hpp>
#include <string>
/** Class GameObject
* a class that handles renderable object in the game, such as players, boxes, coins, etc
**/
class GameObject {
	friend class Renderer;
	sf::Texture texture;
	sf::Vector2f size;
	sf::RectangleShape shape;
	
public:
	//constructor
	GameObject(std::string texture_file, sf::Vector2f _size, sf::Vector2f _pos);
	//positioning the object in the window
	void move(float x, float y);
	void move(sf::Vector2f dir);
	//getter function 
	sf::Vector2f getPos();

};