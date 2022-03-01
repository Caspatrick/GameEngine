#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <string>
#include <map>
/** Class GameObject
* a class that handles renderable object in the game, such as players, boxes, coins, etc
**/
class GameObject {
friend class Renderer;
//variables
private:
	sf::Texture texture;
	sf::Vector2f size;
	sf::RectangleShape shape;
	std::map<std::string, Animation> animations;
	std::string curAnimation;

public:
	float movingSpeed = 0.01f;

//methods
public:
	//constructor
	GameObject(sf::Vector2f _size, sf::Vector2f _pos);
	//positioning the object in the window
	void move(float x, float y);
	void move(sf::Vector2f dir);

	void addAnimation(std::string name, std::string filename, int nImgsX, int nImgsY);
	void playAnimation(std::string name, int textureLine = 0);
	void flipHorizontally(bool flipH = true);
	void update();
	//getter function 
	sf::Vector2f getPos();

};